#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}
template<typename T, typename V> void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }
template<typename T> void print(vector<T> v){ cout<<"[ "; for(auto it : v){ print(it); cout<<" "; } cout<<"]"; }
template<typename T> void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }
template<typename K, typename V> void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename K, typename V> void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename T> void print(stack<T> st){ cout<<"[ "; while(!st.empty()){ print(st.top());cout<<" "; st.pop(); } cout<<"]"; }


/*

Topological sort: 

Linear ordering of the vertices(nodes) in such a way, that if
there exist an edge between u and v, 
then u must be appearing before v in that ordering

Note : It is only applicable for Directed Acyclic Graphs [DAG]

	Not applicable for Undirected Graphs
	Not applicable for Cyclic Graphs


	Topological sort in bfs --> Kahn's Algo

*/


void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adjList){

	vis[node] = 1;

	for(auto it : adjList[node]){
		if(!vis[it]) dfs(it, st, vis, adjList);
	}

	st.push(node);
	return;
}


// Kahn's Algorithm
void bfs(int node, vector<int> &vis, vector<vector<int>>&adjList, vector<int> &indegree, 
		vector<int> &ans){

	queue<int>q;
	
	for(int i=0;i<indegree.size();i++){
		if(indegree[i]==0 && !vis[i]){
			q.push(i);
			vis[i] =1;
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);

		for(auto it : adjList[node]){
			indegree[it]--;

			if(indegree[it]==0){
				vis[it]=1;
				q.push(it);
			}
		}

	}

	return;

}


void printAdjList(vector<vector<int>> &adjList){

	int n = adjList.size();
	for(int i=0;i<n;i++){
		cout<<i<<" ->{ ";
		for(auto it : adjList[i]){
			cout<<it<<" ";
		}cout<<"}"<<endl;
	}

}



int main()
{


	int n, m;
	cin>>n>>m;

	vector<vector<int>> adjList(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		// adjList[v].push_back(u);
	}


/*
	6 6
	1 3
	2 3
	4 1
	4 0
	5 0
	5 2

	printAdjList(adjList);
	
	0 ->{ }
	1 ->{ 3 }
	2 ->{ 3 }
	3 ->{ }
	4 ->{ 1 0 }
	5 ->{ 0 2 }

*/

/*
	DFS Way

	vector<int>vis(n, 0);
	stack<int>st;

	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i, st, vis, adjList);
		}
	}


	// deb(st);

	vector<int>ans;
	while(!st.empty()){
		int x = st.top();
		st.pop();

		ans.push_back(x);
	}

	for(auto it : ans){
		cout<<it<<" ";
	}cout<<endl;
*/


	vector<int>vis(n, 0);

	vector<int>indegree(n, 0);

	for(int i=0;i<n;i++){
		for(auto it : adjList[i]){
			indegree[it]++;
		}
	}
	vector<int>ans;

	for(int i=0;i<n;i++){
		if(!vis[i]){
			bfs(i, vis, adjList, indegree, ans);
		}
	}

	deb(ans);


	return 0;
}