#include<iostream>
using namespace std;
int main(){
	int N,i;
	cin>>N>>i;
	int z= N & (1<<i);
	if(z==0){
		cout<<"0"<<endl;
	}
	else{
		cout<<"1"<<endl;
	}
}
