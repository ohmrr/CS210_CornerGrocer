# CS 210 Project Three: Corner Grocer Item Tracking Program

## Project Summary

This project was created for the Corner Grocer scenario in CS 210. The program reads a text file containing a list of grocery items purchased throughout the day and analyzes how often each item appears. The main problem it solves is helping the store understand item purchase frequency so they can make better decisions about how to organize their produce section.

The program gives the user a menu with four choices. The user can search for the frequency of one specific item, print a full list of every item and its frequency, print a text-based histogram of all item frequencies, or exit the program. The program also automatically creates a backup file called `frequency.dat` that stores each item and its frequency.

## What I Did Well

One thing I think I did well was organizing the program into a class instead of putting everything directly into `main()`. This made the program easier to read and made each part of the program responsible for a specific task. I also used a map to store the grocery items and their counts, which was a good fit because each item name could be paired with its frequency.

I also made sure the menu was clear and that the program could handle the different user options correctly. The histogram output was another part I thought worked well because it makes the frequency data easier to understand visually instead of only showing numbers.

## Where I Could Enhance the Code

One way I could improve the code would be to make the file names more flexible. Right now, the program expects the input file to have a specific name. In a larger application, I could allow the user to enter the file name or use a configuration file. This would make the program more adaptable.

I could also improve the input validation even more. The current program handles menu choices, but a more advanced version could include stronger error handling for missing files, empty files, or unusual input. These improvements would make the program more secure and reliable because it would be better prepared for unexpected situations.

## Challenges and How I Overcame Them

The most challenging part of this project was making sure the file input, map storage, and menu functions all worked together correctly. I had to think through the order of operations carefully because the program needed to read the input file first, store the item frequencies, create the backup file, and then let the user interact with the menu.

I overcame this by breaking the program into smaller functions and testing each menu option separately. I also used course resources, examples from zyBooks, and C++ documentation as support while working through the file input/output and map logic. These are resources I would continue using in future programming assignments.

## Transferable Skills

This project helped me practice several skills that will transfer to other projects and coursework. File input and output are important in many programs because applications often need to read data from files or save results for later use. Using maps is also useful because many real programs need to store key-value pairs, such as names and counts, IDs and records, or usernames and account data.

The project also helped reinforce object-oriented programming, menu-driven design, input validation, and writing readable code. These skills are useful beyond this class because they apply to many software development situations.

## Maintainability, Readability, and Adaptability

I made the program maintainable by separating the code into functions and using a class to organize the main program behavior. This keeps the code from becoming too crowded in one place and makes it easier to update later. I used clear variable and function names so that another person reading the code could understand what each part is doing.

I also included comments where they were useful, especially around the file processing and menu logic. This makes the program easier to follow without over-commenting every single line. The program is adaptable because the item frequencies are stored in a map, so it can handle different grocery item names from the input file without needing the code to be rewritten for each item.
