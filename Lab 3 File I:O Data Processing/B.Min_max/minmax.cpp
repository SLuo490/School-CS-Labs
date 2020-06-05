/*
 Name: Shi Tao Luo
 course: csci-13600
 Instructio: Maryash
 Assignment: Lab 3: B
 
 This program reads the tsv file and prints out the minimum and maximum value in the east basin storage
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
    ifstream fin("Current_Reservoir_Levels.tsv");               //if there is no file print file                                                   cannot be open for reading and close program
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    string junk;
    getline(fin, junk);
    
    string date;
    double eastSt, eastEl, westSt, westEl;
    double minimum = 1000;
    double maximum;
    double number;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore (INT_MAX, '\n');
        
        if (maximum < eastSt)                       // find the maximum value
        {
            maximum = eastSt;
        }
        if (minimum > eastSt)                       // find the minimum value
        {
            minimum = eastSt;
        }
        
    }
    fin.close();
    cout << "The minimum storage in East basin is: " << minimum << endl;    //prints the min/max value
    cout << "The maximum storage in East basin is: " << maximum << endl;
    return 0;
}

