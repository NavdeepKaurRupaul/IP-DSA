#include<iostream>
using namespace std;
long long find_Ways(int N){
    if(N==1 || N==2){
    	return 2;
	} 
    long long ans=find_Ways(N-1)+find_Ways(N-2);
    return ans;
}
int main(){
int N;
cin>>N;
cout<<find_Ways(N);
}

