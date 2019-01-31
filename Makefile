#compile
clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping main.cpp -o main

#remove any previous profdata files
rm -f ./coverage/*.profdata

#declare tests
tests=(
    square
    rectangle
    trapezoid
    kite
    parallelogram
    rhombus
    quadrilateral
    error1
    error2
    error3
    error4
    error5
    error6
    error7
    error8
    error9
    error10
    error11
    error12
    blank
)

#create the first .profdata
touch ./coverage/blank.profdata
lastTest=blank

#loop through tests and merge each profraw file with the last generated profdata file
for currentTest in "${tests[@]}"
do
    ./main < ./coverage/testFiles/${currentTest}.txt > ./coverage/testFiles/${currentTest}Output.txt
    xcrun llvm-profdata merge -sparse ./coverage/testFiles/${lastTest}.profdata ./default.profraw -o ./coverage/testFiles/${currentTest}.profdata
    lastTest=testFiles/${currentTest}
done

#show code coverage
xcrun llvm-cov show ./main -instr-profile=./coverage/testFiles/${lastTest}.profdata main.cpp