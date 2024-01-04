#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <iostream>
#include "DSList.h"

TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)

    DSList<char> list;

    list.push_front('[');
    list.push_front('{');
    list.push_front('(');

    std::cout<< "Length is: " << list.size() << std::endl;
    REQUIRE(list.size() == 3);
    std::cout<< "Is it empty? " << list.empty() << std::endl;
    REQUIRE(list.empty() == 0);
    std::cout<< "Front element is: " << list.front() <<std::endl;
    REQUIRE(list.front() == '(');

    list.pop_front();
    std::cout<< "Front element is: " << list.front() <<std::endl;
    REQUIRE(list.front() == '{');
    list.push_back('(');

    list.pop_back();

    list.clear();

    std::cout<< "Is it empty? " << list.empty() << std::endl;
    REQUIRE(list.empty() == 1);
    //std::cout<< "Front element is: " << list.front() <<std::endl;

    REQUIRE(0 + 1 == 1);
    // This creates an error
    // REQUIRE(0 == 1);
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 