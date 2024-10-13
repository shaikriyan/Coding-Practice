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


class DisJointSetPair{
public:
	int n;
	vector<vector<pair<int,int>>>par;
	vector<vector<int>> size;
	DisJointSetPair(int _n, vector<vector<int>> &grid){
		n = _n;
		par.resize(n+1, vector<pair<int,int>>(n+1));
		size.resize(n+1, vector<int>(n+1, 1));


		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				par[i][j] = {i,j};
				size[i][j] = grid[i][j];
			}
		}
	}

	void unionBySize(pair<int,int> p1, pair<int,int> p2){

		auto pp1 = findUPar(p1);
		auto pp2 = findUPar(p2);

		int r1 = pp1.first;
		int c1 = pp1.second;

		int r2 = pp2.first;
		int c2 = pp2.second;

		if(r1!=r2 || c1!=c2){
			if(size[r1][c1] < size[r2][c2]){
			par[r1][c1] = {r2, c2};
			size[r2][c2] += size[r1][c1]; 
			}
			else{
				par[r2][c2] = {r1, c1};
				size[r1][c1] += size[r2][c2]; 
			}
		}



	}

	pair<int,int> findUPar(pair<int,int> pr){
		int r1 = pr.first;
		int c1 = pr.second;

		auto pr2  = par[r1][c1];
		if(pr2.first == r1 && pr2.second == c1) return {r1, c1};

		return findUPar(pr2);
	}



};














class DisjointSet{
/*
	DisjointSets mainly has two functionalities {findUPar, union}
	union can be done in two ways {unionBySize, unionByRank}

	Time Complexity of both the methods is gonna be (4 Alpha) 
	with is as good as Constant Time Complexity

	findUPar means find Ultimate Parent

*/

private:
	int n;
	vector<int>parent;
	vector<int>size;
	vector<int>rank;

public: 
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
		return parent[node] = findUPar(parent[node]);
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





int main()
{
/*

	// At a time, use either unionBySize or unionByRank

	DisjointSet disJointSet(7);

	disJointSet.unionBySize(1, 2);
	disJointSet.unionBySize(2, 3);
	disJointSet.unionBySize(4, 5);
	disJointSet.unionBySize(6, 7);
	disJointSet.unionBySize(5, 6);

	if(disJointSet.findUPar(7) == disJointSet.findUPar(3))
		cout<<"Same Component"<<endl;
	else
		cout<<"Different Component"<<endl;

	disJointSet.unionBySize(3, 4);


	if(disJointSet.findUPar(7) == disJointSet.findUPar(3))
		cout<<"Same Component"<<endl;
	else
		cout<<"Different Component"<<endl;

*/

/*
	// Union By Rank

	DisjointSet dsu(7);

	dsu.unionBySize(1, 2);
	dsu.unionBySize(2, 3);
	dsu.unionBySize(4, 5);
	dsu.unionBySize(6, 7);
	dsu.unionBySize(5, 6);

	if(dsu.findUPar(7) == dsu.findUPar(3))
		cout<<"Same Component"<<endl;
	else
		cout<<"Different Component"<<endl;


	dsu.unionByRank(3, 4);

	if(dsu.findUPar(7) == dsu.findUPar(3))
		cout<<"Same Component"<<endl;
	else
		cout<<"Different Component"<<endl;

*/

	vector<vector<int>>grid = {{0, 0, 1, 1, 0}, {1,0,1,0,1}, {1,0,0,1,0},
	 {1,1,1,0,1}, {0,1,0,1,1}};

	DisJointSetPair dsp(4, grid);

	// dsp.unionBySize(0,2);
	// dsp.unionBySize(0,3);
	// dsp.unionBySize(1,0);
	// dsp.unionBySize(1,2);
	// dsp.unionBySize(1,4);

	// dsp.unionBySize(2,0);
	// dsp.unionBySize(2,3);
	// dsp.unionBySize(3,0);
	// dsp.unionBySize(3,1);
	// dsp.unionBySize(3,2);

	// dsp.unionBySize(3,4);
	// dsp.unionBySize(4,1);
	// dsp.unionBySize(4,3);
	// dsp.unionBySize(4,4);

	dsp.unionBySize({0,2}, {0,3});
	dsp.unionBySize({0,2}, {1,2});

	dsp.unionBySize({1,4}, {1,4});
	
	dsp.unionBySize({2,3}, {2,3});

	dsp.unionBySize({1,0}, {2,0});
	dsp.unionBySize({2,0}, {3,0});
	dsp.unionBySize({3,0}, {3,1});
	dsp.unionBySize({3,1}, {3,2});
	dsp.unionBySize({3,1}, {4,1});

	dsp.unionBySize({3,4}, {4,4});
	dsp.unionBySize({4,3}, {4,4});


	if(dsp.findUPar({1,2})==dsp.findUPar({0,3}))
		cout<<"Same Comp"<<endl;
	else
		cout<<"Diff Comp"<<endl;


	if(dsp.findUPar({1,2})==dsp.findUPar({4,4}))
		cout<<"Same Comp"<<endl;
	else
		cout<<"Diff Comp"<<endl;



	for(auto it : dsp.par){
		deb(it);
	}

	

	for(auto it : dsp.size){
		deb(it);
	}





	return 0;
}