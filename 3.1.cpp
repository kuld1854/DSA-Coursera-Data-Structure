#include <bits/stdc++.h>
using namespace std;
struct node{
      node* left;
      int phone;
      string name;
      node*right;
      node(string name , int phone){
            left = NULL;
            right= NULL;
            this->name = name;
            this->phone = phone;
      }
};
class phone_mana{
       private:
            node** arr;
            int p = 10000019;
            int m;
         public:
            phone_mana(int m){
                   arr = new node*[m];
                   for(int i=0; i<m; i++){
                        arr[i] = NULL;
                   }
                   this->m = m;
            }
            void add(int phone , string name);
            void del(int phone);
            string find(int phone);
            int hash_fun(int phone){
                   return  ((7*phone+3)%p)%m;
            }
           
};
void phone_mana::add(int phone , string name){
       int i= hash_fun(phone);
       node *temp = *(arr+i);
      node *n = new node(name,phone);
          //cout<<"add: "<<i<<" "<<name<<" "<<temp<<endl;
        if(temp == NULL){
            arr[i] = n;
             //n->left = *(arr+i);
             return;
        }
         if(temp->phone == n->phone){
                 temp->name = n->name;
                 return;
         }
        while( temp->right ){
                  if(temp->phone == phone){
                           temp->name = name;
                           return;
                  } 
                  temp = temp->right;
        }
        temp->right = n;
        n->left = temp;
        
        return;  
}
string phone_mana::find(int phone){
      int i = hash_fun(phone);
      node * temp = arr[i];
      while(temp){
              if(temp->phone == phone){
                       return temp->name;
              }
               temp =temp->right;
      } 
      return "not found";
}
void phone_mana::del(int phone){
    int i = hash_fun(phone);
    node* temp = arr[i] ;
    node* dele;
    node* p;
     //cout<<temp->phone<<endl;
    if(temp && temp->phone == phone){
            arr[i] = NULL;
            return;
    }
    //cout<<"del"<<endl;
    while(temp){
            if(temp->phone == phone){
                    dele = temp;
                    p = temp->left;
                    temp = temp->right;
                    if(p)
                    p->right =  temp;
                    if(temp){
                          temp->left = p;
                    }
                  //  cout<<"del "<<dele->name<<endl;
                   delete dele;
                   return;
            }
            temp = temp->right;
    }
}
int main(){
    int n,m,phone;
    cin>>n;
     m = (2*n)/3;
    phone_mana* ph = new phone_mana(m);
    string str , name;

    for(int i=0; i<n; i++){
        // cout<<"kya bat"<<endl;
           cin>>str>>phone;
           if(str == "add"){
                  cin>>name;
                  ph->add(phone,name);
           }
           else if(str == "find")
                     cout<<ph->find(phone)<<endl;
              else 
                      ph->del(phone);
            }
      return 0;
}