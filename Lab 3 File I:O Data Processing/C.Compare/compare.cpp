/*
 Name: Shi Tao LUo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab3: C
 
 This program compare the east elevation and west elevation through the user input date of start and end date.
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
    bool next_date = false;
    
    string start_date;
    string end_date;
    
    cout << "Enter starting date: ";                    //ask the user for start/end date
    cin >> start_date;
    cout << "Enter ending date: ";
    cin >> end_date;
    
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)    //read the file
    {
        fin.ignore(INT_MAX, '\n');
        
        if (start_date == date)
        {
            next_date = true;
        }
        if (next_date == true)                          //loops through start date to end date
        {
            if (eastEl > westEl)                        //compares the east and west storage
                {
                    cout << date << " East" << endl;
                }
            else if (eastEl < westEl)
                {
                    cout << date << " West" << endl;
                }
            else if (eastEl == westEl)
                {
                    cout << date << " Equal" << endl;
                }
            if (end_date == date)
            {
                next_date = false;
            }
        }
    }
    fin.close();
    return 0;
}


