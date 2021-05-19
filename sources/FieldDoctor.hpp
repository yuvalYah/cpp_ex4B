#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class FieldDoctor : public Player{
    
    public:
        FieldDoctor(pandemic::Board& board , pandemic::City city);
    Player& treat(City c)
    {
        if(city !=c && !board.node(city).is_nib(c))
        {
            throw std::out_of_range{"ERROR!! FieldDoctor can treat only in nib city\n"};

        }
        if( board.node(c).get_disease_cubes() == 0){
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}

        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            return *this;

        }
        board.node(c).get_disease_cubes() = board.node(c).get_disease_cubes()-1;
     
        
        return *this;
    }

    std::string role()
    {
        return "FieldDoctor";
    }


};
}