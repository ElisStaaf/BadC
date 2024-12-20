#!/usr/bin/python3

import TheInterpreter
from sys import argv as ArgumentVector
from os import system as SystemCommand

IsThisTheCorrectSourceFileIDK = __name__ == "__main__"

def MainFunctionWithManyElements(TheArgumentVector):
    THE_NEW_Interpreter = TheInterpreter.THE_Interpreter(TheArgumentVector[1])
    THE_NEW_Interpreter.CompileOneSelf("Temporary.c")
    SystemCommand("gcc -o Temporary Temporary.c")
    SystemCommand("./Temporary")
    if len(TheArgumentVector) > 3 and TheArgumentVector[2] != "-S":
        SystemCommand("rm Temporary*")

if IsThisTheCorrectSourceFileIDK:
    MainFunctionWithManyElements(ArgumentVector)
