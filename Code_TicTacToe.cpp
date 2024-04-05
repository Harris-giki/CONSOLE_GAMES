#include <iostream>
#include<cstdlib>
#include<ctime>



using namespace std;

class Tictak
{
	private:
		const int maxMoves=15;
	
	
public:
	// terminal display for menu options
	void menu()
	{
 cout << "\033[31m"; 
     cout << "      ___           ___           ___           ___     \n";
    cout << "     /\\__\\         /\\  \\         /\\__\\         /\\__\\    \n";
    cout << "    /::|  |       /::\\  \\       /::|  |       /:/  /    \n";
    cout << "   /:|:|  |      /:/\\:\\  \\     /:|:|  |      /:/  /     \n";
    cout<<"\033[33m";
	cout << "  /:/|:|__|__   /::\\~\\:\\  \\   /:/|:|  |__   /:/  /  ___ \n";
    cout << " /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\ /:/ |:| /\\__\\ /:/__/  /\\__\\\n";
    cout << " \\/__/~~/:/  / \\:\\~\\:\\ \\/__/ \\/__|:|/:/  / \\:\\  \\ /:/  /\n";
    cout << "       /:/  /   \\:\\ \\:\\__\\      |:/: /  /   \\:\\  /:/  / \n";
 	cout<<"\033[36m";
    cout << "      /:/  /     \\:\\ \\/__/      |:: /  /     \\:\/:/   /  \n";
    cout << "     /:/  /       \\:\\__\\        /: /  /       \\:/   /   \n";
    cout << "     \\/__/         \\/__/         \\/__/         \\/__/    \n";

    cout << "\033[0m"; // Reset text color
    cout<<endl;
    cout<<endl;
}                                                                                                    
// using bool function to check is a line of patterns has been completed in certain directions.
//if yes, the player wins the game                                                                                                    
                                                                                               
