#include "WordToGuess.cpp"
#include <cstdlib>
using namespace std;

class GameLoop{
	public: //temporary
	WordToGuess word;

	public:
		GameLoop();
		void mainLoop();
		char getInput();
		bool checkInput(char guess);
};

GameLoop::GameLoop(){
}

void GameLoop::mainLoop(){
	while(true){
		cout << "The word so far is " << word.getGuessedWord() << endl;
		char guess = getInput();
		bool con = word.guessLetter(guess);
		if(con){
			cout << guess << " is in the word." << endl;
		} else{
			cout << guess << " is not in the word." << endl;
			cout << "You have " << word.guessesLeft() << " guesses left." << endl;
		}
		cout << endl;
		if(word.wordIsComplete() || word.guessesLeft()<=0){
			break;
		}
	}
	if(word.wordIsComplete()){
		cout << "Congratulations, you win!" << endl;
	} else{
		cout << "Sorry, you lose!" << endl;
		cout << "The word was '" << word.getWord() << "'." << endl;
	}
}
char GameLoop::getInput(){
	char guess;
	while (true) {
		cout << "Please enter a letter: ";
		if (!(cin >> guess)) {
			cerr << "input error\n";
			return 1;
		}
		bool ret = checkInput(guess);
		if(!ret){
			cout << "That guess is invalid." << endl;
		} else if(word.checkForLetterInGuesses(guess)){
			ret = false;
			cout << "You have already guessed '" << guess << "'." << endl;
		}
		if(ret){break;}
	}
	return guess;
}
bool GameLoop::checkInput(char guess){
	bool isGood = true;
	return isGood;
}

int main(){
	GameLoop gl;
	gl.mainLoop();
	return 0;
}
