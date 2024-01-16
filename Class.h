#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include "Function.h"
using namespace std;

class Object{
 public:
string name;
string class_name; //typeul obiectului
vector<IdInfo*> fields;
vector<Function*> methods;
};

class Class{
    public:
    string name;
    vector<IdInfo*> fields;
    vector<Function*> methods;
};

class ObjectTable{
    vector<Object*> objects;
    vector<Class*> classes;
    public:
    bool existsObject(const char* name);
    bool existsClass(const char* name);
    Class* getClass(const char* name);
    Object* getObject(const char* name);
    int addObject(const char* name, const char* class_name, vector<IdInfo> fields, vector<Function> methods);
    int addClass(const char* name, vector<IdInfo> fields, vector<Function> methods);
    void printObjects();
    void printClasses();
};