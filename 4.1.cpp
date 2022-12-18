#include <bits/stdc++.h>
#define fr(l) for(int i=0; i<l; i++)
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
void inorder(node *temp){
    if(temp == NULL)
               return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
void preorder(node *temp){
    if(temp == NULL)
               return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(node *temp){
    if(temp == NULL)
               return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
int main(){
    int n;
    cin>>n;
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
     inorder(root);
     cout<<endl;
     preorder(root);
     cout<<endl;
     postorder(root);
     cout<<endl;

}
