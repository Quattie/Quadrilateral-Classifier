./main < testFiles/square.txt > outputSquare.txt
diff testFiles/outputSquare.txt testFiles/squareOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/rectangle.txt > testFiles/outputRectangle.txt
diff testFiles/outputRectangle.txt testFiles/rectangleOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/trapezoid.txt > testFiles/outputTrapezoid.txt
diff testFiles/outputTrapezoid.txt testFiles/trapezoidOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/kite.txt > testFiles/outputKite.txt
diff testFiles/outputKite.txt testFiles/kiteOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/parallelogram.txt > testFiles/outputParallelogram.txt
diff testFiles/outputParallelogram.txt testFiles/ParallelogramOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/rhombus.txt > testFiles/outputRhombus.txt
diff testFiles/outputRhombus.txt testFiles/rhombusOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/quadrilateral.txt > testFiles/outputQuadrilateral.txt
diff testFiles/outputQuadrilateral.txt testFiles/quadrilateralOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error1.txt > testFiles/outputError1.txt
diff testFiles/outputError1.txt testFiles/error1Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error2.txt > testFiles/outputError2.txt
diff testFiles/outputError2.txt testFiles/error2Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error3.txt > testFiles/outputError3.txt
diff testFiles/outputError3.txt testFiles/error3Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error4.txt > testFiles/outputError4.txt
diff testFiles/outputError4.txt testFiles/error4Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error5.txt > testFiles/outputError5.txt
diff testFiles/outputError5.txt testFiles/error5Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error6.txt > testFiles/outputError6.txt
diff testFiles/outputError6.txt testFiles/error6Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error7.txt > testFiles/outputError7.txt
diff testFiles/outputError7.txt testFiles/error7Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error8.txt > testFiles/outputError8.txt
diff testFiles/outputError8.txt testFiles/error8Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error9.txt > testFiles/outputError9.txt
diff testFiles/outputError9.txt testFiles/error9Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error10.txt > testFiles/outputError10.txt
diff testFiles/outputError10.txt testFiles/error10Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error11.txt > testFiles/outputError11.txt
diff testFiles/outputError11.txt testFiles/error11Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
./main < testFiles/error12.txt > testFiles/outputError12.txt
diff testFiles/outputError12.txt testFiles/error12Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
exit 1
else
echo "test didn't run properly"
exit 1
fi
