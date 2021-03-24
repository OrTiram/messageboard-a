#include "Board.hpp"
using namespace std;

namespace ariel{
Board::Board(){
    count = 0;
}
Board:: ~Board(){}

void Board::post(unsigned int col, unsigned int row , Direction d , const std::string &mes){}
string Board::read(unsigned int col, unsigned int row , Direction d , unsigned int len){
    count ++;
    return "";
}
void Board::show(){}

};