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

class DisjointSet{
/*
	DisjointSets mainly has two functionalities {findUPar, union}
	union can be done in two ways {unionBySize, unionByRank}

	Time Complexity of both the methods is gonna be (4 Alpha) 
	with is as good as Constant Time Complexity

	findUPar means find Ultimate Parent

*/


public: 
	int n;
	vector<int>parent;
	vector<int>size;
	vector<int>rank;

	DisjointSet(int _n){
		// cout<<"Disjointset constr called..."<<endl;
		n = _n;
		parent.resize(n+1); // This will work for both 0-based & 1-based indexing
		size.resize(n+1);
		rank.resize(n+1, 1);

		for(int i=0;i<n+1;i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findUPar(int node){
		
		// logarthim time.
		// if(parent[node]) return node;
		// return findUPar(parent[node]);
		
		// with path Compression
		if(parent[node]==node) return node;
		return findUPar(parent[node]);
	}

	void unionBySize(int u, int v){

		int pu = findUPar(u);
		int pv = findUPar(v);

		if(pu!=pv){

		// Then we decide to join the u and v based on size of there parent

			if(size[pu] > size[pv]){
				parent[pv] = pu;
				size[pu] += size[pv];
			}
			else if(size[pu] < size[pv]){
				parent[pu] = pv;
				size[pv] += size[pu];
			}
			else{
				// size[pu] == size[pv];
				parent[pu] = pv;
				size[pv] += size[pu];	
			}

		}
	}

	void unionByRank(int u, int v){

		int pu = findUPar(u);
		int pv = findUPar(v);

		if(pu!=pv){

			// On the Basis of the rank , we join the u & v;

			if(rank[pu] > rank[pv]){
				parent[pv] = pu;
			}
			else if(rank[pu] < rank[pv]){
				parent[pu] = pv;
			}
			else {
				// rank[pu] == rank[pv];
				// u can either join (pu to pv) or (pv to pu)
				// parent[pu] = pv; 
				parent[pv] = pu;
				rank[pu]++; 
			}
		}
	}


};


/*class DisjointSet{

public : 
	int n;
	vector<int> par, size;

	DisjointSet(int _n){
		n = _n;
		par.resize(n+1);
		size.resize(n+1, 1);
		for(int i=0;i<n+1;i++) par[i] =i;
	}

	int findUPar(int node){
		if(par[node]==node) return node;
		return par[node] = findUPar(par[node]);
	}

	void unionBySize(int u, int v){
		int pu = findUPar(u);
		int pv = findUPar(v);

		if(pu!=pv){
			if(size[pu] > size[pv]){
				par[pv] = pu;
				size[pu] += size[pv];	
			}
			else{
				par[pu] = pv;
				size[pv] += size[pu];
			}
		}
	}

};*/




int solve(vector<vector<int>> &grid){

	// since it a n*n matrix ; just considering only n
	int n = grid.size();


	DisjointSet dsu(n*n);

	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};

	for(int r=0;r<n;r++){
		for(int c=0;c<n;c++){

			if(grid[r][c]==1){
				int u = (r * n) + c;

				for(int k=0;k<4;k++){
					int nr = r + dr[k];
					int nc = c + dc[k];

					if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
						int v = (nr * n) + nc;
						if(dsu.findUPar(v)!=dsu.findUPar(u)){
							// cout<<"r : "<<r<<" c : "<<c<<" nr : "<<nr<<" nc : "<<nc<<" u : "<<u<<" v : "<<v<<endl;
							dsu.unionBySize(u, v);
						}
					}
				}
			}
		}
	}

	// for(int r=0;r<n;r++){
	// 	for(int c=0;c<n;c++){
	// 		// cout<<dsu.size[(r * n) + c ]<<" ";
	// 		// cout<<dsu.parent[(r * n) + c ]<<" ";
	// 	}cout<<endl;
	// }

	int ans = INT_MIN;

	for(int r=0;r<n;r++){
		for(int c=0;c<n;c++){

			if(grid[r][c]==0){

				int tempAns = 1;
				unordered_map<int, bool>umap;
				for(int k=0;k<4;k++){
					int nr = r + dr[k];
					int nc = c + dc[k];

					if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
						int v = (nr * n) + nc;
						int pv = dsu.findUPar(v);
	// cout<<"r : "<<r<<" c : "<<c<<" nr : "<<nr<<" nc : "<<nc<<" v : "<<v<<" pv : "<<pv<<endl;

						// deb(pv);

						if(umap.find(pv)==umap.end()){
							
							tempAns += dsu.size[pv];
							// cout<<"tempAns : "<<tempAns<<endl;
							umap[pv] = true;
						}

					}
				}
				if(tempAns > ans){
					cout<<"r : "<<r<<" c : "<<c<<" tempAns : "<<tempAns<<endl;
				}
				ans = max(ans, tempAns);
			}
		}
	}

	return ans;


}





int main()
{
	vector<vector<int>>grid = {
		{0, 0, 1, 1, 0}, 
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0},
	 	{1, 1, 1, 0, 1},
	  	{0, 1, 0, 1, 1}
	  };


	  int ans = solve(grid);
	  deb(ans);

	return 0;
}