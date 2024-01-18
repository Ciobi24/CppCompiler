#include "Class.h"
IdInfo *Object::getField(const char *name)
{
    for (IdInfo &id : fields)
    {
        if (id.name == name)
        {
            return &id;
        }
    }
    return nullptr;
}
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
        IdInfo id;
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
        if (id.isArr == true)
        {
            int dim = 1;
            for (auto i : field.dimensions)
            {
                dim *= i;
            }
            for (int i = 0; i < dim; ++i)
            {
                IdInfo *init = new IdInfo;
                init->type = id.type;
                init->name = string("");
                init->isArr = false;
                if (id.type == "int")
                {
                    init->value.iVal = 0;
                }
                else if (id.type == "float")
                {
                    init->value.fVal = 0.0;
                }
                else if (id.type == "bool")
                {
                    init->value.bVal = false;
                }
                else if (id.type == "char")
                {
                    init->value.cVal = '\0';
                }
                else if (id.type == "string")
                {
                    init->value.sVal = NULL;
                }
                id.arrVal.push_back(init);
            }
        }
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
        fs << endl
           << "Classes:";
        for (Class *c : classes)
        {
            cout << "Class: " << c->name << endl;
            cout << "Fields: " << endl;
            fs << "Class: " << c->name << endl;
            fs << "Fields: " << endl;
            for (IdInfo id : c->fields)
            {
                if (id.isArr == false)
                {
                    cout << id.type << " " << id.name << endl;
                    fs << id.type << " " << id.name << endl;
                }
                else
                {
                    cout << id.type << " " << id.name << "  value: ";
                    fs << id.type << " " << id.name << "  value: ";
                    for (int i = 0; i < id.dimensions.size(); i++)
                    {
                        cout << "[";
                        fs << "[";
                        cout << id.dimensions[i];
                        fs << id.dimensions[i];
                        cout << "]";
                        fs << "]";
                    }
                }
            }

            cout << endl<<"Methods: " << endl;
            fs << endl<<"Methods: " << endl;
            for (Function f : c->methods)
            {
                bool first = true;
                cout << f.type << " " << f.name << " (";
                fs << f.type << " " << f.name << " (";
                for (IdInfo id : f.param)
                {
                    if (!first)
                    {
                        cout << ", ";
                        fs << ", ";
                    }
                    cout << id.type << " " << id.name;
                    fs << id.type << " " << id.name;
                    if (first)
                    {
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
        fs << endl
           << "Objects:";
        for (Object *o : objects)
        {
            cout << endl
                 << "Object: " << o->name << " of class " << o->class_name << endl;
            cout << "Fields: " << endl;
            fs << endl
               << "Object: " << o->name << " of class " << o->class_name << endl;
            fs << "Fields: " << endl;
            for (IdInfo id : o->fields)
            {
                if (id.isArr == false)
                {
                    cout << id.type << " " << id.name << "  value: ";
                    fs << id.type << " " << id.name << "  value: ";
                    if (id.type == "int")
                    {
                        cout << id.value.iVal << endl;
                        fs << id.value.iVal << endl;
                    }
                    else if (id.type == "float")
                    {
                        cout << id.value.fVal << endl;
                        fs << id.value.fVal << endl;
                    }
                    else if (id.type == "char")
                    {
                        cout << id.value.cVal << endl;
                        fs << id.value.cVal << endl;
                    }
                    else if (id.type == "bool")
                    {
                        cout << boolalpha << id.value.bVal << noboolalpha << endl;
                        fs << boolalpha << id.value.bVal << noboolalpha << endl;
                    }
                    else if (id.type == "string")
                    {
                        cout << id.value.sVal << endl;
                        fs << id.value.sVal << endl;
                    }
                }
                else
                {
                    cout << id.type << " " << id.name << "  value: ";
                    fs << id.type << " " << id.name << "  value: ";
                    for (int i = 0; i < id.dimensions.size(); i++)
                    {
                        cout << "[";
                        fs << "[";
                        cout << id.dimensions[i];
                        fs << id.dimensions[i];
                        cout << "]";
                        fs << "]";
                    }
                    cout << " = ";
                    fs << " = ";
                    if (id.type == "int")
                    {
                        for (int i = 0; i < id.arrVal.size(); i++)
                        {
                            cout << id.arrVal[i]->value.iVal << " ";
                            fs << id.arrVal[i]->value.iVal << " ";
                        }
                        cout << endl;
                        fs << endl;
                    }
                    else if (id.type == "float")
                    {
                        for (int i = 0; i < id.arrVal.size(); i++)
                        {
                            cout << id.arrVal[i]->value.fVal << " ";
                            fs << id.arrVal[i]->value.fVal << " ";
                        }
                        cout << endl;
                        fs << endl;
                    }
                    else if (id.type == "char")
                    {
                        for (int i = 0; i < id.arrVal.size(); i++)
                        {
                            cout << id.arrVal[i]->value.cVal << " ";
                            fs << id.arrVal[i]->value.cVal << " ";
                        }
                        cout << endl;
                        fs << endl;
                    }
                    else if (id.type == "bool")
                    {
                        for (int i = 0; i < id.arrVal.size(); i++)
                        {
                            cout << boolalpha << id.arrVal[i]->value.bVal << noboolalpha << " ";
                            fs << boolalpha << id.arrVal[i]->value.bVal << noboolalpha << " ";
                        }
                        cout << endl;
                        fs << endl;
                    }
                    else if (id.type == "string")
                    {
                        for (int i = 0; i < id.arrVal.size(); i++)
                        {
                            cout << id.arrVal[i]->value.sVal << " ";
                            fs << id.arrVal[i]->value.sVal << " ";
                        }
                        cout << endl;
                        fs << endl;
                    }
                }
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
                    if (!first)
                    {
                        cout << ", ";
                        fs << ", ";
                    }
                    cout << id.type << " " << id.name;
                    fs << id.type << " " << id.name;
                    if (first)
                    {
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