// room.h
//
// In this file are constructors, destructors, methods, functions, and variables
// for the Room class
//
// The room class contains the variables isBat, isPit, and isWumpus 
// to determine what is inside a room
//
// The room class also includes the bat class and updates the batHealth 
// based on the turn
////////////////////////////////////////////////////////////////////

#ifndef ROOM_H
#define ROOM_H

#include "bat.h"

class Room {
	public:

		// constructor
		Room();
		~Room();


		// functions		
		void setBat();
		void setPit();
		bool getBats();
		bool getPit();
		void nextTurn();

		Bat bat;

	private:

		// variables
		bool isBat;
		bool isPit;
		bool isWumpus;
		int roomNumber;
};

#endif
