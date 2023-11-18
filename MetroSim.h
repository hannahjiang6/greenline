/*
 *  MetroSim.h
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Holds the interface of the MetroSim.cpp file
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

// Put any other necessary includes here
#include "PassengerQueue.h"

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>


// Put any other structs you need here
struct Station {
    std::string stationName;
    PassengerQueue sq; // sq = station queue
    int stationId;
};

struct Train {
    int trainId;
    PassengerQueue tq; // tq = train queue
};

class MetroSim {
public:

    // initialize the game
    MetroSim();

    // runs the game
    void run_game(std::string stationsFile, std::istream &input, 
                  std::ostream &output);


private:

    // read the stations file
    void readStations(std::string stationsFile);

    // initialize the stations
    void init_stations(std::istream &stationsFile);

    // initialize train;
    void init_train();

    // query loop
    bool query(std::istream &input, std::ostream &output);

    // printing the game interface
    void print_passengers();
    void print_stations();
    
    // add passengers functions
    void addPassenger(int arrival, int departure);
    void addSp(Passenger passenger, int arrival);
    void addTp(Passenger passenger, int departure);

    // check queue functions
    void checkQueue();
    void checkTq(std::ostream &output);

    // move the train
    void moveTrain(std::ostream &output);

    // sending output
    void passenger_left(Passenger passenger, std::ostream &output);

    // exiting the game
    bool exitGame();

    std::vector<Station> stations;
    std::vector<Train> train;
    int train_location;
    int numPassengers;
    int numStations;

};

#endif
