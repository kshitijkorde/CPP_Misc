//http://www.spoj.com/problems/CAM5/
#include<bits/stdc++.h>

using namespace std;

void DFS(int src, list<int> * adjList, bool * visited){

	visited[src] = true;
	list<int> :: iterator itr;
	//for(itr = adjList[src].begin(); itr != adjList[src].end(); ++itr){ 
	// Range Based Loop Below for C++ 11
	for(auto i : adjList[src]){
		//if(!visited[*itr]){
			//DFS(*itr, adjList, visited);
		//}
		if(!visited[i]){
			DFS(i, adjList, visited);
		}
	}
}

int main(){

	int tcs, num, conn;
	list<int> *adjList;
	bool * visited; 


	cin >> tcs;

	while(tcs--){

		int cnt = 0;
		cin >> num;
		cin >> conn;

		visited = new bool[num];
		adjList = new list<int>[num];

		memset(visited, false, sizeof(bool)*num);

		for(int i=0; i<conn; i++){
			int a, b;
			cin >> a >> b;
			adjList[a].push_back(b);	
			adjList[b].push_back(a);
		}

		for(int i=0; i<num; i++){
			if(!visited[i]){
				cnt++;
				DFS(i, adjList, visited);
			}
		}
		cout << cnt << endl;
		delete [] adjList;
	}
	return 0;
}
