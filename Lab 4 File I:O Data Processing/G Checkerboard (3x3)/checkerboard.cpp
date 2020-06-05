/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: G
 
 This program print a checkerboard with width and height
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //ask user for height and width
    int height;
    cout << "Input Height: ";
    cin >> height;
    int width;
    cout << "Input Width: ";
    cin >> width;
    
    cout << "Shape: " << endl;
    
    //print out a checkerboard shape with height and width
    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < height; col++)
       {
          if ((row + col) % 2 == 0)
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

