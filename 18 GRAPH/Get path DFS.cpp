#include <iostream>
using namespace std;
#include<vector>
vector<int>* helper(int **edges,int n,bool* visited,int sv,int ev){
//	vector<int> ans;
	if(sv==ev){
		vector<int>* ans=new vector<int>();
		ans->push_back(ev);
		return ans ;
	}
	visited[sv]=true;
	//vector<int> a;
	for(int i=0;i<n;i++){
		if(visited[i]==0 and edges[sv][i]==1){
			vector<int>*a=helper(edges,n,visited,i,ev);
		    if(a!=NULL){
		       a->push_back(sv);
		       return a;
     	}
		}
	}
	return NULL;
}
vector<int>* getPath(int** edges,int n,int sv,int ev){
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	vector<int>*ans=helper(edges,n,visited,sv,ev);
	delete[]visited;
	return ans;
}
int main(){
  int V, E, tempX, tempY;
  cin >> V >> E;
  int ** edges= new int*[V];
  for(int i=0;i<V;i++){
  	edges[i]=new int[V];
  	for(int j=0;j<V;j++){
  		edges[i][j]=0;
	  }
  }
  for(int i=0;i<E;i++){
  	int firstVertex,secondVertex;
  	cin>>firstVertex>>secondVertex;
  	edges[firstVertex][secondVertex]=1;
  	edges[secondVertex][firstVertex]=1;
  }
  int startvertex,endvertex;
  cin>>startvertex>>endvertex;
  vector<int>* ans=getPath(edges,V,startvertex,endvertex);
  if(ans==NULL){
      return NULL;
  }
  for(int i=0;i<ans->size();i++){
  	cout<<ans->at(i)<<" ";
  }
  cout<<endl;
  return 0;
}

