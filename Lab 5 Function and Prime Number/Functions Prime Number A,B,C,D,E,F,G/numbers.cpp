/*
Author: Shi Tao Luo
Course: CSCI-136
Instructor: Maryash
Assignment: Lab 5:A,B,C,F

This program create a variety of functions
*/


#include <iostream>
using namespace std;

//function isdivisibleby (A)
bool isDivisibleBy (int n, int d)
{
    bool isDivisible = false;
    if (d == 0)
    {
        isDivisible = false;
    }
    else if (n % d == 0)
    {
        isDivisible = true;
    }
    else
    {
        isDivisible = false;
    }
    return isDivisible;
}

//check is number is prime (B)
bool isPrime(int n)
{
    bool prime = true;

    //set prime to false if number is less than or equal to 1
    if (n <= 1)
    {
        prime = false;
    }

    //if number is divisible by 2, then it is not prime
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}


//function to find the next prime number that user input (C)
int nextPrime(int n)
{
    
    bool found = false;
    int prime = n;
    
    
    //loops until the next prime is found
    while (!found)
    {
        if (n<=1)
        {
            return 2;
        }
        prime++;
        
        //uses previous function isPrime to find whether "prime" is a prime or not
        if (isPrime(prime))
        {
            found = true;
        }
    }
    return prime;
}


//function that count the number of prime numbers in a range (D)
int countPrimes (int a, int b)
{
    int num_prime = 0;
    while (a <= b)
    {
        if (isPrime(a))
        {
            num_prime+=1;
        }
        a++;
    }
    cout << num_prime;
    return num_prime;
}

//function that find if user input number is a twin prime or not (E)
bool isTwinPrime (int n)
{
    bool isTwinPrime = false;
    
    //start with a number that is greater than 2
    if (n <= 2)
    {
        isTwinPrime = false;
        cout << "False" <<endl;
    }
    //else if n+2 or n-2 is prime, then set isTwinPrime to true
    else if ((isPrime(n-2) || isPrime(n + 2)) && ((isPrime(n))))
    {
        isTwinPrime = true;
        cout << "Twin Number" <<endl;
    }
    else
    {
        isTwinPrime = false;
        cout << "Not a Twin Number" <<endl;
    }
    return isTwinPrime;
}



//Function to find the next twin prime (F)

int nextTwinPrime (int n)
{
    int next_Twin_Prime = n - 1;
    //loops to find the next largest twin prime
    while (!isTwinPrime(next_Twin_Prime))
    {
        next_Twin_Prime--;
    }
    return next_Twin_Prime;
}

//function to find the largest twin number with 2 given number
int largestTwinPrime(int a, int b)
{
    int largest_Twin_Prime;
    largest_Twin_Prime = -1;
    
    for (int i = b; i >= a; i--)
    {
        if (isTwinPrime(i))
        {
            largest_Twin_Prime = i;
            break;
        }
    }
    return largest_Twin_Prime;
}

//test the function
int main ()
{
    int num;
    cout << "Enter a num: ";
    cin >> num;
    int num2;
    cout << "Enter num2: ";
    cin >> num2;
    cout << largestTwinPrime(num,num2) <<endl;
    return 0;
}
