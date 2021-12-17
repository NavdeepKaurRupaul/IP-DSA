#include<iostream>
using namespace std;
void print(int ** edges,int n,int sv, bool* visited){
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[i][sv]==1){
			if(visited[i]){
				continue;
			}
			print(edges,n,i,visited);
		}
	}
}
void DFS(int ** edges,int n){
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			print(edges,n,i,visited);
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	int ** edges=new int*[n];
	for (int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int firstVetex;
		int secondVertex;
		cin>>firstVetex>>secondVertex;
        edges[firstVetex][secondVertex]=1;
        edges[secondVertex][firstVetex]=1;
	}
	DFS(edges,n);
}
