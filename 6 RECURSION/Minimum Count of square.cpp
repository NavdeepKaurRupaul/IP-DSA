#include<iostream>
#include<cmath>
using namespace std;
int minCount(int n){
	// base cases 
    // if n is perfect square then Minimum squares required is 1 (144 = 12^2) 
    //The floor() function in C++ returns the largest possible integer value which is less than or equal to the given argument.
    if (sqrt(n) - floor(sqrt(n)) == 0){
    	return 1; 
	}
    if (n <= 3) {
    	return n;
	}
    // getMinSquares rest of the table using recursive formula 
    int res = n; // Maximum squares required is n (1*1 + 1*1 + ..) 
    // Go through all smaller numbers to recursively find minimum 
    for (int x = 1; x <= n; x++) { 
        int temp = x * x; 
        if (temp > n){
        	break;
		}    
        else{
        	res = min(res, 1 + minCount(n - temp));
		}     
    } 
    return res;
}

int main(){
  int num;
  cin >> num;
  cout << minCount(num);
}

