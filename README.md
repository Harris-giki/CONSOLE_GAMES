# HANG-THE-MAN-GAME
Showcasing my first semester project, built by using C++ programming language. With a simple construct the project aims to provide user with a fun gaming experience.
<br> 
<br>
### Overview ###
<br>
<br>
This C++ program implements a Country Guessing Game where the player has to guess the name of a randomly selected country, for every incorrect guess a hang-man simulation proceeds until all lives/chances of invalid tries are used up by the user(FINAL HANG-MAN STAGE=PLAYER LOSES). The game utilizes features such as functions, arrays, loops, conditional statements, user input, random number generation, character manipulation, preprocessor directives etc.
<br>
<br>
### C++ features Details ###
<br>
<br>
The C++ features used in the code are:
<br>
1. FUNCTIONS:<br>
The code defines multiple functions (e.g., displaystage1(), printguessedcountry(), findChar(), random(), clearScreen(), hangmandisplaystages(), main()), which helps in organizing and modularizing the code.
<br>
2. FUNCTION INVOCATIONS:<br>
The code calls one function into another. For example: the function of display stages of the hangman is called into another function which accesses each display stage through switch statement. 
<br>
3. ARRAYS:<br>
The code uses arrays to store the names of countries (array[4][7]), guessed letters (guessedLetters[26]), the selected country (selectedcountry[7]), and the guessed characters (guessedcountry[7]).
<br>
4. Loops:<br>
The code utilizes for and while loops for iterating through arrays and performing specific tasks such as counting the number of alphabets in a country, initializing arrays, and checking conditions in the game loop.
<br>
5. Conditional Statements:<br>
The code uses if, else if, and else statements for making decisions based on conditions. For example, checking if the user's guess is a repeat, checking if the guessed country matches the selected country, and displaying different hangman stages based on the number of incorrect guesses.
<br>
6. Random Number Generation:<br>
The code uses the rand() function along with srand(time(0)) for generating random indices to select a random country.
<br>
7. Character Manipulation:<br>
The code uses functions like toupper() to convert characters to uppercase for case-insensitive comparisons.
<br>
8. Clearing Screen (Platform Dependent):<br>
The clearScreen() function uses platform-specific commands (system("cls") for Windows, system("clear") for other systems) to clear the console screen.
<br>
<br>
### INSTRUCTIONS FOR USERS ###
<br>
1. Run the program <br>
2. The game will display a set of dashes representing the letters of a randomly selected country.<br>
3. Guess letters by entering them through the keyboard.<br>
4. Avoid repeating letters, and note that the game is case-insensitive.<br>
5. The hangman figure progresses with each incorrect guess.<br>
6. You win if you correctly guess the entire country within 11 incorrect attempts.<br>
7. You lose if you reach the maximum number of incorrect guesses.<br>
8. After the game ends, you can choose to play again by entering '1' when prompted.<br>
<br>
Have fun playing the Country Guessing Game!
<br>
Author - Muhammad Haris.
