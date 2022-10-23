#!/bin/bash 
echo "Enter the number"
read n
c=2
flag=0
while [ $c -le $(($n/2)) ]
do
    if [ $(($n%$c)) -eq 0 ]
    then
    ((flag++))
    break
    fi
    
((c++))
done

if [ $flag -eq 0 ]
then
echo "Number is prime"
else
echo "Number is not prime"
fi 