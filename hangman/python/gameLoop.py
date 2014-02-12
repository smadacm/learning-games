from wordToGuess import WordToGuess
from hungDude import HungDude

class gameLoop:

	def __init__(self):
		self.word = self.getWordToGuess()
		self.hd = HungDude()
	
	def mainLoop(self):
		word=self.word
		while not word.wordIsComplete() and word.guessesLeft():
			print 'The word so far is \'%s\'.'%word.getGuessedWord()
			guess = self.getInput()
			con = word.guessLetter(guess)
			self.printHD()
			if con:
				print '\'%s\' is in the word.'%guess
			else:
				print '\'%s\' is not in the word.'%guess
				print 'You have %d guesses left.'%word.guessesLeft()
			print ''
		if word.wordIsComplete():
			print 'Congratulations, you win!'
			return True
		print 'Sorry, you lose!'
		print 'The word was \'%s\'.'%word.getWord()
		return False
	
	def printHD(self):
		for x in self.hd.getFull(self.word.getWrongGuesses()):
			print x
	def getInput(self):
		ret = False
		while not ret:
			guess = raw_input('Please enter a letter: ')
			ret = self.checkInput(guess)
			if not ret:
				print 'That guess is invalid.'
			else:
				guess = guess.lower()
				if self.word.checkForLetterInWrongGuesses(guess):
					ret = False
					print 'You have already guessed \'%s\''%guess
		return guess
	
	def checkInput(self, guess):
		isGood = True
		isGood = isGood and len(guess) == 1
		isGood = isGood and str(guess) == guess
		isGood = isGood and guess.isalpha()
		return isGood
	def getWordToGuess(self):
		return WordToGuess()


if __name__ == '__main__':
	gl=gameLoop()
	gl.mainLoop()
