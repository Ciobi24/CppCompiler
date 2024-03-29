%{
#include <iostream>
#include <vector>
#include <stack>
#include "Class.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class IdList ids;
vector<int>dimensionContainer;
IdInfo* temp = new IdInfo;
vector<IdInfo*>valueContainer;

stack<int>scopes;
int currScope = 0;
int maxScope = 0;

void incrementScope(){
     currScope=maxScope+1;
     scopes.push(currScope);
     ids.scope_path.push_back(currScope);
     maxScope = max(currScope, maxScope);
}
void decrementScope(){
     if(currScope < 0 || scopes.empty()){
          cout << "[ScopeManager]: error at decrementScope\n";
          return;
     }
     scopes.pop();
     ids.scope_path.pop_back();
     currScope=scopes.top();
}
FunctionTable functions;
vector<IdInfo>params;
int flag_func=0;

ObjectTable all_obj_class;
vector<IdInfo>fields;
vector<Function>methods;
IdInfo ret_val;
%}
%start progr
%union {
     char* string;
     char char_value;
     int integer_value;
     float float_value;
     bool bool_value;
     class node* node;
}
%token  BGIN END ASSIGN OPENBRK CLOSEDBRK IF ELSE WHILE FOR CONST EVAL TOF RETURN VOID CLASS NEW
%token<string> ID TYPE STR
%token<integer_value> NR
%token<bool_value> BOO
%token<float_value>FLT
%token<char_value>CHR
%token PLU "+"
%token MIN "-"
%token TIM "*"
%token DVD "/"
%token LT "<"
%token GT ">"
%token LET "<="
%token GET ">="
%token NOE "!="
%token NEG "!"
%token BEQ "=="
/* %type<node>expression */
%type<node>expression
%left LT GT LET GET NOE NEG BEQ
%left PLU MIN
%left TIM DVD
%right UMINUS
%%

progr: class_block var_block function_block block {printf("The programme is correct!\n");}
     | var_block function_block block {printf("The programme is correct!\n");}
     | function_block block {printf("The programme is correct!\n");}
     | block {printf("The programme is correct!\n");}
     | class_block var_block block {printf("The programme is correct!\n");}
     | class_block function_block block {printf("The programme is correct!\n");}
     | class_block block {printf("The programme is correct!\n");}
     | var_block block {printf("The programme is correct!\n");}
     ;
class_block: class_decl class_block
           | class_decl
           ;
function_block: func_decl function_block
              | func_decl
              ;
var_block: decl ';'
          | var_block decl ';'
          | objects ';'
          | var_block objects ';'
          ;
declarations :  decl ';'          
	      |  declarations decl ';' 
           |  assignation ';'
           |  declarations assignation ';' 
           |  control_statement
           |  declarations control_statement
           | call_function ';'
           | declarations call_function ';'
           | objects ';'
           |declarations objects ';'
           | obj_field ';'
           | declarations obj_field ';'
	      ;
