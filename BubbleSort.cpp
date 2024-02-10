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

void bubbleSort(vector<int>&v){

	int n = v.size();

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(v[j]>v[j+1]) swap(v[j], v[j+1]);
		}
	}

	return;

}


int main()
{

	// vector<int>v = {5,4,1,3,2};
	vector<int>v = {0, 23,234, -123, 534,34,245,34,664,74,56,4};
	
	int n = v.size();

	bubbleSort(v);

	for(auto it : v){
		cout<<it<<" ";
	}cout<<endl;

	

	return 0;
}