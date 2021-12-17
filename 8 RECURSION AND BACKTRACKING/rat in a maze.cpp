#include<iostream>
using namespace std;
bool ispathhelper(int ** input, int n, int ** solution,int x,int y){
	//base case
	if(x==n-1&&y==n-1){
		return true;
	}
	//invalid positions
	if(x<0 || y<0 || x>=n || y>=n || input[x][y]==0 || solution[x][y]==1 ){
		return false;
	}
	//mark the current position 1 (as visited so that it can't be accessed later)
	solution[x][y]=1;
	if(ispathhelper(input,n,solution,x-1,y)){
		return true;
	}
	if(ispathhelper(input,n,solution,x+1,y)){
		return true;
	}
	if(ispathhelper(input,n,solution,x,y-1)){
		return true;
	}
	if(ispathhelper(input,n,solution,x,y+1)){
		return true;
	}
	solution[x][y]=0;
	return false;
}
bool ispath(int ** input, int n){
	int ** solution = new int *[n];
	for(int i=0;i<n;i++){
		solution[i]=new int[n];
		for(int j=0;j<n;j++){
			solution[i][j]=0;
		}
	}
	return ispathhelper(input,n,solution,0,0);
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
	if(ispath(arr,n)){
		cout<<"There is a path"<<endl;
	}
	else{
		cout<<"There is no path"<<endl;
	}
}
