#include <iostream>
#include <exception>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream){
	if(stream.peek() != '/'){
		stringstream ss;
		ss << "expected / , but has: " << char(stream.peek());
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date ParsDate(const string& s){
	stringstream stream(s);
	Date date;
	stream >> date.year;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.month;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.day;
	return date;
}

void PrintDate(string date_str){
	try{
	Date date = ParsDate(date_str);
	cout << setw(2) << setfill('0') << date.day << "."
		<< setw(2) << setfill('0') << date.month << "." << date.year << endl;
	} catch (exception& ex) {
		cout << "exception: " << ex.what() << endl;
	}
}

int main(int argc, char const *argv[])
{	
	for(str : {"2017/01/25", "1998a09.10"}){
		PrintDate(str);
	}
	cout << "DONE" << endl;
	return 0;
}