/* 
 * File:   Player.h
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:22 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <iostream>
#include <iomanip>
#include "Hand.h"

class Player{
private:
  //Structure
    struct Data{
        std::string name;
        float cash;
        int plays;
    };
    Data data;
  //Cash
    float bet;
  //Game
    Hand hand;
    Hand splitHand;
public:
    bool doubleD;
    bool didSplit;
  //Constructor
    Player(std::string);
    void printData();
  //Structure
    void setData(std::string,float,int);
    void writeData(std::fstream&);
    void readData(std::fstream&);
  //Name
    std::string getName();
  //Cash
    void setBet(float);
    float getBet();
    float getCash();
    void anotherHand();
  //Game
    void deleteHand();
    Hand getHand();
    Hand getSplit();
    void hit(Card);
    void hitSplit(Card);
    void doubleDown();
    bool canSplit();
    void split();
    void surrender();
    void insurance();
    void end(int);
    int getHandValue();
    int getSplitValue();
    int getHandSize();
    int getSplitSize();
  //Graphic
    void printHand();
    void printSplit();
    void printValueHand();
    void printValueSplit();
};


#endif	/* PLAYER_H */

