#include <iostream>
using namespace std;
bool helper(int ** edges, int n,int start,int end,bool * visited){
	if(edges[start][end]==1){
		return true;
	}
	visited[start]=true;
	for(int i=0;i<n;i++){
        if(visited[i]==0 and edges[start][i]==1){
            bool ans=helper(edges,n,i,end,visited);
        if(ans==true){
            return true;
        }
        }
        //bool ans=helper(edges,n,i,end,visited);
	}
     if(visited[end]){
        return true;
    }
	return false;
}
bool haspath(int ** edges, int n,int start,int end){
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	return helper(edges,n,start,end,visited);
}
int main() {
    int V, E;
    cin >> V >> E;
    int ** edges= new int*[V];
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
	int start,end;
	cin>>start>>end;
    if(haspath(edges,V,start,end)){
    	cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	for(int i=0;i<V;i++){
		delete [] edges[i]; 
	}
	delete [] edges;
  return 0;
}

