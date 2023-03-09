#pragma once
// Task.h

#ifndef Task_H
#define Task_H

#include <iostream>
using namespace std;

// Task is a simple class that stores a name,time and type as strings
// it just provides i/o operators, == operator, constructors and Set function
class Task
{
private:
    char* name;
    char* time;
    char* type;
    //initialized members of the task

    // output the Task in the format:
        // name, time , type
    friend ostream& operator <<(ostream&, const Task&);

    // input the Task in the format:
    // name,  time , type
    friend istream& operator >> (istream&, Task&);

public:
    // constructors
    Task();

    Task(const char*, const char*, const char*);

    Task(const Task&);

    //Destructor
    ~Task();

    // Set the Task
    void Set(const char* t, const char*, const char*);

    //Getters
    char* getName()const;

    char* getTime()const;

    char* getType()const;

    // Assignment Operator
    Task& operator = (const Task&);

    // compare two Task objects for equality
    bool operator == (const Task&)const;
};
#endif