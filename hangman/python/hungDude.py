class HungDude:
	def getBlank(self):
		return self.plain

	def addHead(self, soFar):
		h = self.head
		for x in h:
			soFar[x[0]]=x[1]
		return soFar

	def addBody(self, soFar):
		b = self.body
		for x in b:
			soFar[x[0]]='%s%s%s'%(soFar[x[0]][:x[1]], x[2], soFar[x[0]][(x[1]+1):])
		return soFar

	def addLeftArm(self, soFar):
		la = self.leftArm
		for x in la:
			soFar[x[0]]='%s%s%s'%(soFar[x[0]][:x[1]], x[2], soFar[x[0]][(x[1]+1):])
		return soFar

	def addRightArm(self, soFar):
		ra = self.rightArm
		for x in ra:
			soFar[x[0]]='%s%s%s'%(soFar[x[0]][:x[1]], x[2], soFar[x[0]][(x[1]+1):])
		return soFar

	def addLeftLeg(self, soFar):
		ll = self.leftLeg
		for x in ll:
			soFar[x[0]]='%s%s%s'%(soFar[x[0]][:x[1]], x[2], soFar[x[0]][(x[1]+1):])
		return soFar

	def addRightLeg(self, soFar):
		rl = self.rightLeg
		for x in rl:
			soFar[x[0]]='%s%s%s'%(soFar[x[0]][:x[1]], x[2], soFar[x[0]][(x[1]+1):])
		return soFar

	def getFull(self, wrongs):
		p=self.getBlank()
		scripts=[self.addHead,
			self.addBody,
			self.addLeftArm,
			self.addRightArm,
			self.addLeftLeg,
			self.addRightLeg]
		for x in range(wrongs):
			p=scripts[x](p)
		return p


	plain = [
		'		-------------              ',
		'		|           |              ',
		'		|           |              ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'		|                          ',
		'_____________________________________']

	leftArm = [(10, 13, '/'),
		(11, 12, '/'),
		(12, 11, '/'),
		(13, 10, '/'),
		(14, 9,  '/'),
		(14, 10, '|'),
		(14, 11, '\\')]

	head = [
		(2,'		|        ___|___ '),
		(3,'		|       /       \\'),
		(4,'		|	| x   x |'),
		(5,'		|       |   ^   |'),
		(6,'		|	| \\___/ |'),
		(7,'		|        \\_____/')]

	body = [(8, 14, '|'),
		(9, 14, '^'),
		(10, 14, '|'),
		(11, 14, '|'),
		(12, 14, '|'),
		(13, 14, '|'),
		(14, 14, '|'),
		(15, 14, '|'),
		(16, 14, '^')]

	rightArm = [(10, 16, '\\'),
		(11, 17, '\\'),
		(12, 18, '\\'),
		(13, 19, '\\'),
		(14, 18, '/'),
		(14, 19, '|'),
		(14, 20, '\\')]

	
	leftLeg = [(17, 13, '/'),
		(18, 12, '/'),
		(19, 11, '/'),
		(20, 10, '/'),
		(21, 9, '/'),
		(22, 8, '/')]

	rightLeg = [(17, 15, '\\'),
		(18, 16, '\\'),
		(19, 17, '\\'),
		(20, 18, '\\'),
		(21, 19, '\\'),
		(22, 20, '\\')]



full = [
'		-------------',
'		|           |',
'		|           |',
'		|        /-----\\',
'		|	| x   x |',
'		|       |   ^   |',
'		|	| \\___/ |',
'		|        \\_____/',
'		|           |',
'		|           ^',
'		|          /|\\',
'		|         / | \\',
'		|        /  |  \\',
'		|	/   |   \\',
'		|     /|\\   |   /|\\',
'		|           |',
'		|           ^',
'		|          / \\',
'		|         /   \\',
'		|        /     \\',
'		|       /       \\',
'		|',
'		|',
'		|',
'		|',
'		|',
'		|',
'_____________________________________']



if __name__ == '__main__':
	hd = HungDude()
	for x in range(7):
		print '\n'.join(hd.getFull(x))
