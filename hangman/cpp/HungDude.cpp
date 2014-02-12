#include <utility>
#include <vector>
#include <iostream>
using namespace::std;

class HungDude{
	public: //temporary
	std::vector< std::string > plain;
	std::vector< std::string > headString;
	std::vector< int> headPosition;
	std::vector< std::string > bodyString;
	std::vector< std::pair< int, int> > bodyPosition;
	std::vector< std::string > leftArmString;
	std::vector< std::pair< int, int> > leftArmPosition;
	std::vector< std::string > rightArmString;
	std::vector< std::pair< int, int> > rightArmPosition;
	std::vector< std::string > leftLegString;
	std::vector< std::pair< int, int> > leftLegPosition;
	std::vector< std::string > rightLegString;
	std::vector< std::pair< int, int> > rightLegPosition;

	std::vector< std::string > addBodyPart(std::vector< std::string > soFar, std::vector< std::string > partString, std::vector< std::pair< int, int > > partMappings);
	public:
		HungDude();
		std::vector< std::string > getBlank();
		std::vector< std::string > addHead(std::vector< std::string > soFar);
		std::vector< std::string > addBody(std::vector< std::string > soFar);
		std::vector< std::string > addLeftArm(std::vector< std::string > soFar);
		std::vector< std::string > addRightArm(std::vector< std::string > soFar);
		std::vector< std::string > addLeftLeg(std::vector< std::string > soFar);
		std::vector< std::string > addRightLeg(std::vector< std::string > soFar);
		std::vector< std::string > build(int wrongs);
};

HungDude::HungDude(){
	plain.push_back("		-------------              ");
	plain.push_back("		|           |              ");
	plain.push_back("		|           |              ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("		|                          ");
	plain.push_back("__________________________________________");

	headString.push_back("		|        ___|___ ");
	headString.push_back("		|       /       \\");
	headString.push_back("		|	| x   x |");
	headString.push_back("		|       |   ^   |");
	headString.push_back("		|	| \\___/ |");
	headString.push_back("		|        \\_____/");
	headPosition.push_back(2);
	headPosition.push_back(3);
	headPosition.push_back(4);
	headPosition.push_back(5);
	headPosition.push_back(6);
	headPosition.push_back(7);

	bodyString.push_back("|");
	bodyString.push_back("^");
	bodyString.push_back("|");
	bodyString.push_back("|");
	bodyString.push_back("|");
	bodyString.push_back("|");
	bodyString.push_back("|");
	bodyString.push_back("|");
	bodyString.push_back("^");

	bodyPosition.push_back(make_pair(8, 14));
	bodyPosition.push_back(make_pair(9, 14));
	bodyPosition.push_back(make_pair(10, 14));
	bodyPosition.push_back(make_pair(11, 14));
	bodyPosition.push_back(make_pair(12, 14));
	bodyPosition.push_back(make_pair(13, 14));
	bodyPosition.push_back(make_pair(14, 14));
	bodyPosition.push_back(make_pair(15, 14));
	bodyPosition.push_back(make_pair(16, 14));

	leftArmPosition.push_back(make_pair(10, 13));
	leftArmPosition.push_back(make_pair(11, 12));
	leftArmPosition.push_back(make_pair(12, 11));
	leftArmPosition.push_back(make_pair(13, 10));
	leftArmPosition.push_back(make_pair(14, 9));
	leftArmPosition.push_back(make_pair(14, 10));
	leftArmPosition.push_back(make_pair(14, 11));
	leftArmString.push_back("/");
	leftArmString.push_back("/");
	leftArmString.push_back("/");
	leftArmString.push_back("/");
	leftArmString.push_back("/");
	leftArmString.push_back("|");
	leftArmString.push_back("\\");

	rightArmPosition.push_back(make_pair(10, 15));
	rightArmPosition.push_back(make_pair(11, 16));
	rightArmPosition.push_back(make_pair(12, 17));
	rightArmPosition.push_back(make_pair(13, 18));
	rightArmPosition.push_back(make_pair(14, 17));
	rightArmPosition.push_back(make_pair(14, 18));
	rightArmPosition.push_back(make_pair(14, 19));
	rightArmString.push_back("\\");
	rightArmString.push_back("\\");
	rightArmString.push_back("\\");
	rightArmString.push_back("\\");
	rightArmString.push_back("/");
	rightArmString.push_back("|");
	rightArmString.push_back("\\");

	leftLegPosition.push_back(make_pair(17, 13));
	leftLegPosition.push_back(make_pair(18, 12));
	leftLegPosition.push_back(make_pair(19, 11));
	leftLegPosition.push_back(make_pair(20, 10));
	leftLegPosition.push_back(make_pair(21, 9));
	leftLegPosition.push_back(make_pair(22, 8));
	leftLegString.push_back("/");
	leftLegString.push_back("/");
	leftLegString.push_back("/");
	leftLegString.push_back("/");
	leftLegString.push_back("/");
	leftLegString.push_back("/");

	rightLegPosition.push_back(make_pair(17, 15));
	rightLegPosition.push_back(make_pair(18, 16));
	rightLegPosition.push_back(make_pair(19, 17));
	rightLegPosition.push_back(make_pair(20, 18));
	rightLegPosition.push_back(make_pair(21, 19));
	rightLegPosition.push_back(make_pair(22, 20));
	rightLegString.push_back("\\");
	rightLegString.push_back("\\");
	rightLegString.push_back("\\");
	rightLegString.push_back("\\");
	rightLegString.push_back("\\");
	rightLegString.push_back("\\");
}

std::vector< std::string > HungDude::getBlank(){
	std::vector< std::string > ret = plain;
	return ret;
}

std::vector< std::string > HungDude::addHead(soFar){
	for(int x; x<headString.size(); x++){
		soFar[headPosition[x]]=headString[x];
	}
	return soFar;
}

std::vector< std::string > HungDude::addBodyPart(soFar, partString, partMappings){
	for(int x; x<partMappings.size(); x++){
		soFar[partMappings[x].first][partMappings[x].second]=partString[x];
	}
	return soFar;
}

std::vector< std::string > HungDude::addBody(soFar){
	soFar = addBodyPart(soFar, bodyString, bodyPosition);
	return soFar;
}

std::vector< std::string > HungDude::addLeftArm(soFar){
	soFar = addBodyPart(soFar, leftArmString, leftArmPosition);
	return soFar;
}

std::vector< std::string > HungDude::addRightArm(soFar){
	soFar = addBodyPart(soFar, rightArmString, rightArmPosition);
	return soFar;
}

std::vector< std::string > HungDude::addLeftLeg(soFar){
	soFar = addBodyPart(soFar, leftLegString, leftLegPosition);
	return soFar;
}

std::vector< std::string > HungDude::addRightLeg(soFar){
	soFar = addBodyPart(soFar, rightLegString, rightLegPosition);
	return soFar;
}
		std::string build(int wrongs);

std::vector< std::string > HungDude::build(wrongs){
	std::vector< std::string > p = getBlank();
	if(wrongs > 0){
		addHead(p);
	}
	if(wrongs > 1){
		p=addBody(p);
	}
	if(wrongs > 2){
		p=addLeftArm(p);
	}
	if(wrongs > 3){
		p=addRightArm(p);
	}
	if(wrongs > 4){
		p=addLeftLeg(p);
	}
	if(wrongs > 5){
		p=addRightLeg(p);
	}
	return p;
}




/*
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
*/

int main(){
	HungDude hd;
	std::vector< std::string > dude = hd.build(4);
	for(int x=0; x<dude.size(); x++){
		cout << dude[x] << endl;
	}
}
