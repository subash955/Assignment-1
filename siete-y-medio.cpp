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
    Player p1(100);
    Hand p1_hand;
    Player dealer(900);
    Hand dealer_hand;
    int win, bet;
    while(p1.get_money() > 0 && dealer.get_money() > 0)
    {
        cout << "You have: " << p1.get_money();
        bet = p1.bet();
        p1_hand.draw();
        cout << "Your cards: " << endl;
        p1_hand.display();
        cout << "Your total is " << p1_hand.get_total() << " Do you want another card? ";
        char c;
        cin >> c;
        while (c == 'Y' || c == 'y' )
        {
            
            cout << "New card: ";
            p1_hand.draw().print();
            cout << "Your total is " << p1_hand.get_total() << endl;
            if(p1_hand.get_total() > 7.5)
                break;
            cout << " Do you want another card? ";
            cin >> c;
        }
         while (dealer_hand.get_total() < 5.5)
            {
                cout << "New card: ";
                dealer_hand.draw().print();
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
        p1_hand.empty();
        dealer_hand.empty();
    }
    
   return 0;
}
