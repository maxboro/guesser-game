#include <string>
#include <iostream>
#include <random>
#include "GameManager.h"

using namespace std;

void GameManager::game_init(GameEngine &game_engine_inst){
    _game_engine_inst = game_engine_inst;
    int number_to_guess = _get_random_number(MIN_VAL, MAX_VAL);
    _game_engine_inst.set_game(number_to_guess, N_LIVES);
}
    
void GameManager::_submit_guess(int number){
    bool result = _game_engine_inst.guess(number);
    if (result){
        cout << "You guessed! Game over." << endl;
        _game_engine_inst.stop_game();
    } else {
        cout << "Nope. This is not a " << number << endl;
        if (!_game_engine_inst.have_lives()){
            cout << "No more lives" << endl;
            _game_engine_inst.stop_game();
        }
    }
}

void GameManager::run_game_loop(){
    while (_game_engine_inst.game_status()){
        cout << "write you guess: ";
        string user_input;
        cin >> user_input;
        int user_input_cast = stoi(user_input);
        _submit_guess(user_input_cast);
    }
    cout << "End of game loop" << endl;
    
}
    
void GameManager::show_current_game_status(){
    cout << "Lives: " << _game_engine_inst.get_lives() << "; Number was: " << _game_engine_inst.get_number() << endl;
}
    
int GameManager::_get_random_number(int min, int max){
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    int randomValue = distrib(gen);

    return randomValue;
}