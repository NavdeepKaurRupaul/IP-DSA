#include <iostream>
using namespace std;
int returnFirstSetBit(int n){
    return (n &(~(n-1)));
}


int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}


