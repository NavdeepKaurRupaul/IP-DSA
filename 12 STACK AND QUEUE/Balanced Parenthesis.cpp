#include <iostream>
using namespace std;
#include<stack>
#include<cstring>
bool checkBalanced(char *exp) {
	stack<char> s;
	for(int i=0;exp[i]!='\0';i++){
		if( exp[i]=='(' || exp[i]=='[' || exp[i]=='{' ){
			s.push(exp[i]);
		}
		if(exp[i]==')' ){
            if(!s.empty() && s.top()=='(')
				s.pop();
            else
                return false;
		}
		if(exp[i]==']' ){
            if(!s.empty() && s.top()=='[')
				s.pop();
            else
                return false;
		}
		if(exp[i]=='}' ){
			if(!s.empty() && s.top()=='{')
				s.pop();
            else
                return false;
		}
	}
	if(s.empty()){
		return true;
	}
	else{
		return false;
	}
}
int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

