#!/usr/bin/env python3

import random

path = "rongmin/"

def makeRandomFiles():
    for x in range(10000):
        open(path + "random%d.txt" % x, "w").write(str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " "
            + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + "\n")

makeRandomFiles()