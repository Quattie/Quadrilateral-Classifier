#!/usr/bin/env python3

import random

path = "pyFiles/"

def makeSquareOutput():
    sqOutputFile = open(path + "squareOutput.txt", "w")
    for x in range(100):
        sqOutputFile.write("square" + "\n")


def makeRectangleOutput():
    rectOutputFile = open(path + "rectangleOutput.txt", "w")
    for x in range(90):
        rectOutputFile.write("rectangle" + "\n")

def makeRandomCoords():
    randFile = open("randomAuto.txt", "w")
    for x in range(50):
        randFile.write(
            str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " "
            + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + "\n")

def make1000FilesTest():
    for x in range(1000):
       open("file%03d.txt" % x, "w").write("some text\n")

def makeHoweverManyFiles(amount, quadName, numString):
    for x in range(amount):
        open(str(quadName) + "%03d.txt" % x, "w").write(str(numString) + "\n")

def makeUniqueSquareFiles():
    A = 1
    B = 0
    C = 1
    D = 1
    E = 0
    F = 1
    for x in range(100):
        open(path + "square%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

        # makeHoweverManyFiles(10, "square", (str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
        #                      + str(E) + " " + str(F + x) + "\n"))

def makeUniqueRectangleFiles():
    A = 1
    B = 0
    C = 1
    D = 1
    E = 0
    F = 1
    for x in range(100):
        open(path + "rectangle%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeUniqueRandomFiles():
    for x in range(1000):
        open(path + "random%d.txt" % x, "w").write(str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " "
            + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + "\n")


def makeNegativeFiles():
    for x in range(100):
        open(path + "errorNeg%03d.txt" % x, "w").write(str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1))
            + " " + str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1)) + " "
                + str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1)) + "\n")


def makeOverflowFiles():
    for x in range(100):
        open(path + "random%03d.txt" % x, "w").write(
            str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " "
            + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(
                random.randint(0, 100)) + " " + str(random.randint(0, 100))+ "\n")

def makeUniqueTrapezoidFiles():
    A = 2
    B = 0
    C = 3
    D = 1
    E = 2
    F = 1
    for x in range(50):
        open(path + "trapezoid%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D) + " "
                             + str(E + x) + " " + str(F) + "\n")

def makeUniqueParallelogramFiles():
    A = 2
    B = 0
    C = 3
    D = 1
    E = 1
    F = 1
    for x in range(50):
        open(path + "parallelogram%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeOneSquareFile():
    A = 1
    B = 0
    C = 1
    D = 1
    E = 0
    F = 1
    file = open(path + "squares.txt", "w")
    for x in range(100):
        file.write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeOneRectangleFile():
    A = 2
    B = 0
    C = 2
    D = 3
    E = 0
    F = 3
    file = open(path + "rectangle.txt", "w")
    for x in range(90):
        file.write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeOneTrapezoidFile():
    A = 2
    B = 0
    C = 3
    D = 1
    E = 2
    F = 1
    file = open(path + "trapezoid.txt", "w")
    for x in range(90):
        file.write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeTrapezoidOutput():
    rectOutputFile = open(path + "trapezoidOutput.txt", "w")
    for x in range(90):
        rectOutputFile.write("trapezoid" + "\n")

def makeOneParallelogramFile():
    A = 2
    B = 0
    C = 3
    D = 1
    E = 1
    F = 1
    file = open(path + "parallelogram.txt", "w")
    for x in range(90):
        file.write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeParallelogramOutput():
    rectOutputFile = open(path + "parallelogramOutput.txt", "w")
    for x in range(90):
        rectOutputFile.write("parallelogram" + "\n")

def makeOneNegativeFile():
    file = open(path + "negative.txt", "w")
    for x in range(90):
        file.write(str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1))
            + " " + str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1)) + " "
                + str(random.randint(-100, -1)) + " " + str(random.randint(-100, -1)) + "\n")


def makeNegativeOutput():
    rectOutputFile = open(path + "negativeOutput.txt", "w")
    for x in range(90):
        rectOutputFile.write("error 1" + "\n")


makeOneSquareFile()
makeSquareOutput()
makeOneRectangleFile()
makeOneTrapezoidFile()
makeRectangleOutput()
makeUniqueRandomFiles()
makeTrapezoidOutput()
makeOneParallelogramFile()
makeParallelogramOutput()
# makeOneNegativeFile()
# makeNegativeOutput()
