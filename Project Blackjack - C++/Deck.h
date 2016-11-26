/* 
 * File:   Deck.h
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:24 PM
 */

#ifndef DECK_H
#define	DECK_H

#include <vector>
#include "Card.h"

class Deck{
private:
    /** Stores the "deck" as a vector of 52 Card objects */
    std::vector<Card> deck;
public:
  /**
    * \brief Constructs a deck of 52 cards and shuffles them SHUFFLE amount of times
    */
    Deck();
  /**
    * \brief Copies the first card (at the top) of the Deck and deletes the original
    * @return Returns the copy of the first card in the Deck
    */
    Card deal();
};

#endif	/* DECK_H */

