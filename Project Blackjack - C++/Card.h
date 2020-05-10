/* 
 * File:   Card.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 12:25 PM
 */

#ifndef CARD_H
#define	CARD_H

#include <string>

const int CARD = 6;

class Card{
private:
    /** Stores the value of a card*/
    int value;
    /** Stores the face (single character) of a card*/
    char face;
    /** Stores the suit (int 0-4) of a card */
    int suit;
    /** String array that maintains the ascii graphic representing a card */
    std::string graphic[CARD];
    /** \brief assigns the graphic to the graphic string array */
public:
    void setGraphic();
    void printCard();
  /**
    * \brief Constructor for card class
    * @param f face of Card to be created
    * @param s suit of Card to be created
    */
    Card(int,int);
    Card();
  /**
    * \brief Returns the graphic of Card in the 'n' row
    * @param n element of string array to be returned
    * @return Returns a string stored in the n position of the string array
    */
    std::string getGraphic(int);
  /**
    * \brief Returns a Cards value
    * @return value of card 2-11 as an int
    */
    int getValue();
  /**
    * \brief Prints the graphic of the Card to the console
    */
    char getFace();
};


#endif	/* CARD_H */


