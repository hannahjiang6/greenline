/*
 *  unit_tests.h
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  File to test cases for my program: MetroSim
 *
 */

#include <iostream>
#include <string>
#include <cassert>

#include "PassengerQueue.h"
#include "MetroSim.h"

// tests if the printed output get sent to the file
void Passenger_Print() {
    std::ofstream file("test.txt");
    Passenger passenger(1, 5, 6);
    passenger.print(std::cout);
}

// test the enqueue and dequeue
void Passenger_queue_dequeue() {
    PassengerQueue PQ{};
    
    Passenger passenger1(1, 5, 6);
    Passenger passenger2(2, 5, 6);
    Passenger passenger3(3, 5, 6);
    Passenger passenger4(4, 5, 6);

    PQ.enqueue(passenger1);
    PQ.enqueue(passenger2);
    PQ.enqueue(passenger3);
    PQ.enqueue(passenger4);
    assert(PQ.size() == 4);

    PQ.dequeue();
    PQ.dequeue();
    PQ.dequeue();
    PQ.dequeue();
    assert(PQ.size() == 0);
}

// test whether it prints an entire queue of passengers
void Passenger_queuePrint() {
    PassengerQueue PQ{};
    
    Passenger passenger1(1, 5, 6);
    Passenger passenger2(2, 5, 6);
    Passenger passenger3(3, 5, 6);
    Passenger passenger4(4, 5, 6);

    PQ.enqueue(passenger1);
    PQ.enqueue(passenger2);
    PQ.enqueue(passenger3);
    PQ.enqueue(passenger4);

    PQ.print(std::cout);
}

void Passenger_front() {
    PassengerQueue PQ{};

    Passenger passenger1(1, 5, 6);
    Passenger passenger2(2, 5, 6);
    Passenger passenger3(3, 5, 6);
    Passenger passenger4(4, 5, 6);

    PQ.enqueue(passenger1);
    PQ.enqueue(passenger2);
    PQ.enqueue(passenger3);
    PQ.enqueue(passenger4);

    Passenger P;

    P = PQ.front();
    P.print(std::cout);
}

// test for my intializing stations
    // for (std::vector<Station>::iterator it = stations.begin();
    //     it != stations.end(); it++) {
    //     std::string sn = it->stationName;
    //     std::cout << sn << std::endl;
    // }
    // std::cout << numStations << std::endl;

// test for initializing my train vector
    // std::cout << "initializing trains" << std::endl;
    // for (std::vector<Train>::iterator it = train.begin();
    //     it != train.end(); it++) {
    //     int location = it->location;
    //     std::cout << location << std::endl;
    // }
    // std::cout << train.size() << std::endl;