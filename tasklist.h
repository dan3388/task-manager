#pragma once
#include <vector>
#include "task.h"

using namespace std;

class TaskList{
    public:
        TaskList() {}; //Constructor
        ~TaskList(); //Deconstructor 
        void AddTask();
        void ListbyName();
        void ListbyType();
        void deleteTask(int);
        int getSize() {return size;};
        void searchTask(string);
    private:
        struct Node {
            Task data;
            Node* next;
            Node(const Task& aData)
		    {
			    data = aData;
			    next = nullptr;
		    } 
        };
        Node* head = nullptr;
        int size = 0;
};



