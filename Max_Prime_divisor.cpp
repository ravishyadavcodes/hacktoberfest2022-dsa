#include<bits/stdc++.h>
using namespace std;

int max_prime_divisor(int n){
	int ans=1;
    while(n%2==0){
        ans=2;
        n/=2;
    }
    while(n%3==0){
        ans=3;
        n/=3;
    }
    for(int i=5;i*i<=n;i++){
        while (n % i == 0) {
            ans = i;
            n = n / i;
        }
        while (n % (i+2) == 0) {
            ans = i+2;
            n = n / (i+2);
        }
    }
    if(n>4){
        ans=n;
    }
    return ans;
}

int main(){
	int number;
	cin>>number;

	cout<<max_prime_divisor(number)<<"\n";
}