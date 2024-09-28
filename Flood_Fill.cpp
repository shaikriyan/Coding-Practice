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


void dfs(int r, int c, int start, int color, vector<vector<int>>&image, vector<vector<int>> &ans
	, vector<vector<int>> &vis){

	int n = image.size();
	int m = image[0].size();

	ans[r][c] = color;
	vis[r][c] = 1;

	int row[] = {-1, 0, 1, 0};
	int col[] = {0, 1, 0, -1};

	for(int i=0;i<4;i++){
		int dr = r + row[i];
		int dc = c + col[i];

		if(dr>=0 && dr<n && dc>=0 && dc<m && image[dr][dc]==start && !vis[dr][dc]){
			dfs(dr, dc, start, color, image, ans, vis);
		}

	}


	return;


}




int main()
{

	vector<vector<int>> image = {
		{1,1,1},{1,1,0},{1,0,1}
	};

	int sr = 1;
	int sc = 1;
	int color = 2;

	int n = image.size();
	int m = image[0].size();

	vector<vector<int>>ans(image);
	vector<vector<int>>vis(n, vector<int>(m, 0));

	dfs(sr, sc, image[sr][sc], color, image, ans, vis);

	for(auto it : ans){
		deb(it);
	}


	return 0;
}