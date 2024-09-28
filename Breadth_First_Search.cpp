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
		}
		cout<<"}"<<endl;
	}

}


vector<int> BFS(int start, vector<vector<int>> &adjList){

	vector<int> bfs;
	int n = adjList.size();
	vector<int> vis(n, 0);

	queue<int>q;
	vis[start] = 1;
	q.push(start);

	while(!q.empty()){
		int x = q.front();
		q.pop();

		bfs.push_back(x);
		for(auto it : adjList[x]){
			if(!vis[it]){
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	// deb(vis);

	return bfs;

}

int cloudyDays(int start, vector<vector<int>> &adjList, int cost){

	vector<int> bfs;
	int n = adjList.size();
	vector<int> vis(n, 0);
	int ans = 0;

	queue<int>q;
	vis[start] = 1;
	q.push(start);
	ans++;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		bfs.push_back(x);


		if(cost==0){
			break;
		}


		for(auto it : adjList[x]){
			if(!vis[it]){
				vis[it] = 1;
				ans++;
				q.push(it);
			}
		}

		cost--;

	}
	// deb(vis);

deb(cost);
	return ans;

}



int main()
{

	int n, m,cost, start;
	cin>>n>>m>>cost>>start;

	// Assuming 0-based indexing graph.
	vector<vector<int>> adjList(n+1); 

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	printAdjList(adjList);

	// vector<int> bfs = BFS(1, adjList);
	// deb(bfs);


	int ans = cloudyDays(start, adjList, cost);
	deb(ans);





	return 0;
}