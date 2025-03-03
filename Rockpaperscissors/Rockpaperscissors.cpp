#include <iostream>
#include <random>
using namespace std;


int getHumanchoice()
{
	//A function to prompt the human player to select rock, paper, scissors, or quit(to end the
	//tournament).Use a validation loop to ensure that the player’s choice is one of the 4 options.
	//Return the player’s choice.
	//inputs=user input
	//output=return human choice of rock, paper scissors as 1,2, or 3 as an integer.
	//preconditions=user must enter Rock, Paper, Scissors or Quit with the appropriate cases.
	//postcondition=returns human choice of rock,papper,scissors as an integer.
	string choice;

	while (true)
	{
		std::cout << "Enter your choice of Rock, Paper, Scissors, or Quit -Warning Case Sensitive- ";
		cin >> choice;
		if (choice == "Rock")
		{
			std::cout << "You chose Rock" << endl;
			
			return 1;
		}
		else if (choice == "Paper") {
			std::cout << "You chose Paper" << endl;
			
			return  2;
		}
		else if (choice == "Scissors") {
			std::cout << "You chose Scissors" << endl;
			
			return 3;
		}
		else if (choice == "Quit")
		{
			
			

			return 4;
		}
		else
		{
			std::cout << "Wrong Answer, please reenter your choice of Rock, Paper, Scissors, Quit, and remember that it's case sensitive!" << endl;
		}
	}




}



int getRoundWinner(int Aswitch)
{
	//A function that takes as input the computer’s choice and the human player’s choice and
	//returns the winner(or draw both chose the same item).
	//inputs=input from humanchoice function. I named it Aswitch to not confuse the program with humanchoice.
	//outputs=integer round winner
	//preconditions= input must be integer.
	//post conditions= returns data for roundwinner 

	random_device engine;

	uniform_int_distribution<int>computerchoice(1, 3);
	int AI = computerchoice(engine);

	//I used an array to typecast my integer computer choice into a string below
	string choices[] = { " ", "Rock", "Paper", "Scissors" };
	cout << "Computer Chose " << choices[AI] << endl;;

	if (Aswitch == AI) {
		
		std::cout << "Draw" << endl;
		return 1;
	}
	else if ((Aswitch == 3 and AI == 1) or (Aswitch == 1 and AI == 2) or (Aswitch == 2 and AI == 3))
	{
	
		std::cout << "Computer Wins" << endl;
		return 2;
	}
	else {
	
		std::cout << "You win" << endl;

		return 3;
	}

}

void scoreupdaterw(int& winner, int& computerscore1, int& humanplayerscore1) {
	//Function takes winner and adds one to their score. Passes data on by reference rather than by value.
	//inputs=winner
	//outputs=computer score and humanplayer score
	//preconditions=winner's score is updated, if there is a winner.
	//postconditions=adds one to either human score or computer score and adds nothing if they are equal.
	//the flag for draw, computer wins or human wins is taken from getround winner which is returned as integer 1,2 or 3.

	if (winner == 1) {
		humanplayerscore1 = humanplayerscore1;
		computerscore1 = computerscore1;

	}
	else if (winner == 2) {
		computerscore1++;

	}
	else {
		humanplayerscore1++;


	}
}

void totalscoredisplay(int& computerscore1, int& playerscore1)
//Function displays total score onto the screen once called.
// inputs=computerscore and player score.
// output=print human and player score onto screen.
//preconditions-player or computer score must be an integer.
//postconditions-prints score for human and computer onto screen.
{

	std::cout << "the player score is " << playerscore1 << endl;
	std::cout << "the computer score is " << computerscore1 << endl;

}

//This program initializes 3 integer variables to zero, winner, computerscore1 and humanplayerscore1. Then it uses a while
//loop to cycle through the program and break if the user enters 'Quit'. In the first part of the loop winner is assigned to
//the function getHumanChoice. If the function returns 4 then it ends the loop, displays the scoreboard and ends the program.
//Else, I assign variable 'hi' to getRoundwinner which takes the input from human choice that was stored in variable 'winner'
//Then returns an integer from that function in integer variable 'hi'. Then I plug variable hi into scoreupdater function
//scoreupdate function then takes hi, the initialized to zero computer and human score and then updates the score
//Until the user enters quit this cycle repeats itself.
//Once the user enters quit then The function totalscoredisplay is called which displays the final scores. Then the program 
//terminates. Please note that while testing I put in totalscoredisplay before the loop ended to verify my results were
//what I expected. Once they were then I commented out the function as seen below so that the program does exactly as requested.
int main()
{
	int winner = 0;
	int computerscore1 = 0;
	int humanplayerscore1 = 0;

	while (true) {

		
		int winner = getHumanchoice();
		
			if (winner == 4) {
				break;
			}
			else {
			
				
				int hi = getRoundWinner(winner);
				scoreupdaterw(hi, computerscore1, humanplayerscore1);
			
				
			}
		
			//totalscoredisplay(computerscore1, humanplayerscore1); 
			// I used the above greened out function to verify that my output was correct after each iteration.
	}
	totalscoredisplay(computerscore1, humanplayerscore1);
	return 0;

	//end loop
}