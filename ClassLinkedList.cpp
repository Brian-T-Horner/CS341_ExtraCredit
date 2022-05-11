// Class Linked List Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version


// --- Standard Library Includes ---
#include <string>
#include <iostream>

// --- User Defined Includes ---
#include "ClassNode.h"
#include "ClassLinkedList.h"

// --- Constructor ---
ClassLinkedList::ClassLinkedList() {
    headNode = nullptr;
    tailNode = nullptr;
    numClasses = 0;
}

// --- General Methods ---

void ClassLinkedList::addClass(std::string &newClass) {
    if(numClasses < 4){
        ClassNode * temp = new ClassNode;
        if(temp!= nullptr){
            temp->setClassName(newClass);

            if(getHeadNode() == nullptr){
                setHeadNode(temp);
                setTailNode(temp);
                numClasses +=1;
                std::cout << "Added " <<newClass <<"."<<std::endl;
            }else{
                tailNode->setNextClass(temp);
                setTailNode(temp);
                numClasses +=1;
                std::cout << "Added " <<newClass <<"."<<std::endl;
            }
        }else{
            std::cout << "Error: Heap full. Please delete objects before trying "
                         "again." <<std::endl;
        }
    }else{
        std::cout << "Error: Student is at the maximum number of classes. "
                     "Please delete a class and retry." <<std::endl;
    }
}

ClassNode *ClassLinkedList::findClass(std::string &className) {
    ClassNode * temp = headNode;
    while(temp!= nullptr && temp->getClassName() !=className){
        temp=temp->getNextClass();
    }
    return temp;
}

void ClassLinkedList::deleteClass(std::string &className) {
    ClassNode * deletePtr = findClass(className);
    if(deletePtr != nullptr){
        if(headNode == deletePtr){
            headNode = deletePtr->getNextClass();
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "Class deleted."<<std::endl;
        }else if(tailNode == deletePtr){
            tailNode = deletePtr->getNextClass();
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "Class deleted."<<std::endl;
        }else{
            ClassNode * prev = deletePtr->getPreviousClass();
            ClassNode * next = deletePtr->getNextClass();
            prev->setNextClass(next);
            next->setPreviousClass(prev);
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "Class deleted."<<std::endl;
        }
    }else{
        std::cout << "Error: Class not found. Please check spelling and try "
                     "again." <<std::endl;
    }
}


// --- Get Methods ---
ClassNode *ClassLinkedList::getTailNode() {return tailNode;}
ClassNode *ClassLinkedList::getHeadNode() {return headNode;}
int ClassLinkedList::getNumClasses() {return numClasses;}

// --- Set Methods ---
void ClassLinkedList::setTailNode(ClassNode * newTail) {tailNode = newTail;}
void ClassLinkedList::setHeadNode(ClassNode *newHead) {headNode = newHead;}

// --- Destructor ---
ClassLinkedList::~ClassLinkedList() {
    while (headNode != nullptr){
        ClassNode * temp = headNode;
        headNode = temp->getNextClass();
        delete temp;
        temp = nullptr;
    }
}