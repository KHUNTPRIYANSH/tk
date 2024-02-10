#include <bits/stdc++.h>
using namespace std;

void Sol(int n , vector<string> v)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string> s;
    for(int i = 0 ;i< n ; i++){
        sort(v[i].begin(),v[i].end());
        s.insert(v[i]);
    }
    cout<<v.size()-s.size();
}

int main()
{
    //1.
    // vector<string> v = {"cat","act","dog","god"};
    //2.
    vector<string> v = {"abc","bca","cde"};

    Sol(v.size() , v);
    return 0;
}