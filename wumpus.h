// wumpus.h
//
// In this file are constructors, destructors, methods, functions, and variables
// for the Wumpus class
//
// The Wumpus class contains the functions to set and change
// the health, tiredness, and room the Wumpus is in
////////////////////////////////////////////////////////////////////

#ifndef WUMPUS_H
#define WUMPUS_H

class Wumpus {
	public:

		// constructors
		Wumpus();

		// destructor
		~Wumpus();

		// functions		
		void setWumpusTiredness(int value);
		int getWumpusHealth();
		int getWumpusTiredness();
		int getRoom();
		void changeRoom(int room);
		void changeWumpusTiredness();
		void wumpusDead();


	private:
		// functions

	
		// variables
		int wumpusHealth;
		int wumpusTiredness;
		int wumpusRoom;
		
};

#endif
