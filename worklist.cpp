#include "Worklist.h"

Task Worklist::operator[](int index)
{
	return plist[index];
}

Worklist::Worklist()//constructor is called
{
	this->plist = new Task[2]();
	this->capacity = 2;
	this->recorder = 0;
	this->index = 0;
}

Worklist::Worklist(const Worklist& TaskObj)
{
	this->plist = new Task[TaskObj.capacity];
	this->capacity = TaskObj.capacity;
	this->recorder = TaskObj.recorder;
	this->index = TaskObj.index;
	for (int i = 0; i < recorder; ++i)
	{
		plist[i] = TaskObj.plist[i];
	}
}

Worklist::~Worklist()//deconstructor is called 
{
	if (plist != nullptr)
	{
		delete[] plist;
		plist = nullptr;
	}
}

void Worklist::AddTask(const Task& newTask)//task is added 
{
	plist[index++] = newTask;
	++recorder;
	if (capacity == recorder)
	{
		doubleSize();
	}
}

bool Worklist::DeleteTask(const Task& Task)//task is deleted
{
	for (int i = 0; i < index; ++i)
	{
		if (plist[i] == Task)
		{
			--index;
			for (int j = i; j < index; ++j)
			{
				plist[i] = plist[i + 1];
			}
			--recorder;
			if (recorder <= capacity / 2)
			{
				halfSize();
			}
			return true;
		}
	}
	return false;
}

void Worklist::Start(const int& num)
{
	if (num == 1)
	{
		for (int i = 0; i < recorder; ++i)
		{
			cout << "Task " << i + 1 << "\nName: " << plist[i].getName() << endl << endl;
		}
	}
	else
	{
		if (num <= index)
		{
			for (int i = num - 1; i < index; ++i)
			{
				cout << "Task " << i + 1 << " Name: ";
				plist[i].getName();
				cout << endl << endl;
			}
			for (int i = 0; i < num - 1; ++i)
			{
				cout << "Task " << i + 1 << " Name: ";
				plist[i].getName();
				cout << endl << endl;
			}
		}
	}
}

void Worklist::ShowAll()const
{
	for (int i = 0; i < index; ++i)
	{
		cout << "Task " << i + 1 << ". " << '\n' << plist[i] << endl;
	}
}

void Worklist::ShowStatus()const
{
	cout << "Capacity: " << capacity << endl;
	cout << "Total Added Tasks: " << recorder << endl;
	cout << "Index: " << index << endl;
}

void Worklist::doubleSize()
{
	cout << "Before: <>\n";
	ShowStatus();
	cout << endl;
	capacity *= 2;
	Task* NewTasklist = new Task[capacity];
	for (int i = 0; i < index; ++i)
	{
		NewTasklist[i] = this->plist[i];
	}
	if (plist != nullptr)
	{
		delete[] plist;
		plist = nullptr;
	}
	plist = NewTasklist;
	cout << "After: <>\n";
	ShowStatus();
	cout << endl;
}

void Worklist::halfSize()
{
	cout << "Before: <>\n";
	ShowStatus();
	cout << endl;
	capacity /= 2;
	Task* NewTasklist = new Task[capacity];
	for (int i = 0; i < index; ++i)
	{
		NewTasklist[i] = this->plist[i];
	}
	if (plist != nullptr)
	{
		delete[] plist;
		plist = nullptr;
	}
	plist = NewTasklist;
	cout << "After: <>\n";
	ShowStatus();
	cout << endl;
}

Worklist& Worklist::operator + (const Task& obj)
{
	AddTask(obj);
	return *this;
}

Worklist& Worklist::operator - (const Task& obj)
{
	DeleteTask(obj);
	return *this;
}
