// Student Node Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4
// 5/10/2022 - Changed to basic student node class

#ifndef STUDENTNODE_H
#define STUDENTNODE_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---
#include "ClassNode.h"


class StudentNode {

public:
    StudentNode ();

    // Classes Methods
    // Add classes method???
     void printClasses();
     void deleteClasses();

    // Sets
    void setNextStudent(StudentNode*);
    void setPreviousStudent(StudentNode*);
    void setStudentName(std::string&);
    void setClassLinkedList(ClassNode*);


    // Gets
    StudentNode* getNextStudent();
    StudentNode* getPreviousStudent();
    std::string getStudentName();
    ClassNode * getClassList();
    int getNumberClasses();

    // Destructor
    ~StudentNode();

private:
    std::string studentName;
    StudentNode* nextStudent{nullptr};
    StudentNode* previousStudent{nullptr};
    ClassNode * classList{nullptr};
    int numClasses{0};



};

#endif
