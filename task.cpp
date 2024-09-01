#include "task.h"
#include "tasklist.h"
#include <iostream>
#include <string>

using namespace std;

void Task::getter() {
    // Collect Date of Month
    bool check = false;
    while (check == false) {
        cout << "Enter the day of the task (whole numbers between 1 and 30): ";
        cin >> this->dom;
        if (cin.fail() || this->dom < 1 || this->dom > 30) {
            cin.clear();
            cin.ignore();
            cout << "Invalid day! Must be between 1 and 30 inclusive!\n";
        } else {
            check = true;
        }
    }

    // Collect taskName
    check = false;
    cin.ignore();
    while (check == false)
    {
        cout << "Enter the task name (50 characters or less): ";
        getline(cin, this->taskName);
        if (this->taskName.length() > 50) {
            cin.clear();
            cin.ignore();
            cout << "Invalid task name! Must be 50 characters or less!\n";
        } else {
            check = true;
        }
    }
    
    // Collect personName
    check = false;
    while (check == false)
    {
        cout << "Enter the person’s name (50 characters or less): ";
        getline(cin, this->personName);
        if (this->personName.length() > 50) {
            cin.clear();
            cin.ignore();
            cout << "Invalid name! Must be 50 characters or less!\n";
        } else {
            check = true;
        }
    }

    // Collect taskDuration
    check = false;
    while (check == false)
    {
        cout << "Enter the number of hours (whole numbers between 1 and 10): ";
        cin >> this->taskDuration;
        if (cin.fail() || this->taskDuration < 0 || this->taskDuration > 10) {
            cin.ignore();
            cin.clear();
            cout << "Invalid number of hours! Must be between 1 and 10!\n";
        } else {
            check = true;
        }
    }
    
    //Collect taskType
    check = false;
    while (check == false) {
        cout << "Enter the task type 0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
        cin >> this->taskTypeNum;
        if (std::cin.fail() || this->taskTypeNum < 0 || this->taskTypeNum > 4) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid task type! Must be between 0 and 4 inclusive." << std::endl;
            } else {
                this->typeConvert();
                check = true;
            }
    }
}

void Task::dataPrint() {
    cout << this->dom << ';'
        << this->taskName << ':'
        << this->personName << ';'
        << this->taskType << endl;
}

void Task::typeConvert() {
    taskType = taskTypeDict[taskTypeNum];
}