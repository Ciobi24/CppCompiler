#include "IdList.h"
using namespace std;

int IdList::addVar(const char *vtype, const char *vname, int scopeId, bool visArr, bool constness)
{
    if(alreadyDeclared(vname, scopeId)){
        log("[addVar]: variable with this name has already been declared in current scope\n");
        return -1;
    }
    IdInfo*var = new struct IdInfo;
    var->type = string(vtype);
    var->name = string(vname);
    var->scopeId = scopeId;
    var->isArr = visArr;
    var->isConst = constness;

    // IdInfo var = {string(type), string(name), scopeId, isArr};
    if(this->log_flag){
        cout << "addVar: Created variable " << var->name << " with scopeId " << var->scopeId << " and arr_flag " << var->isArr << endl;
    }
    vars.push_back(var);
    return 0;
}

bool IdList::existsVar(const char* var) { //add scope checking
    string strvar = string(var);
    for (const IdInfo* v : vars) {
        if (strvar == v->name) { 
            return true;
        }
    }
    return false;
}

IdInfo *IdList::getVar(const char *name, int scope)
{
    string strvar = string(name);
    // if(this->log_flag){
    //     cout << "[getVar]: path array for " << name << " is ";
    //     for(auto& elem : this->scope_path){
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }
    IdInfo*res = nullptr;
    for(auto scope_elem = (this->scope_path).rbegin(); scope_elem != (this->scope_path).rend(); scope_elem++){
        // if(this->log_flag){
        //     cout << "[getVar]: searching in scope " << *scope_elem << endl;
        // }
        for (IdInfo* v : vars) {
            if (strvar == v->name && v->scopeId == *scope_elem) { 
                // if(this->log_flag){
                //     cout << "[getVar]: found variable in scope " << *scope_elem << endl;
                // }
                return v;
            }
        }
    }
    
    return res;
}

IdInfo *IdList::getArray(const char *name, int scope)
{
    string strvar = string(name);
    int matched_scope = -1;
    IdInfo*res = nullptr;
    for (IdInfo* v : vars) {
        if (strvar == v->name && v->isArr == true) { 
            if(v->scopeId == scope){
                return v;
            }
            if(v->scopeId > matched_scope && v->scopeId < scope){
                matched_scope = v->scopeId;
                res = v;
            }
        }
    }
    return res;
}

bool IdList::checkType(const char *name1, const char *name2, int scope1, int scope2)
{
    IdInfo* v1;
    IdInfo* v2;
    v1 = getVar(name1, scope1);
    v2 = getVar(name2, scope2);
    if(v1 == nullptr || v2 == nullptr){
        log("[checkType]: variable not found in symbol table\n");
    }
    if(v1->type == v2->type){
        log("[checkType]: assignation is possible\n");
        return true;
    }
    log("[checkType]: assignation is impossible\n");
    return false;
}

bool IdList::alreadyDeclared(const char *name, int scope)
{
    string strvar = string(name);
    for (const IdInfo* v : vars) {
        if (strvar == v->name && scope == v->scopeId) { 
            return true;
        }
    }
    return false;
}

