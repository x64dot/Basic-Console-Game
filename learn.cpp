#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Inventory{
  int cash;  
};

int main(){
    string input;
    Inventory my_Inventory;
    bool HackCooldown = false;
    int commands_count = 0;

    my_Inventory.cash = 0; /* starting cash amount*/

    while (true){
        cout << "Enter command: ";
        getline(std::cin, input);

        
        for (char &c : input) {
            c = tolower(c);
        }

        if (input == "beg"){
            if (HackCooldown == true){
                commands_count++;
            }
            my_Inventory.cash += 5;

            cout << "You have earned 5 Cash from the beg.\n";

            cout << "Current balance: " << my_Inventory.cash << "\n";
        }
        else if (input == "exit"){
            break;
        }
        else if (input == "hack"){  
            if (HackCooldown == false){
                commands_count = 0;
                HackCooldown = true;
                my_Inventory.cash += 100;

                cout << "You have earned 100 Cash from the hack.\n";

                cout << "Current balance: " << my_Inventory.cash << "\n";
            }
            else if (HackCooldown == true && commands_count < 10){
                
                cout << "Hack command is on cooldown you must use 10 commands before you use this command again.\n";
            }
            else if (HackCooldown == true && commands_count >= 10){
                commands_count = 0;
                my_Inventory.cash += 100;

                cout << "You have earned 100 bucks from the hack.\n";

                cout << "Current balance: " << my_Inventory.cash << "\n";
            }
        }
        else if (input == "balance"){
            cout << "Cash balance: " << my_Inventory.cash << "\n";
        }
        else {
            cout << "Command not recognized: " << input << "\n";
        }
        }

    return 0;
    }
    
