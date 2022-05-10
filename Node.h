// Node Class Specification
//
// Author: Brian Horner
// Edit History:
// 5/10/2022 - Initial version modified from CS341 HW4

#ifndef NODE_H
#define NODE_H

// --- Standard Library Includes ---
#include <string>

// --- User Defined Includes ---



class Node {
public:
    Node ();



    // Sets
    void setNextPointer(Node*);
    void setData(std::string&);

    // Gets
    Node* getNextPointer();
    std::string getData();


private:
    std::string data;
    Node* next{nullptr};

};

#endif
