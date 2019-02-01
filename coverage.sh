#!/bin/bash

clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
random="random"
for i in `seq 0 799`;
do
    output="output"
    LLVM_PROFILE_FILE="profraw/$random$i.profraw" ./main < pyFiles/$random$i.txt > pyFiles/$output$i.txt
done

LLVM_PROFILE_FILE="profraw/square.profraw" ./main < pyFiles/squares.txt > pyFiles/outputSquare.txt
LLVM_PROFILE_FILE="profraw/rectangle.profraw" ./main < pyFiles/rectangle.txt > pyFiles/outputRectangle.txt


str=""
for i in `seq 0 799`;
do
    str+="profraw/$random$i.profraw "
done

str+="profraw/square.profraw "
str+="profraw/rectangle.profraw "

xcrun llvm-profdata merge -sparse $str -o main.profdata
xcrun llvm-cov show ./main -instr-profile=main.profdata > coverage.txt

for i in `seq 0 799`;
do
    rm -f "profraw/$random$i.profraw"
done

rm -f profraw/square.profraw
rm -f profraw/rectangle.profraw
