#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print_stdout(const string& f_name){
	ifstream input(f_name);
	string line;
	if(input){
		while(getline(input,line)){
			cout << line << endl;
		}
	}else{
		cout << "error" << endl;
	}
	
}

void print_file(const string& input_name, const string& output_name){
	ifstream input(input_name);
	ofstream output(output_name);
	string line;
	if(input){
		if(output){
			while(getline(input,line)){
				output << line << endl;
			}
			output << "DONE" << endl;
		}else{
			cout << "error output" << endl;
		}	
	}else{
		cout << "error input" << endl;
	}
}


int main(int argc, char const *argv[])
{
	print_stdout("input.txt");
	cout << "----------" << endl;
	print_file("input.txt", "output.txt");
	print_stdout("output.txt");

	return 0;
}