read -p "Enter a Number" num

if(($num<=1)) then
echo "$num is not prime"
fi

if(($num==2)) then
echo "$num is prime"
fi


is_prime=true

for((i=2;i<=num/2;i++));do
if((num%i==0))then
is_prime=false
fi
done

if $is_prime; then
echo "$num is  prime"
else
echo "$num is not prime"
fi