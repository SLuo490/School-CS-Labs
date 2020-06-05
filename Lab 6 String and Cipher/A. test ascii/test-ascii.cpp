/*
Author: Shi Tao Luo
Course: CSCI-136
Instructor: Progfessor Maryash
Assignment: Lab 6: A

This converts a sentence into ascii
*/

#include <iostream>
using namespace std;


int main()
{
    
    //asks user for sentence
    string sentence;
    cout << "Input: ";
    getline(cin, sentence);
    
    int ascii;
    //converts the sentence into ascii character
    for (int i = 0; i < sentence.length(); i++)
    {
        ascii = sentence[i];
        cout << sentence[i] << " " << ascii << endl;
        
    }
    return 0;
}

