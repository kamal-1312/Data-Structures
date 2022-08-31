#include <iostream>
#define MAX 5
using namespace std;
struct queue
{
int data;
int priority;
};
struct queue q[MAX];
int front = -1, rear = -1;
void enqueue()
{
if (rear == MAX - 1)
{
cout << "Queue overflow";
}
else
{
struct queue a;
cout << "Enter data:";
cin >> a.data;
cout << "Enter priority:";
cin >> a.priority;
if (front == -1)
{
front = 0;
q[++rear] = a;
}
else
{
int b = ++rear;
for (int i = 0; i <= rear; i++)
{
if (q[i].priority < a.priority)
{
b = i;
break;
}
}
for (int i = rear - 1; i >= b; i--)
{
q[i + 1] = q[i];
}
q[b] = a;
}
}
}
void dequeue()
{
if (front == -1)
{
cout << "\nQueue is underflow\n";
}
else
{
if (front == rear)
{
q[front].data = 0;
front = -1;
rear = -1;
}
else
{
q[front++].data = 0;
}
}
}
void display()
{
cout << "Priority queue\n";
if (front == -1)
{
cout << "\nQueue is empty\n";
return;
}
cout << "priority |data\n";
for (int i = front; i <= rear; i++)
{
cout << q[i].priority << "\t |" << q[i].data << endl;
}
}
int main()
{ 
while (1)
{
int i;
cout << "\n1 for Insert:" << endl;
cout << "2 for Delete:" << endl;
cout << "3 for exit:" << endl;
cout << "Enter your choice:";
cin >> i;
switch(i)
{
case 1:
enqueue();
display();
break;
case 2:
dequeue();
display();
break;
case 3:
exit(0);
break;
default:
cout<<"Enter valid choice";
break;
}
}
return 0;
}

