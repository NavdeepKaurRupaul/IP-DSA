#include <iostream>
using namespace std;
#include<queue>
void print(int ** edges,int n, int sv, bool* visited){
	queue<int> q;
	q.push(sv);
	visited[sv]=true;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		//visited[front]=true;
		cout<<front<<" ";
		for(int i=0;i<n;i++){ 
		    if(i==front){
		    	continue;
			} 
	    	if(edges[i][front]==1 && !visited[i]){
		        q.push(i);
		        visited[i]=true;
		    }
     	}  
	}
	//cout<<endl;
}
void BFS(int ** edges,int n){
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
		print(edges,n,i,visited);
	    }
	}
    cout<<endl;
	delete [] visited;
}
int main() {
    int V, E;
    cin >> V >> E;
    int ** edges=new int*[V];
    for(int i=0;i<V;i++){
    	edges[i]=new int[V];
    	for(int j=0;j<V;j++){
    		edges[i][j]=0;
		}
	}
    for(int i=0;i<E;i++){
    	int firstVetex;
		int secondVertex;
		cin>>firstVetex>>secondVertex;
        edges[firstVetex][secondVertex]=1;
        edges[secondVertex][firstVetex]=1;
	}
	
	BFS(edges,V);
	for(int i=0;i<V;i++){
		delete [] edges[i];
	}
	delete[] edges;
    return 0;
}

