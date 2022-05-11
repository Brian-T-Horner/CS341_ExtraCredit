// Class Linked List Class Implementation
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version
// 5/10/2022 - Added constructor, get and set methods
// 5/10/2022 - Added general methods for adding, deleting and finding a
// specific class
// 5/10/2022 - Removed general methods and relocated in studentNode class


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

}


// --- Get Methods ---
ClassNode *ClassLinkedList::getTailNode() {return tailNode;}
ClassNode *ClassLinkedList::getHeadNode() {return headNode;}

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