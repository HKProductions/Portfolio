/* 
 * File:   Deck.cpp
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "Deck.h"

/** Number of faces a card can have */
const int FACE = 13;
/** Number of suits a card can have */
const int SUIT = 4;
/** Number of times to shuffle the deck */
const int SHUFFLE = 10;
    
/**
 * \brief Constructs a deck of 52 cards and shuffles them SHUFFLE amount of times
 */
Deck::Deck(){
    /** Temporary vector to manipulate */
    std::vector<Card>newDeck;
    for(int i=0;i<SUIT;i++){
        for(int j=0;j<FACE;j++){
            newDeck.push_back(Card(j,i));
            std::cout<<newDeck[newDeck.size()-1].getGraphic(1);
        }
    }
    for(int i=0;i<SHUFFLE;i++)
        std::random_shuffle(newDeck.begin(),newDeck.end());
    
    deck = newDeck;
}
/**
 * \brief Copies the first card (at the top) of the Deck and deletes the original
 * @return Returns the copy of the first card in the Deck
 */
Card Deck::deal(){
    Card dealt = deck[0];
    deck.erase(deck.begin());
    return dealt;
}

