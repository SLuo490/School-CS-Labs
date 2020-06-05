/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: D
 
 This program print a lower triangle with the length
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //ask user for length
    int length;
    cout << "Enter a length: ";
    cin >> length;
    
    cout << "Shape: ";
    
    
    //print the lower triangle
    for (int i = 0; i <= length; i++)
    {
        for (int j = 0; j < i ; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

