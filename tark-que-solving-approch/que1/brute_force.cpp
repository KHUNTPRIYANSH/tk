#include <bits/stdc++.h>
using namespace std;

int Sol(int n, vector<pair<char, int>> vp)
{
    int a = 0;
    long long int tmp = a;
    while (tmp < n)
    {
        tmp = a;
        for (auto it : vp)
        {
            switch (it.first)
            {
            case '+':
                tmp += it.second;
                break;
            case '-':
                tmp -= it.second;
                break;
            case '*':
                tmp *= it.second;
                break;
            case '/':
                tmp /= it.second;
                break;
            case '%':
                tmp %= it.second;
                break;
            case '^':
                tmp = pow(tmp, it.second) + 1;
                break;
            }
        }
        if (tmp == n)
            return a;
        a++;
    }
    return -1;
}

int main()
{
    // vector<string> v{"x + 10", "x - 5", "x * 5", "x ^ 2"};
    // int n = 2500;
    // vector<string> v{"x * 5", "x / 0", "x ^ 3"};
    // int n = 1000;
    // vector<string> v{"x * 5", "x * 0", "x + 10"};
    // int n = 10;
    // vector<string> v{"x + 5", "x - 0", "x + 1","x / 2","x ^ 1"};
    // int n = 617283948;
    auto q1 = find(v.begin(), v.end(), "x / 0");
    auto q2 = find(v.begin(), v.end(), "x * 0");
    auto q3 = find(v.begin(), v.end(), "x ^ 0");

    if (q1 != v.end())
        cout << -1 << endl;
    else if (q2 != v.end())
        cout << -2 << endl;
    else if (q3 != v.end())
        cout << -2 << endl;
    else
    {
        vector<pair<char, int>> vp;
        for (const string &expr : v)
        {
            istringstream iss(expr);
            char op;
            int val;
            string x;
            iss >> x;
            iss >> op;
            iss >> val;

            vp.push_back({op, val});
        }

        cout << Sol(n, vp);
    }
}