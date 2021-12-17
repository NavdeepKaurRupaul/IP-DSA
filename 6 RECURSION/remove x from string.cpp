#include<iostream>
using namespace std;
void removeX(char s[]){
	if(s[0]=='\0'){
		return ;
	}
	if(s[0]!='x'){
		removeX(s+1);
	}
	else{
		int i=1;
		for(;s[i]!='\0';i++){
			s[i-1]=s[i];
		}
		//to shift null character
		s[i-1]=s[i];
		//if shifted string s[0]==x
		removeX(s);
	}
}
int main(){
	char str[1000];
	cin>>str;
	removeX(str);
	cout<<str<<endl;
}
