#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> Interface(){
	int n;
	cout << "N = ";
	cin >> n;
	vector<vector<string>> result(n);
	for(int i = 0; i < n; i++){
		vector<string> str(2);
		cin >> str[0] >> str[1];
		result[i] = str;
	}
	
	return result;
}

void PrintStartVector(const vector<vector<string>>& v){
	for(int i = 0; i < v.size(); i++){
		cout << endl << "---" << i << "---" << endl;
		for(const auto& str : v[i]){
			cout << str << " ";
		}
	}
}

void PrintLiter(const map<char,int>& v){
	for(const auto& item : v){
		cout << item.first << " - " << item.second << endl;
	}
}

map<char,int> MakeMap(string s){
	map<char,int> liter;
	for(int i = 0; i < s.size(); i++){
		liter[s[i]] = count(s.begin(), s.end(), s[i]);
	}
	return liter;
}

void IsAnogramm(const vector<vector<string>>& v){
	map<char,int> first, second;
	for(const auto& item : v){
		first = MakeMap(item[0]);
		second = MakeMap(item[1]);
		if(first == second){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;	
		}
	}
}

int main(){
	IsAnogramm(Interface());
	//PrintLiter(MakeMap("Hello"));
	return 0;
}