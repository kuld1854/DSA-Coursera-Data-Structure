#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int maxi = 0,n;
     string str;
      stack<int> st;
    while(t--){
       cin>>str;
       if(str[1]=='u'){
            cin>>n;
             maxi = max(maxi,n);
             st.push(maxi);}
         else  if(str[1]=='o')
                 st.pop();
            else 
                 cout<<st.top()<<endl;
              
    }
    return 0;
}