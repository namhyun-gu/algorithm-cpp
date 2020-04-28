#!/bin/bash

PROGNAME=$(basename $0)

if [ $# -eq 0 ]; then
  echo "${PROGNAME}: Require solution name"
  exit 1
fi

mkdir $1
echo "Created $1 folder"
touch $1/input.txt
echo "Created $1/input.txt"
echo "#include <bits/stdc++.h>
using namespace std;
main() {
}" > $1/solution.cpp
echo "Created $1/solution.cpp"