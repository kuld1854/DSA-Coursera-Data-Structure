#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define m  1000000007
#define x  263
ll cons(int len){
      ll con = 1;
      for(int i=0; i<len; i++){
            con = con*x%m;
      }
      return con%m;
}
ll poly_hash(string str, int len, int i){
    ll fact  = 1;
    ll hash = 0,k = 0;
    while(k<len){
             hash += ((ll)str[i]*fact);
             // cout<<(int)str[i]<<" "<<fact<<"  "<<str[i]<<endl;
             k++;
             i++;
             hash%=m;
             fact = fact*x%m;
             
             
    }
    return hash;
}
ll rec_hash(string &p, ll hash , int i , int len, int con){
    return   ((x*hash + (ll)p[i] -  con*(ll)p[i+len])%m+m)%m;
}
bool are_equal(string &p, string &t, int i, int len ){
    for(int k=0; k<len; k++){
          if(p[i+k] != t[k])
                 return false;
    }
    return true;
}
int main(){
     string p,t;
     cin>>t>>p;
     ll con = cons(t.length());
     int p_len  = p.length(),t_len = t.length();
     ll t_hash , hash;
     t_hash = poly_hash(t,t_len,0);
     vector<int> ans;
     hash = poly_hash(p,t_len,p_len - t_len);
     bool first = false;
     for(int i=p_len-t_len; i>=0; i--){
          if(first)
          hash = rec_hash(p,hash,i,t_len,con);
          if(t_hash == hash){
                  if(are_equal(p, t ,i,t_len))
                          ans.push_back(i);
          }
          first = true;
         
     }
                                        // empty function use to remove empty vector error
        for( auto it = ans.end()-1 ; !ans.empty() && it>=ans.begin(); it--)
               cout<<*it<<" ";
               cout<<endl;
    
         
}