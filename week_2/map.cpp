#include <iostream>
#include <string>
#include <map>

using namespace std;

void PrintMap(const map<int,string>& m){
	cout << "Size: " << m.size() << endl;
	for(auto item : m){
		cout << item.first << " : " << item.second << endl;
	}
}


void PrintReversedMap(const map<string,int>& m){
	cout << "Size: " << m.size() << endl;
	for(auto item : m){
		cout << item.first << " : " << item.second << endl;
	}
}

map<string,int> ReverseMap(const map<int,string>& m){
	map<string,int> result;
	for(auto item : m){
		result[item.second] = item.first;
	}
	return result;
}

int main(){
	map<int,string> events;
	events[1950] = "Stroustrup's birth";
	events[1941] = "Ritchie's birth";
	events[1998] = "Ganjela's birth";
	PrintMap(events);
	events.erase(1998); //delete
	PrintMap(events);
	map<string,int> rev = ReverseMap(events);
	PrintReversedMap(rev);

	return 0;
}