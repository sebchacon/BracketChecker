#include "BracketChecker.h"
#include <iostream>
#include <cstring>

bool BracketChecker::StackCheck(char *stackFile)
{
    DSStack stack; // initialize stack array object

    FILE *stream;                  // open our file using cstring method
    char buffer[1000];
    stream = fopen(stackFile, "r");

    int count = 1; // line count for proper error messaging 

    while (fgets(buffer, sizeof(buffer), stream) != NULL) // while not eof
    {
        char *line = buffer;
        size_t size = strlen(line);

        for (size_t i = 0; i <= size; ++i) //loop through every line, every character to find brackets open or closed
        {
            if (line[i] == '/' && line[i + 1] == '/') //if comment bars, break line 
            {
                break;
            }

            if (line[i] == '{') //if open push
            {
                stack.push('{');
            }
            if (line[i] == '[')// ^
            {
                stack.push('[');
            }
            if (line[i] == '(') //^
            {
                stack.push('(');
            }
            if (line[i] == '}') //if closed, check for stack emptiness, closed matchup, otherwise pop and continue
            {
                if (stack.empty())
                {
                    std::cout << "Stack is empty...Bracket Mismatch on line " << count << " for bracket '{'" << std::endl;
                    fclose(stream);
                    return false;
                }
                if ('{' != stack.peek())
                {
                    std::cout << "Bracket Mismatch { on line " << count << std::endl;
                    std::cout << "Peak stack is: " << stack.peek() << ", for bracket: '{'" << std::endl;
                    fclose(stream);
                    return false;
                }
                stack.pop();
                // std::cout<< "Popped } on line " << count <<std::endl;
            }
            if (line[i] == ')') //^
            {
                if (stack.empty())
                {
                    std::cout << "Stack is empty...Bracket Mismatch on line " << count << " for bracket '('" << std::endl;
                    fclose(stream);
                    return false;
                }
                if ('(' != stack.peek())
                {
                    std::cout << "Bracket Mismatch ( on line " << count << std::endl;
                    std::cout << "Peak stack is: " << stack.peek() << ", for bracket: '('" << std::endl;

                    fclose(stream);
                    return false;
                }
                stack.pop();
            }
            if (line[i] == ']') //^
            {
                if (stack.empty())
                {
                    std::cout << "Stack is empty...Bracket Mismatch on line " << count << " for bracket '['" << std::endl;
                    fclose(stream);
                    return false;
                }
                if ('[' != stack.peek())
                {
                    std::cout << "Bracket Mismatch [ on line " << count << std::endl;
                    std::cout << "Peak stack is: " << stack.peek() << ", for bracket: '['" << std::endl;
                    fclose(stream);
                    return false;
                }
                stack.pop();
            }
        }
        ++count;
    }
    fclose(stream);
    if (stack.empty()) //at end of file, if stack is empty all brackets match up, return good line and break, otherwise return bad line and break
    {
        std::cout << "File checks out..." << std::endl;
        return true;
    }
    else
    {
        std::cout<< "Stack not empty at finish...Bracket Mismatch" << std::endl;
        return false;
    }
}

bool BracketChecker::ListCheck(char *listFile)
{
    DSStack_List list; //initalize linked list object

    FILE *stream;                 //open file using cstring method
    char buffer[1000];
    stream = fopen(listFile, "r");
    int count = 1;

    while (fgets(buffer, sizeof(buffer), stream) != NULL) // while not eof
    {
        char *line = buffer;
        size_t size = strlen(line);

        for (size_t i = 0; i < size; ++i)
        {
            if (line[i] == '/' && line[i + 1] == '/') //check for comment bars, break line if found
            {
                break;
            }
            if (line[i] == '{') //if open, push
            {
                list.push('{');
            }
            if (line[i] == '[')//^
            {
                list.push('[');
            }

            if (line[i] == '(')//^
            {
                list.push('(');
            }
            if (line[i] == '}') //if closed bracket, check list head for open of same type, otherwize break
            {
                if (list.empty())
                {
                    std::cout << "List is empty...Bracket Mismatch on line " << count << " for bracket '{'" << std::endl;
                    fclose(stream);
                    return false;
                }
                if ('{' != list.peek())
                {
                    std::cout << "Bracket Mismatch { on line " << count << std::endl;
                    fclose(stream);
                    return false;
                }
                list.pop();
            }
            if (line[i] == ')')
            {
                if (list.empty())
                {
                    std::cout << "List is empty...Bracket Mismatch on line " << count << " for bracket '('" << std::endl;
                    fclose(stream);
                    return false;
                }
                if ('(' != list.peek())
                {
                    std::cout << "Bracket Mismatch ( on line " << count << std::endl;
                    fclose(stream);
                    return false;
                }
                list.pop();
            }
            if (line[i] == ']')
            {
                if (list.empty())
                {
                    std::cout << "List is empty...Bracket Mismatch on line " << count << " for bracket '['" << std::endl;
                    fclose(stream);
                    return false;
                }

                if ('[' != list.peek())
                {
                    std::cout << "Bracket Mismatch [ on line " << count << std::endl;
                    fclose(stream);
                    return false;
                }
                list.pop();
            }
        }
        ++count;
    }
    fclose(stream);
    if (list.empty())
    {
        std::cout << "File checks out..." << std::endl;
        return true;
    }
    else
    {
        std::cout<< "List not empty at finish...Bracket Mismatch" << std::endl;
        return false;
    }
}