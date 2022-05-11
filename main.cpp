// CS341 - Extra Credit
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial Version

// --- Standard Library Includes ---
#include <iostream>
#include <vector>


// --- User Built Includes ---
#include "StudentLinkedList.h"
#include "ClassLinkedList.h"
#include "StudentNode.h"


void run(StudentLinkedList&);
void studentsEdits(StudentLinkedList&);
void classesEdits(StudentLinkedList&);
bool checkClassInput(std::string&);
void fixCase(std::string&);

int main() {
    StudentLinkedList studentList;
    run(studentList);
    return 0;
}





void run(StudentLinkedList& studentList){
    char mainSelection;
    bool on = true;
    while(!std::cin.eof() && std::cin.good() && on){
        std::cout << "Please use the designated character to interact with "
                     "the menu." <<std::endl;
        std::cout << "Enter students menu (S) or enter classes menu (C).";
        std::cout << "To exit the menu (X):  ";
        std::cin >> mainSelection;
        if(!std::cin.eof() && std::cin.good()){
            switch(mainSelection){
                case 'S': case 's':{
                    studentsEdits(studentList);
                    break;
                }case 'C': case 'c':{
                    classesEdits(studentList);
                    break;
                }case 'X': case 'x':{
                    std::cout << "\nExiting program."<<std::endl;
                    on = false;
                    break;
                }default: {
                    std::cout << "\nInvalid input entered."<<std::endl;
                    break;
                }
            }
        }
    }
}

void classesEdits(StudentLinkedList& studentList){
    char modeSelection;
    bool on = true;
    std::string studentName;
    while(!std::cin.eof() && on){
        std::cout << "\nEntered the classes menu."<<std::endl;
        while(!std::cin.eof() && std::cin.good()){
            std::cout << "Enter your function with the designated "
                         "character."<<std::endl;
            std::cout << "Add Class (A), Delete Class (D), Print "
                         "Student's Classes (P), Exit (X):  ";
            std::cin >> modeSelection;
                if (!std::cin.eof() && std::cin.good()){
                    switch (modeSelection){
                        case 'A': case 'a':{
                            std::cout << "\nEnter the student's name you'd like"
                                         " to edit:  " <<std::endl;
                            std::cin>>studentName;
                            fixCase(studentName);
                            StudentNode * student = studentList.findStudent(studentName);
                            if(student != nullptr){
                                std::cout << "The accepted classes to enter are \"French\", \"History\", \"Mathematics\", \"Biology\","
                                             "\"Literature\", \"German\", \"Italian\", \"Physics\","
                                             "\"Chemistry\", \"Drama\", "
                                             "\"Education\"."<<std::endl;
                                std::cout << "\nPlease enter your class "
                                             "selection:  ";
                                std::string className;
                                std::cin >>className;
                                fixCase(className);
                                if(!std::cin.eof() && std::cin.good()){
                                    if(checkClassInput(className)){
                                        student->addClass(className);
                                    }else{
                                        std::cout << "\nClass name invalid. "
                                                     "Please "
                                                     "check spelling and try "
                                                     "again.\n";
                                    }
                                }
                            }else{
                                std::cout << "\nError: Invalid student name. "
                                             "Please try again.\n"
                                <<std::endl;
                            }
                            break;
                        }case 'D': case 'd':{
                            std::string deleteClass;
                            std::cout << "\nEnter the student's name you'd like"
                                         " to edit:  " <<std::endl;
                            std::cin>>studentName;
                            fixCase(studentName);
                            StudentNode * student = studentList.findStudent(studentName);
                            if(student != nullptr){
                                std::cout << "\nPlease enter the class to "
                                             "delete:  ";
                                std::cin >> deleteClass;
                                if(!std::cin.eof() && std::cin.good()){
                                    student->deleteClass(deleteClass);
                                }
                            }else{
                                std::cout << "\nError: Invalid student name. "
                                             "Please try again.\n"
                                <<std::endl;
                            }
                            break;
                        }case 'P': case 'p':{
                            std::cout << "\nEnter the student's name you'd like"
                                         " to edit:  " <<std::endl;
                            std::cin>>studentName;
                            fixCase(studentName);
                            StudentNode * student = studentList.findStudent(studentName);
                            if(student != nullptr){
                                student->printClasses();
                            }else{
                                std::cout << "\nError: Invalid student name. "
                                             "Please try again.\n"<<std::endl;
                            }
                            break;
                        }case 'X': case 'x':{
                            on = false;
                            std::cout << "\nExiting classes menu.\n"
                            <<std::endl;
                            break;
                        }default:{
                            std::cout << "\nInvalid input entered"
                                         ".\n"<<std::endl;
                            break;
                        }
                    }
                }
            }


        }
    }




void studentsEdits(StudentLinkedList& studentList){
    char modeSelection;
    bool on = true;
    std::cout << "\nEntered the student menu." <<std::endl;
    while(!std::cin.eof() && std::cin.good() && on){
    std::cout << "Enter your function with the designated character"
                 "."<<std::endl;
    std::cout <<"Add Student (A), Print Students (P), Delete Students (D), "
                "Erase Student Classes (E), Exit (X):  ";
    std::cin >> modeSelection;
    if(!std::cin.eof() && std::cin.good()){
        switch (modeSelection){
            case 'A': case 'a':{
                std::string addName;
                std::cout << std::endl;
                std::cout << "\nPlease enter student's name to add:  ";
                std::cin >> addName;
                fixCase(addName);
                if(!std::cin.eof() && std::cin.good()){
                    studentList.addStudent(addName);
                }
                break;
            }case 'P': case 'p':{
                studentList.printStudents();
                break;
            }case 'D': case 'd':{
                std::string deleteName;
                std::cout << "\nPlease enter student's name to delete: ";
                std::cin>>deleteName;
                fixCase(deleteName);
                if(!std::cin.eof() && std::cin.good()){
                    studentList.deleteStudent(deleteName);
                }
                break;
            }case 'E': case 'e':{
                std::string eraseName;
                std::cout << "\nPlease enter student's name to delete their "
                             "classes: ";
                std::cin >> eraseName;
                fixCase(eraseName);
                if(std::cin.eof() && std::cin.good()){
                    studentList.deleteStudentClasses(eraseName);
                }
                break;
            }case 'X': case 'x':{
                on = false;
                std::cout << "\nExiting student menu.\n" <<std::endl;
                break;
            }default:{
                std::cout << "\nInvalid input entered.\n"<<std::endl;
                break;
            }
        }
    }
    }
}


bool checkClassInput(std::string& newClass){
    bool accepted = false;
    std::vector<std::string> acceptedClasses {
        "French", "History", "Mathematics", "Biology",
        " Literature", "German", "Italian",     "Physics",
        "Chemistry", "Drama", "Education"};

    for(const std::string& i: acceptedClasses){
        if (i == newClass){
            accepted = true;
        }
    }
    return accepted;
}


void fixCase(std::string& stringInput){
    int stringLength = stringInput.length();
    for (int i{0}; i<stringLength; i++){
        if(i == 0){
            stringInput[i] = std::toupper(stringInput[i]);
        }else{
            stringInput[i] = std::tolower(stringInput[i]);
        }

    }
}