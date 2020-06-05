/*
 Shi Tao Luo
 CSCI 135
 Maryash
 Assignment: LAB 12: A
 This program creates a vector with a size n
 */


#include <iostream>
#include <vector>

using namespace std;


//creates a new vector from 0 to size n
vector <int> makeVector (int n) {
    vector <int> vect;
    
    for (int i = 0; i < n; i++) {
        vect.push_back(i);
    }
    
    return vect;
}

int main()
{
   int n;
   cout<<"Enter value for n: ";
   cin>>n;
   
   vector<int> v = makeVector(n);
   
    //Prints out the vector into terminal
   for(int i = 0;i<n;i++){
      cout<<v[i]<<endl;
   }
   
   return 0;
}

