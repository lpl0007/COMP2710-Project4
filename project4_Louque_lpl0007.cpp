//FILENAME: project4_Louque_lpl0007.cpp
//AUTHOR: Lanie Louque (lpl0007)
//COMPILE: g++ project4_Louque_lpl0007.cpp
//SOURCES:
/*https://stackoverflow.com/questions/1282295/what-is-the-nullptr-keyword-and-why-is-it-better-than-null*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
using namespace std;

struct Trivia {
    struct TriviaNode {
        string question;
        string answer;
        int value;
        TriviaNode *next;

        TriviaNode(string qIn, string aIn, int vIn) {
            question = qIn;
            answer = aIn;
            value = vIn;
            next = nullptr;
        }
    };

    struct TriviaIterator {
        TriviaNode *current;

        TriviaIterator(TriviaNode *nIn) {
            current = new TriviaNode("", "", 0);
            current->next = nIn;
        }

        bool hasNext() {
            return current->next != nullptr;
        }

        TriviaNode next() {
            current = current->next;
            return (*current);
        }
    };

    TriviaNode *first;
    TriviaNode *last;
    int size;
    int score;

    Trivia() {
        first = nullptr;
        last = nullptr;
        size = 0;
        score = 0;
    }

    bool add(string qIn, string aIn, int vIn) {
        TriviaNode* newNode = new TriviaNode(qIn, aIn, vIn);
        if (size == 0) {
            first = newNode;
        }
        else {
            last->next = newNode;
        }
        last = newNode;
        size++;
        return true;
    }

    TriviaIterator iterator() {
        return TriviaIterator(first);
    }

    void addQuest() {
        string newQ;
        string newA;
        string valueRespon;
        int newVal;
        cout << "\nEnter a question: ";
        getline(cin, newQ);
        cout << "Enter an answer: ";
        getline(cin, newA);
        cout << "Enter award points: ";
        getline(cin, valueRespon);
        newVal = stoi(valueRespon);
        add(newQ, newA, newVal);
    }

    bool askQuest(int numQuest) {
        if (numQuest < 1) {
            cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
            return false;
        }
        else if (size < numQuest) {
            cout << "Warning - there (is/are) only " << size << " trivia question(s) in the list." << endl;
            return false;
        }
        else {
            score = 0;
            TriviaIterator itr = iterator();
            int count = 0;
            while (itr.hasNext() && count < numQuest) {
                TriviaNode current = itr.next();
                string userAns;
                cout << "\nQuestion: " << current.question;
                cout << "\nAnswer: ";
                getline(cin, userAns);
                if (userAns.compare(current.answer) == 0) {
                    cout << "Your answer is correct. You receive " << current.value << " points." << endl;
                    score += current.value;
                }
                else {
                    cout << "Your answer is wrong. The correct answer is: " << current.answer << endl;
                }
                cout << "Your total points: " << score << endl;
                count++;
            }
            return true;
        }
    }

    void initialQuest(int version) {
        size = 0;
        score = 0;
        if (version > -1) {  // Version 0 selects this list only
            add("How long was the shortest war on record? (Hint: how many minutes)", "38", 100);
        }
        if (version > 0) {  // Version 1 adds this block and the previous
            add("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?", "Bank of Germany", 50);
            add("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);
        }
    }
};

#define triviaQuiz
/*#define UNIT_TESTING*/

int main() {
    Trivia game = Trivia();

    #ifdef triviaQuiz
        cout << "*** Welcome to Louque's trivia quiz game ***" << endl;

        bool add = false;
        do {
            game.addQuest();
            string userRespon = "";
            while (userRespon == "") {
                cout << "Continue? (y/n): ";
                getline(cin, userRespon);
                if (userRespon.at(0) == 'y' || userRespon.at(0) == 'Y') {
                    add = true;
                }
                else if (userRespon.at(0) == 'n' || userRespon.at(0) == 'N') {
                    add = false;
                }
                else {
                    cout << "Invalid Response" << endl;
                    userRespon = "";
                }
            }
        } while (add);

        cout << "\n\nWelcome to the Trivia Game!" << endl;
        game.askQuest(game.size);

        cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    #endif

    #ifdef UNIT_TESTING
        cout << "*** This is a debugging version ***" << endl;
        cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
        bool warning = game.askQuest(0);
        assert(!warning);
        cout << "\nCase 1 Passed" << endl << endl;

        game.initialQuest(1);
        cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
        game.askQuest(1);
        assert(game.score == 0);
        cout << "\nCase 2.1 passed" << endl << endl;

        cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
        game.askQuest(1);
        assert(game.score == 100);
        cout << "\nCase 2.2 passed" << endl << endl;

        cout << "Unit Test Case 3: Ask all the questions in the linked list." << endl;
        bool played = game.askQuest(3);
        assert(played);
        cout << "\nCase 3 passed" << endl << endl;

        cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
        warning = game.askQuest(5);
        assert(!warning);
        cout << "\nCase 4 passed" << endl << endl;

        cout << "*** End of debugging version ***";
    #endif

    return 0;
}
