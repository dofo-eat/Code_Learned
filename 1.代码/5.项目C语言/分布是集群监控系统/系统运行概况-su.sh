Time=`date +"%Y-%m-%d__%H:%m:%S"`
HostName=`hostname`

OsType=`cat /etc/issue.net | tr " " "_"`
KernelVersion=`uname -r`
LoadAvg=`cut -d  " " -f 1-3 /proc/loadavg`
Uptime=`uptime -p | tr -s " " "_"`
eval `df -T -x devtemps -x tmpfs -m --total | tail -n 1 | awk \
    '{printf("DiskTotal=%d;DiskUsedP=%d", $3, $6)}'`

DiskWarningLevel="normal"
if [[ ${DiskUsedP} -gt 90 ]];then
    DiskWarningLevel="warning"
elif [[ ${DiskUsedP} -gt 80 ]];then
    DiskWarningLevel="note"
fi

eval `free -m | head -n 2 |tail -n 1 | awk \
    '{printf("MemTotal=%s;MemUsed=%s", $2, $3)}'`
MemUsedP=$[ ${MemUsed}*100/${MemTotal} ]

MemWaringLevel="normal"
if [[ ${MemUsedP} -gt 80 ]];then
    MemWaringLevel="warning"
elif [[ ${MemUsedP} -gt 70 ]];then    
    MemWaringLevel="note"
fi

CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp}/100" | bc`
CpuWarningLevel="normal"
if [[ `echo "${CpuTemp} >= 70" | bc -l` = 1 ]];then
    CpuWarningLevel="warning"
elif [[ `echo ${CpuTemp} '>=' 50 | bc -l` = 1 ]];then
    CpuWarningLevel="note"
fi

echo "${Time} ${HostName} ${OsType} ${KernelVersion} ${Uptime} ${LoadAvg} ${DiskTotal} ${DiskUsedP}% ${MemTotal} ${MemUsedP}% ${CpuTemp} ${DiskWarningLevel} ${MemWaringLevel} ${CpuWarningLevel}"

