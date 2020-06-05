/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4:E
 
 This program print a upper half triangle with the length
 */


#include <iostream>
using namespace std;

int main ()
{
    
    //ask the user for length
    int length;
    cout << "Enter a length: ";
    cin >> length;
    
    
    cout << "Shape: " << endl;
    
    //Print out a top-right half of a square
    for (int i = 1; i <= length ; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            cout << " ";
        }
        for (int k = length; k >= i; k--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

