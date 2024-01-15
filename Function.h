#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include "IdList.h"
using namespace std;


class Function{
public:
string name;
string type;
vector <IdInfo> param;
};

class FunctionTable{
    vector<Function*> functions;
    public:
    bool existsFunc(const char* name, const char* type, const vector<IdInfo> param);
    bool existsFuncCall(const char* name, const vector<IdInfo> param);
    Function* getFunc(const char* name, const vector<IdInfo> parameters);
    int addFunc(const char* type, const char* name, vector<IdInfo> parameters);
    void printFuncs();

};