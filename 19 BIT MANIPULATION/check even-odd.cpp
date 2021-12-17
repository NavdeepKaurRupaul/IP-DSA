#include <iostream>
using namespace std;
bool isEven(int n){
	return (n & 1);
}
int main() {
	int n;

	cin >> n;
	
    if(isEven(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	return 0;
}


