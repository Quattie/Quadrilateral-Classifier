//
//  main.cpp
//  assignment3
//
//  Created by Alex Moyle on 1/15/19.
//  Copyright © 2019 Alex Moyle. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;


bool isSquare() {
    return false;
}
bool isRectangle() {
    return false;
}
bool isRhombi() {
    return false;
}
bool isParrallelagram() {
    return false;
}
bool isKite() {
    return false;
}
bool isTrapezoid() {
    return false;
}
//Only outputs one line of data at a time
vector<double> parseQuadData(const string input) {
    istringstream iss(input);
    vector<string> data(istream_iterator<string>{iss}, istream_iterator<string>());
    
    vector<double> parsedLine;
    parsedLine.push_back(0.0);
    parsedLine.push_back(0.0);
    for (string s : data) {
        parsedLine.push_back(stod(s));
    }
    return parsedLine;
    
}
//Reads in the whole file where each line is a single string
vector<string> readInQuads(const string input) {
    ifstream inny(input);
    string line;
    vector<string> allData;
    
    if (inny.is_open()) {
        while (getline(inny, line)) {
            allData.push_back(line);
        }
    }
    inny.close();
    return allData;
}

int main(int argc, const char * argv[]) {
    vector<string> test;
    vector<double> testD;
    test = readInQuads("Quadrilaterals.txt");
    for (string s : test) {
        testD = parseQuadData(s);
        for (double d : testD) {
            cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}
