#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
using namespace std;


class WordToGuess {
	std::string word;
	int wrongGuessesAllowed;
	std::vector<std::string> wordList;
	std::vector<char> wrongGuesses;
	std::vector<char> wordAsGuessed;

	public:
		WordToGuess();
		void populateWordList();
		bool guessLetter(char guess);
		void markCorrect(int ind);
		void addWrongGuess(char guess);
		bool wordIsComplete();
		int guessesLeft();
		string getGuessedWord();
		bool checkForLetterInGuesses(char guess);
		std::vector<std::string> getWordList();
		std::string getWord();
};

WordToGuess::WordToGuess(){
	srand ( time(NULL) );
	wrongGuessesAllowed = 6;
	populateWordList();
	word = wordList[rand()%wordList.size()];
	for(int x=0; x<word.size(); x++){
		wordAsGuessed.push_back('_');
	}
}

void WordToGuess::populateWordList(){
	wordList.push_back("bear");
	wordList.push_back("word");
	wordList.push_back("list");
	wordList.push_back("easy");
}

bool WordToGuess::guessLetter(char guess){
	std::vector<int> indexes;
	for(int i=word.find(guess, 0); i!=string::npos; i=word.find(guess, i))
	{
		indexes.push_back(i);
		i++;  // Move past the last discovered instance to avoid finding same string
	}
	if(indexes.size() <= 0){
		addWrongGuess(guess);
		return false;
	}
	for(int x=0; x<indexes.size(); x++){
		markCorrect(indexes[x]);
	}
	return true;
}

void WordToGuess::markCorrect(int ind){
	wordAsGuessed[ind]=word[ind];
}

void WordToGuess::addWrongGuess(char guess){
	wrongGuesses.push_back(guess);
}

bool WordToGuess::wordIsComplete(){
	bool ret;
	string wag;
	for(int x=0; x<wordAsGuessed.size(); x++){
		if(wordAsGuessed[x]!='_'){
			wag = wag + wordAsGuessed[x];
		}
	}
	if(wag.size() == word.size()){
		ret=true;
	} else{
		ret=false;
	}
	return ret;
}

int WordToGuess::guessesLeft(){
	int ret;
	ret = wrongGuessesAllowed-wrongGuesses.size();
	return ret;
}

std::string WordToGuess::getGuessedWord(){
	std::string wd;
	std::vector<char> wag=wordAsGuessed;
	for(int x=0; x<wag.size(); x++){
		wd = wd + wag[x];
	}
	return wd;
}

bool WordToGuess::checkForLetterInGuesses(char guess){
	for(int x=0; x<wrongGuesses.size(); x++){
		if(wrongGuesses[x]==guess){
			return true;
		}
	}
	for(int x=0; x<wordAsGuessed.size(); x++){
		if(wordAsGuessed[x]==guess){
			return true;
		}
	}
	return false;
}

std::vector<std::string> WordToGuess::getWordList(){
	return wordList;
}

std::string WordToGuess::getWord(){
	return word;
}
/*
int main(){
	WordToGuess wg;
	if(!wg.wordIsComplete()){
		cout << "works" << endl;
	} else{
		cout << "fail" << endl;
	}
	std::vector<std::string> wl = wg.getWordList();
	for(int x=0; x<wl.size(); x++){
		cout << wl[x] << ", ";
	}
	cout << endl;
	string letters = "abcdefghijklmnopqrstuvwxyz";
	for(int x=0; x<letters.size()&& wg.guessesLeft()>0; x++){
		wg.guessLetter(letters[x]);
		cout << wg.getGuessedWord() << endl;
	}
	cout << endl;
	cout << endl;
	cout << wg.getWord() << endl;
	return 0;
}
*/
