# COMP 2710: Project 4

## Goals
- To learn how to use linked data structures (Note: no array is allowed)
- To use strings
- To learn creating multiple versions via conditional compilation
- To design and implement functions
- To perform unit testing

In this homework assignment, you will write a simple trivia quiz game. Your program first allows players to create their trivia questions and answers. Multiple questions should be organized and managed using **a linked data structured; no array is allowed in this homework assignment**. Then, your program asks a question to the player, input the player’s answer, and check if the player’s answer matches the actual answer. If so, award the player the award points for that question. If the player enters the wrong answer your program should display the correct answer. When all questions have been asked, the total award points that the player has won should be displayed

Please perform the following steps to finish this assignment:

### Step 1
Create a TriviaNode **structure** that contains (1) information about a single trivia question and (2) a pointer pointing to other TriviaNode. This structure must contain a **string** for the question, a **string** for the answer to the question, an integer representing points the question is worth, and **a pointer of the TriviaNode type**. Please keep in mind that a harder question should be worth more points.

### Step 2
Create a linked list of Trivia using the TriviaNode structure defined in [Step 1](#step-1).

### Step 3
Design and implement a function that initialize the Trivia linked list by hard-coding the following three trivia questions (including answers and award points).
- Trivia 1
  - Question
    - How long was the shortest war on record? (Hint: how many minutes)
  - Answer
    - 38
  - Award points
    - 100
- Trivia 2
  - Question
    - What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)
  - Answer
    - Bank of Italy
  - Award points
    - 50
- Trivia 3
  - Question
    - What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?
  - Answer
    - Wii Sports
  - Award points
    - 20

### Step 4
Design and implement a function to create and add a new TriviaNode into the linked list. You must use operator **new** to dynamic allocate memory to a new TriviaNode. Please remember to check that a new TriviaNode is successfully created.

### Step 5
Design and implement a function that asks a question to the player, input the player’s answer, and check if the player’s answer matches the actual answer. If so, award the player the dollar amount for that question. If the player enters the wrong answer your program should display the correct answer.
- **Input**
  - A linked list of TriviaNode, the number of trivia to be asked in the list
- **Output**
  - Void or int
    - 0 indicates success
    - 1 indicates failure

### Step 6
Write a test driver to perform unit testing for the function implemented in [Step 5](#step-5). Assume there are three trivia in your created list, you must cover at least the following cases:
- Case 1
  - Ask 0 question
- Case 2
  - Ask 1 question (i.e., the first one) from the list
    - Correct answer
    - Wrong answer
- Case 3
  - Ask 3 questions (i.e., all the questions) from the list.
    - Correct answer
    - Wrong answer
- Case 4
  - Ask 5 questions that exceed the number of available trivia in the linked list (i.e., the index of the trivia is larger than the size of the linked list)

### Step 7
Write the main function that performs the following:
- Create hard-code trivia quizzes (i.e., questions/answers/awards)
  - *Note*: Just call the function implemented in [Step 3](#step-3)
- Create more than 1 trivia quiz from a keyboard
  - *Note*: Just call the function implemented in [Step 4](#step-4)
- Write a for loop that does the following:
  - Asks a question to the player
  - Takes the player’s answer
  - Compares the input answer with the actual answer
    - If the player’s answer matches the actual answer, then award the player the corresponding award points for that question
    - Else (i.e., the player enters the wrong answer) your program should display the correct answer
- When all questions have been asked, display the total award points the player has won

### Step 8
Create two versions using conditional compilation.

- Version 1
  - Simply run the test driver implemented in [Step 6](#step-6).
- Version 2
  - A regular version run the main function implemented in [Step 7](#step-7).

*Note*: This version should not include the test driver.

## How to Create Two Versions?
You can use the preprocessor directive #ifdef to create and maintain two versions (i.e., a debugging version and a product version) in your program. If you have the following code:

1. #define UNIT_TESTING
2. #ifdef UNIT_TESTING
3. add your unit testing code here
4. #else
5. add your code for the product version here
6. #endif

In your program, the code that is compiled depends on whether a preprocessor macro by that name is defined or not. For example, if the UNIT_TESTING has been defined, i.e., line is enabled, then line 3 "add your unit testing code here" is compiled and line 5 "add your code for the product version here" is ignored. If the macro is not defined, i.e., line 1 is disabled, then line 5 "add your code for the product version here" is compiled and line 3 "add your unit testing code here" is ignored.

These macros look a lot like if statements, but macros behave completely differently. More specifically, an **if** statement decides which statements of your program must be executed at run time, while a **#ifdef** controls which lines of code in your program are actually compiled.

## Unit Testing
Unit testing is a way of determining if an individual function or class works as expected. You need to isolate a single function or class and test only that function or class. For each function in this homework, you need to check *normal cases and boundary cases*.

Examples for tested values:
- String
  - Empty string
  - Medium length
  - Very long
- Array
  - Empty array
  - First element
  - Last element
- Integer
  - Zero
  - Mid-value
  - High-value

You must implement a unit test driver for each function implemented in your program. You may need to use assert() to develop your unit test drivers if tested results are predictable.

## Integration Testing
Integration testing (a.k.a., Integration and Testing) is the phase in software testing in which individual software modules are combined and tested as a group.
