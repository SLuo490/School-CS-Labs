/*
 Shi Tao Luo
 CSCI 135
 Maryash
 Assignment: LAB 12: D
 This program creates a vector that have the pair sum of each vector
 */


#include <vector>
#include <iostream>

using namespace std;


//calculate the pairwise sum or two vector
vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    vector <int> pair_sum;
    int sum = 0;
    int i = 0;
    
    while (i < v1.size() || i < v2.size()) {
        sum = 0;
        if (i < v1.size()) {
            sum += v1[i];
        }
        if (i < v2.size()) {
            sum += v2[i];
        }
        pair_sum.push_back(sum);
        i++;
    }
    return pair_sum;
}

//test case:
int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};
    vector<int> result = sumPairWise(v1, v2); // returns [5, 7, 3]
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

