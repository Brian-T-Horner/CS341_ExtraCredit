// Student Node Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4
// 5/10/2022 - Changed to basic student node class
// 5/10/2022 - Added constructor, get and set methods
// 5/10/2022 - Added general methods for adding, deleting and finding a
// specific class from classlinkedlist

#ifndef STUDENTNODE_H
#define STUDENTNODE_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---
#include "ClassNode.h"
#include "ClassLinkedList.h"


class StudentNode {

public:
    StudentNode ();

    // Classes Methods
     void addClass(std::string &);
     void printClasses();
     void deleteClasses();
     void deleteClass(std::string&);
     ClassNode* findClass(std::string&);

    // Sets
    void setNextStudent(StudentNode*);
    void setPreviousStudent(StudentNode*);
    void setStudentName(std::string&);
    void setClassLinkedList(ClassNode*);



    // Gets
    StudentNode* getNextStudent();
    StudentNode* getPreviousStudent();
    std::string getStudentName();
    int getNumberClasses();
    ClassNode* getClassList();

    // Destructor
    ~StudentNode();



private:
    std::string studentName;
    StudentNode* nextStudent{nullptr};
    StudentNode* previousStudent{nullptr};
    int numClasses{0};
    ClassLinkedList classList;



};

#endif
