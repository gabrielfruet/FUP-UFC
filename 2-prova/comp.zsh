#!/usr/bin/env zsh

files_amount="7"
if [[ $1 == "-m" ]]; then
  shift 1
  for i in "$@"; do
    gcc ./src/"$(printf '%dq.c' $i)" -o ./bin/"$(printf '%dq.o' $i)" -lm
  done 
else
  for i in $(seq 1 $files_amount); do
    gcc ./src/"$(printf '%dq.c' $i)" -o ./bin/"$(printf '%dq.o' $i)" -lm
  done
fi

