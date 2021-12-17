#include<iostream>
using namespace std;
int priority(char a){
	int ans;
	switch(a){
		case '^':
			ans= 1;
			break;
		case '*' :
			ans= 2;
			break;
		case '/' :
			ans= 2;
			break;
		case '+' :
			ans= 3;
			break;
		case '-' :
			ans= 3;
			break;
	}
	return ans;
}
int main(){
	cout<<priority('+');
}
