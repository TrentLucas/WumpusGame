// bat.cpp
// constructors, destructors, and functions for the bat class
///////////////////////

#include "bat.h"



// Constructor
Bat::Bat() {
	batHealth = 1;
}

// Destructor
Bat::~Bat() {
	batHealth = 0;
}

//////////////////////////////////////////
// *batHealth* getter
//////////////////////////////////////////
int Bat::getBatHealth() {
	return batHealth;
}

//////////////////////////////////////////
// *batHealth* sets batHealth to 1 after fly
//////////////////////////////////////////
void Bat::setBatHealthDefault() {
	batHealth = 1;
}

//////////////////////////////////////////
// increases batHealth
//////////////////////////////////////////
void Bat::increaseBatHealth() {
	batHealth++;
	
}
