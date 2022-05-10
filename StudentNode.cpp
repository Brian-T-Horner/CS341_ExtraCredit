// Student Node Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4
// 5/10/2022 - Changed Node name to StudentNode & changed funcs

// --- Standard Library Includes ---
#include <string>
// --- User Defined Includes ---
#include "StudentNode.h"


// --- Constructor ---

StudentNode::StudentNode() {
    studentName = "";
    nextStudent = nullptr;
    //TODO: pointer to class list
}


// --- Set Functions ---
void StudentNode::setNextStudent(StudentNode * nextNode) {nextStudent = nextNode;}
void StudentNode::setStudentName(std::string& newName) {studentName=newName;}
//TODO:: get class list

// --- Get Functions ---
StudentNode *StudentNode::getNextStudent() {return nextStudent;}
std::string StudentNode::getStudentName() {return studentName;}
//TODO: Set class list