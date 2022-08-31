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
cout<<"Enter 1 for insert in Queue"<<endl;
cout<<"Enter 2 for delete last"<<endl;
cout<<"Enter 3 for display "<<endl;
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
