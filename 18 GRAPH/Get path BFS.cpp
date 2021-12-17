#include <iostream>
using namespace std;
#include<queue>
#include<unordered_map>
vector<int>* GetPath(int** edges,int n,int sv,int ev){
	queue<int>q;
	q.push(sv);
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	visited[sv]=true;
	unordered_map<int,int> map;
	bool done=false;
	while(!q.empty() and !done){
		int front=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(!visited[i] and edges[front][i]==1){
				map[i]=front;
				q.push(i);
				visited[i]=true;
				if(i==ev){
					done=true;
					break;
				}
			}
		}
	}
	delete [] visited;
	if(!done){
		return NULL;
	}
	else{
		vector<int>* ans=new vector<int>();
		int current=ev;
		ans->push_back(ev);
		while(current!=sv){
			current=map[current];
			ans->push_back(current);
		}
		return ans;
	}
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
  vector<int>* ans=GetPath(edges,V,startvertex,endvertex);
  if(ans==NULL){
      return NULL;
  }
  for(int i=0;i<ans->size();i++){
  	cout<<ans->at(i)<<" ";
  }
  cout<<endl;
  return 0;
  return 0;
}

