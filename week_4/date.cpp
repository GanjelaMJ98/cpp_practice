#include <iostream>
using namespace std;

struct Day
{
	int value;
	 explicit Day(const int& new_day){
	 	value = new_day;
	 };
};


struct Month
{
	int value;
	 explicit Month(const int& new_month){
	 	value = new_month;
	 };
};


struct Year
{
	int value;
	 explicit Year(const int& new_year){
	 	value = new_year;
	 };
};



class Date
{
public:
	int day;
	int month;
	int year;
	Date(const Day& new_day, const Month& new_month, const Year& new_year){
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	};
};


void PrintDate(const Date& date){
	cout << date.day << "." << date.month << "." << date.year << endl;
}

int main(){
	Date date(Day(19), Month(10), Year(1998));
	PrintDate(date);

	//explicit
	//Date date({19}, {09}, {1998});	- ERROR
	//Date date(19, 9, 1998);			- ERROR
	return 0;
}