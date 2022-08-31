using namespace std;
#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
}*root=NULL;
void preorder(struct node *root)
{
if(root!=NULL)
{
cout<<endl<<root->data<<"->";
preorder(root->left);
preorder(root->right);
}
}
void postorder(struct node *root)
{
if(root!=NULL)
{
 postorder(root->left);
 postorder(root->right);
 cout<<endl<<root->data<<"->";
}
}
void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left);
cout<<endl<<root->data<<"->";
inorder(root->right);
}
}
struct node * max(struct node *ptr)
{
if(ptr==NULL || ptr->right==NULL)
{
 return ptr;
}
else
return max(ptr->right);
}
struct node * min(struct node *ptr)
{
if(ptr==NULL || ptr->left==NULL)
{
 return ptr;
}
else
return min(ptr->left);
}
void findele(struct node *ptr,int val)
{
if(ptr==NULL)
{
cout<<endl<<"Element does not exist in given tree";
return;
}
if(ptr->data==val)
{
cout<<endl<<ptr->data<<" is found";
return;
}
else if(val > ptr->data)
return findele(ptr->right,val);
else 
return findele(ptr->left,val);
}
void insert(int val)
{
struct node *new1,*curr,*prev;
new1=(struct node *)malloc(sizeof(struct node));
new1->data=val;
new1->left=NULL;
new1->right=NULL;
if(root==NULL)
{
 root=new1;
 return ;
}
curr=root;
while(curr!=NULL)
{
 prev=curr;
 if(val > curr->data )
curr=curr->right;
 else
curr=curr->left;
}
if(val > prev->data)
prev->right=new1;
else
prev->left=new1;
cout<<endl;
}
int main()
{
struct node *ptr;
int i,val;
while(i!=8)
{
cout<<endl<<"1. Insert";
cout<<endl<<"2. Inorder";
cout<<endl<<"3. Preorder";
cout<<endl<<"4. Postorder";
cout<<endl<<"5. Max";
cout<<endl<<"6. Min";
cout<<endl<<"7. Find element";
cout<<endl<<"8. Exit";
cout<<endl<<"Enter your choice:";
cin>>i;
switch(i)
{
case 1:
cout<<"Enter value:";
cin>>val;
cout<<endl;
insert(val);
break;
case 2:
inorder(root);
cout<<endl;
break;
case 3:
preorder(root);
cout<<endl;
break;
case 4:
postorder(root);
cout<<endl;
break;
case 5:
ptr = max(root);
cout<<"->"<<ptr->data;
cout<<endl;
break;
case 6:
ptr = root;
ptr = min(ptr);
cout<<ptr->data;
cout<<endl;
break;
case 7:
cout<<"Enter key";
cin>>val;
findele(root,val);
cout<<endl;
break;
case 8:
exit(0);
break;
default:
cout<<"Enter Valid Choice"<<endl;
break;
}
}
return 0;
}




