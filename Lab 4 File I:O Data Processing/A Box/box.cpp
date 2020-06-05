/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: A
 
 This program print a box with the height and width
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //user input for height and width
    int width;
    cout << "Input Width: ";
    cin >> width;
    int height;
    cout << "Input Height: ";
    cin >> height;

    
    cout << "shape: " <<endl;
    //nested loop to create the box
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

