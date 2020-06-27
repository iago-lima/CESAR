#include <iostream>
#include <string>

using namespace std;

string replaceSpaces(string phrase){
	while(phrase.find(' ') != string::npos){

		int firstSpaceIndex = phrase.find(' ');
		int lastLetterIndex = phrase.find_last_not_of(' ');

		for (int i = lastLetterIndex; i >= firstSpaceIndex; i--){
			phrase[i + 2] = phrase[i];
		}

		phrase[firstSpaceIndex] = '&';
        phrase[firstSpaceIndex + 1] = '3';
        phrase[firstSpaceIndex + 2] = '2';

	}

	return phrase;
}

int main(int argc, char const *argv[])
{
	string phrase = replaceSpaces("Iago Oliveira Lima    ");
	cout << phrase << endl;
	phrase = replaceSpaces("User is not allowed      ");
	cout << phrase << endl;

	return 0;
}