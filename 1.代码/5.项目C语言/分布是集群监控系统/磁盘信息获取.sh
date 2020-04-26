#!/bin/bash

Time=`date +"%Y-%m-%d__%H:%M:%S"`

eval `df -T -m -x tmpfs -x devtmpfs |tail -n +2 |awk -v DiskSum=0 -v DisLeft=0 '{printf("Pname["NR"]=%s;Psum["NR"]=%d;Pleft[["NR"]]=%d;Puseprerc["NR"]=%s;", $7，$3, $4, $6); DiskSum+=$3; DisLeft+=$5) END {
printf("Pnum=%d;DiskSum=%d;DisLeft=%d;", NR, DiskSum, DisLeft)
}'`
for (( i = 1;i <= ${Pnum}; i++ ));do
    echo "${Time} 1 ${Pname[$i]} ${Psum[$i]} ${Pleft[$i]} $[Puseprerc[$i]]"
done

DiskPerc=$[ (100 - ${DisLeft}*100/${DiskSum}) ]

echo"${Time} 0 disk ${DiskSum} ${DisLeft} ${DiskPerc}%"

