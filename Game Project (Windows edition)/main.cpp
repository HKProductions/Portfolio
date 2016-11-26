/* 
 * File:   main.cpp
 * Author: Hamza Khan
 *
 * Created on October 13, 2014, 7:16 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

//Declare structures
struct charactercreator
{
    string firstname;
    string lastname;
};

struct weaponselection
{
    int attack;
    int defense;
};

struct inventory
{
    string weaponitem;
    string armor;     //Will get later on in the game
};

//Declare function prototypes
void Chapter1();
void weaponchoice(weaponselection *);
void guard(weaponselection *, int);
void Aracnia(weaponselection *, int *, int );
void weaponsmenu(weaponselection *, inventory[]);
void villianXP(int);
void heroXP(int);
int guarddeath(int, int &);
int AracniaDeath(int, int &);
int playerdeathbyguard(int, int &);
int playerdeathbyAracnia(int, int &);

int main()
{
    // Declaring variables
    int chapterSelection;
    char cont = 'N';
    
    cout << "The Land of Osirius" << endl << endl;
    
       // Menu loop to select the problem
    do
    {
        cout << "Please enter the number for the problem you want to run ";
        cout << "or press '0' to exit" << endl;
	cout << "1 = Problem 1" << endl; //done
        cout << "2 = Problem 2 (coming soon)" << endl; //coming sometime in the future
        cout << "3 = Problem 3 (coming soon)" << endl; //coming sometime in the future
        cout << "4 = Problem 4 (coming soon)" << endl; //coming sometime in the future
        cout << "5 = Problem 5 (coming soon)" << endl; //coming sometime in the future
	cin >> chapterSelection;

        // Loop in case the user wants to run the same problem
	do
	{
            switch (chapterSelection)
            {
                case 1:
                    Chapter1();
                    break;
                        
		case 2:
                    cout << "Coming soon" << endl;
                    break;
                        
		case 3:
                    cout << "Coming soon" << endl;
                    break;
                        
		case 4:
                    cout << "Coming soon" << endl;
                    break;
                        
	        case 5:
                    cout << "Coming soon" << endl;
                    break;
                        
		default:
                        cout<<"That's an invalid entry\n";
                        break;
		}
	}
        
        while(chapterSelection < 1 || chapterSelection > 6);
                        
        cout << "Do you want to run the ";
        cout << "game again? ('Y' to ";
        cout << "continue or any other key to ";
        cout << "cancel)";
	cin >> cont;
    }
    
    while(toupper(cont) == 'Y');
}

void Chapter1()
{
    //Character profile in a structure
    charactercreator creation;
    weaponselection weapon;
    const int items = 5;
    inventory backpack[items];
    
    //Declare local variables
    string firstname;
    string lastname;
    int choice;
    int baseHP = 30;
    int maxHP = 120;
    int DumbledoreHP;
    int DumbledoreAttk;
    
    //Set up the back story to the adventure
    cout << "There was a legend a told by the native Americans saying that ";
    cout << "every time you go to sleep at night your soul travels to ";
    cout << "different worlds and that in the mornings it travels back to your ";
    cout << "body, but if it doesn't get back to your body in time it is trapped ";
    cout << "in that world until nightfall. Until your soul doesn't get back to ";
    cout << "your body you are left in a coma and after three days you and your ";
    cout << "soul start to die." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "The Spirit's Arrival" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Night guys I'm gonna go to sleep." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Opening scene
    cout << "Tap. . . Tap. . . Tap" << endl;
    cout << "Mysterious voice: Get up stranger or else you'll be in danger. ";
    cout << "Get up now!"<< endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Ugh. Where am I and what's up with the bright light?" << endl;
   system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: We need to hurry up or else you'll be captured. ";
    cout << "Your our last hope of survival. Hurry up" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
  
    cout << "Both you and the mysterious person hide in a near by bush." << endl;
    cout << "Then a horse with a rider on top of it came out of a bush with ";
    cout << "10 guards following it." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Horse rider: Look around everywhere look under ever rock, bush, ";
    cout << "cave and tree. If you have to burn this entire forest down, but ";
    cout << "find the chosen one." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You get a closer look at the mysterious person who saved you and ";
    cout << "reminds you of someone you know." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Hey are you by any chance Dumbuldore because you look a lot like him.";
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Get the players name
    cout << "Mysterious person: Who the hell is Dumbledore, but forget about that. ";
    cout << "I need to know your name to know whether to not to save you.";
    cout << "What is your first name: ";
    getline(cin,creation.firstname);
    
    cout << "What is your last name: ";
    getline(cin,creation.lastname);
    
    cout << "Mysterious person: So your name is " << creation.firstname << " ";
    cout << creation.lastname << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: You are the one the prophecy talked about follow ";
    cout << "me." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Guard: Looks like I just hit the jackpot capturing both the chosen ";
    cout << "one and the rogue wizard Nucktuck" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Nucktuck: Well " << creation.firstname << " I must take your leave. ";
    cout << "I leave you with a sword and a stick. Good Luck and find me if you ";
    cout << "live. Every man for himself!" << endl;
   system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Goes to the menu to select a weapon
    weaponchoice(&weapon);
    
    cout << "Your weapon of choice is now in your inventory.";
    cout << "(Inventory is still being made)" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    //Guard taunt
    cout << "Guard: So you can beat me with that weapon. I laugh at that ";
    cout << "chosen one. Let's fight." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl; 
    
    //Goes to the attack menu
    guard(&weapon, baseHP);
    
    cout << "You: Man I thought he would have given a better fight." << endl;
    
    cout << "Mysterious figure: Hello stranger I saw what you did. I must say that was ";
    cout << "quite impressive." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Uh no offense but who the hell are you." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Mysterious person: Oh sorry about that where our my manners. My name is ";
    cout << "Dumbledore, one of the greatest wizards ever." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Wait your Dumbledore. OH MY GOD!" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Yes I am one of the two last wizards that exist. The other ";
    cout << "wizard is a man named Nucktuck, but unlike me who uses magic for good ";
    cout << "he uses it for evil." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Distant guard: Hey guys I here voices close by lets head over there." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Come with me stranger. We need to get you to safety." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Ten painful minutes later" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: God that was a painfully long journey. Also, Dumbledore ";
    cout << "I thought you said that it was going to be a breaze to get here." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: When did I say that? I don't remember saying that at all. ";
    cout << "But forget about that. Welcome to my humble abode." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: So I introduced myself to you, but what is your name anyways." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Oh yeah I completely forgot. My name is " << creation.firstname << " ";
    cout << creation.lastname << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Ah! Your the chosen one. You must be wondering why your here ";
    cout << "right." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Yeah I do. Why was I brought here and also why were those";
    cout << "guys looking for me." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Well where can I start. I could tell you about the king or ";
    cout << "I could tell you about the spirit wars. So I'll start from the beginning. " << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: 10 years ago this land, Osirius was protected by the spirit lords Herana ";
    cout << "and Namag. They would allow spirits like you to travel in and out of this land." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Then one day a spirit named Boluck came into our land. At first he ";
    cout << "helped the people and protected the spirits from harm. He would come to our land everday ";
    cout << "and be gone before the portal closed. Then one day he brought three thousands ";
    cout << "spirits into our land and ravaged it. The spirit lords didn't appreciate what Boluck ";
    cout << "was doing to their land so they fought back with Boluck, but what they didn't ";
    cout << "expect was that Boluck was expecting them and had thirty of the greatest wizards ";
    cout << "set up a trap for the spirits to trap them. The spirits fell for the trap, but before ";
    cout << "they were trapped they created a prophecy that 10 years from that point a spirit will ";
    cout << "enter this land and defeat Boluck and free them from their prison. So Boluck became ";
    cout << "The king of our land and keeping the citizens of our land under his";
    cout << "control through fear."<< endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: So the spirit lords have been bidding their time and trying to gain back ";
    cout << "their power. So today they let in the first spirit back into our land and you must ";
    cout << "help and free the master spirits." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Man that sucks. I don't know if I could help, ";
    cout << "but I'll try. So lets fight" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Well lets go on a journey, but before we head out here's a backpack." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Welcome to the Inventory"<< endl;
    cout << "1. Weapons" << endl;
    cout << "2. Armor" << endl;
    cout << "Please make a selection: ";
    cin >> choice;
    
    do
    {
        switch(choice)
        {
            case 1:
                weaponsmenu(&weapon, backpack);
                break;
                
            case 2:
                cout << "You don't have any armor yet." << endl;
                break;
                
            default:
                cout << "That is an invalid choice please chose from 1-3" << endl;
                break;
        }
    }
    
    while(choice < 1 || choice > 3);
    
    cout << "Dumbledore: Lets head out for our quest then." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Meanwhile in the castle of Boluck." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "King Boluck: So Yami were you able to capture the spirit." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Yami: Well Your Highness we looked all over the spirit forest, but ";
    cout << "we couldn't find him, but we did find this imposter guard in the forest ";
    cout << "knocked out. He claims that he saw the chosen one and Nucktuck there." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "King Boluck: You inbiciles! I gave you one job to capture the chosen one ";
    cout << "but you couldn't even do that! Why the hell am keeping you as my guards. ";
    cout << "Never mind that. How is the plan going is everything going as planned. ";
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Yami: Everything is going as planned, but I must beg of you Your Highness ";
    cout << "this plan of yours could end up killing you." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "King Boluck: Not unless everything goes as I say." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Boluck walks into a room with a glass floor with the spirit lords trapped ";
    cout << "underneath." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "King Boluck: You know what Yami I think we should show the chosen one who ";
    cout << "he's messing with. Release the giant spider." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Meanwhile back with our heroes" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: It's been five hours and we haven't seen a single village. How ";
    cout << "much further are we going to have to walk Dumbledore." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: It's just a little further I know it." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Dumbledore, you realize I've seen that rock about twenty times ";
    cout << "already. I think we're lost." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Nonsense I know this land like it's on the back of my hand. ";
    cout << "Now I think we have to go east and we'll be there." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "You: Do you think that it's that way or you know for sure it's that way ";
    cout << "because there is a huge difference from knowing and believing." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: I know it's this way boy! Now follow me, my feet are killing me ";
    cout << "so hurry along." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Stop where you are boy and get ready for an attack.";
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Raspy voice: So Dumbledore you found the chosen one I see. Now hand him ";
    cout << "over to me so that I can claim my reward from Boluck" << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Dumbledore: Never Aracnia! The boy stays with me." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    cout << "Aracnia: Well then I'll just take him by force after killing you." << endl;
    system("read -p \"Press enter to continue\" -n 1 -s");
    cout << " " << endl << endl;
    
    Aracnia(&weapon, &DumbledoreAttk, baseHP);
    
    cout << "Dumbledore: I think we should rest now. Good night chosen one." << endl;
    
    cout << "End of Chapter 1. Chapter 2 will be available soon." << endl;
}


 void weaponchoice(weaponselection *w)
{
    //Declare local variable
    int choice;
    
    //Starter weapons
    cout << "Please choose a weapon of your liking" << endl;
    cout << "1. Basic Sword" << endl;
    cout << "Attack: 3" << endl;
    cout << "Defense: 5" << endl << endl;
    
    cout << "2. Basic Stick" << endl;
    cout << "Attack: 8" << endl;
    cout << "Defense: 3" << endl << endl;
    
    cin >> choice;
    
    do
    {
        switch(choice)
        {
            case 1: 
                cout << "You have chosen the noble and defensive sword. Good luck.";
                cout << endl;
                break;
                
            case 2:
                cout << "You have chosen the strong and mighty stick. Good luck."; 
                cout << endl;
                break;
                
            default:
                cout << "That is in invalid choice please chose either enter 1 or 2";
                break;
        }
    }
    while (choice < 1 || choice > 3);
    
    if (choice == 1)
    {
        w -> attack = 3;
        w -> defense = 5;
    }
    
    else if (choice == 2)
    {
        w -> attack = 8;
        w -> defense = 3;        
    }
    
}

 void guard (weaponselection *w, int baseHP)
 {
     //Declare local variables
     int guardAttk;
     int guardHP = 25;
     int choice;
     
     while(baseHP > 0 && guardHP > 0)
     {
         //Get the attack points of the guard
         guardAttk = (rand()%5)+1;
         
         cout << "What do you want to do" << endl;
         cout << "1. Attack" << endl;
         cout << "2. Defense" << endl;
         cin >> choice;
         
         do
         {
             switch(choice)
             {
                 case 1:
                     cout << "You choose to attack the guard" << endl;
                     break;
                     
                 case 2:
                     cout << "You choose to shield yourself" << endl;
                     break;
                     
                 default:
                     cout << "That is in invalid choice please chose either enter 1 or 2";
                     break;
                
             }
         }
         while(choice < 1 || choice > 3);
         
         if (choice == 1)
         {
             //Display damage done and life left on the guard
             guardHP = guardHP - (w -> attack);
             cout << "You did " << w -> attack << " damage on the guard." << endl;
             cout << "The guard has " << guardHP << " HP left." << endl;
         
             //Display your life left after guard attacks
             baseHP = baseHP - guardAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         else if (choice == 2)
         {
             baseHP = baseHP-((w -> defense) - guardAttk);
             cout << "You have " << baseHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         guarddeath(guardHP, baseHP);
         playerdeathbyguard(guardHP, baseHP);
     }
 }
 
 int playerdeathbyguard(int guardHP, int &baseHP)
 {
     if (guardHP > 0 && baseHP <= 0)
     {
         cout << "Guard: So you thought you could beat me huh. ";
         cout << "You couldn't even destroy me. HaHaHa" << endl;
         cout << "Game Over" << endl;
     }
     
     return 0;
 }
 
 int guarddeath(int guardHP, int &baseHP) 
 {
     //Declare local variables
     int choice;
     int antagonist;
     int protagonist;
     int XP;
     
     if (guardHP <= 0 && baseHP > 0)
     {
        cout << "The guard has fallen" << endl;
         
        cout << "You have two options you can choose from" << endl;
        cout << "1. You can kill the guard" << endl;
        cout << "2. Or you can let the guard live" << endl;
        cout << "Please make a selection";
        cin >> choice; 
        do
        {
            switch (choice)
            {
                case 1:
                    cout << "You have decided to kill the guard." << " ";
                    cout << "This may effect you later on." << endl;
                    break;
                 
                case 2:
                    cout << "You have decided to let the guard live." << " ";
                    cout << "This may effect you later on." << endl;
                    break;
                 
                default:
                    cout << "That is in invalid choice please chose either enter 1 or 2";
                    break;    
            }
        }
        while (choice < 1 || choice > 3);
        
        if (choice == 1)
        {
            villianXP(antagonist);
            XP = 5;
            cout << "Also you gained " << XP << " points for defeating the guard." << endl;
        }
     
        else if (choice == 2)
        {
            heroXP(protagonist);
            XP = 5;
            cout << "Also you gained " << XP << " points for defeating the guard." << endl;
        }
     }
     return XP;
 }
 
 void villianXP(int antagonist)
 {
     cout << "You: You don't deserve the right to live. Say your last prayer." << endl;
     
     antagonist = 5;
     cout << "You gained " << antagonist << " villian points by your decision." << endl;
 }
 
 void heroXP(int protagonist)
 {
     cout << "You: I can't kill you. I hope this doesn't come back to bite me." << endl;
     
     protagonist = 5;
     cout << "You gained " <<  protagonist << " hero points by this choice." << endl;
 }
 
 void weaponsmenu(weaponselection *w, inventory b[])
 {
     int collection;
     int i = 0;
     
     cout << "How many weapons have you gained so far.(Please enter in 1)" << endl;
     cin >> collection;
     
     for(i = 0; i < collection; i++)
     {
         cout << "Please enter in the name of your weapon.(Please type stick)";
         cin >> b[i].weaponitem;
         
         cout << b[i].weaponitem << endl;
         cout << "This weapon has: " <<  w -> attack << " attack points." << endl;
         cout << "This weapon has: " <<  w -> defense << " defense points." << endl;
     }
     
 }
 
 void Aracnia(weaponselection *w, int *DumbledoreAttk, int baseHP)
 {
     //Declare local variables
     baseHP = 30;
     int AracniaHP = 50;
     int AracniaAttk;
     DumbledoreAttk = nullptr;
     int DumbledoretotalAttk;
     int DumbledoreDefense;
     int choice;
     int i;
     int DumbledoreHP = 50;
     const int DumbledoreMultipleAttk = 2;
     
     DumbledoreAttk = new int[DumbledoreMultipleAttk];
     for (i = 0; i < DumbledoreMultipleAttk; i++)
     {
         DumbledoretotalAttk = 10 * 2 * i;
     }
     
      while(baseHP > 0 && AracniaHP > 0)
     {
         //Get the attack points of the guard
         AracniaAttk = (rand()%8)+1;
         
         cout << "What do you want to do" << endl;
         cout << "1. Attack" << endl;
         cout << "2. Defense" << endl;
         cin >> choice;
         
         do
         {
             switch(choice)
             {
                 case 1:
                     cout << "You choose to attack." << endl;
                     break;
                     
                 case 2:
                     cout << "You choose to shield yourself" << endl;
                     break;
                     
                 default:
                     cout << "That is in invalid choice please chose either enter 1 or 2";
                     break;
                
             }
         }
         while(choice < 1 || choice > 3);
         
         if (choice == 1)
         {
             //Display damage done and life left on the guard
             AracniaHP = AracniaHP - (w -> attack);
             AracniaHP = AracniaHP - DumbledoretotalAttk;
             cout << "You did " << w -> attack << " damage on Aracnia." << endl;
             cout << "Dumbledore did " << DumbledoretotalAttk << " damage to Aracnia." << endl;
             cout << "Aracnia has " << AracniaHP << " HP left." << endl;
         
             //Display your life left after guard attacks
             baseHP = baseHP - AracniaHP;
             DumbledoreHP = DumbledoreHP - AracniaAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             cout << "Dumbledore has " << DumbledoreHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
         else if (choice == 2)
         {
             baseHP = baseHP - ((w -> defense) - AracniaAttk);
             DumbledoreHP = DumbledoreDefense - AracniaAttk;
             cout << "You have " << baseHP << " HP left." << endl;
             cout << "Dumbledore has " << DumbledoreHP << " HP left." << endl;
             system("read -p \"Press enter to continue\" -n 1 -s");
             cout << " " << endl << endl;
         }
         
     }
     AracniaDeath(AracniaHP, baseHP);
     playerdeathbyAracnia(AracniaHP, baseHP);
     delete []DumbledoreAttk;
 }
 
 int AracniaDeath(int AracniaHP, int &baseHP)
 {
     //Declare local variables
     int choice;
     int antagonist;
     int protagonist;
     int XP;
     
     if (AracniaHP <= 0 && baseHP > 0)
     {
        cout << "Aracnia has fallen" << endl;
         
        cout << "You have two options you can choose from" << endl;
        cout << "1. You can kill the Aracnia" << endl;
        cout << "2. Or you can let Aracnia live" << endl;
        cout << "Please make a selection";
        cin >> choice; 
        do
        {
            switch (choice)
            {
                case 1:
                    cout << "You have decided to kill Aracnia." << " ";
                    cout << "This may effect you later on." << endl;
                    break;
                 
                case 2:
                    cout << "You have decided to let Aracnia live." << " ";
                    cout << "This may effect you later on." << endl;
                    break;
                 
                default:
                    cout << "That is in invalid choice please chose either enter 1 or 2";
                    break;    
            }
        }
        while (choice < 1 || choice > 3);
        
        if (choice == 1)
        {
            villianXP(antagonist);
            XP = 5;
            cout << "Also you gained " << XP << " points for defeating Aracnia." << endl;
        }
     
        else if (choice == 2)
        {
            heroXP(protagonist);
            XP = 5;
            cout << "Also you gained " << XP << " points for defeating Aracnia." << endl;
        }
     }
     return XP;
 }
 
 int playerdeathbyAracnia(int AracniaHP, int &baseHP)
 {
     if (AracniaHP > 0 && baseHP <= 0)
     {
         cout << "Aracnia: So you thought you could beat me huh. ";
         cout << "You couldn't even destroy me. HaHaHa" << endl;
         cout << "Game Over" << endl;
     }
     
     return 0;
 }