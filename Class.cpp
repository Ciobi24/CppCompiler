#include "Class.h"
bool ObjectTable::existsClass(const char *name)
{
    for (const Class *c : classes)
    {
        if (c->name == name)
        {
            return true;
        }
    }
    return false;
}
bool ObjectTable::existsObject(const char *name)
{
    for (const Object *o : objects)
    {
        if (o->name == name)
        {
            return true;
        }
    }
    return false;
}
Class *ObjectTable::getClass(const char *name)
{
    for (Class *c : classes)
    {
        if (c->name == name)
        {
            return c;
        }
    }
    return nullptr;
}
Object *ObjectTable::getObject(const char *name)
{
    for (Object *o : objects)
    {
        if (o->name == name)
        {
            return o;
        }
    }
    return nullptr;
}
int ObjectTable::addClass(const char *name, vector<IdInfo> fields, vector<Function> methods)
{
    if (existsClass(name))
    {
        return -1;
    }
    Class *c = new Class;
    c->name = string(name);
    for (auto field : fields)
    {
        IdInfo id ;
        id.type = field.type;
        id.name = field.name;
        id.scopeId = 0;
        id.isConst = field.isConst;
        id.isArr = field.isArr;
        id.dimensions = field.dimensions;
        id.arrVal = field.arrVal;
        c->fields.push_back(id);
    }
    for (auto method : methods)
    {
        Function f;
        f.type = method.type;
        f.name = method.name;
        f.param = method.param;
        c->methods.push_back(f);
    }
    classes.push_back(c);
    return 0;
}
int ObjectTable::addObject(const char *name, const char *class_name, vector<IdInfo> fields, vector<Function> methods)
{
    if (existsObject(name))
    {
        return -1;
    }
    if (!existsClass(class_name))
    {
        return -2;
    }
    Object *o = new Object;
    o->name = string(name);
    o->class_name = string(class_name);
    for (auto field : fields)
    {
        IdInfo id;
        id.type = field.type;
        id.name = field.name;
        id.scopeId = 0;
        id.isConst = field.isConst;
        id.isArr = field.isArr;
        id.dimensions = field.dimensions;
        id.arrVal = field.arrVal;
        o->fields.push_back(id);
    }
    for (auto method : getClass(class_name)->methods)
    {
        Function f;
        f.type = method.type;
        f.name = method.name;
        f.param = method.param;
        o->methods.push_back(f);
    }
    objects.push_back(o);
    return 0;
}
void ObjectTable::printClasses()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        std::string filePath = std::string(cwd) + "/table.txt";
        std::ofstream fs(filePath, std::ios::app); // Open file in append mode
        if (!fs)
        {
            cout << "[printVars]: error at opening file\n";
        }
        fs<<endl<<"Classes:";
        for (Class *c : classes)
        {
            cout <<"Class: " << c->name << endl;
            cout << "Fields: " << endl;
            fs << "Class: " << c->name << endl;
            fs << "Fields: " << endl;
            for (IdInfo id : c->fields)
            {
                cout << id.type << " " << id.name << endl;
                fs << id.type << " " << id.name << endl;
            }
            cout << "Methods: " << endl;
            fs << "Methods: " << endl;
            for (Function f : c->methods)
            {
                bool first = true;
                cout << f.type << " " << f.name << " (";
                fs << f.type << " " << f.name << " (";
                for (IdInfo id : f.param)
                {
                    if(!first){
                        cout << ", ";
                        fs << ", ";
                    }
                    cout << id.type << " " << id.name;
                    fs << id.type << " " << id.name;
                    if(first){
                    first = false;
                    }
                }
                cout << ")" << endl;
                fs << ")" << endl;
            }
        }
    }
    else
    {
        cout << "[printFuncs]: eroare la obținerea directorului curent\n";
    }
}

void ObjectTable::printObjects()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        std::string filePath = std::string(cwd) + "/table.txt";
        std::ofstream fs(filePath, std::ios::app); // Open file in append mode
        if (!fs)
        {
            cout << "[printVars]: error at opening file\n";
        }
        fs<<endl<<"Objects:";
        for (Object *o : objects)
        {
            cout << endl<<"Object: " << o->name << " of class " << o->class_name << endl;
            cout << "Fields: " << endl;
            fs << endl<<"Object: " << o->name << " of class " << o->class_name << endl;
            fs << "Fields: " << endl;
            for (IdInfo id : o->fields)
            {
                cout << id.type << " " << id.name << endl;
                fs << id.type << " " << id.name << endl;
            }
            cout << "Methods: " << endl;
            fs << "Methods: " << endl;
            for (Function f : o->methods)
            {
                bool first = true;
                cout << f.type << " " << f.name << " (";
                fs << f.type << " " << f.name << " (";
                for (IdInfo id : f.param)
                {
                    if(!first){
                        cout << ", ";
                        fs << ", ";
                    }
                    cout << id.type << " " << id.name;
                    fs << id.type << " " << id.name;
                    if(first){
                    first = false;
                    }
                }
                cout << ")" << endl;
                fs << ")" << endl;
            }
        }
    }
    else
    {
        cout << "[printFuncs]: eroare la obținerea directorului curent\n";
    }
}