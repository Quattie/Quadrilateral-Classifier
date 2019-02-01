
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
    sqOutputFile = open("squareOutput.txt", "w")
    for x in range(100):
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
    rectOutputFile = open("rectangleOutput.txt", "w")
    for x in range(100):
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
        open("square%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
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
        open("rectangle%03d.txt" % x, "w").write(str(A + x) + " " + str(B) + " " + str(C + x) + " " + str(D + x) + " "
                             + str(E) + " " + str(F + x) + "\n")

def makeUniqueRandomFiles():
    for x in range(100):
        open("random%03d.txt" % x, "w").write(str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " "
            + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + "\n")


makeUniqueSquareFiles()
makeUniqueRectangleFiles()
makeUniqueRandomFiles()
makeSquareOutput()
makeRectangleOutput()

# makeSquareCoords()
# makeRectangleCoords()
# makeRandomCoords()
# makeHoweverManyFiles("square", "2 0 2 2 0 2")
