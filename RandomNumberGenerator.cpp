// 06.09.23 - RandomNumberGenerator LOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char again;
    do
    {
        srand(static_cast<unsigned int>(time(0)));      //seed RNG

        int randomNumber = rand();                      //generate random number

        int die = (randomNumber % 6) + 1;                 //get a random number between 1 and 6
        cout << "\n**You roll the Dice of Fortune!**\n";
        cout << "\nYou rolled a " << die << "!" << endl;
        
        if (die == 6)
        {
            cout << "\nGreat fortune will be bestowed upon you!\n";
            }
        else if (die >=2)
        {
            cout << "\nBetter luck next time!\n";
        }
        else if (die == 1)
        {
            cout << "\nLuck turns it's back to you. Tread carefully..\n";
        }
        cout << "\nDo you want to roll again? (y/n)\n";
        cin >> again;

    } while (again == 'y');
    cout << "\nOkey, bye!";
    return 0;
}


