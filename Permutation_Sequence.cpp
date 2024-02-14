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

int fact(int n ){
	int ans = 1;

	for(int i=1;i<=n;i++){
		ans *=i;
	}
	return ans;
}

void permutationSequence(int n, int k, string &seq, string &temp){

		if(k==1){
			temp+=seq;
			return;
		}

		int x = fact(n-1); // group length...

		int ind = k/x;

		int newK = k%x;

		if(newK==0){
			newK = ((k-1)%x) + 1;
			ind = (k-1)/x;
		}

		temp += seq[ind];

		string newString = seq.substr(0, ind) + seq.substr(ind+1);

		permutationSequence(n-1, newK, newString, temp);

}



int main()
{
	int n = 4;
	int k = 9;

	string seq = "";

	for(int i=1;i<=n;i++){
		string x = to_string(i);
		seq += x;
	}

	string temp = "";

	cout<<seq<<endl;
	permutationSequence(n, k, seq, temp);

	cout<<"ans : "<<temp<<endl;

	return 0;
}