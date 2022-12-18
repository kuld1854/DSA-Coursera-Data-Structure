#include <bits/stdc++.h>
#define fr(l) for(int i=0; i<l; i++)
#define ll long long
using namespace std;
struct node
{ 
     int data;
     node* left;
     node* right;
     node(){
          data = 0;
          left = NULL;
          right = NULL;
     }
};
bool inorder(node *temp,vector<long long int> &res,ll l,ll h){
    if(temp == NULL)
               return true;
     if( temp->data < l || temp->data >= h )
               return false;
   return inorder(temp->left,res,l,temp->data) &&  inorder(temp->right,res,temp->data,h);
}
int main(){
    int n;
    cin>>n;
    if(n==0){
           cout<<"CORRECT"<<endl;
           return 0;
    }
    int arr[n][3];
    fr(n){
         cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    queue<int> index;
    queue<node*> level;
    index.push(arr[0][1]);
    index.push(arr[0][2]);
    node* root  = new node();
    root->data = arr[0][0];
    level.push(root);
    int in;
    while(!level.empty()){
          node* temp = level.front();
          if(index.front()!=-1){
                   in =  index.front();
                   node* t = new node();
                   t->data = arr[in][0];
                   temp->left = t;
                   level.push(t);
                    index.push(arr[in][1]);
                    index.push(arr[in][2]);
              }
              index.pop();
           if(index.front()!=-1){
                   in =  index.front();
                   node* t = new node();
                    t->data = arr[in][0];
                   temp->right = t;
                    level.push(t);
                    index.push(arr[in][1]);
                    index.push(arr[in][2]);
              }
              index.pop();
              level.pop();
        }
     long long l = INT64_MIN;
     long long h = INT64_MAX;
     vector<long long int> res;
     if(inorder(root,res,l,h))
            cout<<"CORRECT"<<endl;
     else 
            cout<<"INCORRECT"<<endl;
     
    

}
