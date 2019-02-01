#!/bin/bash

clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
