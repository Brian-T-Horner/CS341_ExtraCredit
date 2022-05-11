// Class Node Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4



#ifndef CLASSNODE_H
#define CLASSNODE_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---

class ClassNode {

public:
    ClassNode();

    // Sets
    void setNextClass(ClassNode*);
    void setPreviousClass(ClassNode*);
    void setClassName(std::string&);

    // Gets
    ClassNode* getNextClass();
    ClassNode* getPreviousClass();
    std::string getClassName();

    // Destructor
    ~ClassNode();

private:
    std::string className;
    ClassNode* nextClass{nullptr};
    ClassNode * prevClass{nullptr};

};


#endif
