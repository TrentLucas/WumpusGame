// bat.h
//
// In this file are constructors, destructors, functions, and variables
// for the Bat class
//
// The bat class contains the functions that set and change the 
// health of the bats in the cave
////////////////////////////////////////////////////////////////////

#ifndef BAT_H
#define BAT_H


class Bat {
	public:
		// constructor
		Bat();

		//destructor
		~Bat();

		// functions		
		int getBatHealth();
		void setBatHealthDefault();
		void increaseBatHealth();

	private:

		// variables
		int batHealth;

};

#endif

