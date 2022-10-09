#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int max = INT_MIN;
    int sum = 0;
     for(int i=0;i<n;i++){
        sum+=arr[i];
        if(max<=sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
     }
     cout<<max<<"\n";
    return 0;
}
