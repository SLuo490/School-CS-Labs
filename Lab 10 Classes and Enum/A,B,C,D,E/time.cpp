/*
Author: Shi Tao Luo
Course: CSCI-136
Instructor: Maryash
Assignment: Lab10: A,B,C

This program implements movie timeslot's ending time and print out the start and end time of movie
*/


#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


//find the time after midnight
int minutesSinceMidnight(Time time)
{
    int time_hour_minute = (time.h * 60) + time.m;
    
    return time_hour_minute;
}

//calculate the time between later and earlier time
int minutesUntil(Time earlier, Time later)
{
    int earlier_time;
    int later_time;
    int final_time;
    
    earlier_time = minutesSinceMidnight(earlier);
    later_time = minutesSinceMidnight(later);
    
    final_time = later_time - earlier_time;

    return final_time;
}

//add minutes to time
Time addMinutes(Time time0, int min)
{
    time0.m += min;
    
    while(time0.m >= 60)
    {
        time0.m -= 60;
        time0.h++;
    }
    return time0;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//function to print the timeslot of the movie
void printTimeSlot(TimeSlot timeslot)
{
    //calculates the end time of movie
    Time end_Time = addMinutes(timeslot.startTime, timeslot.movie.duration);

    //prints the movie time start, and time end
    printMovie(timeslot.movie);
    cout << " [starts at "<< timeslot.startTime.h << ":" << timeslot.startTime.m << ", ends by " << end_Time.h << ":" << end_Time.m << "]";
}


//Task D: Schedule X after Y
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot newTimeslot;
    Time nextTimeSlot = addMinutes(ts.startTime, ts.movie.duration);
    
    newTimeslot.startTime = nextTimeSlot;
    newTimeslot.movie = nextMovie;
    
    return newTimeslot;
}

//Task E: timeoverlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    
    int interval = minutesUntil(ts1.startTime, ts2.startTime);
    if (ts1.movie.duration > interval)
       return false;
    else
       return true;

}

//test case:
int main()
{
    scheduleAfter({{"Back to the Future", COMEDY, 116}, {9, 15}}, {"Black Panther", ACTION, 134});
}
