#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string s = "abcdf";
	for(char c : s){
		cout << c << ',';
	}
	cout << '\n';

	vector<int> nums = {1, 2, 3, 5, 6, 5};
	for(auto c : nums){
		cout << c << ',';
	}
	cout << "\n";

	// my count
	int my_quantity = 0;
	for(auto x : nums){
		if(x == 5){
			my_quantity += 1;
		}
	}
	cout << "There are " << my_quantity << " fives" << endl;

	//count
	int quantity = count(begin(nums),end(nums),5);
	cout << "There are " << quantity << " fives" << endl;

	//sort
	sort(begin(nums),end(nums));
	for(auto c : nums){
		cout << c << ',';
	}cout << '\n';

	return 0;
}