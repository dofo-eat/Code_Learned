#!/bin/bash

function init_prime() {
    max_n=$1
    cnt=0
    for (( i = 2; i <= ${max_n}; i++ )) {
        if [[ ${vis[${i}]} -ne 1 ]]; then
            #echo ${i}
            cnt=$[${cnt} + 1]
            prime[${cnt}]=${i}
        fi
        for (( j = 1; j <= ${cnt} && $[${prime[${j}]} * ${i}] <= ${max_n}; j++ )) {
            vis[$[${i}*${prime[ ${j}]}]]=1
            #echo $[${i}*${prime[ ${j}]}]
            if [[ $[${i}%${prime[ ${j}]}] -eq 0 ]]; then
                break
            fi
        }
    }
}


init_prime 1000
sum=0
for (( i = 1; i <= ${cnt}; i++ )) {
    sum=$[${sum} + ${prime[${i}]}]
}
echo "result = " ${sum}

