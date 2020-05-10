/* 
 * File:   table.h
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:21 PM
 */

#ifndef TABLE_H
#define	TABLE_H

#include "game.h"

template<class T>
class Table : public Game{
    private:
        //Has A
        Player player;
        Hand dealer;
        Deck deck;
    public:
       Table(std::string);
       ~Table();
       bool gameOver();
       void resetGame();
};


#endif	/* TABLE_H */