decl       : TYPE ID ASSIGN expression{
                    if(-1 == (ids.addVar($1, $2, currScope, false, false))){
                         yyerror("[parser]: addVar error");
                         YYERROR;
                    }
                    node* res = $4->evaluate();
                    if(res == nullptr){
                         yyerror("[parser]: Error at AST::evaluate()");
                         YYERROR;
                    }

                    if(res->type == exprType::INTEGER){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt($2, res->val.iVal, currScope) == -1){
                         yyerror("[parser]: error at updateInt");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::FLOAT){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat($2, res->val.fVal, currScope) == -1){
                         yyerror("[parser]: error at updateFloat");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::BOOL){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool($2, res->val.bVal, currScope) == -1){
                         yyerror("[parser]: error at updateBool");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::CHAR){ 
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateChr($2, res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if(res->type == exprType::STRING){
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateStr($2, res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         cout << "[parser]: Unrecognized type at assignation\n";
                         YYERROR;
                    }
                    $4->clean();
                    res = nullptr;
               }

           | CONST TYPE ID ASSIGN expression{
                    if(-1 == (ids.addVar($2, $3, currScope, false, true))){
                         yyerror("[parser]: addVar error");
                         YYERROR;
                    }
                    node* res = $5->evaluate();
                    if(res == nullptr){
                         yyerror("[parser]: Error at AST::evaluate()");
                         YYERROR;
                    }

                    if(res->type == exprType::INTEGER){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt($3, res->val.iVal, currScope) == -1){
                         yyerror("[parser]: error at updateInt");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::FLOAT){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat($3, res->val.fVal, currScope) == -1){
                         yyerror("[parser]: error at updateFloat");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::BOOL){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool($3, res->val.bVal, currScope) == -1){
                         yyerror("[parser]: error at updateBool");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::CHAR){ 
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateChr($3, res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if(res->type == exprType::STRING){
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateStr($3, res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         cout << "[parser]: Unrecognized type at assignation\n";
                         YYERROR;
                    }
                    $5->clean();
                    res = nullptr;
               }
           | TYPE ID {
                    if(-1 == (ids.addVar($1,$2, currScope, false, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
               }
           | CONST TYPE ID {
                         if(-1 == (ids.addVar($2, $3, currScope, false, true))){
                              yyerror("[parser]: addVar error ");
                              YYERROR;
                         }
                    }
           | TYPE ID dimension{
                    if(-1 == (ids.addVar($1, $2, currScope, true, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
                    if(ids.setArraySize($2, dimensionContainer, currScope) == -1){
                         yyerror("[parser]: setArraySize error ");
                         YYERROR;
                    }
                    if(ids.initializeArray($2, currScope) == -1){
                         yyerror("[parser]: initializeArray error ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
                    }
           ;

assignation: ID ASSIGN expression{
                    if(all_obj_class.getObject($1)==nullptr){
                    node* res = $3->evaluate();
                    if(res == nullptr){
                         cout << "[parser]: Error assign at assignation AST::evaluate()\n";
                         YYERROR;
                    }
                    IdInfo*id = ids.getVar($1, currScope);
                    if(id == nullptr){
                         yyerror("[parser]: error at retrieving assignation id");
                         YYERROR;
                    }
                    if(id->isConst == true){
                         yyerror("[parser]: error at assignation - variable is declared as constant");
                         YYERROR;
                    }
                    if((res->type == exprType::INTEGER) && (id->type == "int")){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt($1, res->val.iVal, currScope) == -1){
                             yyerror("[parser]: error at updateInt");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::FLOAT) && (id->type == "float")){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat($1, res->val.fVal, currScope) == -1){
                             yyerror("[parser]: error at updateFloat");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::BOOL) && (id->type == "bool")){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool($1, res->val.bVal, currScope) == -1){
                             yyerror("[parser]: error at updateBool");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::CHAR) && (id->type == "char")){
                         cout << "[parser]: Updating char value\n";
                         // ids.updateChr($1, currScope, res->val.cVal);
                         if(ids.updateChr($1, res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if((res->type == exprType::STRING) && (id->type == "string")){
                         cout << "[parser]: Updating char value\n";
                         // ids.updateChr($1, currScope, res->val.cVal);
                         if(ids.updateStr($1, res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         yyerror("[ID ASSIGN EXPRESSION]: Unrecognized or incorrect type at assignation");
                         YYERROR; 
                    }
               }
               else{
                    yyerror("[parser]: Objects doesn't implement copy constructor");
                    YYERROR;
               }
               }
             /* | ID ASSIGN CHR{
                         cout << "[parser]: assignation - Updating char value\n";
                         if(ids.updateChr($1, $3, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
             | ID ASSIGN STR{
                         cout << "[parser]: assignation - Updating string value\n";
                         if(ids.updateStr($1, $3, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    } */
           | ID dimension ASSIGN array_value  {
                    if(ids.updateArrayValue($1, currScope, dimensionContainer, temp) == -1){
                         yyerror("[parser]: Error at array assignation ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
               }
          | ID ASSIGN NEW ID {
               if(all_obj_class.existsObject($1)){
                    yyerror("[parser]: Object already exists\n");
                     YYERROR;
                }
                else if(!all_obj_class.existsClass($4)){
                     yyerror("[parser]: Class does not exist\n");
                     YYERROR;
                 }
               else{
                     all_obj_class.addObject($1, $4, all_obj_class.getClass($4)->fields, all_obj_class.getClass($4)->methods);
                    }
            }
          | ID '.' ID ASSIGN expression{
               if(!all_obj_class.existsObject($1)){
                    yyerror("[parser]: Object does not exist\n");
                     YYERROR;
                }
                else {
                    bool ok=false;
                    for(auto f:all_obj_class.getObject($1)->fields){
                         if(f.name==$3){
                              ok=true;
                              node* res = $5->evaluate();
                              if(res == nullptr){
                                   yyerror("[parser]: Error at AST::evaluate()");
                                   YYERROR;
                              }
                              if(res->type == exprType::INTEGER){
                                   cout << "[parser]: Updating int value\n";
                                   all_obj_class.getObject($1)->getField($3)->value.iVal=res->val.iVal;
                              }
                              else if(res->type == exprType::FLOAT){
                                   cout << "[parser]: Updating float value\n";
                                   all_obj_class.getObject($1)->getField($3)->value.fVal=res->val.fVal;
                              }
                              else if(res->type == exprType::BOOL){
                                   cout << "[parser]: Updating bool value\n";
                                   all_obj_class.getObject($1)->getField($3)->value.bVal=res->val.bVal;
                              }
                              else if(res->type == exprType::CHAR){ 
                                   cout << "[parser]: Updating char value\n";
                                   all_obj_class.getObject($1)->getField($3)->value.cVal=res->val.cVal;
                              }
                              else if(res->type == exprType::STRING){
                                   cout << "[parser]: Updating char value\n";
                                   all_obj_class.getObject($1)->getField($3)->value.sVal=res->val.sVal;
                              }
                              else{
                                   cout << "[parser]: Unrecognized type at assignation\n";
                                   YYERROR;
                              }
                              $5->clean();
                              res = nullptr;
                              break;
                     }
                 }
                if(!ok){
                     yyerror("[parser]: Field does not exist\n");
                     YYERROR;
                }
               }
          }
           ;
func_decl : TYPE ID '(' {incrementScope(); flag_func=1;} list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK {
     if (!functions.existsFunc($2, $1, params)) {
          if (ret_val.type != $1) {
               cout << "[parser]: Return type mismatch\n";
               YYERROR;
          } else {
               functions.addFunc($1, $2, params);
          }
     } else {
          cout << "[parser]: Function already exists\n";
          YYERROR;
     }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";

}
|  TYPE ID '(' ')' OPENBRK {incrementScope();flag_func=1;} f_declarations RETURN ret ';' CLOSEDBRK {             
     if (!functions.existsFunc($2, $1, params)) {
          if(ret_val.name == "error"){
               yyerror("[parser]: return var not found\n");
               YYERROR;
          }
          else if (ret_val.type != $1) {
               yyerror("[parser]: Return type mismatch\n");
               YYERROR;
          } else {
               functions.addFunc($1, $2, params);
          }
     } else {
          cout << "[parser]: Function already exists\n";
          YYERROR;
     }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";
     }
| VOID ID '(' {incrementScope();flag_func=1;} list_param ')' OPENBRK f_declarations {decrementScope();}CLOSEDBRK {
       
     if (!functions.existsFunc($2, "void", params)) {
          functions.addFunc("void", $2, params);
          }
          else{
               cout<< "[parser]: Function already exists\n";
               YYERROR;
          }
          params.clear();
          flag_func=0;
     }       
|VOID ID '(' ')' OPENBRK {incrementScope();flag_func=1;} f_declarations {decrementScope();} CLOSEDBRK {
          if (!functions.existsFunc($2, "void", params)) {
               functions.addFunc("void", $2, params);
          }
          else{
               cout<< "[parser]: Function already exists\n";
               YYERROR;
          }
          flag_func=0;
          params.clear();
          
     }
;
ret: ID {if(ids.getVar($1, currScope)!=nullptr){ret_val.type = ids.getVar($1, currScope)->type; ret_val.name = $1; ret_val.scopeId = currScope;}else{ret_val.name="error";yyerror("[parser]: Error id not found"); YYERROR;}}
     | NR {ret_val.type = "int"; ret_val.value.iVal = $1;}
     | FLT {ret_val.type = "float"; ret_val.value.fVal = $1;}
     | BOO {ret_val.type = "bool"; ret_val.value.bVal = $1;}
     | CHR {ret_val.type = "char"; ret_val.value.cVal = $1;}
     | STR {ret_val.type = "string"; ret_val.value.sVal = strdup($1);}
     ;
f_declarations: decl ';'          
	      |  f_declarations decl ';' 
           |  assignation ';'
           |  f_declarations assignation ';' 
           |  control_statement
           |  f_declarations control_statement
           | call_function ';'
           | f_declarations call_function ';'
           | objects ';'
           | f_declarations objects ';'
           | obj_field ';'
           | f_declarations obj_field ';'
	      ;

control_statement : condition_statement
                  | while_statement
                  | for_statement
                  ;

condition_statement : if_statement
                    | if_statement else_statement
                    ;


if_statement: IF '(' expression ')' OPENBRK{incrementScope();} declarations CLOSEDBRK{decrementScope();} {
                         node* res = $3->evaluate();
                         cout << "[if expr] : if working yay\n";
                         if(res == nullptr){
                              cout << "[parser]: Error at if statement condition evaluate\n";
                              YYERROR;
                         }

                         if(res->type != exprType::BOOL){
                              yyerror("[if expr]: condition does not have bool type ");
                              YYERROR;
                         }
                    }
                    ;
else_statement : ELSE OPENBRK{incrementScope();} declarations CLOSEDBRK{decrementScope();} {
                         cout << "[else expr] : else working yay\n";
                    }
               | ELSE{cout << "[if else expr] : if else working yay\n";} condition_statement
                    ;

while_statement : WHILE '(' expression ')' OPENBRK{incrementScope();} declarations CLOSEDBRK{decrementScope();} {
                    node* res = $3->evaluate();
                    cout << "[while expr] : while working yay\n";
                    if(res == nullptr){
                         cout << "[parser]: Error at while statement condition evaluate\n";
                         YYERROR;
                    }

                    if(res->type != exprType::BOOL){
                         yyerror("[while expr]: condition does not have bool type\n");
                         YYERROR;
                    }
                }
                ;

for_statement : FOR{incrementScope();} '(' for_init ';'  expression ';' for_step ')' OPENBRK declarations CLOSEDBRK{decrementScope();} {
                    node* res = $6->evaluate();
                    cout << "[for expr] : for working yay\n";
                    if(res == nullptr){
                         cout << "[parser]: Error at for statement condition evaluate\n";
                         YYERROR;
                    }
                    
                    if(res->type != exprType::BOOL){
                         yyerror("[for expr]: condition does not have bool type\n");
                         YYERROR;
                    }
               }
              ;

for_init : decl
         |
         ;

for_step : assignation
         | 
         ;

expression: expression "+" expression{
                    $$ = new node(opType::ADD, $1, $3);
               }
               | expression "-" expression{
                    $$ = new node(opType::SUB, $1, $3);
                    }
               | expression "*" expression{
                    $$ = new node(opType::MUL, $1, $3);
               }
               | expression "/" expression{
                    $$ = new node(opType::DIV, $1, $3);
               }
               | expression "<" expression{
                    $$ = new node(opType::LE, $1, $3);
               }
               | expression ">" expression{
                    $$ = new node(opType::GE, $1, $3);
               }  
               | expression "<=" expression{
                    $$ = new node(opType::LEQ, $1, $3);
               }
               | expression ">=" expression{
                    $$ = new node(opType::GEQ, $1, $3);
               }
               | expression "==" expression{
                    $$ = new node(opType::EQU, $1, $3);
               }
               | expression "!=" expression{
                    $$ = new node(opType::NEQ, $1, $3);
               }
               | "!" expression{
                    $$ = new node(opType::NOT, $2, nullptr);
               }
               | '(' expression ')'{
                    $$ = $2;
               }
               | MIN expression %prec UMINUS{
                    $$ = new node(opType::UMIN, $2, nullptr);
               }
               | NR{
                    $$ = new node($1);    
               }
               | FLT{     
                    $$ = new node($1);
               }
               | BOO{     
                    $$ = new node($1);
               }
               | CHR{     
                    $$ = new node($1);
               }
               | STR{     
                    $$ = new node($1);
               }
               | ID{
                    if(all_obj_class.getObject($1)==nullptr){
                    IdInfo*id = ids.getVar($1, currScope);
                    if(id == nullptr){
                         yyerror("[parser]: Error at getVar - id not found");
                         YYERROR;
                    }
                    if(id->type == string("int")){
                         cout << "[parser]: Found int variable in expr - generating node\n";

                         if(flag_func==0){
                              $$ = new node(id->value.iVal); 
                         }else{
                              int node_val = 0;
                              $$ = new node(node_val);
                         }

                    }else if(id->type == string("float")){
                         cout << "[parser]: Found float variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.fVal);
                         }else{
                              float node_val = 0;
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("bool")){
                         cout << "[parser]: Found bool variable in expr - generating node\n";
                        
                         if(flag_func==0){
                              $$ = new node(id->value.bVal);
                         }else{
                              bool node_val = false;
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("char")){
                         cout << "[parser]: Found char variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.cVal);
                         }else{
                              char node_val = '\0';
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("string")){
                         cout << "[parser]: Found string variable in expr - generating node\n";
                        
                         if(flag_func==0){
                              $$ = new node(id->value.sVal);
                         }else{
                              char* node_val = NULL;
                              $$ = new node(node_val);
                         }
                    }
                    else{
                         cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << $1 << endl;
                    }
               }else{
                    yyerror("[parser]: Objects doesn't implement copy constructor");
                    YYERROR;
               }
               }
               | ID '.' ID {
                    if(!all_obj_class.existsObject($1)){
                          yyerror("[parser]: Object does not exist\n");
                          YYERROR;
                     }
                     else {
                         Object* obj = all_obj_class.getObject($1);
                         bool ok=false;
                         for(auto f: obj->fields){
                              if(f.name==$3){
                                   ok=true;
                                   if(f.type == string("int")){
                                    cout << "[parser]: Found int variable in expr - generating node\n";
                              
                                              if(flag_func==0){
                                                    $$ = new node(f.value.iVal);
                                              }else{
                                                    int node_val = 0;
                                                    $$ = new node(node_val);
                                              }
                                   }
                                   if(f.type == string("float")){
                                        cout << "[parser]: Found float variable in expr - generating node\n";
                                   
                                                  if(flag_func==0){
                                                       $$ = new node(f.value.fVal);
                                                  }else{
                                                       float node_val = 0;
                                                       $$ = new node(node_val);
                                                  }
                                   }
                                   if(f.type == string("bool")){
                                        cout << "[parser]: Found bool variable in expr - generating node\n";
                                   
                                                  if(flag_func==0){
                                                       $$ = new node(f.value.bVal);
                                                  }else{
                                                       bool node_val = false;
                                                       $$ = new node(node_val);
                                                  }
                                   }
                                   if(f.type==string("char")){
                                        cout << "[parser]: Found char variable in expr - generating node\n";
                                   
                                                  if(flag_func==0){
                                                       $$ = new node(f.value.cVal);
                                                  }else{
                                                       char node_val = '\0';
                                                       $$ = new node(node_val);
                                                  }
                                   }
                                   if(f.type == string("string")){
                                        cout << "[parser]: Found string variable in expr - generating node\n";
                                   
                                                  if(flag_func==0){
                                                       $$ = new node(f.value.sVal);
                                                  }else{
                                                       char* node_val = NULL;
                                                       $$ = new node(node_val);
                                                  }
                                   }
                                    break;
                               }      
                         }
                         if(!ok){
                              yyerror("[parser]: Field does not exist\n");
                              YYERROR;
                              }
                     }
               }
               | ID '.' ID '(' call_list ')'{
                    if(!all_obj_class.existsObject($1)){
                          yyerror("[parser]: Object does not exist\n");
                          YYERROR;
                     }
                     else {
                           bool ok=false;
                           std::vector<Function> methods = all_obj_class.getObject($1)->methods;
                           for(auto &m : methods)
                              {
                              if(m.name == $3){
                                      ok=true;  
                                    if(m.param.size() != params.size()){
                                          yyerror("[parser]: Wrong number of parameters\n");
                                         YYERROR;
                                          }
                                   else{
                                                for(int i=0;i<m.param.size();i++){
                                                        if(m.param[i].type != params[i].type){
                                                                yyerror("[parser]: Wrong parameter type\n");
                                                               YYERROR;
                                                               }
                                                        }
                                               }
                                   if(m.type == string("int")){
                                         cout << "[parser]: expr functions has type int\n";
                                         int node_val = 0;
                                         $$ = new node(node_val);
                                   }
                                   else if(m.type == string("float")){
                                         cout << "[parser]: expr functions has type float\n";
                                        float node_val = 0;
                                        $$ = new node(node_val);
                                    }
                                    else if(m.type == string("bool")){
                                          cout << "[parser]: expr functions has type bool\n";
                                         bool node_val = false;
                                         $$ = new node(node_val);
                                    }else{
                                         yyerror("[parser]: prohibited function value used in expression\n");
                                        YYERROR;
                                    }
                                          break;
                                  }
                               }
                          if(!ok){
                               yyerror("[parser]: Method does not exist\n");
                               YYERROR;
                           } 
                     }
                 params.clear();
               }
               | ID '.' ID '(' ')'{
                    if(!all_obj_class.existsObject($1)){
                          yyerror("[parser]: Object does not exist\n");
                          YYERROR;
                     }
                     else {
                         bool ok=false;
                       for(auto m:all_obj_class.getObject($1)->methods){
                              if(m.name == $3){
                                 ok=true;
                                if(m.param.size() != params.size()){
                                      yyerror("[parser]: Wrong number of parameters\n");
                                     YYERROR;
                                }
                                if(m.type == string("int")){
                                         cout << "[parser]: expr functions has type int\n";
                                         int node_val = 0;
                                         $$ = new node(node_val);
                                   }
                                   else if(m.type == string("float")){
                                         cout << "[parser]: expr functions has type float\n";
                                        float node_val = 0;
                                        $$ = new node(node_val);
                                    }
                                    else if(m.type == string("bool")){
                                          cout << "[parser]: expr functions has type bool\n";
                                         bool node_val = false;
                                         $$ = new node(node_val);
                                    }else{
                                         yyerror("[parser]: prohibited function value used in expression\n");
                                        YYERROR;
                                    }
                                    break;
                               }
                           }
                          if(!ok){
                               yyerror("[parser]: Method does not exist\n");
                               YYERROR;
                          } 
                    }
                    params.clear();
               }
               | ID '[' NR ']' {
                         IdInfo*id = ids.getUArrElemByIndex($1, currScope, $3);
                         if(id == nullptr){
                              yyerror("[parser]: Error at getUArrElemByIndex - element not found");
                              YYERROR;
                         }
                         //dimensionContainer.clear();
                         if(id->type == string("int")){
                              cout << "[parser]: Found int variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   $$ = new node(id->value.iVal);
                              }else{
                                   int node_val = 0;
                                   $$ = new node(node_val);
                              }
                         }else if(id->type == string("float")){
                              cout << "[parser]: Found float variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   $$ = new node(id->value.fVal);
                              }else{
                                   float node_val = 0;
                                   $$ = new node(node_val);
                              }
                         }
                         else if(id->type == string("bool")){
                              cout << "[parser]: Found bool variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   $$ = new node(id->value.bVal);
                              }else{
                                   bool node_val = false;
                                   $$ = new node(node_val);
                              }
                         }
                         else if(id->type == string("char")){
                              cout << "[parser]: Found char variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   $$ = new node(id->value.cVal);
                              }else{
                                   char node_val = '\0';
                                   $$ = new node(node_val);
                              }
                         }
                         else if(id->type == string("string")){
                              cout << "[parser]: Found string variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   $$ = new node(id->value.sVal);
                              }else{
                                   char* node_val = NULL;
                                   $$ = new node(node_val);
                              }

                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << $1 << endl;
                              YYERROR;
                         }
                    }
               | ID '[' NR ']' '[' NR ']'{
                    IdInfo*id = ids.getMArrElemByIndex($1, currScope, $3, $6);
                    if(id == nullptr){
                         yyerror("[parser]: Error at getMArrElemByIndex - element not found");
                         YYERROR;
                    }
                    //dimensionContainer.clear();
                    if(id->type == string("int")){
                         cout << "[parser]: Found int variable in expr - generating node\n";
                              
                         if(flag_func==0){
                              $$ = new node(id->value.iVal);
                         }else{
                              int node_val = 0;
                              $$ = new node(node_val);
                         }
                    }else if(id->type == string("float")){
                         cout << "[parser]: Found float variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.fVal);
                         }else{
                              float node_val = 0;
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("bool")){
                         cout << "[parser]: Found bool variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.bVal);
                         }else{
                              bool node_val = false;
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("char")){
                         cout << "[parser]: Found char variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.cVal);
                         }else{
                              char node_val = '\0';
                              $$ = new node(node_val);
                         }
                    }
                    else if(id->type == string("string")){
                         cout << "[parser]: Found string variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              $$ = new node(id->value.sVal);
                         }else{
                              char* node_val = NULL;
                              $$ = new node(node_val);
                         }
                    }
                    else{
                         cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << $1 << endl;
                         YYERROR;
                    }
               }
               |ID '(' call_list ')' {
                         if(!functions.existsFuncCall($1, params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         Function* func = new Function;
                         func = functions.getFunc($1, params);
                         if(func == nullptr){
                              yyerror("[parser]: Error at getFunc - function not found in function table\n");
                              YYERROR;
                         }
                         if(func->type == string("int")){
                              cout << "[parser]: expr functions has type int\n";
                              int node_val = 0;
                              $$ = new node(node_val);
                         }
                         else if(func->type == string("float")){
                              cout << "[parser]: expr functions has type float\n";
                              float node_val = 0;
                              $$ = new node(node_val);
                         }
                         else if(func->type == string("bool")){
                              cout << "[parser]: expr functions has type bool\n";
                              bool node_val = false;
                              $$ = new node(node_val);
                         }else{
                              yyerror("[parser]: prohibited function value used in expression\n");
                              YYERROR;
                         }
                         //free aici?
                         params.clear();
                         }
                | ID '(' ')' {
                         if(!functions.existsFuncCall($1, params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         Function* func = new Function;
                         func = functions.getFunc($1, params);
                         if(func == nullptr){
                              yyerror("[parser]: Error at getFunc - function not found in function table\n");
                              YYERROR;
                         }
                         if(func->type == string("int")){
                              cout << "[parser]: expr functions has type int\n";
                              int node_val = 0;
                              $$ = new node(node_val);
                         }
                         else if(func->type == string("float")){
                              cout << "[parser]: expr functions has type float\n";
                              float node_val = 0;
                              $$ = new node(node_val);
                         }
                         else if(func->type == string("bool")){
                              cout << "[parser]: expr functions has type bool\n";
                              bool node_val = false;
                              $$ = new node(node_val);
                         }else{
                              yyerror("[parser]: prohibited function value used in expression\n");
                              YYERROR;
                         }
                         params.clear();
                         }
               ;

dimension  : '[' NR ']' dimension{
                    dimensionContainer.push_back($2);
                    }
           | '[' NR ']'{
                    dimensionContainer.push_back($2);
                    }
           ;

array_value : expression{
          cout << "[parser]: Arr val is expr\n";
          node* res = $1->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at array_value evaluate ");
               YYERROR;
          }

          if(res->type == exprType::INTEGER){
               cout << "[parser]: Updating array int value " << res->val.iVal << endl;
               temp -> type = string("int");
               temp -> name = string("");
               temp -> value.iVal = res->val.iVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::FLOAT){
               cout << "[parser]: Updating float value\n";
               temp -> type = string("float");
               temp -> name = string("");
               temp -> value.fVal = res->val.fVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::BOOL){
               cout << "[parser]: Updating bool value\n";
               temp -> type = string("bool");
               temp -> name = string("");
               temp -> value.bVal = res->val.bVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::CHAR){
               cout << "[parser]: Updating char value\n";
               temp -> type = string("char");
               temp -> name = string("");
               temp -> value.cVal = res->val.cVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::STRING){
               cout << "[parser]: Updating string value\n";
               temp -> type = string("string");
               temp -> name = string("");
               temp -> value.sVal = strdup(res->val.sVal); //strdup? this may cause issues
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else{
               cout << "[parser]: Unrecognized type at assignation\n";
               YYERROR; //define
          }
          $1->clean();
          res = nullptr;
          
          }
      /* | STR{
          cout << "[parser]: Arr val is str\n";
          cout << "[parser]: Updating array string value \n";
          temp -> type = string("string");
          temp -> name = string("");
          temp -> value.sVal = strdup($1);
          temp -> isArr = false;
          temp -> scopeId = currScope;
          }
       | CHR{
          cout << "[parser]: Arr val is char\n";
          cout << "[parser]: Updating array char value \n";
          temp -> type = string("char");
          temp -> name = string("");
          temp -> value.cVal = $1;
          temp -> isArr = false;
          temp -> scopeId = currScope;
          } */
      ;

list_param: param 
            | param ',' list_param
            ;
            
param: TYPE ID { ids.addVar($1,$2,currScope,false,false); IdInfo arg; arg.type=string($1); arg.name=string($2); arg.scopeId=currScope; params.push_back(arg);}
      ; 


block : BGIN list END  
     | BGIN END
     ;
     

list :  statement  
     | list statement 
     ;

statement: decl ';'
         | assignation ';'
         | call_function ';'
         | control_statement
         | eval_stmt ';'
         | typeOf_stmt ';'
         | objects ';'
         | obj_field ';'
         ;
call_function:  ID '(' call_list ')' {if(!functions.existsFuncCall($1, params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
                | ID '(' ')' {if(!functions.existsFuncCall($1, params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
                ;
eval_stmt : EVAL '(' expression ')' {
     if(flag_func==0){   
          node* res = $3->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at Eval AST::evaluate()");
               YYERROR;
          }
          switch(res->type){
               case exprType::INTEGER:{
                    cout << "[Eval]: expression has type INTEGER and value " << res->val.iVal << endl;
                    break;
               }
               case exprType::FLOAT:{
                    cout << "[Eval]: expression has type FLOAT and value " << res->val.fVal << endl;
                    break;
               }
               case exprType::BOOL:{
                    cout << "[Eval]: expression has type BOOL and value " << boolalpha << res->val.bVal << noboolalpha << endl;
                    break;
               }
               case exprType::CHAR:{
                    cout << "[Eval]: expression has type CHAR and value " << res->val.cVal << endl;
                    break;
               }
               case exprType::STRING:{
                    cout << "[Eval]: expression has type STRING and value " << res->val.sVal << endl;
                    break;
               }
          }
     }
}
typeOf_stmt: TOF '(' expression ')'{
     if(flag_func==0){
          node* res = $3->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at TypeOf AST::evaluate()");
               YYERROR;
          }
          switch(res->type){
               case exprType::INTEGER:{
                    cout << "[typeOF]: expression has type INTEGER\n";
                    break;
               }
               case exprType::FLOAT:{
                    cout << "[typeOF]: expression has type FLOAT\n";
                    break;
               }
               case exprType::BOOL:{
                    cout << "[typeOF]: expression has type BOOL\n";
                    break;
               }
               case exprType::CHAR:{
                    cout << "[typeOF]: expression has type CHAR\n";
                    break;
               }
               case exprType::STRING:{
                    cout << "[typeOF]: expression has type STRING\n";
                    break;
               }
          }
     }
}
call_list : NR {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=$1; arg.scopeId=currScope; params.push_back(arg);}
           | call_list ',' NR {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=$3; arg.scopeId=currScope; params.push_back(arg);}
           | FLT {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=$1; arg.scopeId=currScope; params.push_back(arg);}
           | call_list ',' FLT {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=$3; arg.scopeId=currScope; params.push_back(arg);}
           | BOO {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=$1; arg.scopeId=currScope; params.push_back(arg);}
           | call_list ',' BOO {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=$3; arg.scopeId=currScope; params.push_back(arg);}
           | CHR {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=$1; arg.scopeId=currScope; params.push_back(arg);}
           | call_list ',' CHR {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=$3; arg.scopeId=currScope; params.push_back(arg);}
           | STR {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup($1); arg.scopeId=currScope; params.push_back(arg);}
           | call_list ',' STR {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup($3); arg.scopeId=currScope; params.push_back(arg);}
           | ID {IdInfo*id = ids.getVar($1, currScope);
                         if(id == nullptr){
                              yyerror("[parser]: Error at getVar - id not found");
                              YYERROR;
                         }
                         if(id->type == string("int")){
                              IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=id->value.iVal; arg.scopeId=currScope; params.push_back(arg);
                         }else if(id->type == string("float")){
                              IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=id->value.fVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("bool")){
                              IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=id->value.bVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("char")){
                              IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=id->value.cVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("string")){
                              IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup(id->value.sVal); arg.scopeId=currScope; params.push_back(arg);
                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN CALL LIST FOR " << $1 << endl;
                              YYERROR;
                         }
               }
          | call_list ',' ID {IdInfo*id = ids.getVar($3, currScope);
                         if(id == nullptr){
                              yyerror("[parser]: Error at getVar - id not found");
                              YYERROR;
                         }
                         if(id->type == string("int")){
                              IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=id->value.iVal; arg.scopeId=currScope; params.push_back(arg);
                         }else if(id->type == string("float")){
                              IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=id->value.fVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("bool")){
                              IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=id->value.bVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("char")){
                              IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=id->value.cVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("string")){
                              IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup(id->value.sVal); arg.scopeId=currScope; params.push_back(arg);
                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN CALL LIST FOR " << $3 << endl;
                              YYERROR;
                         }}
           ;
class_decl : CLASS ID OPENBRK in_class_decl CLOSEDBRK ';' {
               if(!all_obj_class.existsClass($2)){
                    all_obj_class.addClass($2, fields, methods );
               }
               else{
                    yyerror("[parser]: Class already exists\n");
                    YYERROR;
               }
               fields.clear();
               methods.clear();
               
     }
              | CLASS ID OPENBRK in_class_decl CLOSEDBRK{
                     if(!all_obj_class.existsClass($2)){
                    all_obj_class.addClass($2,fields,methods );
               }
               else{
                    yyerror("[parser]: Class already exists\n");
                    YYERROR;
               }
               fields.clear();
               methods.clear();
               
     }
               ;
in_class_decl: var_class_decl ';'
               |in_class_decl var_class_decl ';'
               ;

var_class_decl: TYPE ID {
                    bool ok=true;
                  for(auto f:fields){
                       if(f.name == $2){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                  }
                  if(ok){
                       IdInfo field;
                       field.type=strdup($1);
                       field.name=strdup($2);
                       field.isArr=false;
                       field.isConst=false;
                       field.scopeId=currScope;
                       fields.push_back(field);
                  }
               }
           | CONST TYPE ID {
                   bool ok=true;
                  for(auto f:fields){
                       if(f.name == $2){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                  }
                  if(ok){
                       IdInfo field;
                       field.type=strdup($2);
                       field.name=strdup($3);
                       field.isArr=false;
                       field.isConst=true;
                       field.scopeId=currScope;
                       fields.push_back(field);
                  }
                    }
           | TYPE ID dimension{
                    bool ok=true;for(auto f:fields){
                       if(f.name == $2){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                    }
                    if(ok){
                         IdInfo field;
                         field.type=strdup($1);
                         field.name=strdup($2);
                         field.isArr=true;
                         field.isConst=false;
                         field.scopeId=currScope;
                         reverse(dimensionContainer.begin(), dimensionContainer.end());
                         field.dimensions=dimensionContainer;
                         fields.push_back(field);

                    }                        
                     dimensionContainer.clear();
               }
          | objects
          | methods
               ;
   
objects: NEW ID ID {
     if(all_obj_class.existsObject($3)){
          yyerror("[parser]: Object already exists\n");
          YYERROR;
     }
     else if(!all_obj_class.existsClass($2)){
          yyerror("[parser]: Class does not exist\n");
          YYERROR;
     }
     else{
          all_obj_class.addObject($3, $2, all_obj_class.getClass($2)->fields, all_obj_class.getClass($2)->methods);
     }
}
methods: TYPE ID '(' {incrementScope(); flag_func=1;} list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK {
             bool ok=true;
          for(auto m: methods){
               if($2 == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string($1);
               m.name=string($2);
               m.param=params;
               methods.push_back(m);
          }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";

}
|  TYPE ID '(' ')' OPENBRK {incrementScope();flag_func=1;} f_declarations RETURN ret ';' CLOSEDBRK {             
              bool ok=true;
          for(auto m: methods){
               if($2 == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string($1);
               m.name=string($2);
               m.param=params;
               methods.push_back(m);
          }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";
     }
| VOID ID '(' {incrementScope();flag_func=1;} list_param ')' OPENBRK f_declarations {decrementScope();}CLOSEDBRK {
       
              bool ok=true;
          for(auto m: methods){
               if($2 == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string("void");
               m.name=string($2);
               m.param=params;
               methods.push_back(m);
          }
          params.clear();
          flag_func=0;
     }       
|VOID ID '(' ')' OPENBRK {incrementScope();flag_func=1;} f_declarations {decrementScope();} CLOSEDBRK {
         bool ok=true;
          for(auto m: methods){
               if($2 == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string("void");
               m.name=string($2);
               m.param=params;
               methods.push_back(m);
          }
          flag_func=0;
          params.clear();
          
     }
;
obj_field: ID '.' ID {
     if(!all_obj_class.existsObject($1)){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto f:all_obj_class.getObject($1)->fields){
               if(f.name == $3){
                    ok=true;
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Field does not exist\n");
          YYERROR;
          }    
     }
}
| ID '.' ID '(' call_list ')' {
     if(!all_obj_class.existsObject($1)){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto m:all_obj_class.getObject($1)->methods){
               if(m.name == $3){
                    ok=true;  
                    if(m.param.size() != params.size()){
                         yyerror("[parser]: Wrong number of parameters\n");
                         YYERROR;
                    }
                    else{
                         for(int i=0;i<m.param.size();i++){
                              if(m.param[i].type != params[i].type){
                                   yyerror("[parser]: Wrong parameter type\n");
                                   YYERROR;
                              }
                         }
                    }
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Method does not exist\n");
          YYERROR;
          } 
     }
     params.clear();
}
| ID '.' ID '(' ')'{
     if(!all_obj_class.existsObject($1)){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto m:all_obj_class.getObject($1)->methods){
               if(m.name == $3){
                    ok=true;
                    if(m.param.size() != params.size()){
                         yyerror("[parser]: Wrong number of parameters\n");
                         YYERROR;
                    }
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Method does not exist\n");
          YYERROR;
          } 
     }
     params.clear();
}
;
%%
void yyerror(const char * s){
printf("-ERROR-: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     scopes.push(currScope);
     ids.scope_path.push_back(currScope);
     ids.log_flag = atoi(argv[2]);
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << endl<<endl<<"Variables:" <<endl;
     ids.printVars();
     cout<<endl<<endl<<"Functions:"<<endl;
     functions.printFuncs();
     cout<<endl<<endl<<"Classes:"<<endl;
     all_obj_class.printClasses();
     cout<<endl<<endl<<"Objects:";
     all_obj_class.printObjects();    
     delete temp;
} 