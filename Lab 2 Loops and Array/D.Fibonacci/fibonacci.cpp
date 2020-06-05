/*
  Name: Shi Tao Luo
  course: csci-13600
  Instructio: Maryash
  Assignment: Lab2: D
  
 This program create a array of 60 integers, then this program would print the Fibonacci sequence up to 60.
  */
 
#include <iostream>

using namespace std;

int main()
{
    
    int fib [60];
    
    for (int i = 0; i < 60; i++)            //loop the program so it would print the 60th Fibonacci Numbers.
    {
        fib[i] = fib[i-1] + fib[i-2];
        fib[0] = 0;
        fib[1] = 1;
        cout << fib[i] << endl;             //as the number get higher and higer, the output starts to diverge. I believe it is because a computer can only contain a certain amount of number before it would overflow. 
    }
    
    return 0;
}

