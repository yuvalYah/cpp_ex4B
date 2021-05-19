#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class Medic : public Player{
    
    public:
        Medic(pandemic::Board &board , pandemic::City city);
    Player& treat(City c)
    {
        if(c != city)
        {
            throw std::out_of_range{"ERROR!! this city need to be === to other city\n"};

        }
        if( board.node(c).get_disease_cubes() == 0){
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        // Color cityColor = board.node(city).getColor();
        // bool discoverCure = false;
        // if(cityColor == Color::Black &&colorArr[0] == true) {discoverCure = true;}
        // else if(cityColor == Color::Blue && colorArr[1] == true) {discoverCure = true;}
        // else if(cityColor == Color::Red &&colorArr[2] == true) {discoverCure = true;}
        // else if(cityColor == Color::Yellow &&colorArr[3] == true) {discoverCure = true;}

        // if(discoverCure){
        //     board.node(c).get_disease_cubes() = 0;
        //     return *this;

        // }
        board.node(c).get_disease_cubes() = 0;
     
        
        return *this;
    }
    Player& drive(City c){
        
        Color cityColor = board.node(c).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}

        Player::drive(c);
        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            
        }
        return *this;

    }
    Player& fly_direct(City c)
    {
        Color cityColor = board.node(c).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}
        Player::fly_direct(c);
        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            
        }
        return *this;
    }
    Player& fly_charter(City c){
        bool discoverCure = false;
        Color cityColor = board.node(c).getColor();
        if(cityColor == Color::Black &&board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}
        Player::fly_charter(c);
        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            
        }
        return *this;
    }
    Player& fly_shuttle(City c){
        bool discoverCure = false;
        Color cityColor = board.node(c).getColor();
        if(cityColor == Color::Black && board.gerColorArr(0) == true) {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) {discoverCure = true;}
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true) {discoverCure = true;}
        Player::fly_shuttle(c);
        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            
        }
        return *this;
    }
    std::string role(){
        return "Medic";
     }


};
}