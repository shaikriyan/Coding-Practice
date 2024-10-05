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



// Not applicable for the negative loops (TLE)
// Not applicable for the negative weights (TLE) 0 -- 1 with weight of -2


void bfs(int srcNode, vector<int>&dist, vector<vector<pair<int,int>>>&adjList){


	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, srcNode});
	dist[srcNode] = 0;

	while(!pq.empty()){

		int dis = pq.top().first;

		int node = pq.top().second;
		pq.pop();

		for(auto it : adjList[node]){
			int n = it.first;
			int wt = it.second;

			if(dis + wt < dist[n]){
				dist[n] = dis + wt;
				pq.push({dist[n], n});
			}
		}
	}
	
	return;
}




int main()
{

	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adjList(n);

// Undirected weighted Graph

	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adjList[u].push_back({v, wt});
		adjList[v].push_back({u, wt});
	}


	// for(auto it : adjList){
	// 	for(auto it1 : it){
	// 		deb(it1);
	// 	// 	int node = it1.first;
	// 	// 	int wt = it1.second;
	// 	// 	deb(node);
	// 	// 	deb(wt);
	// 	}
	// }


	int src = 0;

	vector<int> dist(n, 1e9);

	bfs(src, dist, adjList);

	// for(auto it : dist){
	// 	cout<<it<<" ";
	// }cout<<endl;

	deb(dist);


	return 0;
}