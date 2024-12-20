#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *keywords[] = {
    "Integer",                          "int",
    "Character",                        "char",
    "DoubleItAndGiveItToTheNextPerson", "double",
    "MASSIVE",                          "long",
    "Buoyant",                          "float",
    "Deprived",                         "void",
    "THESizeType",                      "size_t",
    "NoteBook",                         "FILE",
    "Architecture",                     "struct",
    "Undisclosed",                      "unsigned",
    "Persistent",                       "const",
    "Worthless",                        "NULL",
    "VarietyConstrue",                  "typedef",
    "TroughoutTheTime",                 "while",
    "Commence",                         "do",
    "LoopThisWontYa?",                  "for",
    "AssumingThat",                     "if",
    "ButIfItsNotTrue",                  "else",
    "Foreign",                          "extern",
    "ReturnTheFollowing:",              "return",
    "LithoGraphFormat",                 "printf",
    "EstablishString",                  "puts",
    "Consultation",                     "scanf",
    "ProportionOf",                     "sizeof",
    "IncludeTheFollowingLibrary:",      "#include",
    "DefineTheFollowingMacro:",         "#define",
    "RaiseTheFollowingError:",          "#error",
    "Sober:",                           "#pragma"
};

void replace_all(const char *str,
                     const char *substring,
                     const char *replacement) {

    char* _substr = strstr(str, substring);

    while (_substr != NULL && strcmp(substring, replacement) != 0) {

        sprintf(_substr, "%s%s", replacement, _substr + strlen(substring));

        _substr = strstr(str, substring);
    }
}

char *getFileInfo(char *filename) {
    FILE *target;
    target = fopen(filename, "r");
    
    if (!target) {
        printf("Error: L\n");
        return NULL;
    }

    char *buffer;
    fscanf(target, "%s", buffer);
    
    return buffer;
}

int writeToFile(char *filename, char *content) {
    FILE *target;
    target = fopen(filename, "w");

    if (!target) {
        printf("Error: L\n");
        return 1;
    }

    fprintf(target, "%s", content);
    return 0;
}

char *eval(char *filename, char *kw[]) {
    char *code = getFileInfo(filename);
    
    for (int i = 0; i < (sizeof(kw) / sizeof(*kw))/2; i += 2) {
        int j = i + 1;
        replace_all(code, kw[i], kw[j]);
    }
    
    return code;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: L\n");
        return 1;
    }
    
    char *code = eval(argv[1], keywords);
    writeToFile("tmp.c", code);
    system("gcc -o tmp tmp.c");
    system("./tmp");

    if (argc < 3) {
        return 0;
    }

    system("rm tmp*");
    return 0;
}