    bool checkWin_fifteengrid(const char gamegrid[][15], int row, int col) {
    char playerSymbol = gamegrid[row][col];

    // Check horizontally
    int count = 0;
    for (int i = 0; i < 15; i++) {
        if (gamegrid[row][i] == playerSymbol) {
            count++;
            if (count == 5) {
                return true;
            }
        } else {
            count = 0;
        }
    }

    // Check vertically
    count = 0;
    for (int i = 0; i < 15; i++) {
        if (gamegrid[i][col] == playerSymbol) {
            count++;
            if (count == 5) {
                return true;
            }
        } else {
            count = 0;
        }
    }

    // Check diagonally (top-left to bottom-right)
    count = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row + i;
        int c = col + i;
        if (r >= 0 && r < 9 && c >= 0 && c < 9) {
            if (gamegrid[r][c] == playerSymbol) {
                count++;
                if (count == 5) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    count = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row - i;
        int c = col + i;
        if (r >= 0 && r < 9 && c >= 0 && c < 9) {
            if (gamegrid[r][c] == playerSymbol) {
                count++;
                if (count == 5) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }

    return false;
}
//check again by the bool function for the same conditions but using a nine by nine grid
	bool checkWin_ninegrid(const char gamegrid[][9], int row, int col) {
    char playerSymbol = gamegrid[row][col];

    // Check horizontally
    int count = 0;
    for (int i = 0; i < 9; i++) {
        if (gamegrid[row][i] == playerSymbol) {
            count++;
            if (count == 5) {
                return true;
            }
        } else {
            count = 0;
        }
    }

    // Check vertically
    count = 0;
    for (int i = 0; i < 9; i++) {
        if (gamegrid[i][col] == playerSymbol) {
            count++;
            if (count == 5) {
                return true;
            }
        } else {
            count = 0;
        }
    }

    // Check diagonally (top-left to bottom-right)
    count = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row + i;
        int c = col + i;
        if (r >= 0 && r < 9 && c >= 0 && c < 9) {
            if (gamegrid[r][c] == playerSymbol) {
                count++;
                if (count == 5) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    count = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row - i;
        int c = col + i;
        if (r >= 0 && r < 9 && c >= 0 && c < 9) {
            if (gamegrid[r][c] == playerSymbol) {
                count++;
                if (count == 5) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }

    return false;
}

// making a function of human vs human in a nine by nine grid
void nine_grid_play()
{
                const int rows = 9;
                const int columns = 9;
                char gamegrid[rows][columns];

                // Initialize the grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        gamegrid[i][j] = '.';
                    }
                }
                    int usedpositions_rows[maxMoves];
                int usedpositions_cols[maxMoves];

                for (int move = 0; move < maxMoves; move++) {
                    cout << "     PLAYER " << (move % 2) + 1 << endl;
                    int selectedRow, selectedColumn;

                    do {
                        cout << "Enter the number of your row: ";
                        cin >> selectedRow;
                        cout << "Enter the number of column: ";
                        cin >> selectedColumn;

                        bool positionOccupied = false;
                        for (int prevMove = 0; prevMove < move; prevMove++) {
                            if (usedpositions_rows[prevMove] == selectedRow &&
                                usedpositions_cols[prevMove] == selectedColumn) {
                                positionOccupied = true;
                                cout << "THIS POSITION IS ALREADY OCCUPIED. TRY AGAIN" << endl;
                                break;
                            }
                        }

                        if (!positionOccupied && selectedRow >= 1 && selectedRow <= rows &&
                            selectedColumn >= 1 && selectedColumn <= columns) {
                            break;
                        }

                        cout << "Invalid input. Please enter valid row and column numbers." << endl;
                    } while (true);

                    usedpositions_rows[move] = selectedRow;
                    usedpositions_cols[move] = selectedColumn;

                    // Place 'X' or 'O' at the selected location
                    gamegrid[selectedRow - 1][selectedColumn - 1] = (move % 2 == 0) ? 'X' : 'O';
system("cls");
                    // Display the updated grid
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            cout << "|" << gamegrid[i][j] << "|";
                        }
                        cout << endl;
                    }

                    // Check for a win after each move
                    if (checkWin_ninegrid(gamegrid, selectedRow - 1, selectedColumn - 1)) {
                        cout << "PLAYER " << (move % 2) + 1 << " WINS!" << endl;
                        return;
                    }
                }

                cout << "It's a draw!" << endl;
    
}
//making a function of player vs player in a 15 by 15 grid.
void fifteen_grid_play()
{
				const int rows = 15;
                const int columns = 15;
                char gamegrid[rows][columns];

                // Initialize the grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        gamegrid[i][j] = '.';
                    }
                }

                // Display initial grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        cout << "|" << gamegrid[i][j] << "|";
                    }
                    cout << endl;
                }

                int usedpositions_rows[maxMoves];
                int usedpositions_cols[maxMoves];

                for (int move = 0; move < maxMoves; move++) {
                    cout << "     PLAYER " << (move % 2) + 1 << endl;
                    int selectedRow, selectedColumn;

                    do {
                        cout << "Enter the number of your row: ";
                        cin >> selectedRow;
                        cout << "Enter the number of column: ";
                        cin >> selectedColumn;
// checking two conditions, one of that if the user entered value is already occupied by the other user 
// and also checking if the position selected lies in the gamegrid limits.
                        bool positionOccupied = false;
                        for (int prevMove = 0; prevMove < move; prevMove++) {
                            if (usedpositions_rows[prevMove] == selectedRow &&
                                usedpositions_cols[prevMove] == selectedColumn) {
                                positionOccupied = true;
                                cout << "THIS POSITION IS ALREADY OCCUPIED. TRY AGAIN" << endl;
                                break;
                            }
                        }

                        if (!positionOccupied && selectedRow >= 1 && selectedRow <= rows &&
                            selectedColumn >= 1 && selectedColumn <= columns) {
                            break;
                        }

                        cout << "Invalid input. Please enter valid row and column numbers." << endl;
                    } while (true);

                    usedpositions_rows[move] = selectedRow;
                    usedpositions_cols[move] = selectedColumn;

                    // Place 'X' or 'O' at the selected location
                    gamegrid[selectedRow - 1][selectedColumn - 1] = (move % 2 == 0) ? 'X' : 'O';
system("cls");
                    // Display the updated grid
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            cout << "|" << gamegrid[i][j] << "|";
                        }
                        cout << endl;
                    }

                    // Check for a win after each move
                    if (checkWin_fifteengrid(gamegrid, selectedRow - 1, selectedColumn - 1)) {
                        cout << "PLAYER " << (move % 2) + 1 << " WINS!" << endl;
                        return;
                    }
                }

                cout << "It's a draw!" << endl;
}
//setting up a rand function to use a bot to generate a random entry in its turn
//important for the human vs bot game play.
void makeBot_nine_grid(char gamegrid[][9], int& selectedRow, int& selectedColumn) {
    srand(static_cast<unsigned int>(time(0)));
    do {
        selectedRow = rand() % 9 + 1;
        selectedColumn = rand() % 9 + 1;
    } while (gamegrid[selectedRow - 1][selectedColumn - 1] != '.');
}
//human vs bot function; nine by nine grid
void bot_gameplay_nine()
{
	
const int rows = 9;
                const int columns = 9;
                char gamegrid[rows][columns];

                // Initialize the grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        gamegrid[i][j] = '.';
                    }
                }

                // Display initial grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        cout << "|" << gamegrid[i][j] << "|";
                    }
                    cout << endl;
                }

                int usedpositions_rows[maxMoves];
                int usedpositions_cols[maxMoves];

                for (int move = 0; move < maxMoves; move++) {
                    cout << "     PLAYER " << (move % 2) + 1 << endl;
                    int selectedRow, selectedColumn;

                    if (move % 2 == 0) {
                        // Human player's turn
                        do {
                            cout << "Enter the number of your row: ";
                            cin >> selectedRow;
                            cout << "Enter the number of column: ";
                            cin >> selectedColumn;

                            if (selectedRow >= 1 && selectedRow <= rows &&
                                selectedColumn >= 1 && selectedColumn <= columns &&
                                gamegrid[selectedRow - 1][selectedColumn - 1] == '.') {
                                break;
                            }

                            cout << "Invalid input. Please enter a valid and unoccupied position." << endl;
                        } while (true);
                    } else {
                        // Bot's turn
                        makeBot_nine_grid(gamegrid, selectedRow, selectedColumn);
                        cout << "Bot selected row: " << selectedRow << ", column: " << selectedColumn << endl;
                    }

                    usedpositions_rows[move] = selectedRow;
                    usedpositions_cols[move] = selectedColumn;

                    // Place 'X' or 'O' at the selected location
                    gamegrid[selectedRow - 1][selectedColumn - 1] = (move % 2 == 0) ? 'X' : 'O';
system("cls");
                    // Display the updated grid
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            cout << "|" << gamegrid[i][j] << "|";
                        }
                        cout << endl;
                    }

                    // Check for a win after each move
                    if (checkWin_ninegrid(gamegrid, selectedRow - 1, selectedColumn - 1)) {
                        cout << "PLAYER " << (move % 2) + 1 << " WINS!" << endl;
                        return;
                    }
                }

                cout << "It's a draw!" << endl;
            }
