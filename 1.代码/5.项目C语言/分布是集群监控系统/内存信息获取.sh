#!/bin/bash

#是否有参数
if [[ $# -lt 1 ]];then
    echo "Usage:$0 DyAver"
fi

Time=`data +"%Y-%m-%d__%H:%M:%S"`
DyAver=$1

if [[ ${DyAver}x == x ]];then
    exit 1
fi
#内存值
MemValues=(`free -m | head -2 | tail -1 | awk "{printf("%s %s", $2, $3)}"`)

#当前使用总值
MemUsedPrec=`echo "scale=1; ${MemValues[1]}*100/${MemValues[0]}" |bc`

#当前使用平均值
NowAver=`echo "scale=1; 0.7*${MemUsedPrec}+0.3*${DyAver}" | bc`

echo "${Time} ${MemValues[0]}M ${MemValues[1]}M ${MemUsedPrec}% ${NowAver}%"
