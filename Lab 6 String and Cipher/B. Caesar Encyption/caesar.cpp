/*
Author: Shi Tao Luo
Course: CSCI-136
Instructor: Progfessor Maryash
Assignment: Lab 6: B

This program encrupts a sentence into caesar cipher by asking the user for a plain text and shift unit
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


//A function to shift character with given length
char shiftChar (char c, int rshift)
{
    if (int(c) >= 65 && int(c) <= 90)
    {
        if (int(c) + rshift > 90)
        {
            return (int(c)-26+ rshift);
        }
        return (int(c) + rshift);
    }
    if (int(c) >= 97 && int(c) <= 122)
    {
        if (int(c) + rshift > 122)
        {
            return (int(c)-26+ rshift);
        }
        return (int(c) + rshift);
    }
    return int(c);
}

//Function to encrypts a sentence into caesar cipher
string encryptCaesar(string plaintext, int rshift)
{
    string new_word;
    for (int i = 0; i < plaintext.length(); i++)
    {
        new_word += shiftChar(plaintext[i], rshift);
    }
    return new_word;
}


//test the function
int main()
{
    string word;
    cout << "Enter plaintext: ";
    getline(cin, word);
    
    int shift;
    cout << "Enter a shift: ";
    cin >> shift;
    
    cout << "Ciphertext: " << encryptCaesar(word, shift) << endl;
    return 0;
}
