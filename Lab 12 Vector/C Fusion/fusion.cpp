/*
 Shi Tao Luo
 CSCI 135
 Maryash
 Assignment: LAB 12: C
 This program creates a vector that fuse two vector together
 */


#include <vector>
#include <iostream>

using namespace std;


void gogeta(vector<int> &goku, vector<int> &vegeta) {
    
    for (int i = 0; i < vegeta.size();i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

//test case
int main() {
    vector <int> goku {1,2,3};
    vector <int> vegeta {4,5,6};
    gogeta(goku, vegeta);
    return 0;
}
