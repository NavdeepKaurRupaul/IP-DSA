#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#include<vector>
int helper(vector<char> v, int len){
	if(len==0){
		return 0;
	}
	int ans=0;
	if(v[len-1]=='n'){
		ans++;
	}
	int rans=helper(v,len-1);
	return rans+ans;
}
int depth(char str[]) {
	vector<char> v;
	for(int i=0;str[i]!='\0';i++){
		v.push_back(str[i]);
	}
	int len=v.size();
	return helper(v,len);
}

int main(){
	char *str = new char[100000];
	cin>>str;
	cout<<depth(str);
	return 0;
}

