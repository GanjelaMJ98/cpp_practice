#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Person{
public:
	Person(const string& f_name, const string& l_name, const int& y){
		ChangeFirstName(y,f_name);
		ChangeLastName(y,l_name);
		birth = y;
	}
	void ChangeFirstName(int year, const string& first_name){
		if(year < birth){
			return;
		}
		map_first_name[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name){
		if(year < birth){
			return ;
		}
		map_last_name[year] = last_name;
	}

	string GetFullName(int year){
		if(year < birth){
			return "No person";
		}

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
		if(year < birth){
			return "No person";
		}

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
	int birth;
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
	Person person("Polina", "Sergeeva", 1960);
	for(int year: {1959, 1960}){
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for(int year: {1965, 1967}){
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}