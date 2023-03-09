// Task.cpp

#include "Task.h"
#include <cstring>

//deep copy
char* copy(const char* oldptr)
{
    int size = strlen(oldptr);
    char* newptr = new char[size + 1];
    for (int i = 0; i < size; ++i)
    {
        newptr[i] = oldptr[i];
    }
    newptr[size] = '\0';
    return newptr;
}

// default constructor
Task::Task()
{
    name = nullptr;
    time = nullptr;
    type = nullptr;
}

//Parameterized Construct0r
Task::Task(const char* name, const char* time, const char* type)
{
    Set(name, time, type);
}

//Copy Constructor
Task::Task(const Task& Obj)
{
    Set(Obj.name, Obj.time, Obj.type);
}

//Destructor
Task::~Task()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
    if (time != nullptr)
    {
        delete[] time;
        time = nullptr;
    }
    if (type != nullptr)
    {
        delete[] type;
        type = nullptr;
    }
}

//Setter
void Task::Set(const char* name, const char* time, const char* type)
{
    if (this->name != nullptr)
    {
        delete[] this->name;
        this->name = nullptr;
    }
    if (this->time != nullptr)
    {
        delete[] this->time;
        this->time = nullptr;
    }
    if (this->type != nullptr)
    {
        delete[] this->type;
        this->type = nullptr;
    }
    this->name = copy(name);
    this->time = copy(time);
    this->type = copy(type);
}

//Get Name
char* Task::getName() const
{
    if (name != nullptr)
    {
        return copy(this->name);
    }
    return nullptr;
}

//Get Time
char* Task::getTime() const
{
    if (time != nullptr)
    {
        return copy(time);
    }
    return nullptr;
}

//Get Type
char* Task::getType() const
{
    if (type != nullptr)
    {
        return copy(type);
    }
    return nullptr;
}

// output operator
ostream& operator << (ostream& display, const Task& obj)
{
    display << "Name: " << obj.name << " Time: " << obj.time << " Type: " << obj.type << endl;
    return display;
}

// input operator
istream& operator >> (istream& input, Task& obj)
{
    static const int max_chars = 50;
    char name[max_chars];
    char time[max_chars];
    char type[max_chars];
    cout << "Enter Name: ";
    cin.ignore();
    input.getline(name, max_chars);
    cout << "Enter Time: ";
    input.getline(time, max_chars);
    cout << "Enter Type: <Internal, External>";
    input.getline(type, max_chars);
    obj.Set(name, time, type);
    return input;
}

// equality test operator
bool Task::operator == (const Task& obj)const
{
    if (strcmp(this->name, obj.name))
        return false;

    if (strcmp(this->time, obj.time))
        return false;

    if (strcmp(this->type, obj.type))
        return false;

    return true;
}

//Assignment Operator
Task& Task::operator = (const Task& obj)
{
    Set(obj.name, obj.time, obj.type);
    return *this;
}