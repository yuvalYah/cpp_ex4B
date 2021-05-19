#include "Player.hpp"
#include <iostream>
#include <array>

using namespace std;
const int need5cards = 5;

namespace pandemic{

    Player::Player(Board& bo , City ci) : board(bo),city(ci){
        // take_card(ci);
        // for(int i =0 ; i < 4 ; i++){
        //     colorArr[i] = false;
        // }
                //black blue  red    yellow
     }              

    Player& Player::drive(City c) 
    {
        if(!board.node(city).is_nib(c)){
            throw std::out_of_range{"ERROR!! cant drive to this place.\n"};
            
        }
        city = c;
        return *this;
    }
    Player& Player::fly_direct(City c) 
    {
        if(!has_card(c)){
            throw std::out_of_range{"ERROR!! cant fly_direct to this place - need to take fit card.\n"};
        }
        std::list<pandemic::City>::iterator it = cards.begin();
        while (it!=cards.end())
        {
            if(*it ==  c) {
                city = c;
                cards.remove(c);
                break;
            }
            it++;
        }

        return *this;
    }
    Player& Player::fly_charter(City c)
    {
        if(!has_card(city)){
            
            throw std::out_of_range{"ERROR!! cant fly_charter to this place - need to take fit card.\n"};
        }
        std::list<pandemic::City>::iterator it = cards.begin();
        while (it!=cards.end())
        {
            if(*it ==  city) {
                cards.remove(city);

                city = c;
                // cards.remove(city);
                break;
            }
            it++;
        }

        return *this;
    }
    Player& Player::fly_shuttle(City c)
    {
        if(city == c){
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place -cannot fly from city to it self!!.\n"};

        }
        if(!board.node(city).getResearch_station()){
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place - need reaearch station in current city!!.\n"};
        }
        if(!board.node(c).getResearch_station()){
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place - need reaearch station in fly city!!.\n"};
        }
        city = c;
        return *this;
    }
    Player& Player::build()
    {
        if(board.node(city).getResearch_station()){ // if ther is stetion ->throw exption
            // throw std::out_of_range{"ERROR!! cant build twise reasach station!!.\n"};
            return *this;

        }
        if(!has_card(city)){//if we dont have the card of this city
            throw std::out_of_range{"ERROR!! cant build on this place - you dont hava fit card!!.\n"};


        }
        std::list<pandemic::City>::iterator it = cards.begin(); // we have the city card and , here dont has stetion
        while (it!=cards.end()) // move on cardlist
        {
            if(*it ==  city) { // we get  tothe city card
                cards.remove(city); // remove
                // board.node(city).setResearch_station(true); // 
                board.node(city).getResearch_station() = true;
                break;
            }
            it++;
        } 
        return *this;
    }
    Player& Player::discover_cure(Color color)
    {
        int i =0;
        if(color == Color::Black) {i=0;}
        else if(color == Color::Blue) {i=1;}
        else if(color == Color::Red) {i=2;}
        else if(color == Color::Yellow) {i=3;}
        //
        if(!board.node(city).getResearch_station()){
            throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
        }
        if(!board.gerColorArr(i)){
            uint sum = 0;
            // City cityColorArr[5];
            array<City,need5cards> cityColorArr{};
            std::list<pandemic::City>::iterator it = cards.begin(); // we have the city card and , here dont has stetion
            while (it!=cards.end() && sum < need5cards) // move on cardlist
            {
                if(board.node(*it).getColor() ==  color) { // we get  tothe city card
                    cityColorArr.at(sum) = *it;
                    sum++;
                }
                it++;

            }
            if(sum < need5cards){
                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

            }
            if(sum == need5cards){
                it = cards.begin();
                sum =0 ;
                while (sum < need5cards)  // move on cardlist
                {
                    it = cards.begin();
                    while(it!=cards.end()){
                        if(*it  ==  cityColorArr.at(sum)) { // we get  tothe city card
                            cards.remove(cityColorArr.at(sum));
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
    Player& Player::treat(City c)
    {
        if(c != city)
        {
            throw std::out_of_range{"ERROR!! this city need to be == to other city\n"};

        }
        if( board.node(c).get_disease_cubes() == 0){
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0)) {discoverCure = true;}
        if(cityColor == Color::Blue && board.gerColorArr(1)) {discoverCure = true;}
        if(cityColor == Color::Red &&board.gerColorArr(2)) {discoverCure = true;}
        if(cityColor == Color::Yellow &&board.gerColorArr(3)) {discoverCure = true;}

        if(discoverCure){
            board.node(c).get_disease_cubes() = 0;
            return *this;

        }
        board.node(c).get_disease_cubes() = board.node(c).get_disease_cubes()-1;
     
        
        return *this;
    }

    std::string Player::role()
    {
        return "Player";
    }//return the part of the plyer in the game , not implaments here
    Player& Player::take_card(City c)
    {
        cards.push_back(c);
        return *this;
    }


    bool Player::has_card(City c){
        std::list<pandemic::City>::iterator it = cards.begin();
        while (it!=cards.end())
        {
            if(*it ==  c) {return true;}
            it++;
        }
        return false;
    }


   
}