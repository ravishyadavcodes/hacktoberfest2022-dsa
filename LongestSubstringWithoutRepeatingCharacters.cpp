#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string s)
{

    map<char, int> seen;
    int max_length = 0;
    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (seen.find(s[i]) != seen.end())
            start = max(start, seen[s[i]] + 1);

        seen[s[i]] = i;
        max_length = max(max_length,
                         i - start + 1);
    }
    return max_length;
}

int main()
{
    string s;
    cout << "Enter a String :-" << endl;
    cin >> s;
    int length = longestUniqueSubstring(s);

    cout << "The length of the longest non-repeating character of the substring is :- " << length;
}
