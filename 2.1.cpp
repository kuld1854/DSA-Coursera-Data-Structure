#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int l, int r){
       int temp = arr[l];
       arr[l] = arr[r];
       arr[r] = temp;
    
}
void min_heapify(int arr[],int i,int size,vector<int> &res){
      int left,right,temp;
      left = 2*i+1;
      right = 2*i+2;
      temp =  i;
      if( left<size && arr[left] < arr[temp] )
               temp = left;
      if( right<size && arr[right] < arr[temp] )
               temp = right;
      if(i!=temp){
              swap(arr,temp,i);
              res.push_back(i);
              res.push_back(temp);
              min_heapify(arr,temp,size,res);
      }        
}
void build_heap(int arr[], int size, vector<int> &res){
   for(int i = floor(size/2) ; i>=0 ; i--){
         min_heapify(arr,i,size,res);
   }
}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++)
        cin>>arr[i];
        vector<int> res;
    build_heap(arr,n,res);
    cout<<res.size()/2<<endl;
    for(auto i= res.begin() ; i<res.end() ; i+=2)
           cout<<*i<<" "<<*(i+1)<<endl;
          

}