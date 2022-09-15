#!/bin/bash  
echo  "Enter num1" 
read a
echo "Enter num2"
read b
echo "a before swapping is $a and b is $b"
a=$((a+b))
b=$((a - b))
a=$((a-b))
echo "a after swapping is  $a and b is $b" 


