#include<iostream>
using namespace std;
int length(char s[]){
	if(s[0]=='\0'){
		return 0;
	}
	int ans =1;
	return ans+length(s+1);
}
int main(){
	char str[1000];
	cin>>str;
	cout<<length(str);
	
}
