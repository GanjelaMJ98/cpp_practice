#include <iostream>
#include <string>
#include <vector>

using namespace std;

void UpdateIfGreater(const int& first, int& second){
	if(first > second){
		second = first;
	}
}

void MoveString(vector<string>& source, vector<string>& destination){
	for(string s: source){
		destination.push_back(s);
	}
	source.clear();
}

int main(){
	int a = 4;
	int b = 3;
	int c = 10;
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};

	UpdateIfGreater(a, b);
	cout << b << endl;
	UpdateIfGreater(a, c);
	cout << a << endl;

	MoveString(source,destination);
	cout << source.size() << endl;
	for(string a : destination){
		cout << a  << " ";
	}
}