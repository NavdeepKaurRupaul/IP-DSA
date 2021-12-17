#include <iostream>
using namespace std;
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
void reverseEachWord(char input[]){
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
    reverseEachWord(input);
    cout << input << endl;
}

