#!/bin/bash

# 사용법 확인
if [ $# -eq 0 ]; then
  echo "사용법: $0 '커밋 메시지'"
  exit 1
fi

# git add .
git add .

# git commit -m
commit_message="$1"
git commit -m "$commit_message"

# git push
git push

echo "Git add, commit, push가 완료되었습니다."
