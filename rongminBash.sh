#!/bin/bash

#clang++ -std=c++11 -fsanitize=address main.cpp -o main
#the line above will run the code with the address sanitizer on, but it takes a long time to run

errorCount=0

for i in `seq 0 9999`;
do
random="random"
./jordan < "rongmin/$random$i.txt" > "rongmin/rongmin$random$i.txt"
./main < "rongmin/$random$i.txt" > "rongmin/alex$random$i.txt"
diff "rongmin/rongmin$random$i.txt" "rongmin/alex$random$i.txt"
error=$?
if [ $error -eq 0 ]
then
echo "test $i passed"
fi
if [ $error -eq 1 ]
then
errorCount=$((errorCount + 1))
echo "test $i failed"
fi
done

if [ "$errorCount" -gt 0 ]
then
echo "$errorCount Errors"
exit 1
elif [ "$errorCount" -eq 0 ]
then
echo "OK"
echo "$errorCount"
exit 0
fi

for i in `seq 0 9999`;
do
    rm -f "rongmin/alex$random$i.txt"
    rm -f "rongmin/rongmin$random$i.txt"

done
