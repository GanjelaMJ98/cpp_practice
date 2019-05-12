#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Print(const vector<int>& v, const string& title){
	cout << title << ": ";
	for(auto& i : v){
		cout << i << " ";
	}
	cout << endl;
}

bool Gt2(int x){
	if(x > 2){
		return true;
	}
	return false;
}

int main(){
	vector<int> v {1, 5, 3, 2, 4};
	Print(v, "init");

	cout << "count(2): " << count(begin(v), end(v), 2) << endl;

	sort(begin(v), end(v));
	Print(v, "sort");

	cout << "count_if(Gt2): " << count_if(begin(v), end(v), Gt2) << endl;

	int thr;
	cout << "THR = ";
	cin >> thr;
	cout << "count_if(lyamda < thr): " << count_if(begin(v), end(v), [thr](int x){
		if(x < thr){
			return true;
		}
		return false;
	}) << endl;
	
	for(auto& i: v){
		i++;
	}
	Print(v, "item+1");


	return 0;
}