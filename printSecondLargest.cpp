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

int solve(int arr[], int n){

// there are somany things to consider 

//  u can simply sort and return arr[n-2]
//  this logic will only work in case of unique elements

	// for example 
	// 2,3,3,4,5,5,6,6,6,7,7

	// what to return if, these is no second higest ? 
	// example : 1,1,1,1,1,1,1

	// intialize the secondlargest properly
	// don't just use secondLargest = nums[0], 
	// nums[0] can be the firstHighesh as well.

	int first = arr[0];
	int second = INT_MIN;

	for(int i=0;i<n;i++){

		if(first < arr[i]){
			second = first;
			first = arr[i];
		}
		else if( second < arr[i] && arr[i]<first){
			// arr[i]<first is also imp {It might be equal to first}
			second = arr[i];
		}


	}

	return second;

}



int main()
{

	int arr[] = {61 ,30 ,28 ,47 ,42 ,25 ,41 ,56 ,27 ,45 ,44 ,34 ,46 ,35 ,58 ,36 ,60 ,29 ,53 ,55 ,32 ,31 ,33 ,59 ,50 ,51 ,52 ,37 ,39 ,38 ,43 ,49 ,54 ,57 ,40 ,26 ,48};
	int n = sizeof(arr)/sizeof(arr[0]);

	deb(n);

	int ans = solve(arr, n);
	deb(ans);




	return 0;
}