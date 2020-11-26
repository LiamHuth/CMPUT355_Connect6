# Connect 6
This is a simple command line visualizer for the game Connect 6. In its
current setup you can play against other people or against a random player.

# Compiling
To compile, run make in the root directory. This will output an executable
labeled "connect6". Simply run the executable the program will start.

# Gameplay
You will be prompted to select what type of players will be part of the
game. To change options, use the tab key on your keyboard. To select an
option, press enter. 

Once the game begins you will have two options on the bottom of the
UI. If the cursor is on "Place/Remove", then pressing enter will either place
or remove a canditate piece from where your board cursor is, depending on
what is already there.

If the cursor is on "Submit", then pressing enter will submit your choice of
move(s). If there are not enough moves selected then it will not submit.

You can move your board cursor around the board with the "wasd" keys.
w/s are used for up/down respectively, and a/d are used for left/right
respectively.

The program will automatically detect when one person has won and prompt
the user for a decision to play again or exit the program.

# Notes
This program is only tested inside of the command line in MacOS. I expect
it work in any Unix based shell, but it may have trouble in windows due to
the termios header.

Make sure that your shell window is atleast 25 lines tall and 19 characters
wide. If it is smaller then part of the UI will be cut off.

If you are colorblind I recommend using the "-colorblind" flag when running the
executable. This will change the characters used in the UI as well as the color palette.

# Adding Computer Players
To add a new algorithm to play in this program, create a new class
that inherits the abstract class in "Player.h". Include the new class in
"ConnectGame.h" and update lines 49 and 82 in "ConnectGame.cpp" accordingly.
