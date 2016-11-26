/* 
 * File:   Hand.h
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:24 PM
 */

#ifndef HAND_H
#define	HAND_H

#include <vector>
#include "Card.h"

class Hand{
private:
    /** Vector to store cards together as a hand */
    std::vector<Card>hand;
public:
/**
 * \brief Puts a Card into the hand
 * @param c Is the card to be put into the hand
 */
    void getCard(Card);
/**
 * \brief Returns the value of the hand accounting for Aces that can be 1 or 11
 * @return returns the value of the hand as an integer
 */
    int getValue();
/**
 * \brief Outputs the graphic of a hand to the console
 */
    void getGraphic();
/**
 * \brief Outputs the dealers hand with one card appearing facedown
 */
    void getDealer();
/**
 * \brief Clean up function when the player decides to split his/her hand
 * @return The first Card in the Hand 
 */
    Card splitDel();
/**
 * \brief Prints the Value of a hand to the console
 */
    void printValue();
/**
 * \brief Show the dealers first Card only
 */
    void printOne();
/**
 * \brief Decides if the hand (dealer's hand) has an Ace showing to the player
 * @return True if the dealer is showing an Ace
 */
    bool aceUp();
/**
 * \brief Decides if the hand can be split
 * @return True if the hand can be split into two hands
 */
    bool canSplit();
/**
 * \brief Gets the number of Cards in the Hand
 * @return # of Cards in the Hand (integer)
 */
    int handSize();
/**
 * \brief Clean-up the hand by deleting all cards in it
 */
    void clearHand();

};

#endif	/* HAND_H */

