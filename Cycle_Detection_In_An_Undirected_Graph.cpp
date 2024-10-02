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


bool bfs(int node, int vis[], vector<vector<int>> &adjList){

	queue<pair<int,int>>q;
	vis[node] = 1;
	q.push({node, -1});

	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for(auto it : adjList[node]){
			if(it!=parent && vis[it]) return true;
			else{
				if(!vis[it]){
					vis[it] = 1;
					q.push({it, node});
				}
			}
		}

	}
	return false;
}




bool dfs(int node, int parent, int vis[], vector<vector<int>>&adjList){

	vis[node] =1;

	for(auto it : adjList[node]){

		if(vis[it]==1 && it!=parent) return true;
		else{
			if(!vis[it]){
			 if(dfs(it, node, vis, adjList)) return true;
			}
		}
	}

	return false;

}



int main()
{

	int n,m;
	cin>>n>>m;

	vector<vector<int>>adjList(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}


	int vis[n] = {0};
	// vector<int> vis(n, 0);
	bool isCyclicGraph = false;

	// for(int i=0;i<n;i++){
	// 	if(!vis[i]){
	// 		if(dfs(i, -1,  vis, adjList)){
	// 			cout<<"Cycle detected in Graph"<<endl;
	// 			isCyclicGraph = true;
	// 			break;	
	// 		} 
	// 	}
	// }

	// if(!isCyclicGraph){
	// 	cout<<"No cycle detected in Graph"<<endl;
	// }



	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(bfs(i, vis, adjList)){
				cout<<"Cycle detected in Graph"<<endl;
				isCyclicGraph = true;
				break;	
			} 
		}
	}

	if(!isCyclicGraph){
		cout<<"No cycle detected in Graph"<<endl;
	}



	return 0;
}