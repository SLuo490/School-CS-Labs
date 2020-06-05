/*
Author: Shi Tao Luo
Course: CSCI-136
Instructor: Maryash
Assignment: Lab 7: A

This program creates a function that removes indentation from a file
*/

#include <iostream>
#include <cctype>
using namespace std;

// function that removes leading spaces
string removeLeadingSpaces(string line)
{
    string new_line;
    
    int n = 0;
    while (isspace(line[n]))
    {
        bool space = true;
        if (isspace(line[n]))
        {
            space = true;
        }
        else
        {
            space = false;
        }
        n++;
    }
    
    //set i equal to the length of the index n where n is the index is the first non-space char
    for (int i = n; i < line.length();i++)
    {
        //create a new line and add each character of line i to new line
        new_line += line[i];
    }
    return new_line;
}


int main()
{
    string str;
    while (getline(cin, str))
    {
        cout << removeLeadingSpaces(str) << endl;
    }
    return 0;
}
