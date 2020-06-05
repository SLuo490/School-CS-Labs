/*
 Name: Shi Tao Luo
 course: csci-13600
 Instructio: Maryash
 Assignment: Lab 3: A
 
 This program reads the tsv file and ask the user for a date, which would then print the gallon of the east basin storage.

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
    string user_date;
    
    cout <<"Enter a date: ";
    cin >> user_date;
    
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore (INT_MAX, '\n');
        
        if (user_date == date)
        {
            cout << "East basin storage: " << eastSt << " billion gallons";   //reads the date and print out the gallon on the east bason storage
        }
        
    }
    fin.close();

    return 0;
}
