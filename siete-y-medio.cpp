// siete-y-medio.cpp, contains main() for the game

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;


// Global constants (if any)


// Non member functions declarations (if any)
int checkwin(double, double);

// Non member functions implementations (if any)
int checkwin (double p, double d)
{
    if (p > 7.5)
    {
        return 1;
    }
    else if (d > 7.5)
        return 2;
    else if (7.5 - p > 7.5 - d)
        return 1;
    else if (7.5 - p < 7.5 - d)
        return 2;
    else
        return 0;
}

// Stub for main
int main(){
   /* --STATEMENTS-- */
    srand(time (0));
    ofstream fout;
    fout.open("gamelog.txt");
      int m = 0, d = 0;
   
    
    cout << "Welcome to Siete y Medio, how much money would you like to start with? " << endl;
    cin >> m;
  

    
    cout << "How much money would you like the dealer to have? \n";
        cin >> d;
    
    Player p1(m);
    Hand p1_hand;
    Player dealer(d);
    Hand dealer_hand;
    int win, bet, gn = 0;
    
    while(p1.get_money() > 0 && dealer.get_money() > 0)
    {
        cout << "You have: " << p1.get_money();
        bet = p1.bet();
        p1_hand.draw();
        cout << "Your cards: " << endl;
        cout << p1_hand;
        cout << "Your total is " << p1_hand.get_total() << " Do you want another card? (y/n) ";
        char c;
        cin >> c;
        while (c == 'Y' || c == 'y' )
        {
            
            cout << "New card: ";
            cout << p1_hand.draw();
            cout << "Your total is " << p1_hand.get_total() << endl;
            if(p1_hand.get_total() > 7.5)
                break;
            cout << " Do you want another card? ";
            cin >> c;
        }
         while (dealer_hand.get_total() < 5.5)
            {
                cout << "New card: " << endl;
                cout << dealer_hand.draw();
            }
        
            cout << "The dealer's total is: " << dealer_hand.get_total() << endl;
            win = checkwin(p1_hand.get_total(), dealer_hand.get_total());
        if (win == 0)
            cout << "Nobody wins!";
        else if (win == 1)
        {
            cout << "Too bad. You lose $" << bet << endl;
            p1.change_money(p1.get_money() - bet);
        }
        else if (win == 2)
        {
            cout << "You win $" << bet << endl;
            p1.change_money(p1.get_money() + bet);
            dealer.change_money(dealer.get_money() - bet);
        }
        gn++;
        
        fout << "-----------------------------------------------\n" << endl;
        fout << "Game number: " << gn << "     Money left: $" << p1.get_money() << endl;
        fout << "Bet: " << bet << endl;
        fout << "Your cards: " << endl << endl;
        fout << p1_hand << endl;
        fout << "Your total: " << p1_hand.get_total() << endl << endl;
        fout << "Dealer's cards: " << endl << endl;
        fout << dealer_hand << endl;
        fout << "Dealer's total is " << dealer_hand.get_total() << endl;
        
        p1_hand.empty();
        dealer_hand.empty();
        
        
    }
    
   return 0;
}
