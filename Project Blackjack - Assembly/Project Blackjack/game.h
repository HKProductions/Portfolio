/* 
 * File:   game.h
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:21 PM
 */

#ifndef GAME_H
#define	GAME_H

#include "Player.h"
#include "Hand.h"
#include "Deck.h"

template<class T>
class Game{
    private:
        //Has A
        Player player;
        Hand dealer;
        Deck deck;
    public:
       virtual Game(std::string);
       virtual ~Game();
       virtual bool gameOver();
       virtual void resetGame();
};

#endif	/* GAME_H */

