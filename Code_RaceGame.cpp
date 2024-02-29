#include <iostream>
#include <windows.h>

using namespace std;

// initializing struct with variables as described in the assignment question
struct Car {
    int position; // to store the position of the cars in the horizontal track
    int points; //to store the points of the cars while moving in the horizontal track
};
// using another struct
struct RacingTrack {
    int trackLength; //setting variable to storethe track limit to which the car cannot exceed
    Car car1; // instance of struct car for car 1
    Car car2; // another instance to show the next card.
};

void clearScreen() {
    system("cls"); // to clear the screen to show only real time positions of the cars in the terminal, manipulated by user inputs
}

void drawTrack(int screenWidth) {
    for (int i = 0; i < screenWidth; ++i) {
        cout << '-';
    }
    cout << endl;
}
//using ascii art to imporve the game experience
void displayGameOver() {
    cout << "   _____                         ____                 " << endl;
    cout << "  / ____|                       / __ \\                " << endl;
    cout << " | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ " << endl;
    cout << " | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|" << endl;
    cout << " | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   " << endl;
    cout << "  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   " << endl;
    cout << endl;
}
//using ascii art to imporve the game experience
void displayWelcomeMessage() {
    cout << " ___      _____________ __________ ________           ________    ____    ________              ____   ________   __________ __________ ________" << endl;
    cout << "`MM\\     `M'`MMMMMMMMM `MMMMMMMMM `MMMMMMMb.         `MMMMMMM   6MMMMb   `MMMMMMMb.           6MMMMb\\ `MMMMMMMb. `MMMMMMMMM `MMMMMMMMM `MMMMMMMb." << endl;
    cout << " MMM\\     M  MM      \\  MM      \\  MM    `Mb          MM    \\  8P    Y8   MM    `Mb          6M'    `  MM    `Mb  MM      \\  MM      \\  MM    `Mb" << endl;
    cout << " M\\MM\\    M  MM         MM         MM     MM          MM      6M      Mb  MM     MM          MM        MM     MM  MM         MM         MM     MM" << endl;
    cout << " M \\MM\\   M  MM    ,    MM    ,    MM     MM          MM   ,  MM      MM  MM     MM          YM.       MM     MM  MM    ,    MM    ,    MM     MM" << endl;
    cout << " M  \\MM\\  M  MMMMMMM    MMMMMMM    MM     MM          MMMMMM  MM      MM  MM    .M9           YMMMMb   MM    .M9  MMMMMMM    MMMMMMM    MM     MM" << endl;
    cout << " M   \\MM\\ M  MM    `    MM    `    MM     MM          MM   `  MM      MM  MMMMMMM9'               `Mb  MMMMMMM9'  MM    `    MM    `    MM     MM" << endl;
    cout << " M    \\MM\\M  MM         MM         MM     MM MMMMMMM  MM      MM      MM  MM  \\M\\    MMMMMMM       MM  MM         MM         MM         MM     MM" << endl;
    cout << " M     \\MMM  MM         MM         MM     MM          MM      YM      M9  MM   \\M\\                 MM  MM         MM         MM         MM     MM" << endl;
    cout << " M      \\MM  MM      /  MM      /  MM    .M9          MM       8b    d8   MM    \\M\\          L    ,M9  MM         MM      /  MM      /  MM    .M9" << endl;
    cout << "_M_      \\M _MMMMMMMMM _MMMMMMMMM _MMMMMMM9'         _MM_       YMMMM9   _MM_    \\M\\        MYMMMM9  _MM_       _MMMMMMMMM _MMMMMMMMM _MMMMMMM9'" << endl;
    cout << endl;
    cout << "PRESS F TO START THE GAME" << endl;
}

int main() {
    char playAgain;
//setting a do-while loop to prompt user to ask if to play again
    do {
        RacingTrack track;
        track.trackLength = 40; // horizontal track limit
        track.car1.position = 0; //initial position
        track.car1.points = 0;//initial points
        track.car2.position = 0;//initial position
        track.car2.points = 0;//initial point

        int speed = 1;
        bool gameStarted = false; //bool condition set to know whether the game is launched or not

        while (true) {
            clearScreen();

            // Draw top boundary
            drawTrack(track.trackLength);

            // Display welcome messages as original bool condition is not satisfied i.e game hasn't started
            if (!gameStarted) {
                displayWelcomeMessage();
                if (GetAsyncKeyState('F') & 0x8000)  // Check if the key is pressed //function learned from the new use of window.h library
                    gameStarted = true; //sets the condition to start the game
            } else {
            	// Display the positions of car1 and car2 on the track
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < track.trackLength; ++j) {
                        if ((i == 0 && j == track.car1.position) || (i == 1 && j == track.car2.position))
                            cout << 'O';  // Display the circles at (car1.position, 0) and (car2.position, 1)
                        else
                            cout << ' ';
                    }
                    cout << endl;
                }

                // Draw bottom boundary
                drawTrack(track.trackLength);

                // controls to move the cars horizontally
                if (GetAsyncKeyState('D') & 0x8000 && track.car1.position < track.trackLength - 1) {
                    track.car1.position += speed;
                    track.car1.points += 10;  // Increase points by 10 when moving forward
                }
                if (GetAsyncKeyState('A') & 0x8000 && track.car1.position > 0)
                    track.car1.position -= speed;

                if (GetAsyncKeyState('L') & 0x8000 && track.car2.position < track.trackLength - 1) {
                    track.car2.position += speed;
                    track.car2.points += 10;  // Increase points by 10 when moving forward
                }
                if (GetAsyncKeyState('J') & 0x8000 && track.car2.position > 0)
                    track.car2.position -= speed;

                // Check for the winner and update points
                if (track.car1.position >= track.trackLength - 1) {
                    displayGameOver();
                    cout << "Car 1 wins! Points: " << track.car1.points << endl;
                    break;
                } else if (track.car2.position >= track.trackLength - 1) {
                    displayGameOver();
                    cout << "Car 2 wins! Points: " << track.car2.points << endl;
                    break;
                }

                // Display current position and points
                cout << "Car 1 - Position: " << track.car1.position << ", Points: " << track.car1.points << endl;
                cout << "Car 2 - Position: " << track.car2.position << ", Points: " << track.car2.points << endl;
            }

            Sleep(100);
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

