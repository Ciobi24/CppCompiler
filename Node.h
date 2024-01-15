#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

enum exprType{
    INTEGER,
    FLOAT,
    BOOL,
    CHAR,
    STRING
};

enum opType{
    ADD,
    SUB,
    MUL,
    DIV,
    LE,
    GE,
    LEQ,
    GEQ,
    NEQ,
    NOT,
    EQU,
    UMIN
};

class node{
public:
    union{int iVal; float fVal; bool bVal; char cVal; char*sVal;} val;
    opType op;
    exprType type;
    node*left;
    node*right;
    node(opType operation, node*left_node, node*right_node) : op(operation), left(left_node), right(right_node){};
    node(int value): type(INTEGER), left(nullptr), right(nullptr){
        val.iVal = value;
    };
    node(float value): type(FLOAT), left(nullptr), right(nullptr){
        val.fVal = value;
    };
    node(bool value): type(BOOL), left(nullptr), right(nullptr){
        val.iVal = value;
    };
    node(char value): type(CHAR), left(nullptr), right(nullptr){
        val.cVal = value;
    };
    node(char* value): type(STRING), left(nullptr), right(nullptr){
        val.sVal = strdup(value);
    };
    node* evaluate();
    void clean();
};