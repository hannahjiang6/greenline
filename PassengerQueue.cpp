/*
 *  PassengerQueue.cpp
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Holds all the functions for the queue, it includes
 *  all the functions that are able to be called for
 *  a queue list
 *
 */

#include <iostream>
#include <string>
#include <list>

#include "PassengerQueue.h"

/*
 * name:      front
 * purpose:   returns but does not remove the data of the first passenger
 * arguments: none
 * returns:   Passenger
 */
Passenger PassengerQueue::front() { 
    return p.front();
}

/*
 * name:      dequeue
 * purpose:   function to remove the first person in the queue
 * arguments: none
 * returns:   none
 */
void PassengerQueue::dequeue() {
    p.pop_front();
}
/*
 * name:      enqueue
 * purpose:   adds a new passenger to the end of the queue
 * arguments: Passenger &Passenger
 * returns:   none
 */
void PassengerQueue::enqueue(const Passenger &Passenger) {
    p.push_back(Passenger);
}

/*
 * name:      size
 * purpose:   returns an integer of the size of the passenger queue
 * arguments: none
 * returns:   int
 */
int PassengerQueue::size() {
    return p.size();
}

/*
 * name:      print
 * purpose:   prints all the passengers in the queue
 * arguments: output stream
 * returns:   none
 */
void PassengerQueue::print(std::ostream &output) {
    for (std::list<Passenger>::iterator it = p.begin(); 
        it != p.end(); it++) {
        it->print(output);
    }
}
