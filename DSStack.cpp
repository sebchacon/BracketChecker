 #include "DSStack.h"
#include <array>
#include <cstring>

DSStack::DSStack() //constructor 
{
    data = new char[100];
    top = 0;
}

DSStack::DSStack(const DSStack &x) // copy costructor
{
    top = x.top;
    strcpy(data, x.data);
}

DSStack::~DSStack() //delete operator
{
    delete[] data;
}

void DSStack::pop() // "remove" function, slides variable one slot down
{
    --top;
}

void DSStack::push(char x) //slides top variable one slot up
{
    data[top] = x;
    ++top;
}

bool DSStack::empty() //returns bool on top variable location in stack
{
    if( top <= 0)
        return true;
    else  
        return false;
}
int DSStack::size() //returns length
{
    return top;
}
char DSStack::peek() // returns top variable without deleting it
{
    return data[top - 1];
}