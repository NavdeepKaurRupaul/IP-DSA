#include<iostream>
using namespace std;
#include<string>
void print(string input, string output){
	if(input.length()==0){
		cout<<output<<endl;
		return;
	}
	print(input.substr(1),output);
	print(input.substr(1),output+input[0]);
}
int main(){
	string input;
	cin>>input;
	string output="";
	print(input,output);
}
