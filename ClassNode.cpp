// Class Node Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4

// --- Standard Library Includes ---
#include <string>
// --- User Defined Includes ---
#include "ClassNode.h"


// --- Constructor ---
ClassNode::ClassNode() {
    className = "";
    nextClass = nullptr;
}

// --- Set Functions ---
void ClassNode::setClassName(std::string & newName) {className=newName;}
void ClassNode::setNextClass(ClassNode * nextNode){nextClass=nextNode;}

// --- Get Functions ---
std::string ClassNode::getClassName() {return className;}
ClassNode *ClassNode::getNextClass() {return nextClass;}