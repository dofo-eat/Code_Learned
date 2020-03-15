#!/bin/bash

if[[ $# -ne 1 ]];then
    echo "Usage: bash list.sh num"
    exit
fi

Cnt=$1

Names=(`cat names`)

function rand(){
    Min=1
    Max=${#Names[*]}
    Num=`cat /dev/random |head -n 10 |cksum |cut -d ' ' -f 1`
    echo $[ $Num % $Max + $Min]
}

for i in `seq 1 $Cnt`
    Random=`rand`
    echo "${Names[${Random}]}"
done
