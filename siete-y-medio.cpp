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


// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
    Player p1(100);
    Hand p1_hand;
    Player dealer(900);
    Hand dealer_hand;
    while(p1.get_money() > 0)
    {
        cout << "You have: " << p1.get_money();
        p1.bet();
        p1_hand.draw();
        p1_hand.display();
        cout << "Your total is " << p1_hand.get_total() << endl;
        
    }
    
   return 0;
}
