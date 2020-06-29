#include <iostream>
#include <string>

using namespace std;
bool checkTypos(string word1, string word2){
	if (word1.compare(word2) == 0){
		return false;
	}

	int count = 0;
	string word1Aux = word1;
	string word2Aux = word2;

	if(word1.size() == word2.size()){
		for (int i = 0; i < word1.size(); i++){
			if(word2[i] != word1[i]){
				count++;
			}
		}
	}else if(word1.size() > word2.size()){
		int diffLeng = word1.size() - word2.size();
		
		while(diffLeng > 0){
			word2Aux += "$";
			diffLeng--;
		}

		for (int i = 0; i < word1.size(); i++){
			if(word1[i] != word2Aux[i]){
				word2Aux = word2Aux.substr(0, i) + word1[i] + word2Aux.substr(i, word2Aux.size() -1);
				count++;
			}
		}
	}
	else{
		int diffLeng = word2.size() - word1.size();
		
		while(diffLeng > 0){
			word1Aux += "$";
			diffLeng--;
		}

		for (int i = 0; i < word2.size(); i++){
			if(word2[i] != word1Aux[i]){
				word1Aux = word1Aux.substr(0, i) + word2[i] + word1Aux.substr(i, word1Aux.size() - 1);
				count++;
			}
		}
	}

	return count == 1;
	
}

int main(int argc, char const *argv[])
{
	cout << "pale, ple -> " << boolalpha << checkTypos("pale", "ple") << endl;
	cout << "pales, pale -> " << boolalpha << checkTypos("pales", "pale") << endl;
	cout << "pale, bale -> " << boolalpha << checkTypos("pale", "bale") << endl;
    cout << "pale, bake -> " << boolalpha << checkTypos("pale", "bake") << endl; 
    cout << "iago, lima -> " << boolalpha << checkTypos("iago", "lima") << endl; 
    cout << "iago, tiago -> " << boolalpha << checkTypos("iago", "tiago") << endl; 
    cout << "iago, igor -> " << boolalpha << checkTypos("iago", "igor") << endl; 
    	
	return 0;
}