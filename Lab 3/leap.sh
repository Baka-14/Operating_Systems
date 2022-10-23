#!/bin/bash  
echo  "Enter number"  
read n  

if [ $(($n%400)) -eq 0 ]
then
echo "It is a Leap Year"

elif [ $(($n%100)) -eq 0 ]
then 
echo "It is a Leap Year"

elif [ $(($n%4)) -eq 0 ]
then 
echo "It is a Leap Year"

else
echo "It is not a Leap Year"
fi 
