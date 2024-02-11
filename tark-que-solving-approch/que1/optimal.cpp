#include <bits/stdc++.h>
using namespace std;

int guessNumber(int n, vector<pair<char, int>> input_arr)
{
    double original_number = n;
    for (auto input_pair : input_arr)
    {
        switch (input_pair.first)
        {
        case '+':
            original_number -= input_pair.second;
            break;
        case '-':
            original_number += input_pair.second;
            break;
        case '*':
            original_number /= input_pair.second;
            break;
        case '/':
            original_number *= input_pair.second;
            break;
        case '^':
            if (input_pair.second == 0 && original_number != 0)
                return -2; // Multiple answers
            original_number = pow(original_number, 1.0 / input_pair.second);
            break;
        case '%':
            if (input_pair.second == 0)
                return -1;
            original_number *= input_pair.second;
            break;
        }
    }
    return original_number;
}

int main()
{
    // uncomment following inputs to test the whole code
    vector<string> v{"x + 10", "x - 5", "x * 5", "x ^ 2"};
    int n = 2500;
    // vector<string> v{"x * 5", "x / 0", "x ^ 3"};
    // int n = 1000;
    // vector<string> v{"x * 5", "x * 0", "x + 10"};
    // int n = 10;
    // vector<string> v{"x + 5", "x - 0", "x + 1", "x / 2", "x ^ 1"};
    // int n = 617283948;

    reverse(v.begin(), v.end());
    auto q1 = find(v.begin(), v.end(), "x / 0");
    auto q2 = find(v.begin(), v.end(), "x * 0");
    auto q3 = find(v.begin(), v.end(), "x ^ 0");

    if (q1 != v.end())
    {
        // handing "x / 0"
        cout << -1 << endl;
    }
    else if (q2 != v.end())
    {
        // handing "x * 0"
        cout << -2 << endl;
    }
    else if (q3 != v.end())
    {
        // handing "x ^ 0"
        cout << -2 << endl;
    }
    else
    {
        vector<pair<char, int>> input;
        for (const string &expr : v)
        {
            istringstream iss(expr);
            // breaking whole string into 3 parts
            // 1.x
            string x;
            iss >> x;
            // 2.operator
            char op;
            iss >> op;
            // 3.operand
            int val;
            iss >> val;
            // string operator and operand into input array
            input.push_back({op, val});
        }
        cout << guessNumber(n, input);
    }
}