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
    StudentNode * newNode = new StudentNode;
    if(newNode != nullptr){
        newNode->setStudentName(newStudent);
        if(getHeadNode() == nullptr){
            // If there is no node in linked list
            setHeadNode(newNode);
            setTailNode(newNode);
            numStudents +=1;
        }else if (getHeadNode()!= nullptr){
            // If there is a head node
            if (headNode->getStudentName() < newNode->getStudentName()){
                // If head node is less than new node
                if(headNode == tailNode){
                    // If there is only one node in the list
                    headNode->setNextStudent(newNode);
                    newNode->setPreviousStudent(headNode);
                    setTailNode(newNode);
                    numStudents +=1;
                }else if (headNode != tailNode){
                    // If there is more than one node in the list
                    StudentNode * comparison = headNode;
                    // Sort through until temp node is less than comparison
                    while (comparison->getNextStudent()!= nullptr &&
                    comparison->getNextStudent()->getStudentName() < newNode->getStudentName()){
                        comparison = comparison->getNextStudent();
                    }

                    // Setting temp next node to comparison next node
                    newNode->setNextStudent(comparison->getNextStudent());
                    // setting comparison next to new node
                    comparison->setNextStudent(newNode);
                    // setting new node previous to comparison node
                    newNode->setPreviousStudent(comparison);
                    numStudents +=1;
                }
            }else if(headNode->getStudentName() > newNode->getStudentName()){
                // If new node is less than head node
                newNode->setNextStudent(headNode);
                headNode->setPreviousStudent(newNode);
                setHeadNode(newNode);
                numStudents +=1;
            }

        }
    }else{
        // Catch for if out of heap memory
        std::cout << "Error: Out of heap memory for node objects." <<std::endl;
    }

}
//    StudentNode * temp = new StudentNode;
//    if(temp != nullptr){
//        temp->setStudentName(newStudent);
//
//
//        if (getHeadNode() == nullptr){ // If there is no node in list
//            setHeadNode(temp);
//            setTailNode(temp);
//            numStudents +=1;
//            std::cout << "\nAdded " <<newStudent <<".\n"<<std::endl;
//        }else if(headNode != nullptr){ // If there is a head node
//            if(headNode == tailNode){ // if only one node in list
//                setTailNode(temp);
//                headNode->setNextStudent(temp);
//                numStudents +=1;
//                std::cout << "\nAdded " <<newStudent <<".\n"<<std::endl;
//            }else if (headNode != tailNode){ // If there is more than one
//                StudentNode * oldTail = tailNode;
//                tailNode->setNextStudent(temp);
//                setTailNode(temp);
//                tailNode->setPreviousStudent(oldTail);
//                numStudents +=1;
//                std::cout << "\nAdded " <<newStudent <<".\n"<<std::endl;
//            }
//        }
//    }else{
//        std::cout << "Error: Heap full. Please delete objects before trying "
//                     "again." <<std::endl;
//    }
//}

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

        // If there are no nodes
        if(headNode == nullptr){
            std::cout << "\nNo students to delete.\n" <<std::endl;
        }else if(headNode!= nullptr){
            // If there is one node
            if(headNode == tailNode && headNode == deletePtr){
                // one node and it equals
                headNode = nullptr;
                tailNode = nullptr;
                numStudents -=1;
                delete deletePtr;
                deletePtr = nullptr;
                std::cout << "\nStudent deleted."<<std::endl;
            }else if(headNode ==tailNode && headNode != deletePtr){
                // if there is one node and it does not equal
                std::cout << "\nStudent not found. Please check spelling and "
                             "try again." <<std::endl;
            }else if (headNode != tailNode){
                StudentNode* previousNode = deletePtr->getPreviousStudent();
                StudentNode* nextNode = deletePtr->getNextStudent();

                if(nextNode != nullptr){
                    previousNode->setNextStudent(nextNode);
                }else if(nextNode == nullptr){
                    std::cout << "Next node equal to null" <<std::endl;
                }
                if(previousNode != nullptr){
                    nextNode->setPreviousStudent(previousNode);
                }else if (previousNode == nullptr){
                    std::cout << "Previous node equal to null" <<std::endl;
                }
                delete deletePtr;
            }
        }



        // If there are more than one node
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
            StudentNode * prev = deletePtr->getPreviousStudent();
            StudentNode*  next = deletePtr->getNextStudent();

            prev->setNextStudent(next);
            next->setPreviousStudent(prev);


            delete deletePtr;
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