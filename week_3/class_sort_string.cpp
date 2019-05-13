#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SortedStrings{
public:
	void AddString(const string& s){
		SortedStrings.push_back(s);
	}

	vector<string> GetSortedStrings(){
		sort(begin(SortedStrings),end(SortedStrings));
		return SortedStrings;
	}
private:
	vector<string> SortedStrings;
};

void PrintSortedStrings(SortedStrings& strings){
	for(const string& s: strings.GetSortedStrings()){
		cout << s << " ";
	}
	cout << endl;
}

int main(){
	SortedStrings strings;
	strings.AddString("first");
	strings.AddString("thitd");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}