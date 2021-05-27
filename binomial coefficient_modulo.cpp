#include<bits/stdc++.h>
using namespace std;

long long int F[1000001];

// Binomail coefficient using inverse modulo
// (n, k)=n!/k!*(n-k)!
long long int mod=1e9+7;

long long int inverseM(int a, int m){

    long long int res=1;

    while(m){
        if(m%2==0){
            a=(1ll*a*a)%mod;
            m/=2;
        }    
        else{
            res=(res*1ll*a)%mod;
            m--;
        }
    }

    return res;
}


long long int binomial(int n, int k){

    if(k>n) return 0;

    
    long long int  res=(F[n]* 1ll* inverseM(F[k],mod-2))%mod;

    res=(res*1ll*inverseM(F[n-k], mod-2))%mod;

    return res;
}


int main(){


  //   storing the result of factoroial[i] % mod

    F[0]=F[1]=1;
    for(int i=2;i<=1000000;i++){
        F[i]=(F[i-1]*1ll*i)%mod;
    } 

// t is the number of testcases

int t;
cin>>t;
while(t--){

    int n,k;
    cin>>n>>k;

    cout<<binomial(n,k)<<endl;
}

return 0;
}