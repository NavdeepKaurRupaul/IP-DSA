#include <iostream>
using namespace std;
#include <cmath>
//recursion
int balancedBTs(int h) {
	if(h <= 1) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;

	return ans;
}
//memomisation
int helper(int h,int *a){
	if(h<=1){
		return 1;
	}
	if(a[h]!=-1){
		return a[h];
	}
	int mod = (int) (pow(10, 9)) + 7;
	int x = helper(h - 1,a);
	int y = helper(h - 2,a);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	a[h] = (temp1 + temp2) % mod;
	return a[h];
}
int balancedBTsMemo(int h){
	int * a=new int[h+1];
	for(int i=0;i<=h;i++){
		a[i]=-1;
	}
	return helper(h,a);
}
int main() {
    int h;
    cin >> h;
    int ans = balancedBTsMemo(h);
    cout << ans << endl;
}

