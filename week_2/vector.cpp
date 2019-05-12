#include <iostream>
#include <string>
#include <vector>

using namespace std;

//возвращает вектор дней с температурой выше средней
vector<int> temperature(const vector<int>& days){
	int c = 0;
	vector<int> v;

	for(int day: days){
		c += day;
	}
	
	c = c/days.size();
	
	for(int i = 0; i < days.size(); i++ ){
		if(days[i] >= c){
			v.push_back(i);
		}
	} 
	return v;
}

int main(){
	int n;
	cin >> n;
	vector<int> days(n);
	vector<int> temp;

	for(int i = 0; i < n; i ++){
		cin >> days[i];
	}

	temp = temperature(days);

	cout << temp.size() << endl;
	for(auto x: temp){
		cout << x << " ";
	}
}