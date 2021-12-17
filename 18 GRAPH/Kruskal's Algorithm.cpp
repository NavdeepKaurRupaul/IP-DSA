#include <iostream> 
#include <algorithm>
using namespace std;
class Edge{
	public:
		int source;
		int dest;
		int weight;
};
bool compare(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}
int findParent(int v,int* parent){
	if(parent[v]==v){
		return v;
	}
	return findParent(parent[v],parent);
}
void Kruskal(Edge * input,int n,int e){
	//sort input array according to weights(increasing order)
	sort(input,input+e,compare);
	Edge *output=new Edge[n-1];
	int count=0;
	int i=0;
	int * parent = new int[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	while(count != n-1){
		Edge current=input[i];
		int sourceParent = findParent(current.source,parent);
		int destParent = findParent(current.dest,parent);
		if(sourceParent != destParent){
			output[count]=current;
			count++;
			parent[sourceParent]=destParent;
		}
		i++;
	}
	for(int i=0;i<n-1;i++){
		if(output[i].source<output[i].dest){
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;		}
	}
}
int main(){
  int V, E;
  cin >> V >> E;
  Edge * input=new Edge[E];
  for(int i=0;i<E;i++){
  	int s,d,w;
      cin>>s>>d>>w;
  	input[i].source=s;
  	input[i].dest=d;
  	input[i].weight=w;
  }
  Kruskal(input,V,E);
  return 0;
}

