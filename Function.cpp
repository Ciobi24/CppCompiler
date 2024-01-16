#include "Function.h"

bool FunctionTable::existsFunc(const char* type, const char* name, const vector<IdInfo> parameters) {
for (const Function* f : functions) {
    if (f->type == type && f->name == name && f->param.size() == parameters.size()) {
        bool match = true;
        for (size_t i = 0; i < parameters.size(); ++i) {
            if (f->param[i].type != parameters[i].type) {
                match = false;
                break;
            } 
        }
        if (match) {
            return true;
        }
    }
}
return false;
}

 bool FunctionTable:: existsFuncCall(const char* name, const vector<IdInfo> param){
        for (const Function* f : functions) {
        if (f->param.size() == param.size()  && f->name == name) {
            for(size_t i = 0; i < param.size(); ++i){
                if(f->param[i].type != param[i].type){
                    return false;
                }
            }
            return true;
        }
        }
        return false;
 }

Function* FunctionTable::getFunc(const char* name,const vector<IdInfo> parameters) {
for (Function* f : functions) {
    if (f->name == name && f->param.size() == parameters.size()) {
        bool match = true;
        for (size_t i = 0; i < parameters.size(); ++i) {
            if (f->param[i].type != parameters[i].type) {
                match = false;
                break;
            }
        }
        if (match) {
            return f;
        }
    }
}
return nullptr;
}

int FunctionTable::addFunc(const char* type, const char* name, vector<IdInfo> parameters) {
    if (existsFunc(type, name, parameters)) {
        return -1;
    }
    Function* func = new Function;
    func->type = string(type);
    func->name = string(name);
    for (auto params: parameters) {
        func->param.push_back(params);
    } 
    functions.push_back(func);
    return 0;
}
 void FunctionTable::printFuncs(){
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::string filePath = std::string(cwd) + "/table.txt";
        std::ofstream fs(filePath, std::ios::app); // Open file in append mode
if(!fs){
cout << "[printVars]: error at opening file\n";
}
for (const Function* f : functions) {
cout<<"return type: "<<f->type<<", name: "<<f->name<<", parameters: ";
for( auto param : f->param){
    cout<<param.type<<" "<<param.name<<" scope: "<<param.scopeId<<endl;
}
cout<<endl;
fs<<endl;
fs<<"return type: "<<f->type<<", name: "<<f->name<<", parameters: ";
for( auto param : f->param){
    fs<<param.type<<" "<<param.name<<" scope: "<<param.scopeId<<endl;
}
}
fs.close();
}
else{
cout << "[printFuncs]: eroare la obținerea directorului curent\n";
}
 }