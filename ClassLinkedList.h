// Class Linked List Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version


#ifndef CLASSLINKEDLIST_H
#define CLASSLINKEDLIST_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---


class ClassLinkedList {
public:
    // --- Constructor ---
    ClassLinkedList();

    // --- General Methods ---
    void addClass(std::string&);
    void deleteClass(std::string&);
    ClassNode* findClass(std::string&);



    // --- Get Methods ---
    ClassNode * getHeadNode();
    ClassNode * getTailNode();
    int getNumClasses();

    // --- Set Methods ---
    void setHeadNode(ClassNode *);
    void setTailNode(ClassNode *);


    // --- Destructor --
    ~ClassLinkedList();

private:
    ClassNode* headNode{nullptr};
    ClassNode * tailNode{nullptr};
    int numClasses{0};
};


#endif
