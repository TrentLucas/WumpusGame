// room.cpp
// constructors, destructors, and functions for the room class
///////////////////////

#include "room.h"



// Constructor
Room::Room() {
	isBat = false;
	isPit = false;
	isWumpus = false;
}

// Destructor
Room::~Room() {
	isBat = false;
	isPit = false;
	isWumpus = false;
}

//////////////////////////////////////////
// *isBat* setter
//////////////////////////////////////////
void Room::setBat() {
	isBat = true;
}

//////////////////////////////////////////
// *isPit* setter
//////////////////////////////////////////
void Room::setPit() {
	isPit = true;
}

//////////////////////////////////////////
// *isBat* getter
//////////////////////////////////////////
bool Room::getBats() {
	return isBat;
}

//////////////////////////////////////////
// *isPit* getter
//////////////////////////////////////////
bool Room::getPit() {
	return isPit;
}

//////////////////////////////////////////
// nextTurn. increase batHealth for the bat 
// in the room if there is one
//////////////////////////////////////////
void Room::nextTurn() {
	
	if (getBats() == true) {
		bat.increaseBatHealth();
	}
}
