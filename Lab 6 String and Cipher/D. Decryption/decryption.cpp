/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 135
 Assignment:Lab 6: D
 
 This program decrypts a plain text using vigener cipher with a keyword and caesar cipher
 */
#include <iostream>
#include <string>
using namespace std;


//set decrypt C and V to false
bool decryptC = false;
bool decryptV = false;

//shifts each character
char shiftCharCaesar (char c, int rshift)
{
    // if decrypt Caesar is false, encrypt
    if (decryptC == false)
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
    }
    //decrypt
    else
    {
        //lower case char
        if (int(c) >= 65 && int(c) <= 90)
        {
            int shift2 = (int)c - rshift;
            char shiftedChar = (char)shift2;
            if (shift2 < 65)
            {
    
                shift2 = 90 - (rshift - ((int)c - 64));
                shiftedChar = (char)shift2;
            }

            return shiftedChar;
        }
        
        //upper case char
        if (int(c) >= 97 && int(c) <= 122)
        {
            int shift2 = (int)c - rshift;
            char shiftedChar = (char)shift2;
            if (shift2 < 97)
            {
    
                shift2 = 122 - (rshift - ((int)c - 96));
                shiftedChar = (char)shift2;
            }
            return shiftedChar;
        }
    }
    
    return int(c);
}

string decryptCaesar(string plaintext, int shift)
{
    string cipher_text;
    decryptC = true;
    for (int i = 0; i < plaintext.length(); i++)
    {
        cipher_text += shiftCharCaesar(plaintext[i], shift);
    }
    return cipher_text;
}

//Function to encrypts a sentence into caesar cipher
string encryptCaesar(string plaintext, int rshift)
{
    string new_word;
    for (int i = 0; i < plaintext.length(); i++)
    {
        new_word += shiftCharCaesar(plaintext[i], rshift);
    }
    return new_word;
}


char shiftCharVignere (char c, int rshift)
{
    //if decrypt Vigenre is false, encrypt
    if (decryptV == false)
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
    }
    //else decrypt
    else
    {
        //lower case char
        if (int(c) >= 65 && int(c) <= 90)
        {
            int shift2 = (int)c - rshift;
            char shiftedChar = (char)shift2;
            if (shift2 < 65)
            {
    
                shift2 = 90 - (rshift - ((int)c - 64));
                shiftedChar = (char)shift2;
            }

            return shiftedChar;
        }
        
        //upper case char
        if (int(c) >= 97 && int(c) <= 122)
        {
            int shift2 = (int)c - rshift;
            char shiftedChar = (char)shift2;
            if (shift2 < 97)
            {
    
                shift2 = 122 - (rshift - ((int)c - 96));
                shiftedChar = (char)shift2;
            }
            return shiftedChar;
        }
    }
    return int(c);
}


//function to encrypt vigenere cipher
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
            
            cipher_text += shiftCharVignere(plaintext[i], x);
            
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

string decryptVigenere(string plaintext, string keyword)
{
    decryptV = true;
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
            
            cipher_text += shiftCharVignere(plaintext[i], x);
            
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
    //tests both encryption and decryption of Caesar cipher and Vigenere cipher
    string plain_text;
    cout << "Enter plain text: ";
    getline(cin, plain_text);
    
    cout << "= Vignere Cipher =" << endl;
    
    string key_word;
    cout << "Enter keyword: ";
    getline(cin, key_word);
    
    
    cout << "Ciphertext: " << encryptVigenere(plain_text, key_word) << endl;
    cout << "Decrypted: " << decryptVigenere(encryptVigenere(plain_text, key_word), key_word) << endl;


    cout << "= Caesar Cipher =" << endl;

    int shift;
    cout << "Enter a shift: ";
    cin >> shift;

    cout << "Ciphertext: " << encryptCaesar(plain_text, shift) << endl;
    cout << "Decrypted: " << decryptCaesar(encryptCaesar(plain_text, shift), shift) << endl;

    
    return 0;
}
