#!/bin/bash

if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <repeat> <arg1> <arg2>"
  echo "  arg1:   count of numbers"
  echo "  arg2:   range of numbers"
  echo "  repeat: Number of times to run the program"
  exit 1
fi

arg1="$1"
arg2="$2"
repeat_count="$3"

for ((i=1; i<=$repeat_count; i++))
do
    ./PmergeMe `jot -r "$1" 1 "$2" | tr '\n' ' '`

    if [ $? -ne 0 ]; then
        echo "프로그램이 EXIT_FAILURE로 종료되었습니다."
        exit 1
    fi
done

echo "모든 반복이 성공적으로 완료되었습니다."
