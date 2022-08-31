#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
int data;
struct node *next;
}*start=NULL;
void insertlast()
{
int val;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
struct node *ptr;
cout<<"Enter Value :-";
cin>>val;
newnode->data = val;
if(start == NULL)
{
newnode->next = NULL;
start = newnode;
}
else
{
ptr=start;
while(ptr->next!= start)
{
ptr=ptr->next;
}
ptr->next = newnode;
newnode->next = start;
}
}
void deletefirst()
{
if(start == NULL)
cout<<"Underflow";
else
{
struct node *ptr,*preptr,*temp;
ptr = start;
if(ptr ->next == start)
{
free(start);
cout<<"Queue is empty";
return ;
}
else
{
while(ptr->next != start)
{
ptr = ptr->next;
}
temp =start;
start = start->next;
ptr ->next = start;
free(temp);
}
}
}
void display()
{
struct node *ptr;
ptr = start;
cout<<ptr->data<<"->";
ptr = ptr->next;
while(ptr!=start)
{
cout<<ptr->data<<"->";
ptr=ptr->next;
}
cout<<endl;
}
int main()
{
int i;
while(i!=4)
{
cout<<"Enter 1 for insert in Queue"<<endl;
cout<<"Enter 2 for Delete in queue"<<endl;
cout<<"Enter 3 for Display"<<endl;
cout<<"Enter 4 for Exit"<<endl;
cout<<"Enter choice = ";
cin>>i;
switch(i)
{
case 1:
insertlast();
display();
break;
case 2:
deletefirst();
display();
break;
case 3:
display();
break;
case 4:
cout<<"Existing ........";
exit(0);
default :
cout<<"Enter valid Choice";
break;
}
};
return 0;
}