void IdList::printVars() {
     char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != nullptr) {
std::string filePath = std::string(cwd) + "/table.txt";
// std::string filePath=string("table.txt");
ofstream fs(filePath); 
    if(!fs){
        log("[printVars]: error at opening file\n");
    }
    fs<<endl<<"Variables: "<<endl;
    for (const IdInfo* v : vars) {
        if(!v->isArr){
            cout << "name: " << v->name << ", type: " << v->type << ", scope: " << v->scopeId << ", value: ";
            fs << "name: " << v->name << ", type: " << v->type << ", scope: " << v->scopeId << ", value: ";  
            if(v->type == "int"){
                cout << v->value.iVal << endl;
                fs << v->value.iVal << endl;
            }else if(v->type == "float"){
                cout << v->value.fVal << endl;
                fs << fixed << setprecision(6) << v->value.fVal << endl;
            }else if(v->type == "bool"){
                cout << boolalpha << v->value.bVal << noboolalpha << endl;
                fs << boolalpha << v->value.bVal << noboolalpha << endl;
            }else if(v->type == "char"){
                if(v->value.cVal == '\0'){
                    cout << "_ " << endl;
                    fs << "_ " << endl;
                }
                else{
                    cout << v->value.cVal << "\n";
                    fs << v->value.cVal << "\n";
                }
            }else if(v->type == "string"){
                if(v->value.sVal == NULL){
                    cout << "_ " << endl;
                    fs << "_ " << endl;
                }
                else{
                    cout << v->value.sVal << endl;
                    fs << v->value.sVal << endl;
                }
            }
        }
        else{
            cout << "name: " << v->name << ", type: " << v->type << ", scope: " << v->scopeId;
            cout << endl << "dimensions: "; 
            fs << "name: " << v->name << ", type: " << v->type << ", scope: " << v->scopeId;
            fs << endl << "dimensions: "; 
            for(auto elem : v->dimensions){
                    cout << elem << " ";
                    fs << elem << " ";
            }
            fs << endl << "values: ";
            cout << endl << "values: ";
            for(auto elem : v->arrVal){
                if(v->type == "int"){
                    cout << elem->value.iVal << " ";
                    fs << elem->value.iVal << " ";
                }else if(v->type == "float"){
                    cout << elem->value.fVal << " ";
                    fs << fixed << setprecision(6) << elem->value.fVal << " ";
                }else if(v->type == "bool"){
                    cout << boolalpha << elem->value.bVal << noboolalpha << " ";
                    fs << boolalpha << elem->value.bVal << noboolalpha << " ";
                }else if(v->type == "char"){
                    if(elem->value.cVal == '\0'){
                        cout << "_ ";
                        fs << "_ ";
                }
                else{
                    cout << elem->value.cVal << " ";
                    fs << elem->value.cVal << " ";
                }
                }else if(v->type == "string"){
                    if(elem->value.sVal == NULL){
                        cout << "_ ";
                        fs << "_ ";
                    }
                    else{
                        cout << elem->value.sVal << " ";
                        fs << elem->value.sVal << " ";
                    }
                }
            }
            cout << endl;
            fs << endl;
        }
    }
    fs.close();
}
else {
    perror("getcwd() error");
}
}

IdInfo *IdList::getUArrElemByIndex(const char *name, int scope, int index)
{
    IdInfo* v = getVar(name, scope);
    if(!v->isArr){
        log("[getUArrElemByIndex]: var isn't of array type\n");
        return nullptr;
    }
    if(v->dimensions.size() > 1){
        log("[getUArrElemByIndex]: var isn't unidimensional array\n");
        return nullptr;
    }
    return v->arrVal[index];
}

IdInfo *IdList::getMArrElemByIndex(const char *name, int scope, int index1, int index2)
{
    IdInfo* v = getVar(name, scope);
    if(!v->isArr){
        log("[getUArrElemByIndex]: var isn't of array type\n");
        return nullptr;
    }
    if(v->dimensions.size() != 2){
        log("[getUArrElemByIndex]: var isn't bidimensional array\n");
        return nullptr;
    }
    int index = index1 * v->dimensions[1] + index2;
    return v->arrVal[index];
}

int IdList::updateValue(const char *name, int integerValue, float floatValue, char charValue, bool boolValue)
{
    if(!existsVar(name)){
        cout << name << "Error at updateValue: var has not been declared" << endl;
        return -1;
    }
    string strvar = string(name);
    for (IdInfo* v : vars) {
        if (strvar == v->name) { 
            if(v->type == string("int")){
                v->value.iVal = integerValue;
                cout << "updateValue: int value " << v->value.iVal << " updated for variable " << v->name<<endl;
            }
        }
    }
    return 0;
}

