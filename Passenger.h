/*
 *  Passenger.h
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Holds the struct for a single passenger, it has
 *  all the data for the passenger including the
 *  arrival/destination and a unique id  
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger {
    int id, from, to;
    
    Passenger()
    {
        id   = -1;
        from = -1;
        to   = -1;
    }

    Passenger(int newId, int arrivalStation, int departureStation)
    {
        id   = newId;
        from = arrivalStation;
        to   = departureStation;
    }

    void print(std::ostream &output);
};

#endif
