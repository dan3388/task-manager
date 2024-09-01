#pragma once
#include <iostream>
#include <string>
// #include "tasklist.h"

using namespace std;

class Task {
    public:
        Task() {};
        ~Task() {};
        void dataPrint();
        void getter();
        string getPersonName() {return personName;};
        string getTaskName() {return taskName;};
        string getType() {return taskType;};
        int getTypeNum() {return taskTypeNum;};
        void typeConvert();
    private:
        int dom;
        std::string taskName;
        int taskDuration;
        std::string personName;
        std::string taskType;
        int taskTypeNum;
        std::string taskTypeDict[5] = {"Operations", "Maintenance", "Inventory", "Communications", "Other"};
        
};



