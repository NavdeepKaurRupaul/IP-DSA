#include<iostream>
using namespace std;

int getMinSteps(int n, int *memo) { 
    // base case 
    if (n == 1) 
       return 0; 
    if (memo[n] != -1) 
       return memo[n]; 
    // store temp value for n as min( f(n-1), 
    // f(n/2), f(n/3)) +1 
    int res = getMinSteps(n-1, memo); 
    if (n%2 == 0) 
        res = min(res, getMinSteps(n/2, memo)); 
    if (n%3 == 0) 
        res = min(res, getMinSteps(n/3, memo)); 
    // store memo[n] and return 
    memo[n] = 1 + res; 
    return memo[n]; 
} 
int countStepsTo1(int n){
    int memo[n+1]; 
    for (int i=0; i<=n; i++) 
        memo[i] = -1; 
    return  getMinSteps(n, memo); 
}

int main(){
  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;
}



