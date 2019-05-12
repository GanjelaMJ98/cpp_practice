#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void UniqueString(){
	set<string> uniq;
	int N = 0;
	cout << "N = ";
	cin >> N;
	for(int i = 0; i < N; i++){
		string x;
		cin >> x;
		uniq.insert(x);
	}
	cout << uniq.size() << endl;
}

set<string> BuildMapValuesSet(const map<int,string>& m){
	set<string> values;
	for(const auto& item : m){
		values.insert(item.second);
	}
	return values;
}

int main(){
	UniqueString();
	set<string> values = BuildMapValuesSet({
		{1, "odd"},
		{2, "even"},
		{3, "odd"},
		{4, "even"},
		{5, "odd"}
	});
	for(const string& value : values){
		cout << value << endl;
	}

}