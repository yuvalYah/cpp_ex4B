#pragma once
#include "Board.hpp"
#include <iostream>
namespace pandemic{

    class Player{
        protected :
            Board& board ;
            City city;
            std::list<pandemic::City> cards;
            // bool colorArr[4];//
        public:
            Player(Board& board , City city);
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat( City c);

            virtual std::string role();//return the part of the plyer in the game , not implaments here
            Player& take_card(City c);


            bool has_card(City c);

    };
}