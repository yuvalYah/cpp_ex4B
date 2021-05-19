#pragma once

#include "Player.hpp"

#include <iostream>
namespace pandemic{

class Scientist : public Player{
    private:

        int n;
    public:
        Scientist(pandemic::Board& board , pandemic::City city, int);
        Player& discover_cure(Color color)
        {
                int i =0;
                if(color == Color::Black) {i=0;}
                else if(color == Color::Blue) {i=1;}
                else if(color == Color::Red) {i=2;}
                else if(color == Color::Yellow) {i=3;}
                //
                // cout<<cards.size()<<endl;
                if(board.node(city).getResearch_station() == false){
                throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
                }
                if(board.gerColorArr(i)==false){
                        int sum = 0;
                        City cityColorArr[n];
                        std::list<pandemic::City>::iterator it = cards.begin(); // we have the city card and , here dont has stetion
                        while (it!=cards.end() && sum < n) // move on cardlist
                        {
                                if(board.node(*it).getColor() ==  color) { // we get  tothe city card
                                cityColorArr[sum] = *it;
                                sum++;
                                }
                                it++;

                        }
                        if(sum < n){
                                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

                        }
                        if(sum == n){
                                it = cards.begin();
                                sum =0 ;
                                while (sum < n )  // move on cardlist
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
                return "Scientist";
        }


};
}