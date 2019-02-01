#!/bin/bash

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

for i in `seq 0 799`;
do
    random="random"
    output="output"
    output2="Output"
    ./main < "pyFiles/$random$i.txt" > "pyFiles/$output$random$i.txt"
done

for i in `seq 0 799`;
do
    rm -f "pyFiles/$output$i$random.txt"
done

rm -f pyFiles/outputSquare.txt
rm -f pyFiles/outputRectangle.txt

if [[ $erroCount -gt 0 ]]
    then
        echo "Error"
        exit 1
elif [[ $erroCount -eq 0 ]]
    then
        echo "OK"
        exit 0
fi