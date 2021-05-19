#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class Dispatcher : public Player{
    
    public:
        Dispatcher(pandemic::Board& board , pandemic::City city);
        Player& fly_direct(City c) 
        {
                if(city == c){
                         throw std::out_of_range{"Error!! cannot fly from city to it self\n"};

                }
                if(board.node(city).getResearch_station()==false){
                        Player::fly_direct(c);
                        // throw std::out_of_range{"ERROR!! Dispatcher cant fly_direct to this place - need to build Research_station.\n"};
                }
                city = c;
                return *this;
        }
        std::string role(){
                return "Dispatcher";
        }


};
}