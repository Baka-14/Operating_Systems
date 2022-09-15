#!/bin/bash

for i in {1..20}
do
touch file$i.txt 
done 

for i in {1..20}
do
rm -f file$i.txt
done