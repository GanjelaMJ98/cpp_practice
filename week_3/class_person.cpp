#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Person{
public:
	void ChangeFirstName(int year, const string& first_name){
		map_first_name[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name){
		map_last_name[year] = last_name;
	}

	string GetFullName(int year){
		string ans = "";

		string f_name = GetName(year, map_first_name);
		string l_name = GetName(year, map_last_name);

		if(f_name == "" && l_name ==""){
			ans = "Incognito";
		}

		if(f_name != "" && l_name ==""){
			ans = f_name + " with unknown last name";
		}

		if(f_name == "" && l_name !=""){
			ans = l_name + " with unknown first name";
		}

		if(f_name != "" && l_name !=""){
			ans = f_name + " " + l_name;
		}

		return ans;
	}
private:
	map<int, string> map_first_name;
	map<int, string> map_last_name;

	string GetName(const int& year, const map<int, string>& names){
		string ans = "";
		for(const auto& name : names){
			if(name.first <= year){
				ans = name.second;
			}else{
				break;
			}
		}

		return ans;
	}
};

int main(){
	//part 1
	Person person;
	person.ChangeFirstName(1965,"Polina");
	person.ChangeLastName(1967,"Sergeeva");
	for(int year : {1900,1965,1990}){
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for(int year : {1969,1970}){
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for(int year : {1969,1970}){
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}