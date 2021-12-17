#include <iostream>
using namespace std;
int clearAllBits(int n, int i){
    int M=((1<<(i))-1);
    return n&M;   
}


int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< clearAllBits(n, i) <<endl;
		
	return 0;
}


