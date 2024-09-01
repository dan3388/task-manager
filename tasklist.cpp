#include "tasklist.h"
#include "task.h"
#include <cstddef>
using namespace std;

void TaskList::AddTask() {// Adds task to the linked list alphabetically
    Task task;
    task.getter();
    Node* newNode = new Node(task);
    if(head == nullptr) {
        head = newNode;
        size++;
        return;
    } if(task.getPersonName() < head->data.getPersonName()) {
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data.getPersonName() < task.getPersonName()) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    size++;
}

void TaskList::ListbyName() { // creates an array from the linked list and sorts them by alphabetical order
    if (head == nullptr) {
        cout << "Task list is empty!" << endl;
        return;
    }
    // creates array
    Node* current = head;
    Task array[size];
    for (int i=0; i!=size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    //prints the data
    for (int i=0; i!=size; i++) {
        array[i].dataPrint();
    }
}

void TaskList::ListbyType() {// Creates an array from the linked list and sorts them by alphabetical order
    if (head == nullptr) {
        cout << "Task list is empty!" << endl;
        return;
    }

    int input;
    cout << "Enter Type number(0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
    cin >> input;

    // creates array
    Node* current = head;
    Task array[size];
    for (int i=0; i!=size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    //prints the data
    for (int i=0; i!=size; i++) {
        if(array[i].getTypeNum() == input) {
            array[i].dataPrint();
            }
    }
}

void TaskList::deleteTask(int index) {// Deletes the task at index entered by user
    Node* curr = (Node*)malloc(sizeof(Node));
    curr = head;
    Node* prev = nullptr;
    
    if (index == 1) {
        head = head->next;
        delete curr;
        // free(curr);  // DEBUGGING
        // curr=NULL;
        size--;
        return;
    }

    for (int i = 1; (i < index); i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next; 
    delete curr;
    // free(curr);   // DEBUGGING
    // curr=NULL;
    size--;
}

void TaskList::searchTask(string word) {
    Node* curr = head;
    for (int i=0; i<size; i++) {
        if (curr->data.getTaskName().find(word) != string::npos) {
            curr->data.dataPrint();
        }
        curr = curr->next;
    }
}

TaskList::~TaskList() {
    Node *	curr = head;
	while(head)
	{
		head = curr->next;
        delete curr;
        // free(curr);  // DEBUGGING
        // curr=NULL;
		curr = head;
	}
}