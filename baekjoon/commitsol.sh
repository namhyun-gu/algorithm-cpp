#!/bin/bash

PROGNAME=$(basename $0)

if [ $# -eq 0 ]; then
  echo "${PROGNAME}: Require solution name"
  exit 1
fi

git add $1/.
git commit -m "Add 'baekjoon/$1' solution"