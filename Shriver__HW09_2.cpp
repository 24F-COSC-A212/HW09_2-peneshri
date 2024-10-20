/*
Filename:       Shriver__HW09_2.cpp
Description:    
Author:         Penelope Shriver
Dates modified: 10/19/2024
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
        getline(inFile, inputLine, '\n');
        cout << setw(4) << right << lineNumber << ": " << inputLine << endl;
        lineNumber++;
    }

    inFile.close();
    return 0;
}