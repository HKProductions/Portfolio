/* 
 * File:   Player.cpp
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:28 PM
 */

#include "Player.h"
#include <fstream>
#include <sstream>

//Enums
enum{
    BLACKJACK, WIN, LOSE
};

/**
 * \brief Reads or Writes player data to a file
 * @param sign Player name
 */
Player::Player(std::string sign){
    std::fstream play;
    std::string str = sign + ".txt";
    play.open(str.c_str(),std::ios::in|std::ios::binary);
    if(play.is_open()){
        std::cout<<"PLAYER "<<sign<<" FOUND, LOADING DATA...\n";
        readData(play);
    }
    else{
        play.close();
        setData(sign,10000.0,0);
        play.open(str.c_str(),std::ios::out);
        writeData(play);
        std::cout<<"PLAYER "<<sign<<" NOT FOUND, CREATING DATA...\n";
    }
    play.close();
}
/**
 * \brief Prints data relevant to the player
 */
void Player::printData(){
    std::cout<<"||====================================================||\n"
             <<"||  Saved Data:                                       ||\n"
             <<"||     Player name:             "<<data.name<<"\n"
             <<"||     Current Funds:           "<<data.cash<<"\n"
             <<"||     Number of hands played:  "<<data.plays<<"\n"
             <<"||====================================================||\n";
    std::fstream play;
    std::string str = data.name + ".txt";
    play.open(str.c_str(),std::ios::out);
    writeData(play);
    play.close();
}
/**
 * \brief places player data into the data structure
 * @param n string player name
 * @param m float player money
 * @param p integer # of hands played
 */
void Player::setData(std::string n,float m,int p){
    data.cash = m;
    data.name = n;
    data.plays = p;
}
/**
 * \brief Writes player data to the file
 * @param p file stream passed by reference
 */
void Player::writeData(std::fstream &p){
    std::stringstream s;
    s<<data.name<<"\r\n"<<data.cash<<"\r\n"<<data.plays;
    p<<s.str();
}
/**
 * \brief Reads data from the file and places it into the structure
 * @param p file stream passed by reference
 */
void Player::readData(std::fstream &p){
    p>>data.name>>data.cash>>data.plays;
}
/**
 * \brief prints player name
 * @return String player name
 */
std::string Player::getName(){
    return data.name;
}
/**
 * \brief sets the players bet and takes it from his cash
 * @param b
 */
void Player::setBet(float b){
    bet = b;
    data.cash -= b;
    doubleD = false;
    didSplit = false;
}
/**
 * \brief returns player bet
 * @return player bet
 */
float Player::getBet(){
    return bet;
}
/**
 * \brief returns player cash
 * @return Player cash
 */
float Player::getCash(){
    return data.cash;
}
/**
 * \brief deletes the Player's hand
 */
void Player::deleteHand(){
    hand.clearHand();
}
/**
 * \brief increments the number of players times played
 */
void Player::anotherHand(){
    data.plays++;
}
/**
 * \brief Adds a card to the hand
 * @param c Card to be added to the hand
 */
void Player::hit(Card c){
    hand.getCard(c);
}
/**
 * \brief Adds a card to the split hand
 * @param c Card to be added to the split hand
 */
void Player::hitSplit(Card c){
    splitHand.getCard(c);
}
/**
 * \brief Doubles the players bet and sets the doubledown token to true
 */
void Player::doubleDown(){
    data.cash -= bet;
    bet *= 2.0;
    doubleD = true;
}
/**
 * \brief Determines if the hand can be split
 * @return True if hand can be split
 */
bool Player::canSplit(){
    return hand.canSplit();
}
/**
 * \brief Splits the current hand into two hands and sets didSplit token to true
 */
void Player::split(){
    splitHand.getCard(hand.splitDel());
    didSplit = true;
}
/**
 * \brief Retrieves half the bet in order to end the round immediately
 */
void Player::surrender(){
    data.cash += bet/2.0;
}
/**
 * \brief Subtracts half the bet if the player buys insurance
 */
void Player::insurance(){
    data.cash -= bet/2.0;
}
/**
 * \brief Resolves the game by moving around cash for different types of wins
 * @param type resembles the type of win
 */
void Player::end(int type){
    switch(type){
        case BLACKJACK:
            data.cash += bet*2.5;
            break;
        case WIN:
            data.cash += bet*2.0;
            break;
        case LOSE:
            break;
    }
    doubleD = false;
    didSplit = false;
}
/**
 * \brief returns the value of the main hand
 * @return value of hand (integer)
 */
int Player::getHandValue(){
    hand.getValue();
}
/**
 * \brief returns the value of the split hand
 * @return value of split hand (integer)
 */
int Player::getSplitValue(){
    splitHand.getValue();
}
/**
 * \brief prints the hand to the console
 */
void Player::printHand(){
    hand.getGraphic();
}
/**
 * \brief prints the split hand to the console
 */
void Player::printSplit(){
    splitHand.getGraphic();
}
/**
 * \brief prints the value of the main hand
 */
void Player::printValueHand(){
    hand.printValue();
}
/**
 * \brief prints the value of the split hand
 */
void Player::printValueSplit(){
    splitHand.printValue();
}
/**
 * \brief returns the number of cards in the main hand
 * @return the size of the hand (integer)
 */
int Player::getHandSize(){
    return hand.handSize();
}
/**
 * \brief returns the number of cards in the split hand
 * @return the size of the hand (integer)
 */
int Player::getSplitSize(){
    return splitHand.handSize();    
}
/**
 * \brief returns the actual Hand
 * @return Main Hand
 */
Hand Player::getHand(){
    return hand;
}
/**
 * \brief returns the split Hand
 * @return Split Hand
 */
Hand Player::getSplit(){
    return splitHand;
}

