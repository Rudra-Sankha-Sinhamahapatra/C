reverse_number() {
    num=$1
    reversed=0


    while [ $num -gt 0 ]; do

        digit=$((num % 10))

        reversed=$((reversed * 10 + digit))

        num=$((num / 10))
    done

    echo $reversed
}

echo "Enter a number:"
read number

result=$(reverse_number $number)

echo "The reverse of $number is: $result"