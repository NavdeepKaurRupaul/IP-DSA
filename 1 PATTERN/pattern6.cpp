#include <iostream>
using namespace std;
void printPattern(int n){
	int p=n;
	for(int i=1;i<=n;i+=2){
        int k=(i-1)*n+1;
        for(int j=1;j<=n;j++){
            cout<<k<<" ";
            k++;
        }
        //cout<<k<<" ";
        cout<<endl;
    }
    //if(n%2!=0){
      //  p=n-1;
    //}
    for(int i=p;i>0;i-=2){
        int k=(i-1)*n+1;
        for(int j=1;j<=n;j++) {
            cout<<k<<" ";
            k++;
        }
            cout<<endl;
	}
}
int main() {
    int n;
    cin >> n;
    printPattern(n);
}

