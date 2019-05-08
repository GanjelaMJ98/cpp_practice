#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string first){
	string second = first;
	reverse_copy(begin(first), end(first), begin(second));
	if(first == second){
		return true;
	}else{
		return false;
	}
}

vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> ok;
	for(string word : words){
		if(IsPalindrom(word) == 1 && word.size() >= minLength){
			ok.push_back(word);
		}		
	}
	if(ok.empty() == true){
		ok.push_back("empty");
	}
	return ok;
}

int main(){
	cout << "IsPalindrom(madam) = " << IsPalindrom("madam") << endl;
	cout << "IsPalindrom(gantleman) = " << IsPalindrom("gantleman") << endl;
	cout << "IsPalindrom(X) = " << IsPalindrom("X") << endl;
	vector<string> v = {"weew","bro","aba","abacaba","code"};
	vector<string> f = PalindromFilter(v, 4);
	cout << "Filter: weew,bro,aba,abacaba,code , min = 4 : " << endl;
	for(string a : f){
		cout << a << endl;
	}
}