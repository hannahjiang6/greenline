/*
 *  PassengerQueue.h
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Interface for the PassengerQueue list
 *
 */


#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include <fstream>
#include <list>

#include "Passenger.h"

class PassengerQueue {
public:

    Passenger front();

    void dequeue();
    void enqueue(const Passenger &passenger);

    int size();
    void print(std::ostream &output);

private:
    
    // passenger list
    std::list<Passenger> p;

};

#endif
