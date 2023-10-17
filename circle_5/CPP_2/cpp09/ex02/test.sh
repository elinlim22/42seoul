#!/bin/bash

if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <repeat> <arg1> <arg2>"
  echo "  arg1:   count of numbers"
  echo "  arg2:   range of numbers"
  echo "  repeat: Number of times to run the program"
  exit 1
fi

# 인자로 받은 반복 횟수
arg1="$1"
arg2="$2"
repeat_count="$3"

for ((i=1; i<=$repeat_count; i++))
do
    # 프로그램 실행 명령어를 여기에 추가
    ./PmergeMe `jot -r "$1" 1 "$2" | tr '\n' ' '`

    # 프로그램의 Exit status를 확인하고, EXIT_FAILURE인 경우 스크립트 종료
    if [ $? -ne 0 ]; then
        echo "프로그램이 EXIT_FAILURE로 종료되었습니다."
        exit 1
    fi
done

echo "모든 반복이 성공적으로 완료되었습니다."
