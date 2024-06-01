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


int solve(string &s){


	int n = s.size();
	if(n==0) return 0;


	// we will trim the left space and right spaces

	int i=0;
	int start_ind = -1;
	int end_ind = -1;


	while(i<n){
		if(s[i]!=' '){
			start_ind = i;
			break;
		}
		i++;
	}

	i = n-1;
	while(i>=0){
		if(s[i]!=' '){
			end_ind = i;
			break;
		}
		i--;
	}

	// deb(start_ind);
	// deb(end_ind);

	string str = s;

	if(start_ind > 0 || end_ind >0){
	int len = end_ind - start_ind + 1;
	 str = s.substr(start_ind, len);

	deb(str);


	n = str.size();
}

	bool neg = (str[0]=='-') ? true : false;


	i = (str[0]=='-' || str[0]=='+') ? 1 : 0;

	long long ans = 0;
	// int stop = -1;

	while(i<n){

		if( str[i]=='0' || str[i]=='1' || str[i]=='2' ||
				 str[i]=='3' || str[i]=='4' || str[i]=='5' || 
				 str[i]=='6' || str[i]=='7' || str[i]=='8' || 
				 str[i]=='9'){
			int x = str[i]-'0';
			ans = (ans * 10 ) + x;
		}
		else{
			break;
		}

		i++;

	}



	ans =  neg ? -ans : ans ;

	deb(ans);

    if(ans > INT_MAX) ans = INT_MAX;
    else if(ans <INT_MIN) ans = INT_MIN;

    return ans;
}




int main()
{
	// string s = "               1337c0d3                 ";
	// string s = "4193 with words";
	string s = "     ";
	int ans = solve(s);
	deb(ans);

	return 0;
}