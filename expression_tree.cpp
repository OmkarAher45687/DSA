#include<iostream>
using namespace std;

class tree
{
	char data;
	
	public:
	   	int flag;
		tree *result;
		tree *lchild,*rchild;
		
		tree* create(char);
		tree* construct(char[]);
		
		void preorder(tree*);
		void inorder(tree*);
		void postorder(tree*);
		
        		void recursive_preorder(tree*);
       		void recursive_inorder(tree*);
        		void recursive_postorder(tree*);

        
};

class stack 
{
	public:
	    
	    	tree *root;
    		stack *top;
    		stack *next;
    	
		stack()
		{
			top=NULL;
		}
		void push(tree*);
		tree* pop();
		
};

tree *tree :: create(char A)
{
	tree *newnode = new tree();
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	newnode->data=A;
	return newnode;
}

void stack::push(tree *C)
{
	stack *newnode=new stack;
    newnode-> root=C;
	newnode-> next=top;
	top=newnode;
}

tree * stack::pop()
{
	stack *ptr;
	ptr=top;
	top=top->next;
	ptr->next=NULL;
	return ptr->root;
}

tree* tree::construct(char postfix[])
{
	tree * result;
	stack stck;
	int i=0;
	while(postfix[i]!='\0')
	{
		if(isalnum(postfix[i]))
		{
			stck.push(create(postfix[i]));				
		}
		else
		{
			tree *a,*b,*c;
			a=create(postfix[i]);
			b=stck.pop();
			c=stck.pop();
			a->rchild=b;
			a->lchild=c;
			stck.push(a);
		}
		i++;
	}
	result=stck.pop();
	return result;
}

void tree::preorder(tree *curr)
{
    stack stck;
    while(1)
    {
        while(curr!=NULL)
        {
            cout<<curr->data;
            if(curr->rchild)
            {
                stck.push(curr->rchild);
            }
            curr=curr->lchild;
        }
        if( stck.top==NULL)
            break;
        curr=stck.pop();
    }
}

void tree::inorder(tree *curr)
{
    stack stck;
    while(1)
    {
        while(curr!=NULL)
        {
            stck.push(curr);
            curr=curr->lchild;
        }
        if(stck.top==NULL)
        break;
        curr=stck.pop();
        cout<<curr->data;
        curr=curr->rchild;
    }
}

void tree::postorder(tree *curr)
{
    stack stck;
    do
    {
        while(curr!=NULL)
        {
            stck.push(curr);
            curr->flag=0;
            curr=curr->lchild;
        }
        curr=stck.pop();
        if(curr->flag==1)
        {
            cout<<curr->data;
            curr=NULL;
        }
        else
        {
            stck.push(curr);
            curr->flag=1;
            if(curr->rchild)
            {
                curr=curr->rchild;
            }
            else
                curr=NULL;
        }
        
    }while(stck.top!=NULL);
}
void tree::recursive_preorder(tree *curr)
{
	if(curr!=NULL)
	{
		cout<<curr->data;
		recursive_preorder(curr->lchild);
		recursive_preorder(curr->rchild);
	}	
}	

void tree::recursive_inorder(tree *curr)
{
	if(curr!=NULL)
	{
		recursive_inorder(curr->lchild);
		cout<<curr->data;
		recursive_inorder(curr->rchild);
	}
}

void tree::recursive_postorder(tree *curr)
{
	if(curr!=NULL)
	{
		recursive_postorder(curr->lchild);
		recursive_postorder(curr->rchild);
		cout<<curr->data;
	}
}	

int main()
{
	tree obj;
	char postfix[30];
	cout<<"Enter POSTFIX expression :";
	cin>>postfix;
	cout<<"\n";

 	obj.construct(postfix);

 	cout<<"PREORDER By Iterative :";
	obj.preorder(obj.construct(postfix));
	cout<<endl;

	cout<<"INORDER By Iterative :";
	obj.inorder(obj.construct(postfix));
	cout<<endl;

	cout<<"POSTORDER By Iterative :";
	obj.postorder(obj.construct(postfix));
	cout<<endl<<"\n";

	cout<<"PREORDER By Recursive :";
	obj.recursive_preorder(obj.construct(postfix));
	cout<<endl;

	cout<<"INORDER By Recursive :";
	obj.recursive_inorder(obj.construct(postfix));
	cout<<endl;

	cout<<"POSTORDER By Recursive :";
	obj.recursive_postorder(obj.construct(postfix));

	return 0;
}


/*OUTPUT:

Enter POSTFIX expression :AB+C-

PREORDER By Iterative :-+ABC
INORDER By Iterative :A+B-C
POSTORDER By Iterative :AB+C-

PREORDER By Recursive :-+ABC
INORDER By Recursive :A+B-C
POSTORDER By Recursive :AB+C-



Enter POSTFIX expression :ABC*+D/

PREORDER By Iterative :/+A*BCD
INORDER By Iterative :A+B*C/D
POSTORDER By Iterative :ABC*+D/

PREORDER By Recursive :/+A*BCD
INORDER By Recursive :A+B*C/D
POSTORDER By Recursive :ABC*+D/



Enter POSTFIX expression :48*3+

PREORDER By Iterative :+*483
INORDER By Iterative :4*8+3
POSTORDER By Iterative :48*3+

PREORDER By Recursive :+*483
INORDER By Recursive :4*8+3
POSTORDER By Recursive :48*3+
*/
