#!/bin/bash 
echo -n Give the folder name to run all C files:
read folder

find $folder -name *.c > filename.txt
read -p filename.txt
i=0
while read line
do 
((i++))
echo -n Compiling and Running the $line file 
echo 
gcc $line -o output$i.out 
./output$i.out 
echo -n Program is compiled and output is created 
echo 
done < filename.txt