#include<iostream>
using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}
void EnQueue(struct Queue *q, int x)
{
    if(q->rear==q->size-1)
        cout<<"Queue is full";
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int Dequeue(struct Queue *q)
{   int x=-1;
    if(q->front==q->rear)
        cout<<"Queue is empty";
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    for(int i=0;i<q.size;i++)
    cout<<q.Q[i]<<endl;
}
int main()
{
    struct Queue q;
    create(&q,5);
    EnQueue(&q,1);
    EnQueue(&q,2);
    EnQueue(&q,3);
    EnQueue(&q,4);
    EnQueue(&q,5);
    Display(q);
    return 0;
}