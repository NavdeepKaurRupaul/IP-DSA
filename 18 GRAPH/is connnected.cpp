#include <iostream>
using namespace std;
#include<queue>
bool print(int ** edges,int n, int sv, bool* visited){
	queue<int> q;
	q.push(sv);
	while(!q.empty()){
		int front=q.front();
		q.pop();
		visited[front]=true;
		//cout<<front<<" ";
		for(int i=0;i<n;i++){  
	    	if(edges[i][front]==1){
		    	if(visited[i]){
		    		continue;
		        }
		        q.push(i);
		        visited[i]=true;
		    }
     	}  
	}
	for(int i=0;i<n;i++){
		if(visited[i]!=true){
			return false;
		}
	}
	return true;;
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
	bool * visited=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	if(print(edges,V,0,visited)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
    return 0;
}

