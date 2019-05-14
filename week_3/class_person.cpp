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

	string GetFullNameWithHistory(int year){
		string ans = "";

		string f_name = GetName(year, map_first_name);
		string l_name = GetName(year, map_last_name);

		if(f_name == "" && l_name ==""){
			ans = "Incognito";
		}

		if(f_name != "" && l_name ==""){
			ans = f_name + " " + GetPastName(year, f_name,map_first_name) + " with unknown last name";
		}

		if(f_name == "" && l_name !=""){
			ans = l_name + " " + GetPastName(year, l_name,map_last_name) + " with unknown first name";
		}

		if(f_name != "" && l_name !=""){
			ans = f_name + " " + GetPastName(year, f_name,map_first_name) + " " + l_name + " " + GetPastName(year, l_name,map_last_name);
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

	string GetPastName(const int& year, const string& current_name, const map<int , string>& names){
		string ans = " ";
		for(auto& name : names){
			if(name.first <= year){
				if(name.second != current_name){
					ans += name.second + " ";
				}
			}else{
				break;
			}
		}
		if(ans != " "){
			ans = "(" + ans + ")";
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
	cout << endl;
	
	//part 2
	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for(int year: {1960,1967}){
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}