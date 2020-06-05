/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab 4: F
 
 This program ask user for height and width then print a trapezoid with the height and width. If the height and width is not possible, then print impossible shape
 */


#include <iostream>
using namespace std;

int main()
{
    
    //ask user for height and width
    int width, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    
    int stars = width;
    int spaces = 0;
    
    
    
    //checks if the width/height is possible or impossible
    if (stars - ((height-1)*2) <=0 )
    {
        cout << "Impossible Shape";
        return 0;
    }
    
    cout << "Spaces: " <<endl;
    
    
    //prints the trapezoid
    for (int row = height; row > 0; row--)
    {
        for (int spaces = height-row; spaces > 0; spaces--)
        {
            cout << " ";
        }
        for (int col = 0; col < stars; col++)
        {
            cout << "*";
        }
        stars -= 2;
        cout << endl;
    }
    
    return 0;
}

