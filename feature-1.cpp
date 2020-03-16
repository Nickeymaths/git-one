// Game Guessit
// Play guessit

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 100, MIN = 1;
int generateRandumNumber();
int playGuessNumber();
void printAnswer(int Number, int guessNumber);

void Play_Game(){
	int number, guessNumber;
	number = generateRandumNumber();
	do{
	
		guessNumber = playGuessNumber();
		printAnswer(number, guessNumber);
	} while(guessNumber != number);
}
int main(){
	srand(time(NULL));
	char answer;
	do{
		Play_Game();
		cout << "Do you want to play again? (Y/N): ";
		cin >> answer;
	} while(answer == 'Y' || answer == 'y');
	return 0;
}
int generateRandumNumber(){
	return (rand() % (MAX-MIN+1) + MIN);
}

int playGuessNumber(){
	int guessNumber;
	cout << "Enter your answer: ";
	cin >> guessNumber;
	return guessNumber;
}

void printAnswer(int Number, int guessNumber){
	if(guessNumber > Number) cout << "Your number is bigger" << endl;
	else if(guessNumber < Number) cout << "Your number is smaller" << endl;
	else{
		cout << "Congratulation! You won" << endl; 
	}
}
