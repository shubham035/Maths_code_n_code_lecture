#include <bits/stdc++.h>
using namespace std;

// Time complexity : log(M); m is the power we have to calculate
// using binary exponentiation

long long int fermat_little_thm(int a, int m, int mod){

    long long int res=1;
    while(m){
        if(m%2==0){
            a=(a*a)%mod;
            m=m/2;
        }
        else{
            res=(res*a)%mod;
            m--;
        }
    }
    return res;

}

int main() {
    
// FERMAT'S LITTLE THEOREM TO FIND MODULO MULTIPLICATIVE INVERSE
// if a,m are coprime and m is prime then  a inverse (a^-1)is  a^(m-2)%m;
int a,m;
cin>>a>>m;

cout<<" a^-1 =  "<<fermat_little_thm(a, m-2,m)<<endl;

}
