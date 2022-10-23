#!/bin/bash  
echo  "Enter number"  
read n 

if [ $(($n%2)) -eq 0 ]
then
echo "Number is even"
else
echo "Number is odd"
fi 

