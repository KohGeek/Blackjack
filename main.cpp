#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

struct participant{ //database
    int total;
    int cards[11];
} player, dealer;

int dealer_(int i);
int player_(int i);
int draw();
void total(int a);
void compare ();

int main(){

    srand(time(NULL)); //Randomizer based on time

    cout << "Welcome to the Blackjack program!" << endl;

    player.cards[0] = draw(); //Drawing for player
    player.cards[1] = draw(); //As above
    player.total = player.cards[0] + player.cards[1];

    cout << "You get a " << player.cards[0] << " and a " << player.cards[1] << "." << endl;
    cout << "Your total is " << player.total << "." << endl << endl;

    if (player.total > 21){ //If more than 21....
            total(0); //Decision maker
            return 0;
    }

    dealer.cards[0] = draw(); //Drawing for dealer
    dealer.cards[1] = draw(); //As above
    dealer.total = dealer.cards[0] + dealer.cards[1];

    cout << "Your dealer has a " << dealer.cards[0] << " showing, and a hidden card." << endl;
    cout << "His total is obviously hidden, too." << endl << endl;

    if (dealer.total > 21){ //If more than 21....
        total(1);
        return 0;
    }


    int result;
    result = player_(2); //Player selection

    if (result == 0){ //If more than 21....
        total(0); //THE JURY HAMMER HAS SPOKEN
        return 0;
    }


    cout << "Okay dealer's turn." << endl;
    cout << "His hidden card was a " << dealer.cards[1] << "." << endl << endl;
    result = dealer_(2); //Autobot

    if (result == 0){ //If dealer have more than 21......
        total (1);
        return 0;
    }

    compare(); //THE DEATH SENTENCE

    cin.get();
    return 0;
}

int draw(){ //Drawing mechanism
    int result = rand() % 10 + 2; //From 2 to 11
    return result;
}

void total(int a){ //One of the player lost
    if (a == 0){ //Player lost
        cout << "You have a total of more than 21, you busted." << endl;
        cout << "The dealer has a total of " << dealer.total << "." << endl << endl;
        cout << "DEALER WINS!";
    }else if (a == 1){ //Dealer lost
        cout << "The dealer busts with a total of " << dealer.total << "." << endl << endl;
        cout << "YOU WIN!";
    }
    cin.get(); //Pause the console
}

int player_(int i){ //Player selection
    string choice;

    while (true){
        cout << "Would you like to \"hit\" or \"stay\" ? ";
        getline(cin, choice);

        for (unsigned int i = 0; i < choice.length(); ++i){
        choice[i] = tolower(choice[i]); //Making the input plain small letters
        }

        if (choice == "hit"){
            player.cards[i] = draw();  //Draw
            player.total += player.cards[i];  //Addition

            cout << endl << "You drew a " << player.cards[i] << "." << endl;
            cout << "Your total is " << player.total << "." << endl << endl;

            if (player.total > 21){ //If more than 21
                return 0;
            }else{
                i++; //Add 1 to index
            }
        }else if (choice == "stay"){
            cout << endl << "You chose to stay." << endl << endl;
            break;
        }else{
            cout << endl <<  "Invalid input. Please try again." << endl << endl;
            player_(i); //Calling this function again
        }
    }

    return 1;
}

int dealer_(int i){ //Autobot
    while (dealer.total < 18){ //While not more than 17
        dealer.cards[i] = draw(); //Dealer draws
        dealer.total += dealer.cards[i]; //Addition
        cout << "Dealer chooses to hit." << endl;
        cout << "He draws a " << dealer.cards[i] << "." << endl;
        cout << "His total is " << dealer.total << "." << endl << endl;
    }
    if (dealer.total > 21){
        return 0;
    }else{
        cout << "Dealer stays." << endl << endl;
    }
    return 1;
}

void compare(){ //FINAL DESTINATION
    cout << "The dealer's total is " << dealer.total << "." << endl;
    cout << "Your total is " << player.total << "." << endl << endl;

    if (dealer.total >= player.total){
        cout << "DEALER WINS!";
    }else{
        cout << "YOU WIN!";
    }
}
