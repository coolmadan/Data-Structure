#include<iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    int *S;
};
void create1(struct stack *st,int size)
{
    st->size=size;
    st->top=-1;
    st->S=(int *)malloc(size*sizeof(int));
}
void create2(struct stack *stack2,int size)
{
    stack2->size=size;
    stack2->top=-1;
    stack2->S=(int *)malloc(size*sizeof(int));
}
void push1(struct stack *st,int x)
{   if(st->top==st->size-1)
    cout<<"Stack is full"<<endl;
    else
    {   st->top++;
    st->S[st->top]=x;
    }

}
void push2(struct stack *stack2,int x)
{
    if(stack2->top==stack2->size)
        cout<<"Queue is Full"<<endl;
    else{
        stack2->top++;
        stack2->S[stack2->top]=x;
    }
}
int pop1(struct stack *st)
{   int x=-1;
    if(st->top==-1)
    cout<<"Stack is empty"<<endl;
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}
int pop2(struct stack *stack2)
{
    int x=-1;
    if(stack2->top==-1)
    cout<<"Queue is empty"<<endl;
    else{
        x=stack2->S[stack2->top];
        stack2->top--;
    }
    return x;
}
void display(struct stack st)
{

}
int main()
{
    struct stack st,stack2;
    create1(&st,5);
}
/*
#include <iostream>
#include <stack>

using namespace std;
 
class Queue{
private:
    stack<int> e_stk;
    stack<int> d_stk;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
 
void Queue::enqueue(int x) {
    e_stk.push(x);
}
 
int Queue::dequeue() {
    int x = -1;
    if (d_stk.empty()){
        if (e_stk.empty()){
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!e_stk.empty()){
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    d_stk.pop();
    return x;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    cout << "Enqueue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << q.dequeue() << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
 
    return 0;
}*/