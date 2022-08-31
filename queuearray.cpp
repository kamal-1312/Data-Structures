using namespace std;
#include<iostream>
#define SIZE 5
int queue[SIZE],front=-1,rear=-1;
void push(int val)
{
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
rear ++;
queue [front]=val;
}
}
void pop()
{
if(front == -1)
cout<<"Underflow";
else if(front == rear)
{
cout<<"value poped";
front++;
}
}
void peek()
{
for (int i = front;i<=rear;i++)
cout<<"--"<<queue[i];
}
int main()
{
int i,val;
while(i != 4)
{
cout<<endl<<"Enter 1 For Push";
cout<<endl<<"Enter 2 For Pop";
cout<<endl<<"Enter 3 For Peek";
cout<<endl<<"Enter 4 For Exit";
cout<<endl<<"Enter Choice = ";
cin>>i;
switch(i)
{
case 1:
if(rear>=SIZE-1)
{
cout<<"Overflow";
}
else
{
cout<<"Enter Number = ";
cin>>val;
push(val);
}
peek();
break;
case 2 :
pop();
peek();
break;
case 3:
peek();
break;
case 4:
cout<<"Existing ........";
exit(0);
default:
cout<<"Enter Valid Choice";
break;
}
};
}


