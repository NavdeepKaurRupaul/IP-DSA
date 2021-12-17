#include<iostream>
using namespace std;
#include<map>	
int main(){
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    map<int,int> a;
    for(int i=0;i<n;i++){
    	a[arr[i]]++;
	}
	a.begin();
}

