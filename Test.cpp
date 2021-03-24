
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("Empty messages"){
    Board board;
    CHECK(board.read(0,0,Direction::Vertical,5) == ("_____"));
    CHECK(board.read(0,0,Direction::Horizontal,5) == ("_____"));
    board.post(120,120,Direction::Horizontal,"Or");
    CHECK(board.read(120,120,Direction::Horizontal,3) == ("Or_"));
	board.post(120,122,Direction::Horizontal,"T");
	CHECK(board.read(120,121, Direction::Horizontal, 3) == "rT_");
	board.post(0,0,Direction::Horizontal, "b");
	CHECK(board.read(0,0, Direction::Vertical, 3) == ("b__"));
    board.post(300,300, Direction::Horizontal,"   ");
    CHECK((board.read(300,300,Direction::Horizontal,3)) == ("   "));
    board.post(1000,1000, Direction::Horizontal,"     ");
    CHECK((board.read(1000,1000,Direction::Horizontal,5)) == ("   "));

}


TEST_CASE("Random case")
 {
    Board board;
    board.post(10,10, Direction::Horizontal,"Orti");
    CHECK((board.read(10,10,Direction::Horizontal,4)) == ("Orti"));
    board.post(20,20, Direction::Vertical,"Tiram");
    CHECK((board.read(20,20,Direction::Vertical,5)) == ("Tiram"));
    board.post(30,30, Direction::Horizontal,"hello");
    CHECK((board.read(30,30,Direction::Horizontal,5)) == ("hello"));
    board.post(30,35, Direction::Vertical,"world");
    CHECK((board.read(30,30,Direction::Vertical,10)) == ("helloworld"));
    board.post(40,40, Direction::Horizontal,"fast");
    CHECK((board.read(40,40,Direction::Horizontal,4)) == ("fast"));
    board.post(50,50, Direction::Vertical,"food");
    CHECK((board.read(50,50,Direction::Vertical,5)) == ("food_"));
    board.post(60,60, Direction::Horizontal,"pizza");
    CHECK((board.read(60,60,Direction::Horizontal,5)) == ("pizza"));
    board.post(70,70, Direction::Vertical,"hat");
    CHECK((board.read(70,70,Direction::Vertical,3)) == ("hat"));

 }


TEST_CASE("Override previous message")
    {
     Board board;
     board.post(0,0, Direction::Horizontal,"Or");
     board.post(0,1, Direction::Horizontal,"T");
     CHECK((board.read(0,0,Direction::Horizontal,2)) == ("OT"));
     board.post(100,100, Direction::Horizontal,"hello");
     board.post(100,100, Direction::Horizontal,"wo");
     CHECK((board.read(100,100,Direction::Horizontal,5)) == ("wollo"));
     board.post(20,20, Direction::Horizontal,"world");
     board.post(20,24, Direction::Horizontal,"if");
     CHECK((board.read(20,20,Direction::Horizontal,7)) == ("worldif"));
     board.post(10,10, Direction::Horizontal,"dogs");
     board.post(10,12, Direction::Horizontal,"od");
     CHECK((board.read(10,10,Direction::Horizontal,4)) == ("dood"));
     board.post(10,14, Direction::Horizontal,"ss");
     CHECK((board.read(10,10,Direction::Horizontal,6)) == ("doodss"));



}
