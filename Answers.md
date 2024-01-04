# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Sebastian Chacon

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[x] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   For the List implementation the program took 2-3 seconds to check all files while the stack took about 3 on average. The times should be very similar due to the same run complexity of neither having to search or iterate through the active brackets. Since we are just popping the front object every time there should be very similar run times. 

2. Discuss the difference in memory usage based on **your** implementation.

   For both the stack stack and stack list they are using pointers to properly manage our memory for the active brackets. Similar to DSString in my Tweet Sentiment Analysis project, I used a char* that would manipulate a char* for the use we needed it for. For the List since we are doing a linked list it of courses uses more memory slots so we used pointers for that as well based off of the DSList we did in class for memory management. 

3. Which version would you use in practice. Why?

   I would use the Stack List that utilizes a linked list because my stack stack implementation is not as refined for practical use. What I digress is that the stack array implementation simply makes an array with size of one hundred and the "top" variable is merely shifted up and down based off pops and pushes compared to the classier linked list that creates nodes with pointer implementation linking them. This also does not restrict the size of how many open brackets I can have at one time.

4. Make sure that your stack implementations does not have memory leaks.

   DSList implementation
   ```
   Checking Files: 
List is empty...Bracket Mismatch on line 179 for bracket '{'
File 1 bracket mismatch, terminating program...
List not empty at finish...Bracket Mismatch
File 2 bracket mismatch, terminating program...
File checks out...
File 3 brackets check out, moving on...
Checking all files took 42 milliseconds
If you're reading this your files are good...
==42475== 
==42475== HEAP SUMMARY:
==42475==     in use at exit: 0 bytes in 0 blocks
==42475==   total heap usage: 309 allocs, 309 frees, 79,288 bytes allocated
==42475== 
==42475== All heap blocks were freed -- no leaks are possible
==42475== 
==42475== For lists of detected and suppressed errors, rerun with: -s
==42475== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
   

   DSStack
   ```
   Checking Files: 
Stack is empty...Bracket Mismatch on line 179 for bracket '{'
File 1 bracket mismatch, terminating program...
Stack not empty at finish...Bracket Mismatch
File 2 bracket mismatch, terminating program...
File checks out...
File 3 brackets check out, moving on...
Checking all files took 37 milliseconds
If you're reading this your files are good...
==42711== 
==42711== HEAP SUMMARY:
==42711==     in use at exit: 0 bytes in 0 blocks
==42711==   total heap usage: 7 allocs, 7 frees, 74,708 bytes allocated
==42711== 
==42711== All heap blocks were freed -- no leaks are possible
==42711== 
==42711== For lists of detected and suppressed errors, rerun with: -s
==42711== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   None, other than single line commenting. 
