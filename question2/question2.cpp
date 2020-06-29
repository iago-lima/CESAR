#include <iostream>
#include <string>

using namespace std;

bool verifyPartialPermutation(string word1, string word2){
	if(word1.size() == word2.size()){
	    if(word1.size() <= 3){
	        if(word1[0] == word2[0]){
	            return true;
	        }else{
	            return false;
	        }
	    }
		if(word1[0] == word2[0]){
			float diffLettersCounter = 0.0;
		
			for (int i = 0; i < word1.size(); i++){
				int indexFirst = word1.find(word2[i]);
				if(indexFirst == string::npos){
					return false;
				}if(i != indexFirst){
					diffLettersCounter++;
				}
			}
			if(diffLettersCounter < (word1.size() * (2.0/3.0))){
		    	return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[]){
	cout << "you, yuo -> " << boolalpha << verifyPartialPermutation("you", "yuo") << endl; 
    cout << "probably, porbalby -> " << boolalpha << verifyPartialPermutation("probably", "porbalby") << endl;
    cout << "despite, desptie -> " << boolalpha << verifyPartialPermutation("despite", "desptie") << endl;
    cout << "moon, nmoo -> " << boolalpha << verifyPartialPermutation("moon", "nmoo") << endl;
    cout << "misspellings, mpeissngslli -> " << boolalpha << verifyPartialPermutation("misspellings", "mpeissngslli") << endl;
        
    return 0;
}