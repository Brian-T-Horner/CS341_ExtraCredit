// Student Node Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4
// 5/10/2022 - Changed Node name to StudentNode & changed funcs

// --- Standard Library Includes ---
#include <string>
#include <iostream>
// --- User Defined Includes ---
#include "StudentNode.h"


// --- Constructor ---

StudentNode::StudentNode() {
    studentName = "";
    nextStudent = nullptr;
    previousStudent = nullptr;
    classList = nullptr;
    numClasses = 0;
}

// --- Add classes method ---


// --- Delete classes method ---
void StudentNode::deleteClasses() {
    while(classList!= nullptr){
        ClassNode * classListTemp = classList;
        setClassLinkedList(classListTemp->getNextClass());
        delete classListTemp;
        classListTemp = nullptr;
        numClasses-=1;
    }
    std::cout << studentName <<"'s classes have been deleted."<<std::endl;
}

// --- Print classes method ---
void StudentNode::printClasses() {
    ClassNode * temp = classList;
    std::cout << "Classes: " <<std::endl;
    while (temp != nullptr){
        std::cout << temp->getClassName() <<std::endl;
        temp = temp->getNextClass();
    }
}

// --- Set Functions ---
void StudentNode::setNextStudent(StudentNode * nextNode) {nextStudent = nextNode;}
void StudentNode::setStudentName(std::string& newName) {studentName=newName;}
void StudentNode::setPreviousStudent(StudentNode *previousNode){previousStudent=previousNode;}
void StudentNode::setClassLinkedList(ClassNode *classHead){classList=classHead;}

// --- Get Functions ---
StudentNode *StudentNode::getNextStudent() {return nextStudent;}
std::string StudentNode::getStudentName() {return studentName;}
StudentNode* StudentNode::getPreviousStudent() {return previousStudent;}
ClassNode* StudentNode::getClassList() {return classList;}
int StudentNode::getNumberClasses() {return numClasses;}

// --- Destructor ---
StudentNode::~StudentNode() {
    deleteClasses();
}