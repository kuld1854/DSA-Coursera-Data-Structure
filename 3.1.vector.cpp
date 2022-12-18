#include <bits/stdc++.h>
using namespace std;
class phone_mana{
       private:
            int p = 100000009;
            int m =  100001;
             vector<pair<int,string>> arr[100001];
         public:
            void add(int phone , string name);
            void del(int phone);
            string find(int phone);
            int hash_fun(int phone){
                   int a = ((31*phone+13)%p)%m;
                   return a;
            }
           
};
void phone_mana::add(int phone , string name){
       int i= hash_fun(phone);
       auto it = arr[i].begin();
        while(it!=arr[i].end()){
                  if((*it).first == phone){
                         (*it).second = name;
                         return;
                  }
        }
       pair<int , string> temp;
       temp.first = phone;
       temp.second = name;
       arr[i].push_back(temp);
}
string phone_mana::find(int phone){
      int i = hash_fun(phone);
       auto it = arr[i].begin();
        while(it!=arr[i].end()){
                  if((*it).first == phone){
                        return  (*it).second;
                  }
        }
        return "not found";
     
}
void phone_mana::del(int phone){
    int i = hash_fun(phone);
    auto it = arr[i].begin();
        while(it!=arr[i].end()){
                  if((*it).first == phone){
                            arr[i].erase(it);
                  }
        }
    
}
int main(){
 int n,m,phone;
    cin>>n;
    // m = (2*n)/3;
    phone_mana ph;
    string str , name;

    for(int i=0; i<n; i++){
        // cout<<"kya bat"<<endl;
           cin>>str>>phone;
           if(str == "add"){
                  cin>>name;
                  ph.add(phone,name);
           }
           else if(str == "find")
                     cout<<ph.find(phone)<<endl;
              else 
                      ph.del(phone);
            }
      return 0;
}