#!/bin/bash 
echo -n Enter the radius of circle 
read r 
num1=22/7
ans=$((num1 *$r*$r)) 
echo $ans 
c=2
ans1=$(( $c*$num1*$r))
echo $ans1 
