#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# Compiles MetroSim
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(LDFLAGS) -o MetroSim main.o MetroSim.o PassengerQueue.o Passenger.o


# Every .cpp file that is part of your program should have a .o rule.

# This rule builds main.o
main.o: main.cpp MetroSim.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# This rule builds MetroSim.o
MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.cpp
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

# This rule builds Passenger.o
Passenger.o: Passenger.cpp Passenger.h 
	$(CXX) $(CXXFLAGS) -c Passenger.cpp



# Compiles and runs unit_test
unit_test: unit_test_driver.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) $^


# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
					MetroSim.h MetroSim.cpp \
					main.cpp my.output ref.output \
				    unit_tests.h Makefile README

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
