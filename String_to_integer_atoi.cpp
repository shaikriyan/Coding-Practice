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

long long myAtoi(long long ind, long long n, string& s, long long& ans) {

    if (ans >= INT_MAX)
        return ans;

    if (ind == n || (s[ind] < '0' && s[ind] > '9'))
        return ans;

    if (s[ind] >= '0' && s[ind] <= '9') {
        ans = ans * 10 + (s[ind] - '0');
        ans = myAtoi(ind + 1, n, s, ans);
    }
    return ans;
}

long long solve(string& s) {

    long long n = s.size();
    long long i = 0;
    while (i < n) {
        if (s[i] != ' ')
            break;
        i++;
    }

    bool isNeg = false;
    isNeg = (s[i] == '-') ? true : false;

    if (s[i] == '-' || s[i] == '+')
        i++;
    long long sol = 0;

    long long ans = myAtoi(i, n, s, sol);
    ans = (isNeg) ? -ans : ans;

    if (ans <= INT_MIN)
        return INT_MIN;
    if (ans >= INT_MAX)
        return INT_MAX;

    return ans;
}


int main()
{

	string s = "1337c0d3";

	int ans = solve(s);
	deb(ans);


	return 0;
}