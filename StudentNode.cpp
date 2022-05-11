// Student Node Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4
// 5/10/2022 - Changed Node name to StudentNode & changed funcs
// 5/10/2022 - Added constructor, get and set methods
// 5/10/2022 - Added general methods for adding, deleting and finding a
// specific class from classlinkedlist

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
    numClasses = 0;
}

// --- Add classes method ---
void StudentNode::addClass(std::string &newClass) {
    if(numClasses < 4){
        ClassNode * temp = new ClassNode;
        if(temp!= nullptr){
            temp->setClassName(newClass);
            if(classList.getHeadNode() == nullptr){
                classList.setHeadNode(temp);
                classList.setTailNode(temp);
                numClasses +=1;
                std::cout << "\nAdded " <<newClass <<".\n"<<std::endl;
            }else{
                classList.getTailNode()->setNextClass(temp);
                classList.setTailNode(temp);
                numClasses +=1;
                std::cout << "\nAdded " <<newClass <<".\n"<<std::endl;
            }
        }else{
            std::cout << "Error: Heap full. Please delete objects before trying "
                         "again." <<std::endl;
        }
    }else{
        std::cout << "\nError: Student is at the maximum number of classes. "
                     "Please delete a class and retry.\n" <<std::endl;
    }
}

// --- Find Class ---
ClassNode * StudentNode::findClass(std::string &className) {
    ClassNode * temp = classList.getHeadNode();
    while(temp!= nullptr && temp->getClassName() !=className){
        temp=temp->getNextClass();
    }
    return temp;
}

// --- Delete specific class
void StudentNode::deleteClass(std::string &className) {
    ClassNode * deletePtr = findClass(className);
    if(deletePtr != nullptr){
        if(classList.getHeadNode() == deletePtr){
            classList.setHeadNode(deletePtr->getNextClass());
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "\nClass deleted.\n"<<std::endl;
        }else if(classList.getTailNode() == deletePtr){
            classList.setTailNode(deletePtr->getNextClass());
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "\nClass deleted.\n"<<std::endl;
        }else{
            ClassNode * prev = deletePtr->getPreviousClass();
            ClassNode * next = deletePtr->getNextClass();
            prev->setNextClass(next);
            next->setPreviousClass(prev);
            delete deletePtr;
            deletePtr = nullptr;
            numClasses -=1;
            std::cout << "\nClass deleted.\n"<<std::endl;
        }
    }else{
        std::cout << "\nError: Class not found. Please check spelling and try "
                     "again.\n" <<std::endl;
    }
}




// --- Delete classes method ---
void StudentNode::deleteClasses() {
    while(classList.getHeadNode()!= nullptr){
        ClassNode * classListTemp = classList.getHeadNode();
        classList.setHeadNode(classListTemp->getNextClass());
        delete classListTemp;
        classListTemp = nullptr;
        numClasses-=1;
    }
    std::cout << studentName <<"'s classes have been deleted."<<std::endl;
}

// --- Print classes method ---
void StudentNode::printClasses() {
    ClassNode * temp = classList.getHeadNode();
    std::cout << "\nClasses: " <<std::endl;
    while (temp != nullptr){
        std::cout << temp->getClassName() <<std::endl;
        temp = temp->getNextClass();
    }
    std::cout << "\n"<<std::endl;
}

// --- Set Functions ---
void StudentNode::setNextStudent(StudentNode * nextNode) {this->nextStudent =
nextNode;}
void StudentNode::setStudentName(std::string& newName) {studentName=newName;}
void StudentNode::setPreviousStudent(StudentNode *previousNode)
{this->previousStudent=previousNode;}

void StudentNode::setClassLinkedList(ClassNode *newHead) {classList
.setHeadNode(newHead);}


// --- Get Functions ---
StudentNode *StudentNode::getNextStudent() {return nextStudent;}
std::string StudentNode::getStudentName() {return studentName;}
StudentNode* StudentNode::getPreviousStudent() {return previousStudent;}
int StudentNode::getNumberClasses() {return numClasses;}

ClassNode *StudentNode::getClassList() {return classList.getHeadNode();}

// --- Destructor ---
StudentNode::~StudentNode() {
    deleteClasses();
}