//CS PROJECT BY:
//HARIS(2023428)

#include <iostream>
#include <cstdlib> //calling for the random function
#include <ctime> //initializing library to seed random function 
#include <cctype>//initializing library to use toupper function
#include<stdlib.h> //for system/ terminal clear function

using namespace std;
char guessedcountry[7]; //initializing variable to store the characters guessed by the country to match the selected/hidden country
int incorrectguess = 0; //initializing variable to store the number of incorrect guess the user makes
char selectedcountry[7]; //initializing variable to store the randomly selected country by the computer code run time
int sizee=0;
void displaystage1() //initializing void functions to display different stages of the hangman; total of 11 stages symbolizing 11 chances of mistakes
{
    cout<<"   +---+ \n";
    cout<<"   |   | \n";
    cout<<"  (    | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<" ========= \n";

}
void displaystage2()
{
    cout<<"   +---+ \n";
    cout<<"   |   | \n";
    cout<<" (*    | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<" ========= \n";

}
void displaystage3()
{
    cout<<"   +---+ \n";
    cout<<"   |   | \n";
    cout<<" (* *) | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<"       | \n";
    cout<<" ========= \n";

}
void displaystage4()
{
    cout<<"   +----+ \n";
    cout<<"   |    | \n";
    cout<<" (*.*)  | \n";
    cout<<"        | \n";
    cout<<"        | \n";
    cout<<"        | \n";
    cout<<" ========= \n";

}

void displaystage5() 
{
    cout<<"   +----+ \n";
    cout<<"   |    | \n";
    cout<<" (*.*)  | \n";
	cout<<"   |    | \n";
    cout<<"        | \n";
    cout<<"        | \n";
    cout<<" ========= \n";
}
void displaystage6() 
{
    cout<<"   +----+ \n";
    cout<<"   |    | \n";
    cout<<" (*.*)  | \n";
	cout<<"   |    | \n";
    cout<<"  /     | \n";
    cout<<"        | \n";
    cout<<" ========= \n";;
}
void displaystage7() 
{
    cout<<"   +----+ \n";
    cout<<"   |    | \n";
    cout<<" (*.*)  | \n"; 
	cout<<"   |    | \n";
    cout<<"  /|    | \n";
    cout<<"        | \n";
    cout<<" ========= \n";;
}
void displaystage8() 
{
    cout<<"   +----+ \n";
    cout<<"   |     | \n";
    cout<<" (*.*)   | \n";
	cout<<"   |     | \n";
    cout<<"  /|\\    | \n";
    cout<<"         | \n";
    cout<<" ========= \n";;
}
void displaystage9() 
{
    cout<<"   +-----+ \n";
    cout<<"   |     | \n";
    cout<<" (*.*)   | \n";
    cout<<"   |     | \n";
    cout<<"  /|\\    | \n";
    cout<<"   |     | \n";
    cout<<" ========= \n";
}
void displaystage10() 
{
    cout<<"   +-----+ \n";
    cout<<"   |     | \n";
    cout<<" (*.*)   | \n";
    cout<<"   |     | \n";
    cout<<"  /|\\    | \n";
    cout<<"   |     | \n";
    cout<<"  /      | \n";
    cout<<" ========= \n";
}
void displayStage11() 
{
    cout<<"   +-----+ \n";
    cout<<"   |     | \n";
    cout<<" (*.*)   | \n";
    cout<<"   |     | \n";
    cout<<"  /|\\    | \n";
    cout<<"   |     | \n";
    cout<<"  / \\    | \n";
    cout<<" =========\n";
}

//intializing a function that will print the guessed characters of the hidden country if the condition in the main are satisfied.
void printguessedcountry(char guessedcountry[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << guessedcountry[i];
    }
}
//initializing a function that will take the characters of the user guess and the selected country by the code as its parameters and check if they are the same
int findChar(char check[], char ch)
{
    for (int i = 0; i < 7; i++)
    {
        if (toupper(check[i]) == toupper(ch))
        {
            return i; // returning the character position which would replace the dash if it matches the hidden selected country
        }
    }
    return -1; // returning -1 if the user entered character does not match the selected country
}

char* random(char array[4][7])
{
    srand(time(0));
    int rand1 = rand() % 4;    // selecting a random row.
    int rand2 = rand() % 7;    // selecting a random column.
    return array[rand1]; // returning the selected country array
}

void clearScreen() //using a defined function to clear the screen at every hangman stage iteration.
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void hangmandisplaystages(int incorrectguess)
{
	clearScreen(); //Clear the screen before displaying the new stage
    switch(incorrectguess) //each incorrectguess will output a specific hangman stage until all 11 lives are used and the game ends
    {
        case 1:
        displaystage1();
        break;
        case 2:
        displaystage2();
        break;
        case 3:
        displaystage3();
        break;
        case 4:
        displaystage4();
        break;
        case 5:
        displaystage5();
        break;
        case 6:
        displaystage6();
        break;
        case 7:
        displaystage7();
        break;
        case 8:
        displaystage8();
        break;
        case 9:
        displaystage9();
        break;
        case 10:
        displaystage10();
        break;
        case 11:
        displayStage11();
        break;
    }    
}

