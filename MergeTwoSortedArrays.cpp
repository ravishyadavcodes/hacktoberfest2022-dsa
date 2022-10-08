#include <bits/stdc++.h>
using namespace std;
void mergeArrays(int a[], int b[], int n, int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    for (int i = 0; i < m; i++)
        mp[b[i]]++;
    for (auto j : mp)
    {
        for (int i = 0; i < j.second; i++)
            cout << j.first << " ";
    }
}

int main()
{
    int m, n;
    cout << "Enter size of first array :" << endl;
    cin >> m;
    cout << "Enter size of second array :" << endl;
    cin >> n;
    int a[m];
    int b[n];
    cout << "Enter the input for the 1st array :-" << endl;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "Enter the input for the second array :-" << endl;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    mergeArrays(a, b, m, n);

    return 0;
}
