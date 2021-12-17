#include <iostream>
using namespace std;
int ClearBitsLSB(int n,int i){
    int M= ~((1<<(i+1))-1);
    return n&M;
}


int main() {
	int n;

	cin >> n;
	int i;
	cin>>i;
	cout<< ClearBitsLSB(n,i) <<endl;
		
	return 0;
}


