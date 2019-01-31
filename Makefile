all: main

main: main.cpp
	clang++ -std=c++11 main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main
	rm -f testFiles/outputSqaure.txt
	rm -f testFiles/outputRectangle.txt
	rm -f testFiles/outputTrapezoid.txt
	rm -f testFiles/outputKite.txt
	rm -f testFiles/outputParallelogram.txt
	rm -f testFiles/outputRhombus.txt
	rm -f testFiles/outputQuadrilateral.txt
	rm -f testFiles/outputError1.txt
	rm -f testFiles/outputError2.txt
	rm -f testFiles/outputError3.txt
	rm -f testFiles/outputError4.txt
	rm -f testFiles/outputError5.txt
	rm -f testFiles/outputError6.txt
	rm -f testFiles/outputError7.txt
	rm -f testFiles/outputError8.txt
	rm -f testFiles/outputError9.txt
	rm -f testFiles/outputError10.txt
	rm -f testFiles/outputError11.txt
	rm -f testFiles/outputError12.txt


cover:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main

	LLVM_PROFILE_FILE=“profraw/square.profraw” ./main < testFiles/square.txt
	LLVM_PROFILE_FILE=“profraw/rectangle.profraw” ./main < testFiles/rectangle.txt
	LLVM_PROFILE_FILE=“profraw/trapezoid.profraw” ./main < testFiles/trapezoid.txt
	LLVM_PROFILE_FILE=“profraw/kite.profraw” ./main < testFiles/kite.txt
	LLVM_PROFILE_FILE=“profraw/parallelogram.profraw” ./main < testFiles/parallelogram.txt
	LLVM_PROFILE_FILE=“profraw/rhombus.profraw” ./main < testFiles/rhombus.txt
	LLVM_PROFILE_FILE=“profraw/quadrilateral.profraw” ./main < testFiles/quadrilateral.txt
	LLVM_PROFILE_FILE=“profraw/error1.profraw” ./main < testFiles/error1.txt
	LLVM_PROFILE_FILE=“profraw/error2.profraw” ./main < testFiles/error2.txt
	LLVM_PROFILE_FILE=“profraw/error3.profraw” ./main < testFiles/error3.txt
	LLVM_PROFILE_FILE=“profraw/error4.profraw” ./main < testFiles/error4.txt
	LLVM_PROFILE_FILE=“profraw/error5.profraw” ./main < testFiles/error5.txt
	LLVM_PROFILE_FILE=“profraw/error6.profraw” ./main < testFiles/error6.txt
	LLVM_PROFILE_FILE=“profraw/error7.profraw” ./main < testFiles/error7.txt
	LLVM_PROFILE_FILE=“profraw/error8.profraw” ./main < testFiles/error8.txt
	LLVM_PROFILE_FILE=“profraw/error9.profraw” ./main < testFiles/error9.txt
	LLVM_PROFILE_FILE=“profraw/error10.profraw” ./main < testFiles/error10.txt
	LLVM_PROFILE_FILE=“profraw/error11.profraw” ./main < testFiles/error11.txt
	LLVM_PROFILE_FILE=“profraw/error12.profraw” ./main < testFiles/error12.txt

cover:
	xcrun llvm-profdata merge -sparse profraw/square.profraw profraw/rectangle.profraw profraw/trapezoid.profraw profraw/kite.profraw profraw/parallelogram.profraw profraw/rhombus.profraw profraw/quadrilateral.profraw profraw/error1.profraw profraw/error2.profraw profraw/error3.profraw profraw/error4.profraw profraw/error5.profraw profraw/error6.profraw profraw/error7.profraw profraw/error8.profraw profraw/error9.profraw profraw/error10.profraw profraw/error11.profraw profraw/error12.profraw  -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata