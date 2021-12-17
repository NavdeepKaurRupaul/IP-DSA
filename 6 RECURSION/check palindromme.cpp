#include <iostream>
using namespace std;
bool helper(char input[],int start,int end){
	if(start>=end){
        return true;
    }
 	if(input[start]!=input[end]){
		return false;
	}
    start++;
    end--;
	bool b= helper(input,start,end);
    if(b){
        return true;
    }
    else{
        return false;
    }
}
bool checkPalindrome(char input[]) {
	int size=0;
    for(int i=0;input[i]!='\0';i++){
    	size++;
	}
	int start =0;
	int end=size-1;
	return helper(input,start,end);
}
int main() {
    char input[50];
    cin >> input;   
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

