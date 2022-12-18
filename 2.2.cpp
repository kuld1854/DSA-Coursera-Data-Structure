#include <bits/stdc++.h>
using namespace std;
struct th{
     long long int time;
      long long int num;
};
void min_heapify(th arr[], long long int i,  long long int size){
    long long int l = 2*i+1 , r = 2*i+2;
     long long int temp = i;
    if( l<=size  && arr[temp].time>=arr[l].time){
           if(arr[temp].time>arr[l].time || (arr[temp].time==arr[l].time  && arr[temp].num > arr[l].num))
                        temp = l;
    }
    if( r<=size  && arr[temp].time>=arr[r].time){
           if(arr[temp].time>arr[r].time || (arr[temp].time==arr[r].time  && arr[temp].num > arr[r].num))
                        temp = r;
    }
     th t;
   if(temp!=i){
            t = arr[temp];
            arr[temp] = arr[i];
            arr[i] = t;
            min_heapify(arr,temp,size);
   }
}
int main(){
    long long int n,m;
    cin>>n>>m;
    th arr[n];
    long long int job[m];
    for( long long int i=0; i<m; i++){
           cin>>job[i];
    }
    for( long long int i=0; i<n; i++){
             arr[i].num = i;
             arr[i].time = 0;
    }
    for( long long int i=0; i<m; i++){
           cout<<arr[0].num<<" "<<arr[0].time<<"\n";
           arr[0].time+=job[i];
           min_heapify(arr,0,n-1);
    }
    return 0;
}