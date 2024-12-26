#include <string>
#include <iostream>
#include <random>
#include <atomic>
#include "GameManager.h"

using namespace std;

// Game exit by "e" check
void GameManager::_check_for_exit_request(string &user_input){
    if (user_input == "e") {
        _logger->info("Exit is requested");
        throw runtime_error("User requested exit.");
    }
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

void GameManager::game_init(GameEngine *game_engine_inst, Logger *logger, std::atomic<bool> *exit_is_requested_ptr){
    _logger = logger;
    _logger->info("game init");
    _game_engine_inst = game_engine_inst;
    _exit_is_requested_ptr = exit_is_requested_ptr;

    // Set number to guess
    int number_to_guess = _get_random_number(_settings["min_val"], _settings["max_val"]);
    _logger->info("Number to guess: " + to_string(number_to_guess));

    // Set session
    _game_engine_inst->set_game(number_to_guess, _settings["n_lives"]);
    _logger->info("Game engine is set");
}
    
void GameManager::_submit_guess(int number){
    bool result = _game_engine_inst->guess(number);
    if (result){
        cout << "You guessed! Game over." << endl;
        _logger->info("Player guessed successfully");
        _game_engine_inst->stop_game();
    } else {
        cout << "Nope. This is not a " << number << endl;
        _logger->info("Player's guess is wrong: "+ to_string(number));
        if (!_game_engine_inst->have_lives()){
            cout << "No more lives" << endl;
            _logger->info("All lives are wasted");
            _game_engine_inst->stop_game();
        }
    }
}

void GameManager::run_game_loop(){
    while (_game_engine_inst->game_status() && !_exit_is_requested_ptr->load()){
        cout << "write you guess: ";
        string user_input;
        cin >> user_input;
        _check_for_exit_request(user_input);
        int user_input_cast = stoi(user_input);
        _submit_guess(user_input_cast);
    }
    cout << "End of game loop" << endl;
    _logger->info("End of game loop");
    
}
    
string GameManager::get_current_game_status(){
    string live_info, number_info, current_status;
    live_info = "Lives: " + to_string(_game_engine_inst->get_lives());
    number_info = "Number was: " + to_string( _game_engine_inst->get_number());
    current_status = "Current status: " + live_info + "; " + number_info;
    return current_status;
}
