#pragma once
//Worklist.h


#ifndef Worklist_H
#define Worklist_H

#include "Task.h"

// Class to Manage the Tasks
class Worklist
{
private:
	//initialized the members of the task
	Task* plist;
	int capacity;
	int recorder;
	int index;

	//Index Operator
	Task operator [] (int);

public:
	//initialized the functions of the task
	Worklist();
	Worklist(const Worklist&);
	~Worklist();
	void AddTask(const Task&);
	bool DeleteTask(const Task&);
	void Start(const int& = 1);
	void ShowAll()const;
	void ShowStatus()const;
	void doubleSize();
	void halfSize();

	// + Operator Overload
	Worklist& operator + (const Task&);//incrementing

	// - Operator Overload
	Worklist& operator - (const Task&);//decrementing

};

#endif Worklist_H