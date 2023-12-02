// c++tool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <algorithm>

void gradeManager();
void todoList();

const std::string version = "v1.0";

inline bool exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int main()
{
    std::string option;
    std::cout << "Welcome. " << version << "\n";
    std::cout << "1. Utilities" << "\n";
    std::cout << ">";
    std::cin >> option;

    if (option == "1") {
        std::string option1;
        std::cout << "\n";
        std::cout << "1. Grade manager" << "\n";
        std::cout << "2. Todo list" << "\n";
        std::cout << ">";
        std::cin >> option1;

        if (option1 == "1") {
            gradeManager();
        }
        else if (option1 == "2") {
            todoList();
        }
    }
}

void gradeManager() {
    const std::string locationMath = ".\\utilities\\grade manager\\math.txt";
    const std::string locationChemistry = ".\\utilities\\grade manager\\chemistry.txt";
    const std::string locationPhysics = ".\\utilities\\grade manager\\physics.txt";
    const std::string locationBiology = ".\\utilities\\grade manager\\biology.txt";
    const std::string locationSlovak = ".\\utilities\\grade manager\\slovak.txt";
    
    std::string option;
    std::cout << "\n";
    std::cout << "1. View all grades" << "\n";
    std::cout << "2. Add a grade" << "\n";
    std::cout << "3. Exit" << "\n";
    std::cout << ">";
    std::cin >> option;

    if (option == "1") {

        
        
        

        std::string fileContents;

        /*
        std::string selectedSubject;
        std::cout << "\n";
        std::cout << "Enter name of subject you want to view";
        std::cout << ">";
        std::cin >> selectedSubject;
        std::transform(selectedSubject.begin(), selectedSubject.end(), selectedSubject.begin(), ::toupper);
        */

        std::cout << "\n";
        
        bool mathFileExists = exists(locationMath);
            if (mathFileExists) {
                std::ifstream readFile(locationMath);
                std::cout << "Math: ";
                while (getline(readFile, fileContents)) {
                    std::cout << fileContents;
                }
                readFile.close();

            }
            else {
                std::cout << "File containing grades doesn't seem to exist";
            }
            std::cout << "\n";

            bool chemistryFileExists = exists(locationChemistry);
            if (chemistryFileExists) {
                std::ifstream readFile(locationChemistry);
                std::cout << "Chemistry: ";
                while (getline(readFile, fileContents)) {
                    std::cout << fileContents;
                }
                readFile.close();

            }
            else {
                std::cout << "File containing grades doesn't seem to exist";
            }
            std::cout << "\n";

            bool physicsFileExists = exists(locationPhysics);
            if (physicsFileExists) {
                std::ifstream readFile(locationPhysics);
                std::cout << "Physics: ";
                while (getline(readFile, fileContents)) {
                    std::cout << fileContents;
                }
                readFile.close();

            }
            else {
                std::cout << "File containing grades doesn't seem to exist";
            }
            std::cout << "\n";

            bool biologyFileExists = exists(locationBiology);
            if (biologyFileExists) {
                std::ifstream readFile(locationBiology);
                std::cout << "Biology: ";
                while (getline(readFile, fileContents)) {
                    std::cout << fileContents;
                }
                readFile.close();

            }
            else {
                std::cout << "File containing grades doesn't seem to exist";
            }
            std::cout << "\n";

            bool slovakFileExists = exists(locationSlovak);
            if (slovakFileExists) {
                std::ifstream readFile(locationSlovak);
                std::cout << "Slovak: ";
                while (getline(readFile, fileContents)) {
                    std::cout << fileContents;
                }
                readFile.close();

            }
            else {
                std::cout << "File containing grades doesn't seem to exist";
            }
            std::cout << "\n";
            gradeManager();
            
        

    }
    else if (option == "2") {
        std::string subject;
        std::string newGrade;
        std::cout << "\n";
        std::cout << "Enter name of subject you want to add grade to: ";
        std::cin >> subject;
        std::cout << "Enter new grade: ";
        std::cin >> newGrade;

        if (subject == "Math") {
            subject = locationMath;
        }
        else if (subject == "Chemistry") {
            subject = locationChemistry;
        }
        else if (subject == "Physics") {
            subject = locationPhysics;
        }
        else if (subject == "Biology") {
            subject = locationBiology;
        }
        else if (subject == "Slovak") {
            subject = locationSlovak;
        }

        std::ifstream readGradeFile(subject);
        std::string readGradeFileString;

        std::getline(readGradeFile, readGradeFileString);
        std::string newContents = readGradeFileString + newGrade + ", ";
        
        std::ofstream gradeFile(subject);
        gradeFile << newContents;
        gradeFile.close();
        std::cout << "\n";
        gradeManager();
    }
    else if (option == "3") {
        std::cout << "\n";
        main();
    }

    


}

void todoList() {
    
    const std::string todoListPath(".\\utitlties\\todo list");
    const std::string allTodoListsFile(".\\utilities\\todo list\\todolists.txt");

    std::string option;
    std::cout << "1. View all todo lists\n";
    std::cout << "2. View todo list contents\n";
    std::cout << "3. Create a todo list\n";
    std::cout << "4. Exit\n";
    std::cout << ">";
    std::cin >> option;

    if (option == "1") {
        bool allTodoListsFileExists = exists(allTodoListsFile);
        if (allTodoListsFileExists) {
            std::string todoLists;
            std::ifstream getAllTodoLists(allTodoListsFile);
            std::cout << "\n";
            while (getline(getAllTodoLists, todoLists)) {
                std::cout << todoLists;
            }

        }
        else {
            std::cout << "Can't find file containing todo lists";
        }
    }
    else if (option == "2") {
        std::string todoListToView;
        std::cout << "\n";
        std::cout << "Enter name of todo list you want to view: ";
        std::cin >> todoListToView;

        bool todoListExists = exists(todoListToView + ".txt");
        if (todoListExists) {
            std::string todoListContents;
            std::ifstream viewTodoList(todoListToView + ".txt");
            std::cout << "\n";
            while (getline(viewTodoList, todoListContents)) {
                std::cout << "\n";
                std::cout << todoListContents;
            }
        }
        else {
            std::cout << "Todo list doesn't seem to exist. Did you type the name correctly?";
        }
    }
    else if (option == "3") {
        std::string newTodoListName;
        int numberOfItems;
        std::cout << "Enter new todo list name: ";
        std::cin >> newTodoListName;
        std::cout << "Enter how many items todo list will have: ";
        std::cin >> numberOfItems;

        std::ofstream newTodoList(newTodoListName + ".txt");

        std::string newItem;
        int i = 0;
        while (i < numberOfItems) {
            std::cout << "Enter todo list item " << i << ": ";
            std::cin >> newItem;
            newTodoList << "[" << i << "]" << " " << newItem << "\n";
            i++;
        }

        /*
        std::fstream f(allTodoListsFile, std::ios::out | std::ios::app);
        f << newTodoListName << "\n";
        */
        std::ofstream ost;
        ost.open(allTodoListsFile, std::ios::out | std::ios::app);
        ost << "\n" << newTodoListName << ", ";
        ost.close();
    }
    else if (option == "4") {
        std::cout << "\n";
        main();
    }
    std::cout << "\n";
    std::cout << "\n";
    todoList();
}