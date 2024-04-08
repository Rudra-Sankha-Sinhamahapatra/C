#!/bin/bash

# Function to calculate GCD using Euclidean algorithm
gcd() {
    local a=$1
    local b=$2
    while [[ $b -ne 0 ]]; do
        local temp=$b
        b=$(( $a % $b ))
        a=$temp
    done
    echo $a
}

# Read input numbers from user
read -p "Enter first number: " num1
read -p "Enter second number: " num2

# Calculate GCD
result=$(gcd $num1 $num2)

# Output the result
echo "The Greatest Common Divisor of $num1 and $num2 is: $result"