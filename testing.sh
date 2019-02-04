#!/bin/bash

clang++ -std=c++11 -fsanitize=address main.cpp -o main
#the line above will run the code with the address sanitizer on, but it takes a long time to run

errorCount=0

./main < pyFiles/squares.txt > pyFiles/outputSquare.txt
diff pyFiles/squareOutput.txt pyFiles/outputSquare.txt
error=$?
if [ $error -eq 1 ]
then
errorCount+=1
fi

./main < pyFiles/rectangle.txt > pyFiles/outputRectangle.txt
diff pyFiles/rectangleOutput.txt pyFiles/outputRectangle.txt
error=$?
if [ $error -eq 1 ]
then
errorCount+=1
fi

./main < pyFiles/trapezoid.txt > pyFiles/outputTrapezoid.txt
diff pyFiles/trapezoidOutput.txt pyFiles/outputtrapezoid.txt
error=$?
if [ $error -eq 1 ]
then
errorCount+=1
fi

for i in `seq 0 999`;
do
    random="random"
    output="output"
    output2="Output"
    ./main < "pyFiles/$random$i.txt" > "pyFiles/$output$random$i.txt"
done

for i in `seq 0 999`;
do
    rm -f "pyFiles/$output$i$random.txt"
done

rm -f pyFiles/outputSquare.txt
rm -f pyFiles/outputRectangle.txt
rm -f pyFiles/outputTrapezoid.txt

if [[ $erroCount -gt 0 ]]
    then
        echo "Error"
        exit 1
elif [[ $erroCount -eq 0 ]]
    then
        echo "OK"
        exit 0
fi
