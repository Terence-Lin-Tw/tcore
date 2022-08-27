#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

printf '\33[H\33[2J'
echo
echo "Select your favorite test to run:"
echo

ar=(*.cpp)
ar+=("Exit")
for ((i = 0; i < ${#ar[@]}; i++))
do
    let "n = $i + 1"
    menu_text[$i]="  ${n}) ${ar[$i]}"
done

last_index=$(expr ${#menu_text[@]} - 1)

for ((i = 0; i < ${#ar[@]}; i++))
do
    echo "${menu_text[$i]}"
done

echo
flag=0
while [ $flag -eq 0 ]
do
    read -p "  Select the number: " n
    echo -en "\033[1A\033[2K"
    for ((i = 0; i < ${#menu_text[@]}; i++)); do
        if [[ ${i} == ${#menu_text[@]} ]]; then break; fi

        if [[ ${menu_text[$i]} == "  $n) "* ]]; then
            flag=1
            break
        fi
    done
done

if ((i == last_index)); then
    echo "  see ya"
    echo
    export BASE=exit
    return
fi

export BASE=${ar[$i]/_tests.cpp/}
