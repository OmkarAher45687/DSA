#include<iostream>
using namespace std;
class Tbt
{
	int data;
	Tbt *head, *lchild, *rchild, *curr;
	int  lthread, rthread;
	
	public:
		Tbt()
		{
		    lchild=NULL;
			rchild=NULL;
			head = NULL;
		}
		Tbt *create(int A);
		void insert(int);
		
		Tbt *inorder_succ(Tbt*);
		void inorder();
		void preorder();
};


Tbt *Tbt :: create(int A)
{
	Tbt *newnode = new Tbt();
	newnode -> data = A;
	newnode -> lchild = head;
	newnode -> rchild = head;
	newnode -> lthread = 1;
	newnode -> rthread = 1;
	return newnode;
}
	
void Tbt :: insert(int key)
{
	if(head==NULL)
	{
		head=new Tbt();
		head->data=999;
		head->rthread=0;
		head->lthread=1;
	}
	Tbt* curr=head;
	Tbt* newnode=create(key);
	
		if(head -> lthread == 1)
		{
			head -> lchild = newnode;
			head -> lthread = 0;
		}
		else 
		{
			curr = curr -> lchild;
		
			while (1)
			{
				if(key > curr ->data)
				{
					if(curr -> rthread == 1)
					{
					    
						newnode -> rchild = curr -> rchild;
						curr -> rchild = newnode;
						curr ->rthread = 0;
						newnode -> lchild = curr;
						break; 
					}	
					else 
					{
						curr = curr -> rchild;
					}
				}
				else
				{
					if(curr -> lthread == 1)
					{
						newnode -> lchild = curr -> lchild;
						curr -> lchild = newnode;
						curr -> lthread = 0;
					    newnode -> rchild = curr;
						break;				
					}
					else
					{
						curr = curr -> lchild;
					}
				}
			}
		}
}

void Tbt :: inorder()
{
		curr = head -> lchild;
		while(curr -> lthread != 1)
		{
			curr = curr -> lchild;
		}
		cout<<curr -> data;
			
		while(curr -> rchild != head)
		{
			curr = inorder_succ(curr);
			cout<<"\t"<<curr -> data;
		}
	
}

Tbt *Tbt :: inorder_succ(Tbt *curr)
{
	Tbt *temp = curr -> rchild;
	if(curr -> rthread != 1)
	{
		while(temp -> lthread != 1)
		{
			temp = temp -> lchild;
		}
	}
	return temp;
}

void Tbt::preorder()
{
	if(head==NULL)
		cout<<"Tree has no node !!";
	curr=head->lchild;	
	while(curr!=NULL)
	{
		cout<<curr->data<<"\t";
		if(curr->lthread==0)
			curr=curr->lchild;
		else if(curr->rthread==0)	
			curr=curr->rchild;
		else
		{
			while(curr!=NULL && curr->rthread==1)
				curr=curr->rchild;
			if(curr!=NULL)
				curr=curr->rchild;
		}				
	}
}	

int main()
{
	int key;
	Tbt obj;
	int data;
	int i,n;
	string flag;
	do
	{
		cout<<"\n1.Insertion\n2.Inorder traversal\n3.Preorder traversal\n4.Exit\nchoose option from above :";
		cin>>data;
		
		switch(data)
		{
			case 1:
				cout<<"Enter how many element you want to insert in threaded binary tree :";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the element to insert :";
					cin>>key;
					obj.insert(key);
					cout<<"\n";
				}
				break;
			case 2:
				cout<<"The In-Order Traversal is as follows : \n";
				obj.inorder();
				break;
			case 3:
			    cout<<"The Pre-Order Traversal is as follows : \n";	
			    obj.preorder();
			    break;
			case 4:
				cout<<"__FINISHED __";
				exit(0);
				break;
			default:
				cout<<"Invalid input";
		}
		cout<<"\nDo you want to continue ?(y/n)";
		cin>>flag;
	}while(flag == "Y" || flag == "y");
}







/*OUTPUT :-

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :1
Enter how many element you want to insert in threaded binary tree :6
Enter the element to insert :30

Enter the element to insert :25

Enter the element to insert :35

Enter the element to insert :22

Enter the element to insert :28

Enter the element to insert :32


Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :1
Enter how many element you want to insert in threaded binary tree :1
Enter the element to insert :40


Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :2
The In-Order Traversal is as follows : 
22	25	28	30	32	35	40
Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :3
The Pre-Order Traversal is as follows : 
30	25	22	28	35	32	40	
Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :2 1
Enter how many element you want to insert in threaded binary tree :5
Enter the element to insert :27

Enter the element to insert :29

Enter the element to insert :38

Enter the element to insert :42

Enter the element to insert :26


Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :2
The In-Order Traversal is as follows : 
22	25	26	27	28	29	30	32	35	38	40	42
Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :3
The Pre-Order Traversal is as follows : 
30	25	22	28	27	26	29	35	32	40	38	42	
Do you want to continue ?(y/n)y

1.Insertion
2.Inorder traversal
3.Preorder traversal
4.Exit
choose option from above :4
__FINISHED __*/
