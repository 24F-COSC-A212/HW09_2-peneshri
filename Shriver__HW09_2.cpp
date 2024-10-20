/*
Filename:       Shriver__HW09_2.cpp
Description:    This program asks the user for the name of a text file.
                The program opens the file and outputs each line with its number.
                Every 24 lines, the program pauses for the user to read the screen,
                who tells the program when to continue.
Author:         Penelope Shriver
Dates modified: 10/19/2024
                10/20/2024
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    char inName[200];
    string inputLine = "";
    int lineNumber = 1;
    int lineCounter = 1;
    char userEnter;

    cout << "Enter the input file name: ";
    cin >> inName;
    inFile.open(inName);
    if (!inFile)
    {
        cout << "Error opening file " << inName << endl;
        return 42;
    }

    while (!inFile.eof())
    {
        if (lineCounter > 24)
        {
            cout << "Press space and enter to continue...";
            cin.ignore();
            cin.get(userEnter);
            if (userEnter == ' ')
                lineCounter = 1;
        }
        while (lineCounter < 25 && !inFile.eof())
        {
            getline(inFile, inputLine, '\n');
            cout << setw(4) << right << lineNumber << ": " << inputLine << endl;
            lineNumber++;
            lineCounter++;
        }
    }

    inFile.close();
    return 0;
}