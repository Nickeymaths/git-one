//game hangman
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX_WORD = 200;
const int MAX_BAD_GUESS = 7;
string selectWord();
string s[8], list_word[MAX_WORD];
string chosenCharacter;

char guessCharacter();
void update(string &chosenWord, char character, string &guessWord);
void render(string guessWord, int badGuessCount);
bool checkContain(string chosenWord, char character);

int main(){
	srand(time(NULL));
	ifstream file("Eword.txt");
	if(file){
		int dem = 0;
		while(!file.eof()){
			file >> list_word[dem];
			dem++;
		}
	}
	file.close();

	s[7] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                 /|\\\n"
		"|                  |  \n"
		"|                  /\\\n"
		"|                     \n"
		"|                     \n";
	s[6] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                 /|\\\n"
		"|                  |  \n"
		"|                  /  \n"
		"|                     \n"
		"|                     \n";
	s[5] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                 /|\\\n"
		"|                  |  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
	s[4] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                 /|  \n"
		"|                  |  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
	s[3] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                  |  \n"
		"|                  |  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
	s[2] = "--------------------  \n"
		"|                  |  \n"
		"|                  o  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
	s[1] = "--------------------  \n"
		"|                  |  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
	s[0] = "--------------------  \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n"
		"|                     \n";
		
	int badGuessCount = 0;
	string chosenWord = selectWord();
	string guessWord(chosenWord.length(), '-');
	char character;
	cout << "Your guess word has: " << chosenWord.length() << endl;
	do{
		render(guessWord, badGuessCount);
		character = guessCharacter();
		chosenCharacter = chosenCharacter + character + ' ';
		if(checkContain(chosenWord, character)){
			update(chosenWord, character, guessWord);
		}
		else badGuessCount++;
	} while(badGuessCount < MAX_BAD_GUESS && guessWord != chosenWord);
	render(guessWord, badGuessCount);
	if(badGuessCount < MAX_BAD_GUESS) cout << "Congratulation! You won." << endl;
	else{
		cout << "---------------------------------------------------" << endl;
		cout << "You lose" << endl;
		cout << "Chosen word is: " << chosenWord << endl;
	}

	return 0;
}

string selectWord(){
	int random = rand() % MAX_WORD + 1;
	return list_word[random];
}
char guessCharacter(){
	cout << "What character you choose: ";
	char tmp;
	cin >> tmp;
	return tmp;
}
void render(string guessWord, int badGuessCount){
	cout << s[badGuessCount];
	cout << "Characters were chosen: " << chosenCharacter << endl; 
	cout << "Your GuessWord: ";
	cout << guessWord << endl;
	cout << "Your bad count is: " << badGuessCount << endl;
}
void update(string &chosenWord, char character, string &guessWord){
	for(int i = 0; i < chosenWord.length(); i++){
		if(chosenWord[i] == character) guessWord[i] = character;
	}
}
bool checkContain(string chosenWord, char character){
	if(chosenWord.find(character) != string::npos) return true;
	return false;
}





