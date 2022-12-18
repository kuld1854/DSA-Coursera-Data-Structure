#include <bits/stdc++.h>
using namespace std;
int find(int brr[],int i){
      if(brr[i]!=i)
            brr[i] =  find(brr,brr[i]);
    return brr[i];
}
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n],brr[n];
    for(int i=0; i<n; i++)
     {  cin>>arr[i];
         brr[i] = i;
     }
     int x,y;
     int maxi =0;
     for(int i=0; i<n; i++)
          maxi = max(arr[i],maxi);
     for(int i=0; i<q; i++){
           cin>>x>>y;
           x = find(brr,x-1);
           y = find(brr,y-1);
           if(x!=y){
                  arr[x]+=arr[y];
                  arr[y] = 0;
                  brr[y] = x;
                  maxi = max(arr[x],maxi);
                
           }
           cout<<maxi<<"\n";

     }
}