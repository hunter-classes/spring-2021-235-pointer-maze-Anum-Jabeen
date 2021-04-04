#include <iostream>
#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
	bool spellbook = false;
	bool potion = false;
	bool wand = false;

	checkPosition(start, spellbook, potion, wand);

	for(int i=0; i<moves.length(); i++){
	    if(moves[i] == 'N' && start->north != nullptr){
		std::cout << "North" << std::endl;
	        start = start->north;
	        checkPosition(start, spellbook, potion, wand);
	    }else if(moves[i] == 'S' && start->south != nullptr){
		std::cout << "South" << std::endl;
		start = start->south;
                checkPosition(start, spellbook, potion, wand);
	    }else if(moves[i] == 'E' && start->east != nullptr){
                std::cout << "East" << std::endl;
                start = start->east;
                checkPosition(start, spellbook, potion, wand);
            }else if(moves[i] == 'W' && start->west != nullptr){
                std::cout << "West" << std::endl;
                start = start->west;
                checkPosition(start, spellbook, potion, wand);
            }else{
		return false;
	    }
	}
        return spellbook && potion && wand;
}

void checkPosition(MazeCell *start, bool &spellbook, bool &potion, bool &wand){
	if(start->whatsHere == Item::SPELLBOOK){
	   std::cout << "Got Spellbook" << std::endl; 
	   spellbook = true;
	}else if(start->whatsHere == Item::POTION){
           std::cout << "Got Potion" << std::endl;
           potion = true;
	}else if(start->whatsHere == Item::WAND){
           std::cout << "Got Wand" << std::endl;
           wand = true;
        }else if(start->whatsHere == Item::NOTHING){
	   return;
	}
}
