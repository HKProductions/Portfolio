/* 
 * File:   Card.cpp
 * Author: PC Master Race
 *
 * Created on December 7, 2014, 12:26 PM
 */

#include <fstream>
#include <iostream>
#include "Card.h"

/**
 * \brief Creates a printable graphic for each card
 */
void Card::setGraphic(){
    
    std::fstream card;
  //Open correct file associated with suit
    switch(suit){
        case 0: 
            card.open("heart.txt",std::ios::in);
            break;
        case 1: 
            card.open("spade.txt",std::ios::in);
            break;
        case 2: 
            card.open("diamond.txt",std::ios::in);
            break;
        case 3: 
            card.open("club.txt",std::ios::in);
            break;
        case 4:
            card.open("facedown.txt",std::ios::in);
            break;
    }
    
  //Read the blank card into graphic array
    for(int i=0;i<CARD;i++){
        getline(card,graphic[i]);
        
    }
  //Place the face value into the graphic
    graphic[1][1] = face;
    graphic[4][4] = face;
  //Debug Cards
  //  for(int i=0;i<CARD;i++)
  //     std::cout<<graphic[i]<<"\n";
    
   
  //Close File
    card.close();
}

/**
 * \brief Constructor for card class
 * @param f face of Card to be created
 * @param s suit of Card to be created
 */
Card::Card(int f,int s){
    f++;
//
//  Set the Value/Face
//  
  //Deal with Aces
    if(f==1){
        value = 1;
        face = 'A';
    }
  //Deal with Face Cards
    else if(f>9){
        value = 10;
        switch(f){
            case 10:
                face = 'T';
                break;
            case 11: 
                face = 'J';
                break;
            case 12: 
                face = 'Q';
                break;
            case 13: 
                face = 'K';
                break;
        }
    }
  //Deal with the rest
    else{
        value = f;
        face = f + '0';
    }
//
//  Set the suit
//
    suit = s;

//  Set the graphic
    setGraphic();
}
/**
 * \brief Returns the graphic of Card in the 'n' row
 * @param n element of string array to be returned
 * @return Returns a string stored in the n position of the string array
 */
std::string Card::getGraphic(int n){
    return graphic[n];
}
/**
 * \brief Returns a Cards value
 * @return value of card 2-11 as an int
 */
int Card::getValue(){
    return value;
}
/**
 * \brief Returns a Cards Face value
 * @return Returns a Cards Face value as a Char A,2,3,4,5,6,7,8,9,T,J,Q,K
 */
char Card::getFace(){
    return face;
}
/**
 * \brief Prints the graphic of the Card to the console
 */
void Card::printCard(){
    for(int i=0;i<CARD;i++)
        std::cout<<graphic[i]<<"\n";
}
