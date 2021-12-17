#include<iostream>
using namespace std;
void rotate(int **input, int n){
    int output[n][n];
    int i=0;
    int j=0;
    for(int a=n-1;a>=0;a--){
    	for(int b=0;b<n;b++){
    		output[i][j]=input[b][a];
    		j++;
		}
		j=0;
		i++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			input[i][j]=output[i][j];
		}
	}
}


int main() {
    int n;
    cin >> n;
    int **input = new int*[n]; 
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }  
    rotate(input, n);  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

