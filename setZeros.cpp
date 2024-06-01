#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}

template<typename T>
void print(vector<T> v){
	cout<<"[ ";
	for(int i=0;i<v.size();i++){
		print(v[i]);
		cout<<" ";
	}
	cout<<"]";
}

void solve(vector<vector<int>>&matrix){

	int n = matrix.size(); 			// no of Rows
	int m = matrix[0].size();		// no of Cols

	vector<int> row(n, 1);
	vector<int> col(m, 1);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i] = 0;
				col[j] = 0;
			}
		}
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(row[i]==0){
				matrix[i][j] = 0;
			}else{
				if(col[j]==0){
					matrix[i][j] = 0;
				}
			}
		}
	}

	return;


}



int main()
{

	vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};

	solve(matrix);

	for(auto it : matrix){
		for(auto it1 : it){
			cout<<it1<<" ";
		}cout<<endl;
	}

	return 0;
}