int main()
{
    int tryagain; //initializing a variable to store the user input if he wants to replay the game
    do //write the whole code in do while to make the whole game repeatable/ playable again
    {
        srand(time(0)); //seeding random function with program run time
        char array[4][7] = //intiallizing an array of 4 rows and 7 coloums that store the names of the country.
        {
            {'D', 'E', 'N', 'M', 'A', 'R', 'K'},
            {'C', 'H', 'I', 'N', 'A'},
            {'I', 'R', 'A', 'N'},
            {'K', 'U', 'W', 'A', 'I', 'T'}};

char* temp = random(array); //using the random function to generate a random country
        for (int i = 0; i < 7; i++)
        {
            selectedcountry[i] = temp[i]; //storing the random selected country in a temp array
        }

int i=0;
sizee=0; //intializing again to make the game repeatable
while(selectedcountry[i]!='\0')
{
	sizee++;
	i++; //using while loop to count the number of characters in the country selected saving it in the variable sizee
}
        int alphabetcount = 0; //using the for loop to again count the number of alphabets present in the name of the country.
        for (int i = 0; i < 7; i++) //running the loop 7 times as the upper limit of the country in the array defined is 7
        {
            if (selectedcountry[i] >= 'A' && selectedcountry[i] <= 'Z') //checking the number of characters as long as they are in the range of A TO Z
            {
                alphabetcount++;
            }
        }
        cout << "WELCOME TO COUNTRY GUESSING GAME" << endl;
        cout << "THE COUNTRY CONSISTS OF " << alphabetcount << " LETTERS" << endl;

        for (int i = 0; i < sizee; i++) //now using for loop to generate the equal number of dashes w.r.t the alphabet count of the selected country stored in the array
        {
        	
            guessedcountry[i] = '-';
        }
        char guessedLetters[26] = {0}; //initializing a variable that will store the guessed letters/aplhabets entered by the user
		incorrectguess=0; //intializing the variable again to make the game repeatable. (this has already been defined globally to store the incorrect guess)
        while (incorrectguess < 11) //running a while loop until incorrect guesses are less than 11
        {
            cout << "GUESS THE COUNTRY: ";
            printguessedcountry(guessedcountry,sizee); //using the already defined function
            cout << endl;

            char userguess;
            cout << "ENTER A LETTER: ";
            cin >> userguess; //taking the user guess 
            userguess = toupper(userguess); //putting the user guess in upper case

            if (guessedLetters[userguess - 'A'] == 1)
            {
                cout << "ERROR, NO REPEATITION OF ALPHABETS. TRY AGAIN" << endl;
                continue;
            }

            guessedLetters[userguess - 'A'] = 1;

            int found = findChar(selectedcountry, userguess);
        //intitalizing a variable called found and storing the value returned from the findchar function defined above/already
            if (found != -1) //if the findchar function returns i the user has guessed the right country
            {
                guessedcountry[found] = selectedcountry[found];
            }
            else //else the user has made a mistake and the incorrectguess variable will be +1 
            {
                int total = 11;
                cout << "Incorrect guess. Try again" << endl;
                incorrectguess++;

                cout << "Your Hangman Status:" << endl;
                hangmandisplaystages(incorrectguess); //as the user makes mistakes the hangman starts to form

                cout << "You have only " << total - incorrectguess << " tries left" << endl;  //showing the user the number of chances left
            }

            // Check if the whole of the guessed country with matches the whole selected country
            bool match = true;
            for (int i = 0; i < sizee; i++)
            {
                if (guessedcountry[i] != selectedcountry[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            // if the whole guessed country is a match then you won
            {
            	system("cls");
            	hangmandisplaystages(incorrectguess);
				printguessedcountry(guessedcountry,sizee);
                cout <<endl<< "YOU WON!!!" << endl;
                cout << "CONGRATULATIONS! You have guessed the country" << endl;
                break;
            }
        }

        if (incorrectguess == 11)//if the max number of chances that are 11, are reached; the user has lost
        {
            cout << "YOU LOSE. GAME OVER!!!" << endl;
            cout << "Sorry, you have reached the maximum number of incorrect guesses" << endl;
            cout << "The correct country was ";
            for(int i=0; i<sizee; i++)
			{
				cout<<selectedcountry[i];
			}
			cout << endl;
			cout<<endl;
        }
        //asking the user if he wants to restart the game.
        cout << "PRESS 1 IF YOU WANT TO PLAY THE GAME AGAIN" << endl;
        cin >> tryagain;
    } 
while (tryagain == 1); //press 1 to restart the game

    return 0;
}
