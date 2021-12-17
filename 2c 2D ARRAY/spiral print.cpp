#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col){
int count=0;
int rs=0;
int re=row-1;
int cs=0;
int ce=col-1;
while(count<row*col){
	for(int i=cs;i<=ce;i++){
		cout<<input[rs][i]<<" ";
		count++;		
	}
	rs++;
	for(int j=rs;j<=re;j++){
		cout<<input[j][ce]<<" ";
		count++;
	}
	ce--;
	for(int k=ce;k>=cs;k--){
		cout<<input[re][k]<<" ";
		count++;
	}
	re--;
	for(int l=re;l>=rs;l--){
		cout<<input[l][cs]<<" ";
		count++;
	}
	cs++;
}
}

int main() {
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    spiralPrint(input, row, col);
}
