#include<iostream>
using namespace std;
int count(int n){
    if(n==0){
    	return 0;
	}
	int ans=1;
	return ans+count(n/10);
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}



