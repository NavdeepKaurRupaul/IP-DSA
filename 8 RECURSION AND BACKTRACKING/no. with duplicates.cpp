#include <iostream>
using namespace std;
int factorial(int num){
	if(num==1){
		return 1;
	}
	return num*factorial(num-1);
}
long num(int * input,int n,int* fact, int* freq){
	if(n==0||n==1){
		return 0;
	}
	int ans=0;
	int div=1;
	for(int i=0;i<n;i++){
		div=div*factorial(freq[i]);
	}
	
	for(int i=0;i<n;i++){
		if(freq[i]>0){
			ans+=(fact[n-1]*freq[input[0]])/div;
		}
	}
		freq[0]--;
		ans+=num(input+1,n-1,fact,freq);
	return ans;	
}
long numberOfNumbersWithDuplicates(long n){
	int * input=new int[n];
	int * fact=new int[n+1];
	int freq[10]={};
	fact[0]=1;
	for(int i=0;i<n;i++){
		freq[input[i]]++;
		fact[i+1]=(i+1)*fact[i];
	}	
	return num(input,n,fact,freq);
}
int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}

