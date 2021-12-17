#include<iostream>
using namespace std;
bool checkNumber(int input[], int size, int x) {
  if(size==0){
  	return false;
  }
  if(input[0]==x){
  	return true;
  }
  bool ans = checkNumber(input+1,size-1,x);
  if(ans){
  	return true;
  }
  else{
  	return false;
  }
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;   
    cin >> x;   
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}



