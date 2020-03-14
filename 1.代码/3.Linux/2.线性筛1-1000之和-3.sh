#!/bin/bash
#!/bin/bash
declare -a prime

function init() {
    for i in `seq 0 1000`; do
       eval $1[$i]=0
    done
}
init prime

for (( i = 2; i <= 1000; i++ )); do
    if [[ ${prime[$i]} -eq 0 ]] ; then
        prime[0]=$[ ${prime[0]}+1 ]
        prime[${prime[0]}]=$i
    fi
    for (( j = 1; j <= ${prime[0]}; j++)); do
        if [[ $[ $i * ${prime[$j]} ] -gt 1000 ]]; then
            break
        fi
        prime[$[ $i * ${prime[$j]} ]]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]]; then 
            break
        fi
    done
done
for (( i = 1; i <= ${prime[0]}; i++ )); do
    sum=$[ ${sum} + ${prime[$i]} ]
    #echo ${prime[$i]}
done
echo $sum
