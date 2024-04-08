read -p "Enter the number till what digit you want to print" num

a=0
b=1
count=0

echo "Fibonacci series upto $num terms "
while((count<$num)); do
echo "$a"
temp=$((a+b))
a=$b
b=$temp
((count++))
done
