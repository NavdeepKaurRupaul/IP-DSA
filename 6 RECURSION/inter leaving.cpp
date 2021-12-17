#include <iostream>
#include<cstring>
using namespace std;
void InterLeaving(char* first, char* second,int m,int n, char* output, int i){
	if(m==0 && n==0){
		cout<<output<<endl;
	}
	if(m!=0){
		output[i]=first[0];
		InterLeaving(first+1,second,m-1,n,output,i+1);
	}
	if(n!=0){
		output[i]=second[0];
		InterLeaving(first,second+1,m,n-1,output,i+1);
	}
}
void interleaving(char* first, char* second) {
	int m=strlen(first);
	int n=strlen(second);
	char * output=new char[m+n];
	output[m+n]='\0';
	InterLeaving(first,second,m,n,output,0);
	free(output);
}
int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}

