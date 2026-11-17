#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct queue{
int rear,front;
int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item)
{
  if(q->rear==SIZE -1)
    printf("\n queue is full");
else
   {q->rear=q->rear+1;
    q->data[q->rear]=item;
    if(q->front==-1)
      q->front=0;
   }
}
void dequeue(QUEUE *q)
{if(q->front==-1)
  printf("queue is empty");
else
{
printf("the element deleted is %d:",q->data[q->front]);
if(q->front==q->rear)
{q->front=-1;
q->rear=-1;
}
else
q->front=q->front+1;
}
}
void display(QUEUE q)
{
  int i;
if (q.front==-1)
{
printf("\n queue is empty");
else
{for(i=q.front,i<=q.rear,i+=)
  printf("%d \t",q.data[i]);
  }
}
}


