/*
 *  MetroSim.cpp
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Holds all the functions that allows the MetroSim game to run
 *
 */

#include "MetroSim.h"

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>

/*
 * name:      MetroSim
 * purpose:   initialize the MetroSim game
 * arguments: none
 * returns:   none
 */
MetroSim::MetroSim() {
    train_location = 0;
    numPassengers = 0;
    numStations = 0;
}

/*
 * name:      run_game
 * purpose:   runs the program
 * arguments: stationsFile, input stream, output stream
 * returns:   none
 */
void MetroSim::run_game(std::string stationsFile, std::istream &input, 
                        std::ostream &output) {
    bool game_over = false;
    readStations(stationsFile);
    while (not game_over) {
        print_stations();
        if (query(input, output) == true) {
            game_over = true;
        }
    }
}

/*
 * name:      readStations
 * purpose:   read in the stationsFile
 * arguments: stationsFile
 * returns:   none
 */
void MetroSim::readStations(std::string stationsFile) {
    std::ifstream infile;
    // opening the stationsFile
    infile.open(stationsFile);
    if (not infile) {
        // checking if the file is valid
        std::cerr << "Error: could not open file ";
        std::cerr << stationsFile << std::endl;
        exit(EXIT_FAILURE);
    } else {
        // intialize the stations and train vector with the valid file
        init_stations(infile);
        // don't forget to close the file afterwards
        infile.close();
    }
}

/*
 * name:      init_stations
 * purpose:   initializes stations using station file
 * arguments: stationsFile
 * returns:   none
 */
void MetroSim::init_stations(std::istream &stationsFile) {
    std::string stationName;
    // intialize an empty PQ for each station
    PassengerQueue empty_sq{};
    while (not stationsFile.eof()) {
        // reads in the station names
        std::getline(stationsFile, stationName);
        
        // check for case where empty lines at the end of the file
        if (not stationName.empty()) {
            numStations++;
            Station initialize{stationName, empty_sq, numStations-1};
            stations.push_back(initialize);
        }
    }
    // initialize trains based on the number of stations
    init_train();
}

/*
 * name:      init_train
 * purpose:   initializes train based on the number of stations
 * arguments: none
 * returns:   none
 */
void MetroSim::init_train() {
    PassengerQueue empty_tq{};
    for (int i = 0; i < numStations; i++) {
        Train initialize{i, empty_tq};
        train.push_back(initialize);
    }
}

/*
 * name:      print_passengers
 * purpose:   prints all the passengers on the train
 * arguments: none
 * returns:   none
 */
void MetroSim::print_passengers() {
    std::cout << "Passengers on the train: {";
    for (std::vector<Train>::iterator it = train.begin();
    it != train.end(); it++) {
        // prints the passengers on the train
        it->tq.print(std::cout); 
    }
    std::cout << "}" << std::endl;
}

/*
 * name:      print_stations
 * purpose:   prints the stations from the station struct
 * arguments: none
 * returns:   none
 */
void MetroSim::print_stations() { 
    int counter = 0;
    print_passengers();
    for (std::vector<Station>::iterator it = stations.begin();
        it != stations.end(); it++) {
        // check which line to print train on
        if (train_location == counter) {
            std::cout << "TRAIN: ";
        } else {
            std::cout << "       ";
        }
        // prints the station name/id
        std::string sn = it->stationName;
        std::cout << "[" << it->stationId << "] ";
        std::cout << sn << " {";
        it->sq.print(std::cout);
        std::cout << "}" << std::endl;
        counter++;
    } 
}

/*
 * name:      query
 * purpose:   the commands for the game
 * arguments: intput stream, output stream
 * returns:   bool
 */
bool MetroSim::query(std::istream &input, std::ostream &output) {
    // prompts the user for query
    std::string query;
    std::cout << "Command? ";
    input >> query;
    // decides what the command will do
    if (query == "p") {
        int arrival;
        int departure;
        // take in the necessary information to add a passenger
        input >> arrival >> departure;
        addPassenger(arrival, departure);
    } else if (query == "m") {
        char move;
        // decides whether or not the train will move on space or exit the game
        input >> move;
        if (move == 'm') {
            // moves the train
            checkQueue();
            moveTrain(output);
        } else if (move == 'f') {
            // exits the game
            exitGame();
            return true;
        }
    }
    return false;
}

/*
 * name:      addPassenger
 * purpose:   adds a passenger to the station
 * arguments: int arrival, int departure
 * returns:   none
 */
void MetroSim::addPassenger(int arrival, int departure) {
    numPassengers++;
    // creates a new passenger
    Passenger new_passenger(numPassengers, arrival, departure); 
    // add station passenger
    addSp(new_passenger, arrival);
}

/*
 * name:      addSp
 * purpose:   adds a passenger to the station queue
 * arguments: Passenger passenger, int arrival
 * returns:   none
 */
void MetroSim::addSp(Passenger passenger, int arrival) {
    // enqueue the station passenger and reprint
    stations.at(arrival).sq.enqueue(passenger);
}

/*
 * name:      addTp
 * purpose:   adds a passenger to the train queue 
 * arguments: Passenger passenger, int depature
 * returns:   none
 */
void MetroSim::addTp(Passenger passenger, int departure) {
    // enqueue the train passenger and reprint
    train.at(departure).tq.enqueue(passenger);
}

/*
 * name:      checkQueue
 * purpose:   checks the station queue to see if anyone is at the station
 * arguments: none
 * returns:   none
 */
void MetroSim::checkQueue() {
    // if there are people add them to the train queue
    while (stations.at(train_location).sq.size() > 0) {
        // take the front passengers information
        Passenger stationPassenger = stations.at(train_location).sq.front();
        // add front passenger to the train queue
        addTp(stationPassenger, stationPassenger.to);
        // dequeue the front passenger
        stations.at(train_location).sq.dequeue();
    }
}

/*
 * name:      checkTq
 * purpose:   checks the train queue station
 * arguments: output stream
 * returns:   none
 */
void MetroSim::checkTq(std::ostream &output) {
    while (train.at(train_location).tq.size() > 0) {
        Passenger trainPassenger = train.at(train_location).tq.front();
        passenger_left(trainPassenger, output);
        train.at(train_location).tq.dequeue();
    }
}

/*
 * name:      moveTrain
 * purpose:   moves the train one index loops 
 *            around if stationNum = train location
 * arguments: output stream
 * returns:   none
 */
void MetroSim::moveTrain(std::ostream &output) {
    train_location++;
    if (train_location == numStations) {
        train_location = 0;
    }
    checkTq(output);
}

/*
 * name:      passenger_left
 * purpose:   sends when a passenger leaves to the output file
 * arguments: Passenger passenger, output stream
 * returns:   none
 */
void MetroSim::passenger_left(Passenger passenger, std::ostream &output) {
    output << "Passenger ";
    output << passenger.id;
    output << " left train at station ";
    output << stations.at(train_location).stationName;
    output << std::endl;
}

/*
 * name:      exitGame
 * purpose:   exits the game
 * arguments: none
 * returns:   bool
 */
bool MetroSim::exitGame() {
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << std::endl;
    return true;
}   
