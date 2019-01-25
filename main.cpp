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
#include <math.h>

using namespace std;

double calculateLength (double x1, double y1, double x2, double y2){
    double distance = 0;
    
    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    return distance;
}

//Returns a vector of doubles with side1 in the [0] all the way up to 4
vector<double> findAllLengths(const vector<double> &al) {
    
    //originx and originy are 0 and 1
    //x1 and y1 are 0 and 1
    //x2 and y2 are 2 and 3
    //x3 and y3 are 4 and 5
    double side1 = calculateLength(al[0], al[1], al[2], al[3]);
    double side2 = calculateLength(al[2], al[3], al[4], al[5]);
    double side3 = calculateLength(al[4], al[5], al[6], al[7]);
    double side4 = calculateLength(al[6], al[7], al[0], al[1]);
    
    vector<double> allLengths;
    allLengths.push_back(side1);
    allLengths.push_back(side2);
    allLengths.push_back(side3);
    allLengths.push_back(side4);
    
    return allLengths;
}

double findSlope(double x1, double y1, double x2, double y2) {
    double vy = y2 - y1;
    double vx = x2 - x1;
    if (vy == 0 || vx == 0) {
        return 0;
    }
    double slope = vy / vx;
    return slope;
}

vector<double> findAllSlopes(const vector<double> &al) {
    
    //originx and originy are 0 and 1
    //x1 and y1 are 0 and 1
    //x2 and y2 are 2 and 3
    //x3 and y3 are 4 and 5
    double slopeOA = findSlope(al[0], al[1], al[2], al[3]);
    double slopeAB = findSlope(al[2], al[3], al[4], al[5]);
    double slopeBC = findSlope(al[4], al[5], al[6], al[7]);
    double slopeCO = findSlope(al[6], al[7], al[0], al[1]);
    
    vector<double> allSlopes;
    allSlopes.push_back(slopeOA);
    allSlopes.push_back(slopeAB);
    allSlopes.push_back(slopeBC);
    allSlopes.push_back(slopeCO);
    
    return allSlopes;
}


bool isParrallelagram(vector<double> &allSlopes) {
    
//    int counter = 0;
//    if (allLengths[0] == allLengths[2] && allLengths[1] == allLengths[3]) counter++;
    if (allSlopes[0] == allSlopes[2] && allSlopes[1] == allSlopes[3] && allSlopes[0] != allSlopes[1])
//    if (counter == 2)
        return true;
    return false;
}

bool isRectangle(vector<double> &allLengths, vector<double> &allSlopes) {
    
    for (int i = 0; i < 4; i ++) {
        if (allLengths[0] == allLengths[2] && allLengths[1] == allLengths[3] && allSlopes[i] == allSlopes[i + 1]) {
            return true;
        }
    }
    return false;
}

bool isRhombus(vector<double> &allLengths, vector<double> &allSlopes) {
    
    if (!isParrallelagram(allSlopes)) {
        return false;
    }
    for (int i = 0; i < 4; i ++) {
        if ((allSlopes[0] != allSlopes[1]) && (allLengths[i] == allLengths[i + 1])) {
            return true;
        }
    }
    return false;
}

bool isKite(vector<double> &allLengths) {
    
    int counter = 0;
    if (allLengths[0] == allLengths[1] || allLengths[0] == allLengths[3]) counter++;
    if (allLengths[1] == allLengths[2] || allLengths[2] == allLengths[3]) counter++;
    if (counter == 2) {
        return true;
    }
    return false;
}

bool isTrapezoid(vector<double> &allSlopes) {
    
    if ((allSlopes[0] == allSlopes[2]) || (allSlopes[1] == allSlopes[3])) {
        return true;
    }
    return false;
}

bool isSquare(vector<double> &allLengths, vector<double> &allSlopes) {
    
    for (int i = 0; i < 4; i ++) {
        if (allLengths[i] == allLengths[i + 1] && allSlopes[i] == allSlopes[i + 1]) {
            return true;
        }
    }
    return false;
}



//Only outputs one line of data at a time
vector<double> parseQuadData(const string input) {
    istringstream iss(input);
    //    vector<string> data(istream_iterator<string>{iss}, istream_iterator<string>());
    
    vector<string> results;
    vector<double> parsedLine;
    
    for (string input; iss>>input;)
        results.push_back(input);
    parsedLine.push_back(0.0);
    parsedLine.push_back(0.0);
    for (int i = 0; i < results.size(); i++) {
        parsedLine.push_back(stod(results[i]));
    }
    return parsedLine;
}

void determineShape(vector<double> &allLengths, vector<double> &allSlopes) {
    if (isSquare(allLengths, allSlopes)) {
        cout << "square" << endl;
    } else if (isRhombus(allLengths, allSlopes)) {
        cout << "rhombus" << endl;
    } else if (isRectangle(allLengths, allSlopes)) {
        cout << "rectangle" << endl;
    } else if (isParrallelagram(allSlopes)) {
        cout << "parrallelagram" << endl;
    } else if (isTrapezoid(allSlopes)) {
        cout << "trapezoid" << endl;
    } else if (isKite(allLengths)) {
        cout << "kite" << endl;
    } else {
        cout << "quadrilateral" << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<string> test;
    vector<double> testD;
    vector<double> coorList;
    
    string line;
    vector<double> coordinates;
    while (getline(cin, line)) {
        coordinates = parseQuadData(line);
        vector<double> coorLen = findAllLengths(coordinates);
        vector<double> allSlopes = findAllSlopes(coordinates);
        determineShape(coorLen, allSlopes);
    }
    //    test = readInQuads("coordinates.txt");
    //    for (string s : test) {
    //        testD = parseQuadData(s);
    //        for (double d : testD) {
    ////            cout << d << " ";
    //            coorList.push_back(d);
    //        }
    //        cout << endl;
    //    }
    //    for (double d : coorList) {
    //        cout << d << " ";
    //        cout << endl;
    //    }
    //
    //    double slopeTest = findSlope(4, 8, 5, 5);
    //    cout << slopeTest << endl;
    //
    //    vector<double> allSlopes = findAllSlopes(4, 0, 4, 4, 0, 4);
    //    for (double d : allSlopes) {
    //        cout << d << endl;
    //    }
    //    cout << isSquare(4, 0, 4, 4, 0, 4) << endl;
    //
    //    cout << isRhombi(4, 0, 4, 4, 0, 4) << endl;
    //
    //    vector<double> angleTest = calculateAngles(4, 0, 4, 4, 0, 4);
    //    vector<double> angleTest2 = calculateAngles(5, 5, 8, 4, 7, 1);
    //
    //    for (double d : angleTest2) {
    //        cout << d << endl;
    //    }
    //    cout << angleTest[0];
    //
    //    vector<double> lengthTest;
    //    lengthTest = allLengths(4, 0, 4, 4, 0, 4);
    //    for (double d : lengthTest) {
    //        cout << d;
    //    }
    return 0;
}
