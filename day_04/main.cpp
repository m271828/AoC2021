#include <fstream>
#include <iostream>
#include "bingo.h"

int main()
{
    Bingo cards("input");
    
    for(int i = 0; i < 4; i++) {
        cards.nextCall();
    }

    while(cards.moreCalls()) {
        cards.nextCall();
        if(cards.isWinner()) {
            std::cout << "Is winner" << std::endl;
            std::cout << cards.score() << std::endl;
        }
    }

    std::cout << "Finished game." << std::endl;
    return 0;
}