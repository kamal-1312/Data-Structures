#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
int data;
struct node *next;
struct node *prev;
}*start=NULL;
void insertfirst()
{
int val;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
cout<<"Enter Value :-";
cin>>val;
newnode->data = val;
if(start == NULL)
{
newnode->prev = NULL;
newnode->next = NULL;
start = newnode;
}
else
{
newnode -> prev = NULL;
newnode->data = val;
newnode ->next = start;
start = newnode;
cout<<"node inserted"<<endl;
}
}
void insertlast()
{
int val;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
struct node *ptr;
cout<<"Enter Value :-";
cin>>val;
newnode->data = val;
newnode->next = NULL;
if(start == NULL)
{
newnode->next = NULL;
start = newnode;
}
else
{
ptr=start;
while(ptr->next != NULL)
{
ptr=ptr->next;
}
ptr->next = newnode;
newnode -> prev = ptr;
}
}
void insertafter()
{
int key,val,flag=1;
struct node *ptr;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
cout<<"Enter Key =";
cin>>key;
ptr=start;
while(ptr->data!=key)
{
ptr= ptr->next;
if(ptr == NULL)
{
cout<<"Entered value not found"<<endl;
flag = 0;
break;
}
}
if(flag == 1)
{
cout<<"Enter value = ";
cin>>val;
newnode ->prev = ptr; 
newnode->data= val;
newnode->next = ptr->next;
ptr->next = newnode;
}
}
void insertbefore()
{
int key,val,flag=1;
struct node *ptr,*preptr;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
cout<<"Enter Key =";
cin>>key;
ptr=start;
while(ptr->data!=key)
{
preptr = ptr;
ptr= ptr->next;
if(ptr == NULL)
{
cout<<"Entered value not found"<<endl;
flag = 0;
break;
}
}
if(flag == 1)
{
cout<<"Enter value = ";
cin>>val;
newnode -> prev = preptr;
newnode->data= val;
newnode->next = preptr->next;
preptr->next = newnode;
}
}
void deletefirst()
{
if(start == NULL)
cout<<"Underflow";
else
{
struct node *ptr;
ptr = start;
start = start->next;
start -> prev = NULL;
free(ptr);
}
}
void deletelast()
{
if(start == NULL)
cout<<"Underflow";
else
{
struct node *ptr,*preptr;
ptr = start;
while(ptr->next!=NULL)
{
preptr = ptr;
ptr = ptr->next;
}
preptr->next = NULL;
free(ptr);
}
}
void deletespecific()
{
int key;
struct node *ptr,*preptr,*temp;
cout<<"Enter Key = ";
cin>>key;
if(start == NULL)
cout<<"Underflow";
else
{
struct node *ptr,*preptr;
ptr = start;
while(ptr->data!=key)
{
preptr = ptr;
ptr = ptr->next;
if(ptr == NULL)
{
cout<<"Not Found";
break;
}
}
preptr -> next = ptr->next;
ptr ->prev = preptr;
free(ptr);
}
}
void display()
{
struct node *ptr;
ptr = start;
while(ptr!=NULL)
{
cout<<"|"<<ptr->data<<"|"<<"->";
ptr=ptr->next;
}
cout<<endl;
}
int main()
{
int i;
while(i!=9)
{
cout<<"Enter 1 for insert first"<<endl;
cout<<"Enter 2 for insert last"<<endl;
cout<<"Enter 3 for insert before"<<endl;
cout<<"Enter 4 for insert after"<<endl;
cout<<"Enter 5 for delete first"<<endl;
cout<<"Enter 6 for delete last"<<endl;
cout<<"Enter 7 for delete specific"<<endl;
cout<<"Enter 8 for Display"<<endl;
cout<<"Enter 9 for Exit"<<endl;
cout<<"Enter choice = ";
cin>>i;
switch(i)
{
case 1:
insertfirst();
display();
break;
case 2:
insertlast();
display();
break;
case 3:
insertbefore();
display();
break;
case 4:
insertafter();
display();
break;
case 5:
deletefirst();
display();
break;
case 6:
deletelast();
display();
break;
case 7:
deletespecific();
display();
break;
case 8:
display();
break;
case 9:
cout<<"Existing ........";
exit(0);
default :
cout<<"Enter valid Choice";
break;
}
};
return 0;
}

