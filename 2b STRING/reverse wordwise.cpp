#include <iostream>
using namespace std;
int length(char input[]){
	int count=0;
	for(int i=0;input[i]!='\0';i++){
		count++;
	}
	return count;
}
void reverse(char input[], int start, int end){
    int i=start;
    int j=end;
    while(i<j){
		char temp=input[i];
		input[i]=input[j];
		input[j]=temp;
		i++;
		j--;
	}
}
void reverseString(char input[]){
	int i=0;
	int len=length(input);
	int j=len-1;
	while(i<j){
		char temp=input[i];
		input[i]=input[j];
		input[j]=temp;
		i++;
		j--;
	}
}
void reverseStringWordWise(char input[]) {
    reverseString(input);
    int start=0, end=0, i;
    for(i=0; input[i]!='\0'; i++){
        if(input[i]==' '){
            end=i-1;
            reverse(input, start, end);
            start=i+1;
        }
    }
    end=i-1;
    reverse(input, start, end);
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

