//Conversion to postfix | Conversion to prefix | POSTFIX evaluation | PREFIX evaluation

#include<iostream>
using namespace std;
template<typename T>class stack
{
	T data;
	stack *next;
	stack *top;
	
	public :
	    float result;
		stack()
		{
			top=NULL;
		}
		 void push(T);
		 void pop();
		 int priority(char);
		 void infixtopostfix(char[],char[]); 
		 void create(T);
		 void rev(char[],char[]);
		 void infixtoprefix(char[],char[],char[] , char[]);
		 void posteval(char[],char[], float[]); 
		 void preeval(char[],char[],char[],char[],float[]); 
};

template<typename T>void stack<T>::create(T a)
{
	stack *newnode =new stack();
    	newnode -> data=a;
	newnode -> next=NULL;
}


template<typename T>void stack<T>::push(T a)
{
	stack *newnode = new stack();
	newnode->data=a;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
	   newnode->next=top;
	   top=newnode;
	}
}

template<typename T>void stack<T>::pop()
{
	stack *ptr;
	if(top==NULL)
	{
		cout<<"The stack is Empty";
	}
	else
	{
		ptr=top;
		top=top->next;
		delete(ptr);
	}
}

template<typename T>int stack<T>:: priority(char X)
{
	if(X=='/' || X=='*')
	{
		return 3;
	}
	else if(X=='+' || X=='-')
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

template<typename T>void stack<T>::infixtopostfix(char infix[],char postfix[])
{
 	int i=0;
 	int j=0;
 	while(infix[i]!='\0')
 	{
 		if(! (isalnum(infix[i])))
 		{
			  if(top==NULL)
 			{
 				push(infix[i]);
 			}	
 			else if(infix[i]=='(')
 			{
 				push(infix[i]);
 			}
 			else if(infix[i]==')')
 			{
 				while(top->data!='(')
 				{
 					postfix[j]=top->data;
 					pop();
 					j++;
 					if(top==NULL)
 						break;
 				}
 				pop();
 			}
 			else 
 			{
 			while(priority(infix[i])<=priority(top->data))
 			{
 				postfix[j]=top->data;
 					pop();
 					j++;
 				if(top==NULL)
 				{
 					break;
 				}
 			}
 			push(infix[i]);
 		}
 	}
 		else
 		{
 			postfix[j]=infix[i];
 			j++;
 		}
 		i++;
 	}
 	while(top!=NULL)
 	{
 		postfix[j]=top->data;
 		j++;
 		pop();
 	}
 	postfix[j]='\0';
 
 	
 }
 
template<typename T>void stack<T> :: rev(char infix[], char revinfix[])
{
	int length=0;
	int i=0;
	int j=0;
	while(infix[i]!='\0')
	{
		i++;
	}
	length=i;
	i--;
	for( j=0;j<length;j++)
	{
		if(infix[i]=='(')
		{
			revinfix[j]=')';
		}
		else if(infix[i]==')')
		{
			revinfix[j]='(';
		}
		else 
		{
			revinfix[j]=infix[i];
		}
		i--;
	}
	revinfix[j]='\0';
}
 
template<typename T>void stack<T>::infixtoprefix(char infix[],char postfix[],char revinfix[] , char prefix[] )
{
	rev(infix,revinfix);
	infixtopostfix(revinfix,postfix);
	rev(postfix,prefix);
}

template<typename T>void stack<T>::posteval(char postfix[],char infix[],float eval[])
{
    int i=0;
    float r;
    infixtopostfix(infix,postfix);
    while(postfix[i]!='\0')
	{
        if(isalpha(postfix[i]))
	{
            cout<<"Enter the value for :"<<postfix[i]<<" ";
            cin>>eval[i];
            push(eval[i]);
        }
        
        else
	{
            
            float x=top->data;
            pop();
            float y=top->data;
            pop();
            if(postfix[i]=='+')
				r=y+x;
			if(postfix[i]=='-')
				r=y-x;
			if(postfix[i]=='*')
				r=y*x;	
			if(postfix[i]=='/')
				r=y/x;
			push(r);	
        }
        i++;
    }
    result=top->data;
    
}

template<typename T>void stack<T>::preeval(char postfix[],char revinfix[],char prefix[],char infix[],float eval[])
{
    int i=0;
    float r;
    int length=0;
    
    infixtoprefix(infix,postfix,revinfix,prefix);
    while(prefix[i]!='\0')
    {
         i++;
    }
    i=i-1;
    while(i>=0)
    {
        if(isalpha(prefix[i]))
        {
            cout<<"Enter the value for :"<<prefix[i]<<" ";
            cin>>eval[i];
            push(eval[i]);
        }
        
        else{
            cout<<"hello";
            float x=top->data;
            pop();
            float y=top->data;
            pop();
            if(prefix[i]=='+')
				r=x+y;
			if(prefix[i]=='-')
				r=x-y;
			if(prefix[i]=='*')
				r=x*y;	
			if(prefix[i]=='/')
				r=x/y;
			push(r);	
        }
        i--;
    }
    result=top->data;
    cout<<result;
}

int main()
{
    stack < char > obj;
    char prefix[20];
	char infix[20];
	char postfix[20];
	char revinfix[20];
	float eval[20];
	float r;
	int z;
	
    cout<<"Enter INFIX expression :";
    cin>>infix;
    int data;
    do
    {
    	cout<<"\n";
    	cout<<"1.Conversion to postfix\n"<<"2.Conversion to prefix\n"<<"3.POSTFIX evaluation\n"<<"4.PREFIX evaluation\n"<<"5.Exit"<<"\nEnter your Choice : ";
	    cin>>data;
    	switch(data)
    	{
    	    case 1:
    	        		obj.infixtopostfix(infix,postfix);
    	        		cout<<"The POSTFIX Expression is :"<<postfix<<"\n";
    	        		break;
    	    case 2:
    	        	   	obj.infixtoprefix(infix,postfix,revinfix,prefix);
	            	cout<<"The PREFIX Expression is :"<<prefix<<"\n";
	            	break;
	   case 3:
    			obj.posteval(postfix,infix,eval);
    			cout<<"The POSTFIX Evaluation is :"<<obj.result<<"\n";
    			break;
    	    case 4:
			obj.preeval(postfix,revinfix,prefix,infix,eval);
			cout<<"The POSTFIX Evaluation is :"<<obj.result<<"\n";
			break;
	    case 5:
			cout<<"Thank you:)";
			break;
	    default:
                		cout<<"Invalid Input";
    	}
    }while(data!=5);
}



/*OUTPUT :


*TEST CASE 1:

Enter INFIX expression :A*B/C

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 1
The POSTFIX Expression is :AB*C/

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 3
Enter the value for :A 10
Enter the value for :B 10
Enter the value for :C 5
The POSTFIX Evaluation is :20

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 2
The PREFIX Expression is :*A/BC

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 4
Enter the value for :C 5
Enter the value for :B 10
Enter the value for :A 10
The POSTFIX Evaluation is :20

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 5
Thank you:)


*TEST CASE 2 :

Enter INFIX expression :A*B+C/D

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 1
The POSTFIX Expression is :AB*CD/+

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 3
Enter the value for :A 10
Enter the value for :B 5
Enter the value for :C 20
Enter the value for :D 4
The POSTFIX Evaluation is :55

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 2
The PREFIX Expression is :+*AB/CD

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 4
Enter the value for :D 4
Enter the value for :C 20
Enter the value for :B 5
Enter the value for :A 10
The PREFIX Evaluation is :55

1.Conversion to postfix
2.Conversion to prefix
3.POSTFIX evaluation
4.PREFIX evaluation
5.Exit
Enter your Choice : 5
Thank you:)

*/
