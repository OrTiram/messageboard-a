#include "Direction.hpp"
#include <string>


namespace ariel{

    class Board{
        private:
        int count = 0 ;

        public:
        Board();
        ~Board();

        void post(unsigned int col, unsigned int row , Direction d , const std::string &mes);
        std::string read(unsigned int col, unsigned int row , Direction d , unsigned int len);
        void show();
    };
}