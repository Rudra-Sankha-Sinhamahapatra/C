#!/bin/bash

is_armstrong() {
  local num="$1"
  local original_num="$num"
  local sum=0
  local digit

  while [[ $num -gt 0 ]]; do
    digit=$(( num % 10 ))
    sum=$(( sum + digit**3 ))
    num=$(( num / 10 ))
  done

  if [[ $sum -eq $original_num ]]; then
    echo "$original_num is an Armstrong number"
  else
    echo "$original_num is not an Armstrong number"
  fi
}

read -p "Enter a number: " number

is_armstrong "$number"