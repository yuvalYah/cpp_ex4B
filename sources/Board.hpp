#pragma once
#include "City.hpp"
#include "Color.hpp"

#include <algorithm>
#include <iostream>
#include <list>
#include <map>


namespace pandemic{

    class NodeCity{
        private:
            pandemic::City city; //the city he represent
            pandemic::Color color; // the color he represent
            int levelD; // sum of desies cube
            std::list<pandemic::City> nib_city; // nub of this city
            bool Research_station; 
        public:
            // NodeCity();
            NodeCity(pandemic::City ci , pandemic::Color co ,std::list<pandemic::City> nib):city(ci),color(co),nib_city(nib),levelD(0){
                Research_station = false;
                levelD = 0;
            }
            ~NodeCity(){}
            int &get_disease_cubes() { 
                // std::s << levelD << "dgdg" <<std::endl;

                return levelD;
                }
            void set_disease_cubes( int s) { levelD = s;}
            
            bool is_nib(pandemic::City c);
            bool &getResearch_station() {
                // std::cout<<std::boolalpha <<Research_station<<"\n";
                return Research_station;}
            void setResearch_station(bool ans) {Research_station = !Research_station;}
            Color getColor(){
                return color;
            }
            




    };
    class Board{
        private:
            bool clean = true;
            // std::map<pandemic::City,NodeCity(pandemic::City, pandemic::Color ,std::list<pandemic::City>)> board; 
            std::map<pandemic::City,NodeCity> board; 
            bool colorArr[4];

            void initBoard();
        public:
            Board(){
                initBoard();
                 for(int i =0 ; i < 4 ; i++){
                    colorArr[i] = false;
                }
            }
            // const int operator[](pandemic::City city) const; //get number of disease
            int& operator[](pandemic::City city);

            friend std::ostream& operator<< (std::ostream& os, const Board& c);
            bool is_clean();
            void remove_cures();
            NodeCity& node(pandemic::City city){ // return the node from the map board ->help on player
                return board.at(city);
            }
            bool& gerColorArr(int ind){
                return colorArr[ind];
            }




    };
}