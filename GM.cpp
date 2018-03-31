#include <iostream>
#include "GameCore.h"

using namespace CrossTheStones;

int main(){
	GameCore gc(9, 9);
	for(unsigned i = 0; i < 9; ++i)
		gc(i, 0) = BLACK, gc(i, 8) = WHITE;

	gc(0, 0) = BLACK;
	if(gc.move(0, 0, 0, 7))
		std::cout << "move success!\n";
	else
		std::cout << "move failed!\n";


	for(unsigned h = 0; h < 9; ++h){
		for(unsigned w = 0; w < 9; ++w)
			switch(gc(w, h)){
				case State::BLACK:
					std::cout << "X";
					break;
				case State::WHITE:
					std::cout << "O";
					break;
				case State::EMPTY:
					std::cout << " ";
					break;
				default:
					return 1;
			}
		std::cout << "\n";
	}
	return 0;
}
