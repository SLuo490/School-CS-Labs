/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 135
 Assignment:Lab 6: C
 
 This program encrypts a plain text using vigener cipher with a keyword.
 */
#include <iostream>
#include <string>
using namespace std;


//shifts each character 
char shiftChar (char c, int rshift)
{
    //lower case char
    if (int(c) >= 65 && int(c) <= 90)
    {
        if (int(c) + rshift > 90)
        {
            return (int(c)-26+ rshift);
        }
        return (int(c) + rshift);
    }
    
    //upper case char
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

string encryptVigenere (string plaintext, string keyword)
{
    int keyword_index = 0;
    int x;
    string cipher_text;
    
    //loops through each letter in plaintext
    for (int i = 0; i < plaintext.length(); i++)
    {
        //if the plaintext is an alphabet shifts each letter with the char of keyword
        if (isalpha(plaintext[i]))
        {
            x = (int)keyword[keyword_index];
            x = x - 97;
            
            cipher_text += shiftChar(plaintext[i], x);
            
            keyword_index++;
            if (keyword_index == keyword.length())
            {
                keyword_index = 0;
            }
        }
        // if the plaintext character is not an alphabet, then add cipher text to plaintext
        else
        {
            cipher_text += plaintext[i];
        }
    }
    return cipher_text;
}

int main ()
{
    //tests the vigenere function
    string plain_text;
    cout << "Enter plain text: ";
    getline(cin, plain_text);
    
    string key_word;
    cout << "Enter keyword: ";
    getline(cin, key_word);
    
    cout << "Cipher Text: " << encryptVigenere(plain_text, key_word) << endl;
}

