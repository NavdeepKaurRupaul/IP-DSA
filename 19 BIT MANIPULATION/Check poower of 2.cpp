#include <iostream>
using namespace std;
bool isPowerOf2(int n){
    if((n & (n-1))==0 && n>0){
    	return true;
	}    
	else{
		return false;
	}
}


int main() {
	int n;

	cin >> n;
	
    if(isPowerOf2(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	return 0;
}


