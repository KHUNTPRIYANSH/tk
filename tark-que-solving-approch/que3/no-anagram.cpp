#include <bits/stdc++.h>

using namespace std;

string sortString(const string& str) {
    string sortedStr = str; 
    sort(sortedStr.begin(), sortedStr.end()); 
    return sortedStr;
}

int countAnagramPairs(vector<string>& strings) {
    map<string, int> frequency;
    for (const string& str : strings) {
        string sortedStr = sortString(str);
        frequency[sortedStr]++;
    }
    int pairs = 0;
    for (const auto& it : frequency) {
        int count = it.second;
        pairs += count * (count - 1) / 2;
    }
    return pairs;
}

int main() {
    vector<string> strings = {"abcd", "dcab", "bacd", "dabc", "abcd"};
    cout << "Number of anagram pairs: " << countAnagramPairs(strings) << endl;
    return 0;
}
