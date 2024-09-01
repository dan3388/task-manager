#include <iostream>
#include <string>
#include "main.h"
#include "task.h"
#include "tasklist.h"

using namespace std;

int main() {
    // Prints the Welcome message at the start of the program only
    cout << "Welcome!" << endl << "This program will help you manage your tasks for this Space Station." << endl;

    // Create a TaskList Object
    TaskList list;
    // Prints menu message and runs the methods 
    Operation(userInput(), list);
    return 0;
}




