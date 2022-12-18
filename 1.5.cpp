#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
         cin>>arr[i];
   cin>>k;
    deque<int> de;
  if(k!=1)
    de.push_front(0);
    for(int i=1; i<k-1; i++){
       while( !de.empty() && arr[de.front()]<arr[i])
               de.pop_front();
        de.push_front(i);
     }
    for(int i= k-1; i<n; i++){
        while(!de.empty() && arr[de.front()]<arr[i])
               de.pop_front();
        de.push_front(i);
      cout<<arr[de.back()]<<" ";
       if(i-de.back()==k-1)
          de.pop_back();
 }
}