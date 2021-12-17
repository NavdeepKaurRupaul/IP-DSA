#include<bits/stdc++.h> 
using namespace std; 
int countNumbersWith4(int n) { 
	// Base case 
	if (n < 4){ 
		return 0; 
	}
	
	int d = log10(n); 
	
	int *a = new int[d+1]; 
	a[0] = 0, a[1] = 1; 
	for (int i=2; i<=d; i++){ 
		a[i] = a[i-1]*9 + ceil(pow(10,i-1)); 
	}
	
	int p = ceil(pow(10, d)); 
	
	int msd = n/p; 
	
	if (msd == 4) {
		return (msd)*a[d] + (n%p) + 1;
	}
		
	if (msd > 4){ 
		return (msd-1)*a[d] + p + countNumbersWith4(n%p); 
	}

	return (msd)*a[d] + countNumbersWith4(n%p); 
} 

int main() { 
	int n ;
	cin>>n; 
	cout << "Count of numbers from 1 to " << n << " that have 4 as a a digit is "<< countNumbersWith4(n) << endl; 
	return 0; 
} 

