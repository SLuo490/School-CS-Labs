/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: B
 
 This program print a checkerboard with the height and width
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
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
       {
          if ((i + j) % 2 == 0)
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

