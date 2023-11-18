/*
 *  main.cpp
 *  Hannah Jiang (hjiang03)
 *  2/8/2023
 *
 *  CS 15 PROJECT 1 MetroSim
 *
 *  FILE PURPOSE:
 *  Simple program that runs a train simulation
 *  
 *  Usage: ./MetroSim stationsFile outputFile [commandsFile]
 *  
 *  Reads in the inputs and decides whether to run by
 *  manual commands or by a commandFile
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

// function declaration for opening files
template<typename streamtype>
void openFile(streamtype &stream, string file_name);

int main(int argc, char *argv[])
{
    // check for valid input
    if (argc < 3) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]\n";
        exit(EXIT_FAILURE);
    }

    MetroSim my_MetroSim;

    ifstream instream;
    ofstream outstream;

    openFile(outstream, argv[2]);

    // plays the game depending on the inputs
    if (argc == 3) {
        // run without command file
        my_MetroSim.run_game(argv[1], cin, outstream);
    } else {
        // run with command file
        openFile(instream, argv[3]);
        my_MetroSim.run_game(argv[1], instream, outstream);

        instream.close();
    }
    outstream.close();
    return 0;
}

// opens up the files
template<typename streamtype>
void openFile(streamtype &stream, std::string file_name) {
    stream.open(file_name);
    if (not stream.is_open()) {
        std::cerr << "Error: could not open file ";
        std::cerr << file_name << std::endl;
        exit(EXIT_FAILURE);
    }
}