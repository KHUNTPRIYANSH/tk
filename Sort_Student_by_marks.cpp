#include <bits/stdc++.h>
using namespace std;

void Sol()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // write from here
}

int main()
{
    vector<string> names = {"Mahesh", "Suresh", "Ramesh"};
    vector<int> marks = {70, 90, 80};
    vector<pair<int, string>> list;
    for (int i = 0; i < names.size(); i++)
    {
        list.push_back({marks[i], names[i]});
    }
    sort(list.begin(), list.end());
    reverse(list.begin(), list.end());
    for (auto it : list)
    {
        cout << it.first << " " << it.second << endl;
    }
    Sol();
    return 0;
}