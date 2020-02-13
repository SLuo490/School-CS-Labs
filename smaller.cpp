/*
Name: Shi Tao Luo
Assignment: Lab 1: A

This program ask the user for their two numbers, and would print the smallest number
*/

#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    
    cout << "Enter the first number: ";         //Ask user for 2 numbers
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "The smallest number is: " << min(num1, num2) << endl; //print the smallest number of                                                               the two
    return 0;
}




