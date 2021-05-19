#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class GeneSplicer : public Player{
    
    public:
        GeneSplicer(pandemic::Board& board , pandemic::City city);
        Player& discover_cure(Color color)
        {
            /*bool canDisc= false;
            if(!board.gerColorArr(0)){
                Player::discover_cure(Color::Black);
                if(board.gerColorArr(0)) canDisc= true;
            }
            if(!canDisc && !board.gerColorArr(1)){
                Player::discover_cure(Color::Blue);
                if(board.gerColorArr(1)) canDisc= true;
            }
            if(!canDisc && !board.gerColorArr(2)){
                Player::discover_cure(Color::Red);
                if(board.gerColorArr(2)) canDisc= true;
            }
            if(!canDisc && !board.gerColorArr(3)){
                Player::discover_cure(Color::Yellow);
                if(board.gerColorArr(3)) canDisc= true;
            }  
            return *this; */
            int i =0;
            if(color == Color::Black) {i=0;}
            else if(color == Color::Blue) {i=1;}
            else if(color == Color::Red) {i=2;}
            else if(color == Color::Yellow) {i=3;}
            //
            std::cout<<cards.size()<<std::endl;
            if(board.node(city).getResearch_station() == false){
                throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
            }
            if(board.gerColorArr(i)==false){
                
                if(cards.size()<5){
                    throw std::out_of_range{"ERROR!! you dont hava enogh cards.\n"};

                }
                std::list<pandemic::City>::iterator it = cards.begin(); // we have the city card and , here dont has stetion

                int sum =0 ;
                while (sum < 5 )  // move on cardlist
                {
                    it = cards.begin();
                    while(it!=cards.end()){
                        // if(*it ) { // we get  tothe city card
                            cards.remove(*it);
                            sum++;
                            break;

                        // }
                        
                        it++;
                    }

                }
                std::cout<<board.gerColorArr(i)<<std::endl;
                board.gerColorArr(i) = true;
                std::cout<<board.gerColorArr(i)<<std::endl;

                    
                
            }
            return *this; 
        }
        std::string role()
        {
            return "GeneSplicer";
        }


};
}