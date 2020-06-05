/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: C
 
 This program print a X shape using nested loop
 
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //ask user for length
    int size;
    cout << "Enter a Size: ";
    cin >> size;

    cout << "Shape: " <<endl;
    //print the lower triangle
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size ; col++)
        {
            if (row == col || col == (size + 1) - row)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    return 0;
}


