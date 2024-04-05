## CAR RACING GAME:
<br>
This is a simple car racing game implemented in C++ using the Windows API for input handling.
<br>
The game allows two players to control their respective cars using the 'A' and 'D' keys for Player 1 and 'J' and 'L' keys for Player 2. 
<br>
The objective is to reach the end of the racing track while avoiding collisions.
<br>
<br>

## CPP COMPONENTS/FEATURES:
<br>
The C++ code for the car racing game utilizes various features of the C++ programming language. Here's a description of some of the key features used in the code:
<br>
1. Structs:
<br>
The code defines two structs: Car and RacingTrack.
<br>
Car struct represents the properties of a car, including position and points.
<br>
RacingTrack struct includes the track length and instances of Car for two cars.
<br>
<br>
2. Functions:
<br>
The code includes several functions like clearScreen, drawTrack, displayGameOver, and displayWelcomeMessage.
<br>
Functions help organize the code, making it modular and easier to understand.
<br>
<br>
3. Conditional Statements:
<br>
The if and else statements are used to control the flow of the program.
<br>
if statements are used to check key presses and whether the game has started.
<br>
<br>
4. Pointers:
<br>
The -> operator is not explicitly used, but it's implied when accessing struct members.
<br>
<br>
5. Sleep Function:
<br>
The Sleep function from the Windows API is used to introduce a delay in the game loop, controlling the speed of updates.
<br>
<br>
6. Random Number Generation:
<br>
Although not present in this code, random number generation can be introduced for elements like obstacles or dynamic track lengths.
<br>
<br>
Boolean Variable:
<br>
The boolean variable gameStarted is used to determine whether the game has started or not.
<br>
These features collectively contribute to the structure, functionality, and user experience of the car racing game implemented in C++.
<br>


## HOW TO PLAY:

<br>
Press 'F' to start the game.
<br>
Player 1 controls: 'A' to move left, 'D' to move right.
<br>
Player 2 controls: 'J' to move left, 'L' to move right.
<br>
Reach the end of the track to win the game.
<br>
The game will display the winner and points earned.
<br>
<br>
**FEATURES**:
<br>
Real-time display of cars' positions on the racing track.
<br>
Points are awarded for moving forward.
<br>
ASCII art for an enhanced game experience.
<br>
Option to play again after the game ends.
