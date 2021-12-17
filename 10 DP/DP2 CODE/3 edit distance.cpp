#include<iostream>
using namespace std;
int editDistance(string s, string t){
	//recursiion
	if(s[0]=='\0' ){
		return t.size();
	}
	if(t[0]=='\0'){
		return s.size();
	}
	if(s[0]==t[0]){
		return editDistance(s.substr(1),t.substr(1));
	}
	else{
		int x=editDistance(s.substr(1),t);
		int y=editDistance(s.substr(1),t.substr(1));
		int z=editDistance(s,t.substr(1));
		return 1+min(x,min(y,z));
	}
}
//memoization
int helper(string s,string t,int**dp){
	if(s[0]=='\0' ){
		dp[0][t.size()]=t.size();
		return t.size();
	}
	if(t[0]=='\0'){
		dp[s.size()][0]=s.size();
		return s.size();
	}
	int m=s.size();
	int n=t.size();
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	if(s[0]==t[0]){
		dp[m][n]=helper(s.substr(1),t.substr(1),dp);
		return helper(s.substr(1),t.substr(1),dp);
	}
	else{
		int x=helper(s.substr(1),t,dp);
		int y=helper(s.substr(1),t.substr(1),dp);
		int z=helper(s,t.substr(1),dp);
		dp[m][n]= 1+min(x,min(y,z));
		return dp[m][n];
	}
}
int editDistancememo(string s1, string s2){
	int m=s1.size();
	int n=s2.size();
	int ** dp=new int*[m+1];
	for(int i=0;i<=m;i++){
		dp[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			dp[i][j]=-1;
		}
	}
	return helper(s1,s2,dp);
}
//dp
int editDistancedp(string s,string t){
	int m=s.size();
	int n=t.size();
	int **dp=new int*[m+1];
	for(int i=0;i<=m;i++){
		dp[i]=new int[n+1];
	}
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[m-i]==t[n-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				int a=dp[i-1][j];
				int b=dp[i-1][j-1];
				int c=dp[i][j-1];
				dp[i][j]=1+min(a,min(b,c));
			}
		}
	}
	return dp[m][n];
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;
  cout << editDistancememo(s1,s2) << endl;
  cout << editDistancedp(s1,s2) << endl;

}
