def GetFileInfo(TheFileName: str):
    with open(TheFileName, "r") as TheFile:
        TheContentsOfTheFileInStrFormatInAListUsingTheReadLinesFunction = TheFile.readlines()
        TheFile.close()
    return TheContentsOfTheFileInStrFormatInAListUsingTheReadLinesFunction
