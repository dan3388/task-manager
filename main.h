#pragma once
#include <iostream>
#include <string>
#include "task.h"
#include "tasklist.h"

using namespace std;

// check if input is valid (works)
bool inputCheck(char input) {
    const char inputOptions[6] = {'a','b','c','d','e','q'};
    for (int i=0; i<6; i++) {
        if (input == inputOptions[i]) {
            return true;
        }
    }
    return false;
}

// Function code for the program as long as the user does not use 'q'
char userInput() {
    // prompt
    cout << "\nPick an option from below:"<< endl << endl
         << "(a)Add a new task" << endl 
         << "(b)List tasks by name" << endl 
         << "(c)List tasks by Type" << endl
         << "(d)Search by task name" << endl
         << "(e)Remove tasks by index" << endl
         << "(q)Quit\n" << endl;
        
    // collect option from user
    char input;
    cin >> input;
    if (inputCheck(input)) {
        return input;
    }
    else {
        cout << "Invalid option!! Please try again!\n";
        return userInput();
    }
    
        
}

// Index collector for deleting a node by index
int indexInput(TaskList taskList) {
    // Collect index
    int index;
    cout << "Enter Index of Task to delete: ";
    cin >> index;
    if (index <= taskList.getSize()) {
        return index;
    }
    else {
        cout << "Invalid option!! Please try again!\n";
        return indexInput(taskList);
    }
}

// Input word for search
string wordSearch() {
    string word;
    cout << "Enter word to search: ";
    cin >> word;
    return word;
}

// uses switch to determine what method/function is called and recurs itself
void Operation(const char option, TaskList taskList) { 
    switch (option) {
        case 'a': {// Add task
            taskList.AddTask();
            cout << "Task added!\n";
            break;
        }
        case 'b': {// List task by name
            cout << "List by task name\n";
            taskList.ListbyName();
            break;
        }
        case 'c': {// List task by type
            cout << "List by task type\n";
            taskList.ListbyType();
            break;
        }
        case 'd': {// Search task by name
            cout << "Search by task name\n";
            string word = wordSearch();
            taskList.searchTask(word);
            break;
        }
        case 'e': {// Remove task by index
            int index = indexInput(taskList);
            taskList.deleteTask(index);
            break;
        }
        case 'q': {// Quit
            cout << "Byebye!\n";
            return; 
        }
    }

    // Recursion 
    Operation(userInput(), taskList);
}



// string nameInput() {

// }