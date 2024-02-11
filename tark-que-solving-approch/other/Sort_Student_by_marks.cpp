#include <bits/stdc++.h>
using namespace std;

// input
vector<string> names = {"Mahesh", "Suresh", "Ramesh"};
vector<int> marks = {70, 90, 80};

int main()
{
    vector<pair<int, string>> list;

    for (int i = 0; i < names.size(); i++)
    {
        list.push_back({marks[i], names[i]});
    }

    sort(list.begin(), list.end());
    // 70 Mahesh, 80 Ramesh, 90 Suresh
    reverse(list.begin(), list.end());
    // 90 Suresh, 80 Ramesh, 70 Mahesh

    // printing output
    for (auto it : list)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}