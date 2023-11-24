#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "../Model/frog.hpp"
// Move commands: Edit the position of the frog in the model
// and calls the corresponding functions from view.hpp to edit
// user's interface

// ? Il faudrait une classe controlleur
// On travaille avec MVC
void goLeft(Frog frog);
void goRight(Frog frog);
void goFrwrd(Frog frog);
void goBkwrds(Frog frog);
void move();  

// Will take user's input in parameters and execute 
// the upper commands depending on the input.


#endif
