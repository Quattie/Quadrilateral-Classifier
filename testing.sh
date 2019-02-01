#!/bin/bash


for i in 'seq 1 100';
do
    output="output"
    ./main < "pyFiles/$i.txt" > "pyFiles/$i$output.txt"

for i in 'seq 1 800'
do
    output="output"
    ./main < "pyFiles/$i.txt"