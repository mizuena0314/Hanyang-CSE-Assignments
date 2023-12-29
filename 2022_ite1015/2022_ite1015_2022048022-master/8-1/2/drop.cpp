#include "drop.h"
#include <cmath>
#include <iostream>

Planet::Planet (float gravity){ // Implement to store necessary data as member variable
    _gravity = gravity;
}

float Planet::drop (float height){ // Returns the time elapsed to drop an object from a specific height
    return sqrt(2*height/_gravity);
}

Earth::Earth():Planet(9.81f){} // Implement to call the parent class's constructor properly

void Earth::simulate(float height){ // Print out information about this object (ex. ‘Earth gravity = 9.81’) and the result of drop simulation(‘Drop from 30m, 2.4731 seconds.’).
    std::cout << "Earth gravity = " << _gravity << std::endl;
    std::cout << "Drop from " << height << "m, " << drop(height) << " seconds." << std::endl;
}

Moon::Moon():Planet(1.62f){} // Implement to call the parent class's constructor properly

void Moon::simulate(float height){ // Print out information about this object (ex. ‘Earth gravity = 9.81’) and the result of drop simulation(‘Drop from 30m, 2.4731 seconds.’).
    std::cout << "Moon gravity = " << _gravity << std::endl;
    std::cout << "Drop from " << height << "m, " << drop(height) << " seconds." << std::endl;
}
