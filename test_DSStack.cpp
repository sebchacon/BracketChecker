#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack.h"
#include <iostream>

TEST_CASE("Check that DSStack works", "[DSStack]")
{
    // add test cases (create lists and specify what the expected output is)
    DSStack stack;

    stack.push('(');
    stack.push('{');
    stack.push('[');

    std::cout<< stack.peek() << std::endl;
    std::cout<< "Is stack empty? " << stack.empty() << std::endl;
    REQUIRE(stack.empty() == 0);

    std::cout<< "Size: " << stack.size() << std::endl;
    REQUIRE(stack.size() == 3);

    stack.pop();
    REQUIRE(stack.size() == 2);

    std::cout<< "Popped 1, new Size: " << stack.size() << std::endl;

    if(stack.empty() == 1)
        std::cout << "List is empty, false" << std::endl;
    else  
        std::cout<< "List has elements: " << stack.size() << std::endl;
    
    while( ! stack.empty()){
        std::cout<< stack.peek() << std::endl;
        stack.pop();
    }
    REQUIRE(stack.empty() == 1);

    REQUIRE(0 + 1 == 1);
    // This creates an error
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 