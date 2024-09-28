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


void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis){

	int n = grid.size();
	int m = grid[0].size();

	vis[r][c] = 1;

	// Top, Right, Down, Left format

	int row = [-1, 0, 1, 0];
	int col = [0, 1, 0, -1];

	for(int i=0;i<4;i++){
		int dr = r + row[i];
		int dc = c + col[i];

		if(dr>=0 && dr<n && dc>=0 && dc<m && !vis[dr][dc] && grid[dr][dc]=='1'){
			dfs(dr, dc, grid, vis);
		}

	}

	return;

}



int numIslands(vector<vector<char>> &grid){


	int islands = 0;
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>>vis(n, vector<int>(m, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='1' && !vis[i][j]){
				dfs(i,j,grid, vis);
				islands++;
			}
		}
	}

	return islands;
}




int main()
{

	vector<vector<int>> grid = {
		  {"1","1","1","1","0"},
		  {"1","1","0","1","0"},
		  {"1","1","0","0","0"},
		  {"0","0","0","0","0"}
	}

	int ans = numIslands(grid);
	deb(ans);


	return 0;
}