#pragma once

#pragma once
#include "Player.hpp"

#include <iostream>
namespace pandemic{

class OperationsExpert : public Player{
   
    public:
        OperationsExpert(pandemic::Board& board , pandemic::City city);
        Player& build(){
                if(board.node(city).getResearch_station()){ // if ther is stetion ->throw exption
                // cout <<board.node(city).getResearch_station()<<endl;
                        // throw std::out_of_range{"ERROR!! cant build twise reasach station!!.\n"};
                        return *this;
                }
                board.node(city).getResearch_station() = true;
                return *this;
        }
        std::string role(){
                return "OperationsExpert";
        }


};
}