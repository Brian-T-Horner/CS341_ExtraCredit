// Student Linked List Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial Version modified from CS341 HW4



#ifndef STUDENTLINKEDLIST_H
#define STUDENTLINKEDLIST_H

// --- Standard Library Includes ---

// --- User Defined Includes ---

class StudentLinkedList {

public:
    // --- Constructor ---
    StudentLinkedList();

    // --- General Methods ---
    void addStudent(std::string&);
    StudentNode* findStudent(std::string&);

    // --- Print Methods ---
    void printStudents();
    void printStudentsClass(std::string&);


    // --- Deletion Methods ---
    void deleteStudent(std::string&);
    void deleteStudentClasses(std::string&);


    // --- Get Methods ---
    StudentNode* getHeadNode();
    StudentNode* getTailNode();
    int getNumStudents();


    // --- Set Methods ---
    void setHeadNode(StudentNode*);
    void setTailNode(StudentNode*);


    // --- Destructor ---
    ~StudentLinkedList();

private:
    StudentNode* headNode{nullptr};
    StudentNode* tailNode{nullptr};
    int numStudents;

};


#endif
