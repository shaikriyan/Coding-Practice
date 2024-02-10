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


void solve(vector<int>&v){

	int n = v.size();

	for(int i=1;i<n;i++){
		int temp = v[i];
		int j = i-1;

		while(j>=0){
			if(v[j]>temp){
				v[j+1] = v[j];
			}
			else{
				break;
			}
			j--;
		}
		v[j+1] = temp;

	}
	return;
}


int main()
{
	// vector<int> v = {5,4,1,3,2};
	vector<int>v = {0, 23,234, -123, 534,34,245,34,664,74,56,4};
	
	int n = v.size();

	solve(v);

	for(auto it : v){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}