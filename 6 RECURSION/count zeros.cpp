#include <iostream>
using namespace std;
int countZeros(int n) {
	if(n==0){
		return 0;
	}
	int ans=0;
	if(n%10==0){
		ans++;
	}
	return ans+countZeros(n/10);
}
int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

