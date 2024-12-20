import GetFileInfo

class THE_Interpreter:
    def __init__(self, TheFileName):
        self.OneSelfsCode = GetFileInfo.GetFileInfo(TheFileName)
        self.OneSelfsIgnore = False

    def OneSelfsDescentIntoInterpreting(self):
        OneSelfsCompiledCode = []
        for OneSelfsLine in self.OneSelfsCode:
            if self.OneSelfsIgnore and not OneSelfsLine.startswith("\\end-ignore"):
                OneSelfsCompiledCode += OneSelfsLine
                continue
            if OneSelfsLine.startswith("\\do-ignore"):
                self.OneSelfsIgnore = True
                continue
            self.OneSelfsIgnore = False
            if OneSelfsLine.startswith("\\end-ignore"):
                continue
            
            OneSelfsValue = OneSelfsLine\
            .replace("Integer", "int")\
            .replace("Character", "char")\
            .replace("DoubleItAndGiveItToTheNextPerson", "double")\
            .replace("MASSIVE", "long")\
            .replace("Buoyant", "float")\
            .replace("Deprived", "void")\
            .replace("THESizeType", "size_t")\
            .replace("NoteBook", "FILE")\
            .replace("Architecture", "struct")\
            .replace("Undisclosed", "unsigned")\
            .replace("Persistent", "const")\
            .replace("Worthless", "NULL")\
            .replace("VarietyConstrue", "typedef")\
            .replace("TroughoutTheTime", "while")\
            .replace("Commence", "do")\
            .replace("LoopThisWontYa?", "for")\
            .replace("AssumingThat", "if")\
            .replace("ButIfItsNotTrue", "else")\
            .replace("Foreign", "extern")\
            .replace("ReturnTheFollowing:", "return")\
            .replace("LithoGraphFormat", "printf")\
            .replace("EstablishString", "puts")\
            .replace("Consultation", "scanf")\
            .replace("ProportionOf", "sizeof")\
            .replace("IncludeTheFollowingLibrary:", "#include")\
            .replace("DefineTheFollowingMacro:", "#define")\
            .replace("RaiseTheFollowingError:", "#error")\
            .replace("Sober:", "#pragma")
            OneSelfsCompiledCode += OneSelfsValue
        return OneSelfsCompiledCode
            
    def CompileOneSelf(self, OneSelfsTarget):
        with open(OneSelfsTarget, "w") as TheTarget:
            TheTarget.write("".join(self.OneSelfsDescentIntoInterpreting()))
            TheTarget.close()
