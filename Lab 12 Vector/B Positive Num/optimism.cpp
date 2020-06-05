/*
 Shi Tao Luo
 CSCI 135
 Maryash
 Assignment: LAB 12: B
 This program creates a vector that return only positive number
 */

#include <vector>
#include <iostream>

using namespace std;

//create a vector of only positive num
vector<int> goodVibes(const vector<int> v) {
    vector <int> positive;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            positive.push_back(v[i]);
        }
    }
    return positive;
}

int main() {
    vector<int> v{1,2,-1,3,4,-1,6};
    v = goodVibes(v);
    //print out the test case
    for (int i = 0; i < v.size();i++) {
        cout << v[i];
    }
    cout << endl;

    return 0;
}
