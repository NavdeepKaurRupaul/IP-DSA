#include<iostream>
using namespace std;
void printpath(int ** input, int n, int ** solution,int x,int y){
	//base case
	if(x==n-1&&y==n-1){
		solution[x][y]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
			}
			cout<<endl;
			return;
		}
	//invalid positions
	if(x<0 || y<0 || x>=n || y>=n || input[x][y]==0 || solution[x][y]==1 ){
		return;
	}
	//mark the current position 1 (as visited so that it can't be accessed later)
	solution[x][y]=1;
	printpath(input,n,solution,x-1,y);
	printpath(input,n,solution,x+1,y);
	printpath(input,n,solution,x,y-1);
	printpath(input,n,solution,x,y+1);
	solution[x][y]=0;
}
void ispath(int ** input, int n){
	int ** solution = new int *[n];
	for(int i=0;i<n;i++){
		solution[i]=new int[n];
		for(int j=0;j<n;j++){
			solution[i][j]=0;
		}
	}
	printpath(input,n,solution,0,0);
}
int main(){
	int **arr,n;
	cin>>n;
	arr=new int *[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	ispath(arr,n);
}