//generating the same rand function for the fifteen by fifteen grid to generate a bot or automated entry
void makeBot_fifteen_grid(char gamegrid[][15], int& selectedRow, int& selectedColumn) {
    srand(static_cast<unsigned int>(time(0)));
    do {
        selectedRow = rand() % 9 + 1;
        selectedColumn = rand() % 9 + 1;
    } while (gamegrid[selectedRow - 1][selectedColumn - 1] != '.');
}
// a function of human vs bot in 15x 15 grid
void bot_gameplay_fifteen()
{
	const int rows=15;
	const int columns = 15;
                char gamegrid1[rows][columns];

                // Initialize the grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        gamegrid1[i][j] = '.';
                    }
                }

                // Display initial grid
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        cout << "|" << gamegrid1[i][j] << "|";
                    }
                    cout << endl;
                }

                int usedpositions_rows[maxMoves];
                int usedpositions_cols[maxMoves];

                for (int move = 0; move < maxMoves; move++) {
                    cout << "     PLAYER " << (move % 2) + 1 << endl;
                    int selectedRow, selectedColumn;

                    if (move % 2 == 0) {
                        // Human player's turn
                        do {
                            cout << "Enter the number of your row: ";
                            cin >> selectedRow;
                            cout << "Enter the number of column: ";
                            cin >> selectedColumn;

                            if (selectedRow >= 1 && selectedRow <= rows &&
                                selectedColumn >= 1 && selectedColumn <= columns &&
                                gamegrid1[selectedRow - 1][selectedColumn - 1] == '.') {
                                break;
                            }

                            cout << "Invalid input. Please enter a valid and unoccupied position." << endl;
                        } while (true);
                    } else {
                        // Bot's turn
                    makeBot_fifteen_grid(gamegrid1, selectedRow, selectedColumn);
                        cout << "Bot selected row: " << selectedRow << ", column: " << selectedColumn << endl;
                    }

                    usedpositions_rows[move] = selectedRow;
                    usedpositions_cols[move] = selectedColumn;

                    // Place 'X' or 'O' at the selected location
                    gamegrid1[selectedRow - 1][selectedColumn - 1] = (move % 2 == 0) ? 'X' : 'O';
system("cls");
                    // Display the updated grid
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            cout << "|" << gamegrid1[i][j] << "|";
                        }
                        cout << endl;
                    }

                    // Check for a win after each move
                    if (checkWin_fifteengrid(gamegrid1, selectedRow - 1, selectedColumn - 1)) {
                        cout << "PLAYER " << (move % 2) + 1 << " WINS!" << endl;
                        return;
                    }
                }

                cout << "It's a draw!" << endl;
}
};
//class ends
int main()
{
    //initializing variables to input choices
	Tictak obj1; //decalring class object
		char gamechoice1;
   		int gamechoice2;
    	int gamechoice3;
    	int gamechoice4;
    	obj1.menu(); //calling a member function through class object
    		cout << "        			 WELCOME TO STRATEGIC FIVE. 	         " << endl;
            //creating terminal interface ahead
    cout<<"INSTRUCTIONS:"<<endl;
    cout<<"1. ANY PLAYER COMPLETING 5 ENTRIES FISRT; IN 9X9 OR 15X15 GRID WINS!"<<endl;
    cout<<"2. MAXIMUM NUMBER OF MOVES ASIGNED TO EACH PLAYERS IN ANY GRID ARE FIFTEEN."<<endl;
    cout<<"3. THINK WISELY."<<endl;
	cout << "				PRESS 'F' TO START THE GAME." << endl;
    cin >> gamechoice1;
system("cls");
    if (tolower(gamechoice1) == 'f') {
         cout << "\033[31m"; 
		cout << "                 SELECT GAME MODE.           " << endl;
         cout << "\033[34m"; 
		cout << "1. HUMAN VS. HUMAN" << endl;
        cout << "2. HUMAN VS. BOT" << endl;
         cout << "\033[37m"; 
		cin >> gamechoice2;
	 if (gamechoice2 == 1) 
     {
        //human vs human game options
	 	cout << "\033[31m"; 
            cout << "             SELECT THE GAME GRID.        " << endl;
            cout << "\033[35m"; 
            cout << "1. 9X9 GRID" << endl;
            cout << "2. 15x15 GRID" << endl;
            cout << "\033[37m"; 
            cin >> gamechoice3;
			system("cls");       
			     
			cout<<"					 PLAY NOW!!!			"<<endl;
      		cout<<"\033[36m";
	  if (gamechoice3 == 1) {
	  	obj1.nine_grid_play();//calling a member function through class object
	}
	 if (gamechoice3 == 2) {
obj1.fifteen_grid_play();//calling a member function through class object
}
}

//bot game options
if(gamechoice2==2)
{	cout << "\033[31m";
	cout << "             SELECT THE GAME GRID.        " << endl;
	  cout << "\033[34m"; 
            cout << "1. 9X9 GRID" << endl;
            cout << "2. 15x15 GRID" << endl;
            cin >> gamechoice4;
            system ("cls");
            	cout<<"					 PLAY NOW!!!			"<<endl;
      		cout<<"\033[36m";
if(gamechoice4==1)
{

//calling a member function through class object
obj1.bot_gameplay_nine();
}
if(gamechoice4==2)
{
//calling a member function through class object
	obj1.bot_gameplay_fifteen();
}
}
    }
}
