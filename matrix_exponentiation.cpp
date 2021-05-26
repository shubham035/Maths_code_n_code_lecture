#include<bits/stdc++.h>
using namespace std;

#define N 101

// MPOW SPOJ ...

const long long int mod=1e9+7;
long long int arr[N][N], I[N][N];

void mult(long long int A[][N] , long long int B[][N] , int dim){

    long long int res[dim+1][dim+1];

// matrix multiplication code 
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){

            res[i][j]=0;
            for(int k=1;k<=dim;k++){
                res[i][j]= (res[i][j]%mod+((A[i][k]%mod)*(B[k][j]%mod))%mod)%mod;
                
            }
        }
    }

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            A[i][j]=res[i][j];
        }
    }


}

void __power(long long int A[][N] , int dim , int n){

// making the identity matrix

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }
    
    /*
    TIME COMPLEXITY : O(DIM^3 * n) WHICH IS NAIVE APPROACH
    for(int i=1;i<=n;i++){
        // I=I*A; matrix multiplication doesn't work like this

        mult(I , A , dim);
        // I=A*I
    }
     WE CAN USE BINARY EXPONENTION LIKE METHOD HERE TO REDUCE THE TIME COMPLEXITY TO O(dim^3 * LOG(N)) WHICH IS MUCH BETTER

    */
    while(n){
        if(n%2==0){

            mult(A,A, dim);
            n=n/2;
        }
        else{
            mult(I , A , dim);
            n--;
        }
    }
    // result is inside I

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            A[i][j]=I[i][j];
        }
    }

}
    

void __print( long long int A[][N] , int dim){

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
           cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int t;
    cin>>t;
    while(t--){
        
        int dim , n;
        cin>>dim>>n;
        
        
        
        for(int i=1;i<=dim;i++){
            for(int j=1;j<=dim;j++){
                cin>>arr[i][j];
            }
        }
        
        __power(arr, dim, n);
        __print(arr, dim);
    }
    return 0;
}