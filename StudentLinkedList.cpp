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
            std::cout << "Added " <<newStudent <<"."<<std::endl;
        }else{
            tailNode->setNextStudent(temp);
            setTailNode(temp);
            numStudents +=1;
            std::cout << "Added " <<newStudent <<"."<<std::endl;
        }
    }else{
        std::cout << "Error: Heap full. Please delete objects before trying "
                     "again." <<std::endl;
    }
}

void StudentLinkedList::printStudents() {
    StudentNode * temp = getHeadNode();
    std::cout << "There are " <<numStudents << " students." <<std::endl;
    std::cout << "Student List: " <<std::endl;
    while (temp!= nullptr){
        std::cout << temp->getStudentName()<<std::endl;
        temp = temp->getNextStudent();
    }
}

void StudentLinkedList::printStudentsClass(std::string &studentName) {
    StudentNode * temp = findStudent(studentName);
    if(temp!= nullptr){
        if(temp->getClassList()!= nullptr){
            std::cout << studentName<< "'s ";
            temp->printClasses();
        }else{
            std::cout << studentName <<" has no classes." <<std::endl;
        }
    }else{
        std::cout<< "Error: Could not find student. Please check spelling and"
                    " try again"<<std::endl;
    }
}

void StudentLinkedList::deleteStudentClasses(std::string &studentName) {
    StudentNode * temp = findStudent(studentName);
    if(temp != nullptr){
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
            StudentNode* prev = deletePtr->getPreviousStudent();
            StudentNode * next = deletePtr->getNextStudent();
            prev->setNextStudent(next);
            next->setPreviousStudent(prev);
            delete deletePtr;
            deletePtr = nullptr;
            numStudents -=1;
            std::cout << "Student deleted." <<std::endl;
        }
    }else{
        std::cout << "Error: Student not found. Please check spelling and try"
                     "again."<<std::endl;
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