int IdList::setArraySize(const char *name, vector<int>dimensions, int scope)
{
    IdInfo*v = getArray(name, scope);
    if(v == nullptr){
        log("[setArraySize]: error at retrieving array\n");
        return -1;
    }
    reverse(dimensions.begin(), dimensions.end());
    v->dimensions = dimensions;
    if(this->log_flag){
        cout << "setArraySize: added dimensions to " << v->name << ":\n";
        for(auto elem : v->dimensions){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}

int IdList::initializeArray(const char *name, int scope)
{
    IdInfo*arr = getArray(name, scope);
    if(arr == nullptr){
        log("[initializeArray]: error at retrieving array\n");
        return -1;
    }
    int dim = 1;

    for(auto i : arr->dimensions){
        dim*=i;
    }
    // cout << "[arrInitialize]: dim is " << dim << endl;

    for(int i = 0; i < dim; ++i){
        IdInfo*init = new IdInfo;
        init->type = arr->type;
        init->name = string("");
        init->isArr=false;
        if(arr->type == "int"){
            init->value.iVal = 0;
        }else if(arr->type == "float"){
            init->value.fVal = 0.0;
        }else if(arr->type == "bool"){
            init->value.bVal = false;
        }else if(arr->type == "char"){
            init->value.cVal = '\0';
        }else if(arr->type == "string"){
            init->value.sVal = NULL;
        }
            arr->arrVal.push_back(init);
        // cout << "[arrInitialize]: pushed init\n";
    }
    return 0;
}
int IdList::updateArrayValue(const char* name, int scope, vector<int>coordinates, IdInfo* elem){
    IdInfo* v = getArray(name, scope);
    if(v == nullptr){
        cout << "[updateArrayValue]: array variable doesnt exist\n";
        return -1;
    }
    if(v->type != elem->type){
        cout << "[updateArrayValue]: incompatible types\n";
        return -1;
    }
    int index = calculateIndex(name, scope, coordinates);
    cout << "[updateArrayValue]: index is " << index << "\n";
    if(v->type == "int"){
        v->arrVal[index]->value.iVal = elem->value.iVal;
        cout << "[updateArrayValue]: updated int val " << v->arrVal[index]->value.iVal << "\n";
    }else if(v->type == "float"){
        v->arrVal[index]->value.fVal = elem->value.fVal;
        cout << "[updateArrayValue]: updated float val " << v->arrVal[index]->value.fVal << "\n";
    }else if(v->type == "bool"){
        v->arrVal[index]->value.bVal = elem->value.bVal;
        cout << "[updateArrayValue]: updated bool val\n";
    }else if(v->type == "char"){
        v->arrVal[index]->value.cVal = elem->value.cVal;
        cout << "[updateArrayValue]: updated char val\n";
    }else if(v->type == "string"){
        if(v->arrVal[index]->value.sVal!=NULL){
            free(v->arrVal[index]->value.sVal);
        }
        v->arrVal[index]->value.sVal = strdup(elem->value.sVal);
        cout << "[updateArrayValue]: updated string val " << v->arrVal[index]->value.sVal << "\n";
    }
    return 0;
}

int IdList::updateInt(const char * name, int val, int scope)
{
    // cout << "[updateInt] : val to be updated : " << val << endl;
    if(!existsVar(name)){
        if(this->log_flag){
            cout << "[updateInt]: " << name << " has not been declared" << endl;
        }
        return -1;
    }
    IdInfo*v = getVar(name, scope);
    if(v == nullptr){
        log("[updateInt]: error at retrieving id value\n");
        return -1;
    }
    if(v->type == string("int")){
        v->value.iVal = val;
        if(this->log_flag){
            cout << "updateInt: int value " << v->value.iVal << " updated for variable " << v->name<<endl;
        }
    }
    else{
         if(this->log_flag){
            cout << "Error at updateInt, variable " << v->name << " has wrong type for assignment\n";
            return -1;
        }
    }
    return 0;
}

int IdList::updateFloat(const char *name, float val, int scope)
{
    if(!existsVar(name)){
        if(this->log_flag){
            cout << "[updateFloat]: " << name << " has not been declared" << endl;
        }
        return -1;
    }
    IdInfo*v = getVar(name, scope);
    if(v == nullptr){
        log("[updateFloat]: error at retrieving id value\n");
        return -1;
    }
    if(v->type == string("float")){
        v->value.fVal = val;
        if(this->log_flag){
            cout << "[updateFloat]: float value " << v->value.fVal << " updated for variable " << v->name<<endl;
        }
    }
    else{
         if(this->log_flag){
            cout << "[updateFloat] variable " << v->name << " has wrong type for assignment\n";
            return -1;
        }
    }
    return 0;
}

int IdList::updateBool(const char *name, bool val, int scope)
{
    if(!existsVar(name)){
        if(this->log_flag){
            cout << "[updateBool]" << name << " has not been declared" << endl;
        }
        return -1;
    }
    IdInfo*v = getVar(name, scope);
    if(v == nullptr){
        log("[updateBool]: error at retrieving id value\n");
        return -1;
    }
    if(v->type == string("bool")){
        v->value.bVal = val;
        if(this->log_flag){
            cout << "[updateBool]: bool value " << v->value.bVal << " updated for variable " << v->name<<endl;
        }
    }
    else{
         if(this->log_flag){
            cout << "[updateBool]: variable " << v->name << " has wrong type for assignment\n";
            return -1;
        }
    }
    return 0;
}

int IdList::updateStr(const char *name, char *val, int scope)
{
    if(!existsVar(name)){
        if(this->log_flag){
            cout << "[updateStr]" << name << " has not been declared" << endl;
        }
        return -1;
    }
    IdInfo*v = getVar(name, scope);
    if(v == nullptr){
        log("[updateStr]: error at retrieving id value\n");
        return -1;
    }
    if(v->type == string("string")){
        if(v->value.sVal != NULL){
            free(v->value.sVal);
            }
        v->value.sVal = strdup(val);
        if(this->log_flag){
            cout << "[updateStr]: string value " << v->value.sVal << " updated for variable " << v->name<<endl;
        }
    }
    else{
         if(this->log_flag){
            cout << "[updateStr]: variable " << v->name << " has wrong type for assignment\n";
            return -1;
        }
    }
    return 0;
}

int IdList::updateChr(const char *name, char val, int scope){
    IdInfo* v = getVar(name, scope);
    if(v == nullptr){
        log("[updateChr]: error at getVar\n");
        return -1;
    }
    if(v->type != "char"){
        log("[updateChr]: incorrect type for assignment\n");
        return -1;
    }
    v->value.cVal = val;
    if(this->log_flag){
        cout << "[updateChr]: char value " << v->value.cVal << " updated for variable " << v->name<<endl;
    }
    return 0;
}

int IdList::varVarUpdate(const char *name1, int scope1, const char *name2, int scope2)
{
    if(!existsVar(name2)){
        cout << "[varVarUpdate]: variable2 not declared - cannot assign value\n";
        return -1;
    }
    if(!existsVar(name1)){
        cout << "[varVarUpdate]: variable1 not declared - cannot assign value\n";
        return -1;
    }
    IdInfo*v1 = getVar(name1, scope1);
    IdInfo*v2 = getVar(name2, scope2);
    if(v1->type == v2->type){
        v1->value = v2->value;
        if(this->log_flag){
            cout << "[varVarUpdate] : " << v1->name << " value is " << v1->value.iVal << "\n";
        }
        return 0;
    }
    log("[varVarUpdate] : incorrect types\n");
    return -1;
}

IdList::~IdList() {
    vars.clear();
}

void IdList::log(const char*msg){
    if(this->log_flag){
        cout << msg;
    }
}

int IdList::calculateIndex(const char *name, int scope, vector<int> coordinates)
{
    IdInfo* v = getVar(name, scope);
    if(v == nullptr){
        cout << "[calculateIndex]: array variable doesnt exist\n";
        return -1;
    }
    if(!v->isArr){
        cout << "[calculateIndex]: variable isn't of array type\n";
        return -1;
    }
    reverse(coordinates.begin(), coordinates.end());
    cout << "[calculateIndex]: dimensions: ";
    for(auto i : v->dimensions){
        cout << i << " ";
    }
    cout << endl;
    cout << "[calculateIndex]: coordinates: ";
    for(auto i : coordinates){
        cout << i << " ";
    }
    cout << endl;
    
    int res = 0;
    for(int i = 0; i < coordinates.size(); ++i){
        int part = coordinates[i];
        //cout << "[calculateIndex]: part is " << part << "\n";
        cout << "[calculateIndex]: coordinate and dimensions: " << coordinates[i] << " " << v->dimensions[i] << "\n";
        if(coordinates[i] >= v->dimensions[i]){
        cout << "[calculateIndex]: index surpasses dimension: segfault :D\n";
        return -1;
    }
        for(int j = i + 1; j < coordinates.size(); ++j){
            //cout << "[calculateIndex]: part = " << part << " * " << v->dimensions[j] << "\n";
            part*=v->dimensions[j];
        }
        res+=part;
    }
    return res;
}

IdInfo *IdList::getArrElem(const char *name, int scope, vector<int> coordinates)
{
    IdInfo* v = getVar(name, scope);
    int index = calculateIndex(name, scope, coordinates);
    if(!v->isArr){
        cout << "[getArrElem]: var isn't of array type\n";
        return nullptr;
    }
    return v->arrVal[index];
}