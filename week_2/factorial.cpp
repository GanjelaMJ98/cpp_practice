#include <iostream>

using namespace std;

int Factorial(int x){
	if(x <= 1 ){
		return 1;
	}else{
		return(x * Factorial(x-1));
	}
}

int main(){
	int x = 1;
	int y = -2;
	int z = 4;
	cout << x << "! = " << Factorial(x) << endl;
	cout << y << "! = " << Factorial(y) << endl;
	cout << z << "! = " << Factorial(z) << endl; 
}