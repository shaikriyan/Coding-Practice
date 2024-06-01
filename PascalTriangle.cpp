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

vector<vector<int>> solve(int n){


	vector<vector<int>>ans;

	vector<int> first = {1};
	vector<int> second = {1, 1};

	if(n==1) ans.push_back(first);
	else if(n==2) {
		ans.push_back(first);
		ans.push_back(second);
	}
	else if(n>3){

		ans.push_back(first);
		ans.push_back(second);

		for(int i=3;i<n+1;i++){

			vector<int> last = ans[ans.size()-1];

			vector<int> temp;
			temp.push_back(1);

			for(int j=1;j<last.size();j++){
				temp.push_back(last[j] + last[j-1]);
			}

			temp.push_back(1);
			ans.push_back(temp);
		}

	}


	return ans;

}




int main()
{

	int n = 2;

	vector<vector<int>>ans = solve(n);

	for(auto it : ans){
		for(auto it1 : it){
			cout<<it1<<" ";
		}cout<<endl;
	}

	return 0;
}