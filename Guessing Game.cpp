#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_TRIES 5

int RandomNumber()
{
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}

bool checker(int a, int b)
{
    return a == b;
}

int main()
{

    int *gussed = new int[MAX_TRIES];
    cout << "Welcome to the Guessing Game!" << endl;

    int randomNumber = RandomNumber();
    int guess;
    int tries = 0;

    do
    {
        if (tries != 0)
        {
            cout << "You have " << MAX_TRIES - tries << " tries left!" << endl;
            cout << "You have gussed: ";
            for (int i = 0; i < tries; i++)
            {
                cout << gussed[i] << " ";
            }
            cout << endl;
        }
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if (checker(guess, randomNumber))
        {
            cout << "Congratulations! You guessed the number in " << tries << " tries!" << endl;
            return 0;
        }
        else if (guess > randomNumber)
        {
            cout << "Too high!" << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Too low!" << endl;
        }

        tries++;

    } while (tries < MAX_TRIES);

    cout << "You lose! The number was " << randomNumber << endl;
}