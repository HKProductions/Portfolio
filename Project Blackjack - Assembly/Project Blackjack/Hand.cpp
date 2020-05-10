/* 
 * File:   Hand.cpp
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:27 PM
 */

#include <iostream>
#include <string>
#include "Hand.h"

/** is the value 21 and the game's other namesake*/
const int TWENTYONE = 21;
/**
 * \brief Puts a Card into the hand
 * @param c Is the card to be put into the hand
 */
void Hand::getCard(Card c){
    hand.push_back(c);
}
/**
 * \brief Returns the value of the hand accounting for Aces that can be 1 or 11
 * @return returns the value of the hand as an integer
 */
int Hand::getValue(){
    /** Initialized to zero so each card's value can be added*/
    int value = 0;
    int temp;
  //Get Value with ACES as 11
    for(int i=0;i<hand.size();i++){
        if(hand[i].getValue()==1)
            temp = 11;
        else
            temp = hand[i].getValue();
        value += temp;
    }
  //If BUST then try to get value with ACES as 1
    if(value > TWENTYONE){
        value = 0;
        for(int i=0;i<hand.size();i++)
            value += hand[i].getValue();
    }
  //Return total
    return value;
}
/**
 * \brief Outputs the graphic of a hand to the console
 */
void Hand::getGraphic(){
  //Set up and print the hand
    for(int i=0;i<CARD;i++){
        for(int j=0;j<hand.size();j++){
            std::cout<<hand[j].getGraphic(i);
        }
        std::cout<<"\n";
    }
  
}
/**
 * \brief Outputs the dealers hand with one card appearing facedown
 */
void Hand::getDealer(){
  //Print Hand
    std::cout<<hand[0].getGraphic(0)<<" ____ "<<"\n";
    std::cout<<hand[0].getGraphic(1)<<"|////|"<<"\n";
    std::cout<<hand[0].getGraphic(2)<<"|////|"<<"\n";
    std::cout<<hand[0].getGraphic(3)<<"|////|"<<"\n";
    std::cout<<hand[0].getGraphic(4)<<"|////|"<<"\n";
    std::cout<<hand[0].getGraphic(5)<<"`----'"<<"\n";
}
/**
 * \brief Clean up function when the player decides to split his/her hand
 * @return The first Card in the Hand 
 */
Card Hand::splitDel(){
    Card card = hand[0];
    hand.erase(hand.begin());
    return card;
}
/**
 * \brief Prints the Value of a hand to the console
 */
void Hand::printValue(){
    for(int i=0;i<hand.size();i++)
        std::cout<<hand[i].getFace()<<" ";
    std::cout<<"\n";
}
/**
 * \brief Decides if the hand (dealer's hand) has an Ace showing to the player
 * @return True if the dealer is showing an Ace
 */
bool Hand::aceUp(){
    if(hand[0].getFace()=='A')
        return true;
    else
        return false;
}
/**
 * \brief Decides if the hand can be split
 * @return True if the hand can be split into two hands
 */
bool Hand::canSplit(){
    if((hand[0].getValue()==hand[1].getValue())&&hand.size()==2)
        return true;
    else
        return false;
}
/**
 * \brief Gets the number of Card in the Hand
 * @return # of Cards in the Hand (integer)
 */
int Hand::handSize(){
    return hand.size();
}
/**
 * \brief Clean-up the hand by deleting all cards in it
 */
void Hand::clearHand(){
        hand.erase(hand.begin(),hand.end());
}
/**
 * \brief Show the dealers first Card only
 */
void Hand::printOne(){
    std::cout<<hand[0].getFace()<<std::endl;
}
