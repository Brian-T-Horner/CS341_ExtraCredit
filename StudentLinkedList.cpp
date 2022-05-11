// Student Linked List Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial Version modified from CS341 HW4

// --- Standard Library Includes ---
#include <string>
#include <iostream>
// --- User Defined Includes ---
#include "StudentNode.h"
#include "StudentLinkedList.h"

// --- Constructor ---
StudentLinkedList::StudentLinkedList() {
    headNode= nullptr;
    tailNode = nullptr;
    numStudents = 0;
}

// --- General Methods ---

void StudentLinkedList::addStudent(std::string &newStudent) {
    StudentNode * temp = new StudentNode;
    if(temp != nullptr){
        temp->setStudentName(newStudent);

        if (getHeadNode() == nullptr){
            setHeadNode(temp);
            setTailNode(temp);
            numStudents +=1;
            std::cout << "\nAdded " <<newStudent <<".\n"<<std::endl;
        }else{
            tailNode->setNextStudent(temp);
            setTailNode(temp);
            numStudents +=1;
            std::cout << "\nAdded " <<newStudent <<".\n"<<std::endl;
        }
    }else{
        std::cout << "Error: Heap full. Please delete objects before trying "
                     "again." <<std::endl;
    }
}

void StudentLinkedList::printStudents() {
    StudentNode * temp = getHeadNode();
    if(numStudents == 1){
        std::cout << "\nThere is " <<numStudents << " student.";
    }else{
        std::cout << "\nThere are " <<numStudents << " students.";
    }
    std::cout << " Student List: " <<std::endl;
    while (temp!= nullptr){
        std::cout << temp->getStudentName()<<std::endl;
        temp = temp->getNextStudent();
    }
    std::cout << "\n";
}



void StudentLinkedList::deleteStudentClasses(std::string &studentName) {
    StudentNode * temp = findStudent(studentName);
    if(temp != NULL){
        while(temp->getClassList()!= nullptr){
            ClassNode * classListTemp = temp->getClassList();
            temp->setClassLinkedList(classListTemp->getNextClass());
            delete classListTemp;
            classListTemp = nullptr;
        }
        std::cout << studentName << "'s classes have been deleted."<<std::endl;

    }else{
        std::cout << "Student not found. Please check spelling and try again"
        <<std::endl;
    }
}
StudentNode *StudentLinkedList::findStudent(std::string& studentName) {
    StudentNode * temp = headNode;
    while(temp != nullptr && temp->getStudentName() != studentName){
        temp = temp->getNextStudent();
    }
    return temp;
}

void StudentLinkedList::deleteStudent(std::string & studentName) {
    StudentNode * deletePtr = findStudent(studentName);
    if (deletePtr != nullptr){
        if(headNode == deletePtr){
            headNode = deletePtr->getNextStudent();
            delete deletePtr;
            deletePtr = nullptr;
            numStudents -=1;
            std::cout << "Student deleted." <<std::endl;
        }else if(tailNode == deletePtr){
            tailNode = deletePtr->getPreviousStudent();
            delete deletePtr;
            deletePtr = nullptr;
            numStudents -=1;
            std::cout << "Student deleted." <<std::endl;
        }else{
            StudentNode * nextStudent = deletePtr->getNextStudent();
            StudentNode * previousStudent = deletePtr->getPreviousStudent();

            if(nextStudent != nullptr){
                nextStudent->setPreviousStudent(previousStudent);
            }
            if(previousStudent != nullptr){
                previousStudent->setNextStudent(nextStudent);
            }
            delete findStudent(studentName);
//            deletePtr = nullptr;
            numStudents -=1;
            std::cout << "Student deleted." <<std::endl;
        }
    }else{
        std::cout << "\nError: Student not found. Please check spelling and try"
                     " again.\n"<<std::endl;
    }
}


// --- Get Methods ---
StudentNode *StudentLinkedList::getHeadNode() {return headNode;}
StudentNode *StudentLinkedList::getTailNode() {return tailNode;}
int StudentLinkedList::getNumStudents() {return numStudents;}



// --- Set Methods ---
void StudentLinkedList::setHeadNode(StudentNode * newHead) {headNode = newHead;}
void StudentLinkedList::setTailNode(StudentNode *newTail) {tailNode = newTail;}

// --- Destructor ---
StudentLinkedList::~StudentLinkedList() {
    while (headNode != nullptr){
        StudentNode * temp = headNode;
        headNode = temp->getNextStudent();
        delete temp;
        temp = nullptr;
    }
}