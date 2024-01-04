// Implement a stack based on an array.
#ifndef DSSTACK_H
#define DSSTACK_H

#include <string>

using namespace std;


class DSStack{

private:
    char* data; //char* holding our brackets
    int top; //top variable sliding across the index of chars representing top of stack to peek, push, pop
public:
    DSStack();
    DSStack(const DSStack &);
    DSStack& operator=(const DSStack&);
    ~DSStack();

    void pop();
    void push(char);
    bool empty();
    int size();
    char peek();

};

#endif
