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


bool dfs(int start, int prev, vector<int> adjList[], vector<int> &vis){

	cout<<start<<" ";

	vis[start] = 1;

	for(auto it : adjList[start]){
		if(it!=prev && vis[it]) return true;
		else if(!vis[it]){
			return dfs(it, start, adjList, vis);
		}
	}

	return false;

}


bool bfs(int start, vector<int> adjList[], vector<int> &vis){

	queue<pair<int, int>>q;
	vis[start] = 1;
	q.push({start, -1});

	while(!q.empty()){

		int x = q.front().first;
		int prev = q.front().second;
		q.pop();


		for(auto it : adjList[x]){
			if(vis[it] && it!=prev) return true;
			else if(!vis[it]){
				vis[it] = 1;
				q.push({it, x});
			}
		}

	}

	return false;

}





bool isCycle(int n, vector<int> adjList[]){
    vector<int>vis(n, 0);
    for(int i=0;i<n;i++){
	 if(!vis[i]){
	      if(dfs(i, -1, adjList, vis)) return true;
	 }
	   
    }
    return false;

	// vector<int>vis(n, 0);
	// for(int i=0;i<n;i++){
	// 	if(!vis[i]){
	// 		if(bfs(i, adjList, vis)) return true;
	// 	}
	// }

	// return false;


}




int main()
{
	// int n = 5;
	// int m = 5;
	// vector<int>adjList[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};

	int n, m;
	cin>>n>>m;
	vector<int> adjList[n+1];

	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}




	bool ans = isCycle(n, adjList);
	deb(ans);

	return 0;
}