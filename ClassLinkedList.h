// Class Linked List Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version
// 5/10/2022 - Added constructor, get and set methods
// 5/10/2022 - Added general methods for adding, deleting and finding a
// specific class
// 5/10/2022 - Removed general methods and relocated in studentNode class


#ifndef CLASSLINKEDLIST_H
#define CLASSLINKEDLIST_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---


class ClassLinkedList {
public:
    // --- Constructor ---
    ClassLinkedList();

    // --- Get Methods ---
    ClassNode * getHeadNode();
    ClassNode * getTailNode();


    // --- Set Methods ---
    void setHeadNode(ClassNode *);
    void setTailNode(ClassNode *);


    // --- Destructor --
    ~ClassLinkedList();

private:
    ClassNode* headNode{nullptr};
    ClassNode * tailNode{nullptr};
};


#endif
