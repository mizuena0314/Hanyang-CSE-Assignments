#pragma once

class Planet {
public:
	Planet (float gravity); // Implement to store necessary data as member variable
	float drop (float height); // Returns the time elapsed to drop an object from a specific height
protected:
// Define member variables you need
    float _gravity;
};

class Earth: public Planet {
public:
	Earth (); // Implement to call the parent class's constructor properly
	void simulate(float height); // Print out information about this object (ex. ‘Earth gravity = 9.81’) and the result of drop simulation(‘Drop from 30m, 2.4731 seconds.’).
};

class Moon: public Planet {
public:
	Moon (); // Implement to call the parent class's constructor properly
	void simulate(float height); // Print out information about this object (ex. ' Moon gravity = 1.62') and the result of drop simulation(‘Drop from 30m, 6.08581 seconds.’).
};
