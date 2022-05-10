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
#include "ClassLinkedList.h"


class StudentNode {

public:
    StudentNode ();

    // Sets
    void setNextStudent(StudentNode*);
    void setStudentName(std::string&);
    void setClassLinkedList(ClassLinkedList*);

    // Gets
    StudentNode* getNextStudent();
    std::string getStudentName();
    //TODO:: Set class list


private:
    std::string studentName;
    StudentNode* nextStudent{nullptr};
    Class


};

#endif
