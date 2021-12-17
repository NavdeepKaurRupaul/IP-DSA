#include <iostream>
#include<cstring>
using namespace std;
bool isPermutation(char input1[], char input2[]) {
	
	if(strlen(input1)==strlen(input2)){
		int freq[256];
		for(int i=0;i<256;i++){
			freq[i]=0;
		}
		for(int i=0;input1[i]!='\0';i++){
			int a=input1[i];
			freq[a]++;
		}
		for(int i=0;input2[i]!='\0';i++){
			int b=input2[i];
			freq[b]--;
		}
		for(int i=0;i<256;i++){
			if(freq[i]!=0){
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}	
}

int main() {
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if(isPermutation(input1, input2) == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}

