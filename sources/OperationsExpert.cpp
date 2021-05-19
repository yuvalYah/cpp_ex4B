
#include "OperationsExpert.hpp"

#include <iostream>
namespace pandemic{
    OperationsExpert::OperationsExpert(pandemic::Board& board , pandemic::City city):Player(board , city){}

//     Player& build(){
//         if(board.node(city).getResearch_station()){ // if ther is stetion ->throw exption
//         // cout <<board.node(city).getResearch_station()<<endl;
//                 throw std::out_of_range{"ERROR!! cant build twise reasach station!!.\n"};

//         }
//         board.node(city).getResearch_station() = true;
//         return *this;
//      }


}