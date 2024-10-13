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

void checkCoordinates(){

    vector<string>dxy = {"-1", "+0", "+1"};


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            string nr = "r" + dxy[i];
            string nc = "c" + dxy[j];

            cout<<"( "<<nr<<" , "<<nc<<" ) ";
        }cout<<endl;
    }
}



int solve(int r, int c, int n, vector<vector<int>>&dp , 
    vector<vector<int>> &mat, vector<vector<int>> &vis){

    //base condition
    if(r==n-1 && c==n-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];

    vis[r][c] = 1;


    int dxy[] = {-1, 0, 1};


    int ans = 1e9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int nr = r + dxy[i];
            int nc = c + dxy[j];

            // cout<<"(r : "<<r<<" c : "<<c<<" )(nr : "<<nr<<" nc : "<<nc<<" )"<<" ans : "<<ans<<endl;


            // if(nr==r && nc==c) continue;

            if(nr>=0 && nr<n && nc>=0 && nc<n && mat[nr][nc]==0 && !vis[nr][nc]){

                // cout<<"(r : "<<r<<" c : "<<c<<" )(nr : "<<nr<<" nc : "<<nc<<" )"<<endl;
                // vis[r][c] = 1;
                mat[r][c] = 1;
                ans = min(ans, solve(nr, nc, n, dp, mat, vis));
                mat[r][c] = 0;
                // vis[r][c] = 0;
                // cout<<"(r : "<<r<<" c : "<<c<<" )(nr : "<<nr<<" nc : "<<nc<<" )"<<" ans : "<<ans<<endl;
            }
        }
    } 

    vis[r][c] =0;

    return dp[r][c] = ans + 1;



}



int main()
{

    vector<vector<int>> mat = {
        {0,0,1,0,1,1},
        {1,0,0,1,0,0},
        {0,1,0,1,0,0},
        {1,0,1,0,0,0},
        {0,1,0,1,0,0},
        {0,0,0,0,0,0}};



    // vector<vector<int>> mat = {
    //     {0,1,0,0},
    //     {1,0,0,0},
    //     {0,1,0,0},
    //     {0,0,0,0}};


        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        vector<vector<int>>vis(n, vector<int>(n, 0));
        int ans = -1;
        
        if(mat[0][0] || mat[n-1][n-1]){
            deb(ans);
        }
        else{
            ans = solve(0, 0, n, dp, mat, vis);
            deb(ans);
        }


        for(auto it : dp){
            deb(it);
        }

        // check();



    return 0;
}