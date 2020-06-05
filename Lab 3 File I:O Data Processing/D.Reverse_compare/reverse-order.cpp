/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 136
 Assignment: Lab3: D
 
 This program reports the west basin elevation in reverse dates that
 the user gives.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
    //if there is no file print file cannot be open for reading and close program
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl;
    
     //ask the user for start/end date
    string start_date;
    string end_date;
    cout << "Enter starting date: ";
    cin >> start_date;
    cout << "Enter ending date: ";
    cin >> end_date;
    
    //boolean to loop the intervals
    bool next_date = false;
    
    //store the data into array
    const int SIZE = 365;
    int size = 0;
    double array_westel[SIZE];
    string array_date[SIZE];
    
    
    //read the file
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');
        
        if (start_date == date)
        {
            next_date = true;
        }
        
        //sets the date and west elevation to array through user given dates
        if (next_date == true)
        {
            size = size + 1;
            array_westel[size] = westEl;
            array_date[size] = date;

            if (end_date == date)
            {
                next_date = false;
            }
        }
    }
    
    //this reverse the array and prints the date + elevation
    for (int i = size; i > 0; i--)
    {
        cout << array_date[i] << " " << array_westel[i] << " ft" <<endl;
    }
    fin.close();
    return 0;
}

