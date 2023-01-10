#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global Variables
enum fields
{
    WORD,
    HINT,
    NUM_FIELDS
};
const int NUM_WORDS = 5;
const string WORDS[NUM_WORDS][NUM_FIELDS] = {{"wall", "Do you feel you�re banging your head against something?"},
                                             {"glasses", "These might help you see the answer."},
                                             {"labored", "Going slowly, is it?"},
                                             {"persistent", "Keep at it."},
                                             {"jumble", "It�s what the game is all about."}};

// Declare funtions
void getRandomPick(string *word, string *hint);
string jumbledWord(string word);
void start();

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    start();
}

void start()
{
    string THEWORD;
    string THEHINT;
    string answer;
    string jumbledW;
    getRandomPick(&THEWORD, &THEHINT);
    jumbledW = jumbledWord(THEWORD);
    cout << "WELCOME TO \"GUESS THE WORD\", PLAYER" << endl;

    bool exit = false;
    while (answer != THEWORD && !exit)
    {
        cout << "WHAT IS THE WORD: " << jumbledW << endl;
        cin >> answer;
        if (answer == THEWORD)
        {
            cout << "GOOD JOB IS THE CORRECT ANSWER" << endl;
            exit = true;
        }
        else if (answer == "hint")
        {
            cout << "HINT: " << THEHINT << endl;
        }
        else if (answer == "exit")
        {
            exit = true;
        }
        else
        {
            cout << "NO PLAY AGAIN" << endl;
        }
    }

    cout << "GOODBYE PLAYER, SEE YOU NEXT TIME" << endl;
}

string jumbledWord(string word)
{

    int index1, index2;
    for (int i = 0; i < word.size(); i++)
    {
        index1 = rand() % word.size();
        index2 = rand() % word.size();
        char temp = word[index1];
        word[index1] = word[index2];
        word[index2] = temp;
    }
    return word;
}

void getRandomPick(string *word, string *hint)
{
    int index;
    index = rand() % NUM_WORDS;
    *word = WORDS[index][0];
    *hint = WORDS[index][1];
}
