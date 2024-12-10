#include <string>
#include <iostream>
#include <stdexcept>
#include "GameEngine.h"
#include "GameManager.h"

using namespace std;

void run(){
    GameManager manager_inst;
    GameEngine game_engine_inst;

    manager_inst.game_init(game_engine_inst);
    manager_inst.run_game_loop();
}

bool ask_for_rerun(){
    cout << "Wanna rerun? y / n: ";
    string user_input;
    cin >> user_input;
    if (user_input == "y"){
        cout << "Ok, let's rerun" << endl;
        return true;
    } else if (user_input == "n"){
        cout << "Ok, no rerun for you" << endl;
        return false;
    } else {
        cout << user_input << " is not a valid response" << endl;
        return ask_for_rerun();
    }
    
}

int main()
{
    do {
        run();
    } while (ask_for_rerun());
    cout << "End" << endl;
    return 0;
}