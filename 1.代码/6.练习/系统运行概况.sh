#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S`

hostname=`hostname`

OSv=`cat /etc/issue | cut -d ' ' -f 1-3 | tr ' ' '_'`

Uv=`cat /proc/version | cut -d ' ' -f 3`

OStime=(`uptime | tr -s -c 'a-zA-Z0-9.:\n' ' ' | cut -d ' ' -f 3-4,6 | tr -s -c 'a-z0-9.\n' ' '`)

fz=`uptime | tr -s -c 'a-zA-Z0-9.:\n' ' ' | cut -d ' ' -f 11-13 | tr -s -c 'a-z0-9.\n' ' '`

cp=(`df | head -2 | tail -1 | tr -s -c '/a-z0-9\n' ' ' | cut -d ' ' -f 2,5`)
cp[0]=$[${cp[0]}/1000]

total=`free | head -2 | tail -1 | awk '{printf("%d", $2)}'`
total=$[${total}/1000]
free=`free | head -2 | tail -1 | awk '{printf("%d", $4)}'`
free=$[${free}/1000]
used=$[$total-$free]
bi=$[100*${used}/${total}]

wd=`cat /sys/class/thermal/thermal_zone0/temp`
wd=`echo "scale=2;${wd}/1000" | bc`

if [[ ${cp[1]} -gt 90 ]];then
    note[0]="warning"
elif [[ ${cp[1]} -gt 80 ]];then
    note[0]="note"
else
    note[0]="normal"
fi

if [[ $bi -gt 90 ]];then
    note[1]="warning"
elif [[ $bi -gt 80 ]];then
    note[1]="note"
else
    note[1]="normal"
fi

if [[ $(echo "$wd>=90") = 1 ]];then
    note[2]="warning"
elif [[ $(echo "$wd>=80") = 1 ]];then
    note[2]="note"
else
    note[2]="normal"
fi

echo "$time $hostname $OSv $Uv ${OStime[0]}_${OStime[1]}_day,_${OStime[2]}_hours,_${OStime[3]}_minutes $fz ${cp[0]} ${cp[1]}% $total ${bi}% $wd ${note[0]} ${note[1]} ${note[2]}"


