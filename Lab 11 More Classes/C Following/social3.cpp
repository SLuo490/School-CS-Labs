/*
Author: Shi Tao
Course: CSCI-136
Instructor: Maryash
Assignment: Lab 11: C

This program creates a 2D matrix that makes a following
*/

#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn) {
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile() {
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername() {
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName() {
        return displayname + " (@" + username + ")";
    }
    // Change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};


class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
    bool following[MAX_USERS][MAX_USERS]; //implement
    
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // implement
    void printDot(); //implement
};

int Network::findID(string usrn) {
    for (int i = 0; i <= numUsers; i++) {
        //get each profile's username and see if it matches the usrn
        if (profiles[i].getUsername() == usrn) {
            //if matched, return 1
            return 1;
        }
    }
    //if not match, return -1
    return -1;
}

//make an empty network
Network::Network() {
    numUsers = 0;
    
    //initialize matrix to false
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn) {
    if (numUsers == MAX_USERS || usrn.size() == 0) {
        return false;
    }
    for (int j = 0; j < usrn.size(); j++) {
        if (!isalpha(usrn[j]) && !isdigit(usrn[j])) {
            return false;
        }
    }
    for (int i = 0; i <= numUsers; i++) {
        if (profiles[i].getUsername() == usrn) {
            return false;
        }
    }
    Profile p(usrn,dspn);
    profiles[numUsers] = p;
    numUsers++;
    return true;
}

bool Network::follow(string usrn1, string usrn2) {
    
    for (int i = 0; i < numUsers; i++)
    {
        if (profiles[i].getUsername().compare(usrn1) == 0)
        {
            for (int j = 0; j < numUsers; j++)
            {
                if (profiles[j].getUsername().compare(usrn2) == 0)
                {
                    following[i][j] = true;
                    return true;
                }
            }
        }
    }
    return false;
}

void Network::printDot() {
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++) {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numUsers; j++) {
            if (following[i][j] == true) {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}


