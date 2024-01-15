#include "Node.h"

node* node::evaluate()
{
    if(this->left == nullptr && this->right == nullptr){
        //mr_leaf
        return this;
    }
    node*lval = nullptr;
    node*rval = nullptr;
    bool isBinary = (this->left != nullptr && this->right != nullptr);
    lval = this->left->evaluate(); //getting left and right side value for op cases

    if(isBinary){
        rval = this->right->evaluate();
    }
    
    if(isBinary && (lval->type != rval->type)){ //binary operation only
        cout << "[evaluate] : nodes have different type - aborting\n";
        return nullptr;
    }

    if(isBinary){
        if(lval->type == INTEGER){
            cout << "[evaluate] : nodes have same type = int: " << lval->val.iVal << " " << rval->val.iVal << "\n";
        }
        else if(lval -> type == FLOAT){
            cout << "[evaluate] : nodes have same type = float: " << lval->val.fVal << " " << rval->val.fVal << "\n";
        }else if(lval->type == BOOL){
            cout << "[evaluate] : nodes have same type = bool: " << lval->val.bVal << " " << rval->val.bVal << "\n";
        }else{
            cout << "[evaluate] : TYPECHECK ERROR - INCOMPATIBLE TYPE\n";
            return nullptr; //throw si catch
        }
    }
    else{
         if(lval->type == INTEGER){
            cout << "[evaluate] : child of nonbinary node, of type = int: " << lval->val.iVal << "\n";
        }
        else if(lval -> type == FLOAT){
            cout << "[evaluate] : child of nonbinary node, of type = float: " << lval->val.fVal << "\n";
        }else if(lval->type == BOOL){
            cout << "[evaluate] : child of nonbinary node, of type = bool: " << lval->val.bVal << "\n";
        }else{
            cout << "[evaluate] : TYPECHECK ERROR - INCOMPATIBLE TYPE\n";
            return nullptr; //throw si catch
        }
    }

    this->type = lval->type;
    switch(this->op){
        case ADD:{
            if(lval->type == INTEGER){
                this->val.iVal = lval->val.iVal + rval->val.iVal;
                cout << "[evaluate] : int add op val = " << this->val.iVal << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.fVal = lval->val.fVal + rval->val.fVal;
                cout << "[evaluate] : float add op val = " << this->val.fVal << "\n";
            }
            else{
                cout << "[evaluate] : ADD ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            } 
            return this;
            break;
        }
        case SUB:{
            if(lval->type == INTEGER){
                this->val.iVal = lval->val.iVal - rval->val.iVal;
                cout << "[evaluate] : int sub op val = " << this->val.iVal << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.fVal = lval->val.fVal - rval->val.fVal;
                cout << "[evaluate] : float sub op val = " << this->val.fVal << "\n";
            }
            else{
                cout << "[evaluate] : SUB ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
            break;
        }
        case MUL:{
            if(lval->type == INTEGER){
                this->val.iVal = lval->val.iVal * rval->val.iVal;
                cout << "[evaluate] : int mul op val = " << this->val.iVal << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.fVal = lval->val.fVal * rval->val.fVal;
                cout << "[evaluate] : float mul op val = " << this->val.fVal << "\n";
            }
            else{
                cout << "[evaluate] : MUL ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
            break;
        }
        case DIV:{
            if((rval->val.iVal == 0 && rval->type == INTEGER) || (rval->val.fVal == 0 && rval->type == FLOAT)){
                cout << "[evaluate]: ERROR ATTEMPTED DIVISION BY 0\n";
                return nullptr;//?err handling
            }
            if(lval->type == INTEGER){
                this->val.iVal = lval->val.iVal / rval->val.iVal;
                cout << "[evaluate] : int div val = " << this->val.iVal << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.fVal = lval->val.fVal / rval->val.fVal;
                cout << "[evaluate] : float div op val = " << this->val.fVal << "\n";
            }
            else{
                cout << "[evaluate] : DIV ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
            break;
        }//LEQ GE etc
        case LE:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal < rval->val.iVal);
                cout << "[evaluate] : bool le val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal < rval->val.fVal);
                cout << "[evaluate] : bool le val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : LE ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
            break;
        }
        case GE:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal > rval->val.iVal);
                cout << "[evaluate] : bool ge val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal > rval->val.fVal);
                cout << "[evaluate] : bool ge val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : GE ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
            break;
        }
        case LEQ:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal <= rval->val.iVal);
                cout << "[evaluate] : bool leq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal <= rval->val.fVal);
                cout << "[evaluate] : bool leq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : LEQ ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
        case GEQ:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal >= rval->val.iVal);
                cout << "[evaluate] : bool geq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal >= rval->val.fVal);
                cout << "[evaluate] : bool geq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : GEQ ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
        case NEQ:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal != rval->val.iVal);
                cout << "[evaluate] : bool neq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal != rval->val.fVal);
                cout << "[evaluate] : bool neq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == BOOL){
                this->val.bVal = (lval->val.fVal != rval->val.fVal);
                cout << "[evaluate] : bool neq val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : NEQ ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
        case EQU:{
            this->type = exprType::BOOL;
            if(lval->type == INTEGER){
                this->val.bVal = (lval->val.iVal == rval->val.iVal);
                cout << "[evaluate] : bool equ val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.bVal = (lval->val.fVal == rval->val.fVal);
                cout << "[evaluate] : bool equ val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else if(lval->type == BOOL){
                this->val.bVal = (lval->val.fVal == rval->val.fVal);
                cout << "[evaluate] : bool equ val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : EQU ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
        case NOT:{
            this->type = exprType::BOOL;
            if(lval->type == BOOL){
                this->val.bVal = !(lval->val.bVal);
                cout << "[evaluate] : bool not val = " << boolalpha <<this->val.bVal << noboolalpha << "\n";
            }
            else{
                cout << "[evaluate] : NEQ ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
        case UMIN:{
            if(lval->type == INTEGER){
                this->val.iVal = (-1)*lval->val.iVal;
                cout << "[evaluate] : int umin op val = " << this->val.iVal << "\n";
            }
            else if(lval->type == FLOAT){
                this->val.fVal = (-1)*lval->val.fVal;
                cout << "[evaluate] : float umin op val = " << this->val.fVal << "\n";
            }
            else{
                cout << "[evaluate] : SUB ERROR - INCOMPATIBLE TYPE\n";
                return nullptr; //handle error
            }
            return this;
        }
    }
    return nullptr;
}

void node::clean(){
    //cout << "[clean] - started\n";
    if(this == nullptr){
        return;
    }
    if(this->left != nullptr){
        this->left->clean();
    }
    if(this->right != nullptr){
        this->right->clean();
    }
    delete this;
}