#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class Virologist : public Player{
    
    public:
        Virologist(pandemic::Board& board , pandemic::City city);
        Player& treat(City c)
        {
        if(city !=c &&!has_card(c)){//if we dont have the card of this city
            throw std::out_of_range{"ERROR!! Virologist cant treat on this place - you dont hava fit card!!.\n"};
        }
        if( board.node(c).get_disease_cubes() == 0){
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        if(city == c){
            Player::treat(c);
            return *this;
        }
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black && board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red &&board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}

        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            return *this;

        }
        board.node(c).get_disease_cubes() = board.node(c).get_disease_cubes()-1;
        cards.remove(c);
        return *this;
    }

    std::string role()
    {
        return "Virologist";
    }


};
}