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


void printAdjList(vector<vector<int>> &adjList){

	for(int i=0;i<adjList.size();i++){
		cout<<i<<" --> { ";
		for(auto it : adjList[i]){
			cout<<it<<", ";
		}cout<<"} "<<endl;
	}
}

void DFS(int start, vector<vector<int>> &adjList, vector<int>&vis, vector<int>&dfs){

	vis[start] = 1;
	dfs.push_back(start);

	for(auto it : adjList[start]){
		if(!vis[it]){
			DFS(it, adjList, vis, dfs);
		}
	}

	return;

}



int main()
{

	int n,m;
	cin>>n>>m;

	vector<vector<int>>adjList(n+1);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	printAdjList(adjList);


	vector<int> vis(n+1, 0);
	vector<int> dfs;
	int start = 1;


	for(int i=start;i<n+1;i++){
		if(!vis[i]){
			DFS(i, adjList, vis, dfs);
		}
	}

	deb(dfs);


	return 0;
}