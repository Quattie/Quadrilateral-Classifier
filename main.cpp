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


bool inputError(string s) {
    size_t found = s.find_first_not_of("0123456789 ");
    //    cout << (found == string::npos) << endl;
    return (found != string::npos);
}
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

bool isParallelogram(vector<double> &allSlopes) {
    
    if (allSlopes[0] == allSlopes[2] && allSlopes[1] == allSlopes[3] && allSlopes[0] != allSlopes[1]) {
        return true;
    }
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
    
    if (!isParallelogram(allSlopes)) {
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
    
    if (inputError(input)) {
        cout << "Error 1" << endl;
        exit(EXIT_FAILURE);
    }
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

//"error 1" -- if the line contains the wrong number of points, contains invalid characters, has coordinates out of the range 0..100, or otherwise fails to describe three points (six integer values)
bool isError1(const string numbers) {
    
    vector<double> input = parseQuadData(numbers);
    for (double d : input) {
        if (d > 100 || d < 0) {
            return true;
        }
    }
    if (input.size() != 8) {
        return true;
    }
    return false;
}

//"error 2" -- if any two points coincide
bool isError2(vector<double> points) {
    vector<double> A = {points[0], points[1]};
    vector<double> B = {points[2], points[3]};
    vector<double> C = {points[4], points[5]};
    vector<double> D = {points[6], points[7]};
    
    if (A == B || A == C || A == D || B == C || B == D || C == D) {
        return true;
    }
    return false;
}

double orientation(double x1, double y1, double x2, double y2, double x3, double y3) {
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    double val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    
    if (val == 0) return 0;  // colinear
    
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(double x1, double y1, double x2, double y2, double x3, double y3){
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x3, y3);
    int o3 = orientation(x1, y1, x2, y2, x3, y3);
    int o4 = orientation(x1, y1, x2, y2, x3, y3);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    return false; // Doesn't fall in any of the above cases
}
//"error 3" -- if any two line segments representing sides cross each other
bool isError3(vector<double> vect) {
    
    if(doIntersect(vect[0], vect[1], vect[2], vect[3], vect[4], vect[5])) return true; //AB vs BC
    if(doIntersect(vect[2], vect[3], vect[4], vect[5], vect[6], vect[7])) return true; //BC vs CD
    if(doIntersect(vect[4], vect[5], vect[6], vect[7], vect[0], vect[1])) return true; //CD vs DA
    if(doIntersect(vect[6], vect[7], vect[0], vect[1], vect[2], vect[3])) return true; //DA vs AB
    
    return false;
}

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (a == 0) {
        return true;
    }
    return false;
}

//"error 4" -- if any three points are colinear
//x0 and y0 are 0 and 1
//x1 and y1 are 2 and 3
//x2 and y2 are 4 and 5
//x3 and y3 are 6 and 7
bool isError4(vector<double> d) {
    
    bool abc = collinear(d[0], d[1], d[2], d[3], d[4], d[5]);
    bool bcd = collinear(d[2], d[3], d[4], d[5], d[6], d[7]);
    bool cda = collinear(d[4], d[5], d[6], d[7], d[0], d[1]);
    bool dab = collinear(d[6], d[7], d[0], d[1], d[2], d[3]);
    
    if (abc == true || bcd == true || cda == true || dab == true) {
        return true;
    }
    //    if (collinear(d[0], d[1], d[2], d[3], d[4], d[5])) {return true;} //ABC
    //    if (collinear(d[2], d[3], d[4], d[5], d[6], d[7])) {return true;} //BCD
    //    if (collinear(d[4], d[5], d[6], d[7], d[0], d[1])) {return true;} //CDA
    //    if (collinear(d[6], d[7], d[0], d[1], d[2], d[3])) {return true;} //DAB
    
    return false;
}



void determineShape(vector<double> &allLengths, vector<double> &allSlopes) {
    if (isSquare(allLengths, allSlopes)) {
        cout << "square" << endl;
    } else if (isRhombus(allLengths, allSlopes)) {
        cout << "rhombus" << endl;
    } else if (isRectangle(allLengths, allSlopes)) {
        cout << "rectangle" << endl;
    } else if (isParallelogram(allSlopes)) {
        cout << "parallelogram" << endl;
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
        if (isError1(line)) {
            cout << "Error 1" << endl;
            exit(EXIT_FAILURE);
        }
        if (isError2(coordinates)) {
            cout << "Error 2" << endl;
            exit(EXIT_FAILURE);
        }
        if (isError3(coordinates)) {
            cout << "Error 3" << endl;
            exit(EXIT_FAILURE);
        }
        if (isError4(coordinates)) {
            cout << "Error 4" << endl;
            exit(EXIT_FAILURE);
        }
        determineShape(coorLen, allSlopes);
    }
    return 0;
}
