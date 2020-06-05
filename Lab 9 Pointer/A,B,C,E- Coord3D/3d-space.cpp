/*
 Name: Shi Tao Luo
 Course: CSCI 136
 Professor: Maryash
 Assignment: Lab 9: E
 
 This program creates a function that creates and delete objecrs dynamically
 */

#include <iostream>
#include <math.h>
using namespace std;

class Coord3D
{
public:
    double x;
    double y;
    double z;
};

//measures the length of coordinate
double length(Coord3D *p)
{
    double length = 0;
    length = sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
    return length;
}

//find which two coordinate are furthest from origin
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    double distance_p = length(p1);
    double distance_q = length(p2);

    if (distance_p < distance_q)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}

//moves the position of the coordinate
void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    ppos -> x = (ppos -> x) + (pvel -> x) * dt;
    ppos -> y = (ppos -> y) + (pvel -> y) * dt;
    ppos -> z = (ppos -> z) + (pvel -> z) * dt;
}


// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z)
{
    Coord3D* coordptr = new Coord3D;
    *coordptr = {x,y,z};
    return coordptr;
}


// free memory
void deleteCoord3D(Coord3D *p)
{
    delete p;
}


//test cases:
int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: "
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}
