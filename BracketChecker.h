#ifndef BRACKETCHECKER_H
#define BRACKETCHECKER_H

#include <iostream>
#include "DSStack_List.h"
#include "DSStack.h"

class BracketChecker{
public:
    BracketChecker() = default;
    bool StackCheck(char*);
    bool ListCheck(char*);
};

#endif