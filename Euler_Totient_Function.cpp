#include<bits/stdc++.h>
#define long long int lli
using namespace std;

// Novice approach nlog(n) time complexity



int phi_novice(int N){

    int cnt=0;
    for(int i=1;i<=N;i++){
        if(__gcd(i,N)==1) cnt++;
    }

    return cnt;
}

/*
prime and totient function

    phi(p)=p-1;
    for all values of P is prime 

    phi(p^x)=?
     
     multiplicative function
     
     f(n*m)=f(n)*f(m);
      if gcd(n,m)=1;

      Euler totient function is multiplicative

      d[n]=divisor count of N

      d[n]=d[p^x]=(x1+1)*(x2+1).....*(xk+1);

    
*/

// TIME COMPLEXITY : O(sqrt(n);


int phi_1(int n){

    int res=n;

    for(int i=2;i<=sqrt(n);i++){

        if(n%i==0){
            res=res/i;
            res=res*(i-1);

            while(n%i==0){
                n=n/i;
            }
        }
    }
    
    if(n>1){
        res/=n;
        res*=(n-1);
    }
    return res;

}
// calulating ETF ie. phi(n) for 1 to n
// if use phi_1 method then it is O(nsqrt(n)) time which is expensive 

//  calculating Euler Totient function in(nloglog(n))

int ETF[1000001];

void ETF_sieve(int n){

    for(int i=1;i<=1000000;i++){
        ETF[i]=i;
    }

    for(int i=2;i<=1000000;i++){

        if(ETF[i]==i){
            for(int u=i;u<=1000000;u+=i){
                ETF[u]/=i;
                ETF[u]*=(i-1); 
            }
        }
    }

}


int main(){


    int t,n;
    cin>>t;

      ETF_sieve(n);

    while(t--){

        cin>>n;
       //  cout<<phi_1(n)<<endl;

       cout<<ETF[n]<<endl;

      
    }

    return 0;
     
}