/*
 *  Passenger.cpp
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Holds the print function for the passenger
 *
 */

#include <iostream>
#include <string>

#include "Passenger.h"

/*
 * name:      print 
 * purpose:   prints from the given data and sends it
 *            the given file from the user
 * arguments: ostream &output
 * returns:   none
 */
void Passenger::print(std::ostream &output)
{   
    output << "[" << id << ", ";
    output << from << "->";
    output << to << "]";
}
