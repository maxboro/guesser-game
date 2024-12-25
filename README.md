## Description
Simple terminal game of guessing numbers.

Bounds and number of guesses are set in settings.txt.
Type "e" to exit.

# Settings
- min_val - minimum value of number guessed
- max_val - maximum value of number guessed
- n_lives - number of guesses player can make during one game
- logging - logging enabled (1) / disabled (0)
- fast_logging - if logging enabled script uses more resource safe logger at 0, more fast and less resource safe at 1
- reminder_period - period (in seconds) after which to remind to get some rest from the game
- max_n_reminds - number of reminders, each would be `reminder_period` seconds from previous or from the game start

# Example
Typical games session looks like this:
```terminal
Reading the settings.
min_val: 0
max_val: 10
n_lives: 3
logging: 1
fast_logging: 0
Read all
Settings are loaded.

Logging is enabled
Safe logging mode
write you guess: 4
Nope. This is not a 4
write you guess: 2
Nope. This is not a 2
write you guess: 1
Nope. This is not a 1
No more lives
End of game loop
Wanna rerun? y / n: y
Ok, let's rerun

Logging is enabled
Safe logging mode
write you guess: 2
Nope. This is not a 2
write you guess: 1
Nope. This is not a 1
write you guess: 4
Nope. This is not a 4
No more lives
End of game loop
Wanna rerun? y / n: n
Ok, no rerun for you
End
```

## How to run:
```bash
make          # Builds the project
./bin/game    # Runs the executable
make clean    # Cleans up build files
```