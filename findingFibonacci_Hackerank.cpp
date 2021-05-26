#include<bits/stdc++.h>
#define lli long long int
#define INF 1000000000
using namespace std;


const long long int mod=1e9+7;

long long int arr[3];

long long int I[3][3],T[3][3];

void mult(long long int A[3][3],long long int B[3][3], int dim){

    long long int res[dim+1][dim+1];

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){

            res[i][j]=0;

            for(int k=1;k<=dim;k++){
               //  res[i][j]+=A[i][k]*B[k]{j};
               res[i][j]=(res[i][j]%mod +((A[i][k]%mod)*(B[k][j]%mod)%mod))%mod;
            }
        }
    }

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            A[i][j]=res[i][j];
        }
    }

   

}


int getFib(int n){

    if(n<=2) return arr[n];

    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;

    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;

    int power=n-1;

    while(power){

        if(power%2==0){
            mult(T,T,2);
            power/=2;
        }
        else{
           
            mult(I,T,2);
             power--;
        }
    }

   // I matrix contains the result

    lli Fn=(arr[1]*I[1][1] +arr[2]*I[2][1])% mod;

    return Fn;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    arr[0]=0;
    int t, n;
    cin>>t;
    while(t--){
        cin>>arr[1]>>arr[2]>>n;
        n++;

        int ans=getFib( n);
        cout<<ans<<endl;
    }
    return 0;
}