from random import choice

class WordToGuess:
	wrongGuesses = []
	wrongGuessesAllowed = 6
	wordAsGuessed = []

	def __init__(self):
		self.populateWordList()
		self.word=choice(self.wordList).lower()
		for x in range(len(self.word)):
			self.wordAsGuessed.append(None)

	def guessLetter(self, guess):
		if not guess in self.word:
			self.addWrongGuess(guess)
			return False
		index = self.word.find(guess)
		while index >= 0:
			self.wordAsGuessed[index]=guess
			index = self.word.find(guess, index+1)
		return True

	def wordIsComplete(self):
		return self.getGuessedWord() == self.word

	def guessesLeft(self):
		return self.wrongGuessesAllowed-self.getWrongGuesses()

	def getWrongGuesses(self):
		return len(self.wrongGuesses)

	def getWord(self):
		return self.word

	def getGuessedWord(self):
		return ''.join(((x and x) or '_') for x in self.wordAsGuessed)

	def addWrongGuess(self, guess):
		self.wrongGuesses.append(guess)

	def checkForLetterInWrongGuesses(self, guess):
		return guess in self.wrongGuesses

	def populateWordList(self):
		### TODO: 
		###	make copy of Linux word list in directory
		###	import word list and pick a random word
		wordList = """
			word
			bear
			list
			easy
			"""
		wordList = [x.strip('\t ')for x in wordList.split('\n') if x.strip('\t ')]
		self.wordList=wordList
		return True


#if __name__ == '__main__':
### TODO:
### 	Do something about testing
