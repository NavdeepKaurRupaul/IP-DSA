#include<iostream>
using namespace std;
#include<climits>
//recursion
int helper(int*p,int i,int j){
	if(i==j){
		return 0;
	}
	int min=INT_MAX;
	int count;
	for(int k=i;k<j;k++){
		int count=helper(p,i,k)+helper(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min){
			min=count;
		}
	}
	return min;
}
int mcm(int* p, int n){
	return helper(p,1,n);
}
//dp
int mcmdp(int*p,int size){
	int n=size+1;
    int m[n][n]; 
    int i, j, k, L, q;  
    for (i = 1; i < n; i++) {
    	m[i][i] = 0; 
	} 
    for (L = 2; L < n; L++) { 
        for (i = 1; i < n - L + 1; i++) { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) { 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    return m[1][n - 1]; 
}
int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcmdp(p, n);

}



