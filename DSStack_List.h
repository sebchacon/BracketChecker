// Implement a stack based on an array.
#ifndef DSLIST_LIST_H
#define DSLIST_LIST_H

#include <string>
#include "DSList.h"

using namespace std;

class DSStack_List{

private:
    DSList<int> data;
public:
    void pop(){ data.pop_front(); }
    void push(char ch){ data.push_front(ch); }
    bool empty(){ return data.empty(); }
    int size(){ return data.size(); }
    char peek(){ return data.front(); }
};

#endif
