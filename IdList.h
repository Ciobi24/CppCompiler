#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include "Node.h"

using namespace std;
struct IdInfo {
    //common var attributes
    string type;
    string name;
    int scopeId;
    bool isConst;
    union{int iVal; float fVal; char cVal; bool bVal; char*sVal;}value;
    //array attributes - separate class?
    bool isArr;
    vector<int>dimensions;
    vector<IdInfo*>arrVal;
};

class IdList {
    vector<IdInfo*> vars;   //symbol table
    public:
    vector<int>scope_path;  //for var matching
    int log_flag;
    bool existsVar(const char* name);
    bool alreadyDeclared(const char*name, int scope);
    IdInfo* getVar(const char* name, int scope);
    IdInfo* getArray(const char* name, int scope);
    bool checkType(const char* name1, const char* name2, int scope1, int scope2);
    int addVar(const char* type, const char* name, int scopeId, bool isArr, bool constness);

    int updateValue(const char* name, int iVal, float fVal, char cVal, bool bVal); //scope checking
    int updateInt(const char* name, int val, int scope);
    int updateFloat(const char* name, float val, int scope);
    int updateBool(const char* name, bool val, int scope);
    int updateStr(const char* name, char*val, int scope);
    int updateChr(const char* name, char val, int scope);
    int varVarUpdate(const char* name1, int scope1, const char* name2, int scope2);

    int setArraySize(const char* name, vector<int>dimensions, int scope);
    int initializeArray(const char* name, int scope);
    //int updateArray(const char* name, vector<int>values);
    int updateArrayValue(const char* name, int scope, vector<int>coordinates, IdInfo* elem); 
    int calculateIndex(const char*name, int scope, vector<int>coordinates);
    IdInfo* getArrElem(const char*name, int scope, vector<int>coordinates);
    IdInfo* getUArrElemByIndex(const char* name, int scope, int index);
    IdInfo* getMArrElemByIndex(const char* name, int scope, int index1, int index2);
    void printVars();
    void log(const char*msg);
    ~IdList();
};