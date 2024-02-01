#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node (int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int length(Node *head)
{
    int count=0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
Node *merging(Node * head1,Node *head2)
{
    if(head1==NULL)
        return head1;
    if(head2==NULL)
        return head2;
    Node *newhead=NULL,*newTail=NULL;
    if(head1->data<head2->data)
    {
        newhead=head1;
        newTail=head1;
        head1=head1->next;
    }
    else
    {
        newhead=head2;
        newTail=head2;
        head2=head2->next;
    }
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            newTail->next=head1;
            head1=head1->next;
            newTail=newTail->next;
        }
        else
        {
            newTail->next=head2;
            head2=head2->next;
            newTail=newTail->next;
        }
    }
    if(head1!=NULL)
        newTail->next=head1;
    if(head2!=NULL)
        newTail->next=head2;
    return newhead;
}
Node *mergeSort(Node *head)
{
	//Write your code here
    int len=length(head);
    int mid=(len-1)/2;
	Node *head1=head;
    Node *head2=head;
    
    for(int i=0;i<mid;i++)
    {
        head2=head2->next;
    }
    head2=head2->next;
    head1=mergeSort(head1);
    head2=mergeSort(head2);
   Node *finalhead= merging(head1,head2);
    return finalhead;
    
    
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}