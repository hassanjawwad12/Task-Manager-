// sample main.cpp
//L20-1122 Hassan Jawwad Asiignment#2
#include "Task.h"
#include "Worklist.h"

void DoAdd(Worklist& task_list)//input is taken from the user 
{
    Task s;
    cout << "Enter Task\n: ";
    cin >> s;

    task_list.AddTask(s);
}

void DoDelete(Worklist& task_list)//user enters the task he wants to delete
{
    Task del_Task;
    cout << "Enter Task to delete\n: ";
    cin >> del_Task;

    if (task_list.DeleteTask(del_Task))
    {
        cout << "Task successfully deleted\n";
    }
    else
    {
        cout << "No such Task exists\n";
    }
}

bool Menu(Worklist& task_list)//menu is shown
{
    bool good;

    do
    {
        good = true;

        cout << "\n\nWorklist Program!\n"
            << "\tA - Add a Task\n"
            << "\tD - Delete a Task\n"
            << "\tP - Start a Task\n"
            << "\tS - Show all Tasks\n"
            << "\tT - Show Worklist status\n"
            << "\tQ - Quit\n: ";

        char choice;
        cin >> choice;

        switch (toupper(choice))
        {
        case 'A':
            DoAdd(task_list);
            break;

        case 'D':
            DoDelete(task_list);
            break;

        case 'P':
            task_list.Start();
            break;

        case 'S':
            task_list.ShowAll();
            break;
        case 'T':
            task_list.ShowStatus();
            break;
        case 'Q':
            return false;

        default:
            good = false;
        }
    } while (!good);

    return true;
}

int main()
{
    Worklist task_list;

    while (Menu(task_list));

    // Using Operators
    Task Task1;
    cin >> Task1;

    //Adding
    cout << "Using Operator + <>\n";
    task_list = task_list + Task1;
    task_list.ShowAll();

    //Deleting
    cout << "Using Operator - <>\n";
    task_list = task_list - Task1;
    task_list.ShowAll();

    return 0;
}