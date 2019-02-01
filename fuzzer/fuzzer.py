


import random

def makeSquareCoords():
    squareFile = open("squaresAuto.txt", "w")
    A = 2
    B = 0
    C = 2
    D = 2
    E = 0
    F = 2
    for x in range(50):
        squareFile.write(
            str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " " + str(E) + " " + str(F + x) + "\n")

def makeSquareOutput():
    sqOutputFile = open("squareAutoOutput.txt", "w")
    for x in range(50):
        sqOutputFile.write("square" + "\n")

def makeRectangleCoords():
    rectFile = open("rectanglesAuto.txt", "w")
    A = 2
    B = 0
    C = 2
    D = 3
    E = 0
    F = 3
    for x in range(50):
        rectFile.write(
            str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " " + str(E) + " " + str(F + x) + "\n")

def makeRectangleOutput():
    rectOutputFile = open("rectangleAutoOutput.txt", "w")
    for x in range(50):
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

makeSquareCoords()
makeSquareOutput()
makeRectangleCoords()
makeRectangleOutput()
makeRandomCoords()
make1000FilesTest()
