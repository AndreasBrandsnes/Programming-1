// BugSwatTeam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    enum bugPoints { FLIES_SWAPPED = 50, BEES_WACKED = 75, CRICKETS_CROOKED = 100, MUSQETOS_MINCED = 150 };
    int flies, bees, crickets, musqetos, score;
    string agent;

    //get the info
    cout << "Welcome to The BugSwat Team!\n\n";
    cout << "Please enter the following info for your personalized score. Your goal is 1000 points or more! \n";
    cout << "The flies are worth 50 points. The bees are worth 75 points. The crickets are 100, and lastly the musqetos are worth a whopping 150 points! ";
    cout << "Remember; NO CHEATING!\n\n";

    cout << "How many flies have you swatted?: ";
    cin >> flies;

    cout << "How many bees have you wacked?: ";
    cin >> bees;

    cout << "How many crickets have you crooked?: ";
    cin >> crickets;

    cout << "How many musqetos have you minced?: ";
    cin >> musqetos;

    cout << "Enter your last name: ";
    cin >> agent;

    score = (flies * FLIES_SWAPPED)+(bees *  BEES_WACKED)+(crickets * CRICKETS_CROOKED)+(musqetos * MUSQETOS_MINCED);
    cout << "\nWell done " << agent << ". Your bugswattingscore is " << score;

    if (score >= 1000)
        cout << ". Well done! You scored a 1000 points or more, and have passed the test. Congratulations!!!\n";

    else if (score >= 750)
        cout << ". Close, but no cigar! Better luck next time.\n";

    else if (score >= 500)
        cout << ". Not even close to the 1000 point marker! Next!\n";

    else if (score >= 250)
        cout << ". This is way below average! Horrendeus!\n";

    else if (score >= 1)
        cout << ". This is terrible! Terrible! NEXT!\n";

    else if (score == 0)
        cout << ". You'r a buglover trying to infiltrate us, aren't you!? GUARDS! HURRY!\n";
    

    //if (score == 0)
        //cout << ". I don't belive you were even trying!\n\n\";
    //if (score >= 1000)
        //cout << ", which is the top elite level!\n\n\";
    //if (score >= 500)
        //cout << ". Thats on the riht side of the 500-point limit, and is very respectable!\n\n\";
    //if score >= 250
        //cout << ", and thats below avaerage. Pity!\n\n\";

    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
