#include <iostream>
#include <algorithm>
#include <chrono>
#include "BracketChecker.h" 


// To test the 2 seperately, I commented out the if else blocks of one or the other. If looking to 
// test both just uncomment 1 or the other. 


int main (int argc, char **argv)
{
    BracketChecker bracket;

    std::cout << "Checking Files: " << std::endl;

    for(int i = 1; i < argc; ++i) 
    {
        // if(bracket.ListCheck(argv[i]) == false)
        // {
        //     std::cout<< "File " << i << " bracket mismatch, terminating program..." <<std::endl;
        //     //return 1;
        // }
        // else    
        //     std::cout<< "File " << i << " brackets check out, moving on..." << std::endl;

        if(bracket.StackCheck(argv[i]) == false)
        {
            std::cout<< "File " << i << " bracket mismatch, terminating program..." <<std::endl;
            return 1;
        }
        else    
            std::cout<< "File " << i << " brackets check out, moving on..." << std::endl;
    }
    std::cout<< "If you're reading this your files are good..." << std::endl;
    // A return code != 0 tells the operating system that there is an issue.
    return 0;
}


// // in the terminal type `cd build` and then `./check_brackets test_data/*`