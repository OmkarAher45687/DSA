#include <iostream>

using namespace std;

class Queue
{
	int rear;
	int front;

	public:
		void qisfull( int n);
	    	void enqueue(int [], int n);
	    	void qisempty(int n);
		void dequeue(int [], int n);
		void display(int [], int n);
		
		Queue()
		{
			rear=front=-1;
		}
};

void Queue :: qisfull(int n)
{
	if(front==(rear+1)%n)
	{
		cout<<"Queue is full,no space!!\n";
	}
}
void Queue :: enqueue(int q[], int n)
{
	int item;
	int flag=0;
	
	if (front==-1)
	{
		front=0;
	}		
	rear=(rear+1)%n;
	cout<<"Enter the item to be add :";
	cin>>item;
	q[rear]=item;
	qisfull(n);
}

void Queue :: qisempty(int n)
{
	if (front==-1)
	{
		cout<<"Queue is empty!!\n";
	}
}

void Queue :: dequeue(int q[],int n)
{
	 if(front==rear)
	{
		
		front=rear=-1;
	}
	else
	{
		cout<<"Deleting element: "<<q[front]<<"\n";
		front=(front+1)%n;
	}
	qisempty(n);
}

void Queue :: display(int q [],int n)
{
    int i;
     for (i=front; i!=rear; i=(i+1)%n)
        {
            cout<<q[i]<<"\t";
        }
        cout<<q[i]<<"\n"; 
}
	
int main()
{
	int n;
	string flag;
	cout<<"Enter the size of Q that you want :\t ";
	cin>>n;
	int q[n];
	Queue q1;
	
	int data;
	char cont;
	int a;
	do
	{	
	    cout<<"\n";
		cout<<"1.Insert an element in Q \n"<<"2.Delete an element from Q\n"<<"3.Display the Q\n"<<"Enter your choice from above options :";
		
		cin>>data;
		
		switch(data)
		{
			case 1:
			    q1.enqueue(q,n);
				break;
				
			case 2:
				q1.dequeue(q,n);
				break;
				
			case 3:
			    q1.display(q,n);
				break;
				
			default:
			    cout<<"Invalid input";
		}
		cout<<"Do you want to continue?(Y/n): ";
		cin>>flag;
	}while(flag=="Y"||flag=="y");
	return 0;
}


/*OUTPUT :-



Enter the size of Q that you want :	 5

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :10
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :20
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :30
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :40
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :50
Queue is full,no space!!
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :3
10	20	30	40	50
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 10
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 20
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :3
30	40	50
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :10
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :1
Enter the item to be add :20
Queue is full,no space!!
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :3
30	40	50	10	20
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 30
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 40
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 50
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Deleting element: 10
Do you want to continue?(Y/n): y

1.Insert an element in Q 
2.Delete an element from Q
3.Display the Q
Enter your choice from above options :2
Queue is empty!!
Do you want to continue?(Y/n): n
  */
