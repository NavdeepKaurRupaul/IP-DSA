#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int**edges,int* distance, bool* visited, int n,int source){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || distance[minVertex] > distance[i]){
			minVertex = i;
		}
	}
	return minVertex;
}


void Dijkstra(int** edges, int n){
	int* distance = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		visited[i] = false;
		distance[i] = INT_MAX;
	}
	distance[0] = 0;

	for(int i = 0; i < n - 1; i++){
		// Find Min Vertex
		int minVertex = findMinVertex(edges,distance, visited, n,i);
		visited[minVertex] = true;
		// Explore un visted neighbours
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				int currentDistance=distance[minVertex]+edges[minVertex][j];
				if(currentDistance < distance[j]){
					distance[j]=currentDistance;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout<<i<<" "<<distance[i]<<endl;
	}
}
int main(){
    int n;
	int e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	Dijkstra(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
  return 0;
}

