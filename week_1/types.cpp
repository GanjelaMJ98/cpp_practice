#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Person{
	string name;
	string surname;
	int age;
};

int main(){
	int x =5;
	double pi = 3.14;
	bool logical_value = false;
	char symbol = 'z';

	string hw = "Hello, world";
	cout << hw << endl;

	vector<int> nums = {1, 2, 3, 4};
	cout << "Vector's size: " << nums.size() << endl;

	map<string, int> name_to_value;
	name_to_value["one"] = 1;
	name_to_value["two"] = 2;
	cout << "tho is " << name_to_value["two"] << endl;

	vector<Person> staff;
	staff.push_back({"Ivan", "Ivanov", 25});
	staff.push_back({"Petr", "Petrov", 30});
	cout << staff[1].surname << endl;
	return 0;
}
