#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration
{
	int hour;
	int min;
	int total;

	Duration(int h = 0, int m = 0){
		total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
		if(hour < 0){
			hour = hour + 12;
		}
		if(min < 0){
			min = min + 60;
			hour -= 1;
		}
	}
};

ostream& operator<<(ostream& stream, const Duration& duration){
	stream << setfill('0');
	stream << setw(2) << duration.hour << ":"
			<< setw(2) << duration.min;
	return stream;
}

istream& operator>>(istream& stream, Duration& duration){
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs){
	return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

Duration operator-(const Duration& lhs, const Duration& rhs){
	return Duration(lhs.hour - rhs.hour, lhs.min - rhs.min);
}

bool operator<(const Duration& lhs, const Duration& rhs){
	if(lhs.hour == rhs.hour){
		return lhs.min < rhs.min;
	}else{
		return lhs.hour < rhs.hour;
	}
}

int main(int argc, char const *argv[])
{
	Duration test;
	cin >> test;
	cout << test << endl;

	Duration d1 = {2,50};
	Duration d2 = {0,35};
	Duration d3 = d1 + d2;
	Duration d4 = d1 - d2;
	Duration d5 = d2 - d1;
	vector<Duration> v = {d1,d2,d3,d4,d5};
	sort(begin(v),end(v));
	for(const auto& i : v){
		cout << i.hour << ":" << i.min << " ";
	} 

	return 0;
}