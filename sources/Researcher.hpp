#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class Researcher : public Player{
    
    public:
        Researcher(pandemic::Board& board , pandemic::City city);
    Player& discover_cure(Color color)
    {
        int i =0;
        if(color == Color::Black) {i=0;}
        else if(color == Color::Blue) {i=1;}
        else if(color == Color::Red) {i=2;}
        else if(color == Color::Yellow) {i=3;}
        //
        
        if(board.gerColorArr(i)==false){
            int sum = 0;
            City cityColorArr[5];
            std::list<pandemic::City>::iterator it = cards.begin(); // we have the city card and , here dont has stetion
            while (it!=cards.end() && sum < 5) // move on cardlist
            {
                if(board.node(*it).getColor() ==  color) { // we get  tothe city card
                    cityColorArr[sum] = *it;
                    sum++;
                }
                it++;

            }
            if(sum < 5){
                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

            }
            if(sum == 5){
                it = cards.begin();
                sum =0 ;
                while (sum < 5 )  // move on cardlist
                {
                    it = cards.begin();
                    while(it!=cards.end()){
                        if(*it  ==  cityColorArr[sum]) { // we get  tothe city card
                            cards.remove(cityColorArr[sum]);
                            sum++;
                            break;

                        }
                        
                        it++;
                    }

                }
                board.gerColorArr(i) = true;
                
            }
        }
        return *this;
    }
    std::string role(){
        return "Researcher";
    }


};
}