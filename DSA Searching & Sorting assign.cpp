#include<iostream>

using namespace std;

struct student
	{
		float sgpa;
		
		string name;
		
		int roll_no;
	};
	
int quick(struct student s[],int n,int first ,int last)
{
	int pivot =first;
	int big= first;
	int small=last;
	if(small>big)
	{
		while(big<small)
		{
			while (s[big].sgpa>=s[pivot].sgpa)
			{
				big++;
			}
			while (s[small].sgpa<s[pivot].sgpa)
			{
				small--;
			}
			if (big<small)
			{
				struct student temp=s[big];
				s[big]=s[small];
				s[small]=temp;
			}
		}	
		
		struct student temp=s[small];
		s[small]=s[pivot];
		s[pivot]=temp;
		
		quick(s,n,first,small-1);
		quick(s,n,small+1,last);
	}
}
	
int insertion(struct student s[],int n)
{
	struct student temp;
	int i;
	int j;
	
	for (i=1 ; i<n ; i++)
	{
		temp=s[i];
		j=i-1;
		
		while(j>=0)
		{
			if(s[j].roll_no>temp.roll_no)
			{
				s[j+1]=s[j];
			}
			
			else
				break;
			j--;
		}
		s[j+1]=temp;
	}
}
	
int iterating_binary_search(struct student s[],int low ,int high, string sname,int n)
{
    int flag=0;
    int mid;
    
	while(low<=high)
	{
		mid=(low+high)/2;
		
		if(s[mid].name == sname)
		{
		    flag=1;
		    
		    cout<<"location of binary search :"<<mid<<"\n";
		    
		    cout<<"sgpa\t"<<"name\t"<<"roll_no\n";
		    
			cout<<s[mid].sgpa<<"\t";
		
			cout<<s[mid].name<<"\t";
		
			cout<<s[mid].roll_no<<"\n";
		
			cout<<"\n";
			
			break;
		}
		else if(s[mid].name> sname)
		{
			high=mid-1;
		}
		else
		{	
			low=mid+1;
		}
	}
	if(flag==0)
	{
	    cout<<"Record not found \n";
	}
}
	

int b_sort(struct student s[],int n)
{
	int flag=0;
	for(int i=0; i<n-1 ; i++)
	{
		for(int j=0; j<n-i-1 ; j++)
		{
			if(s[j].name>s[j+1].name)
			{
				struct student c;
				c=s[j];
				s[j]=s[j+1];
				s[j+1]=c;
				
				flag=1;
			}
		}
		if (flag==0)
			 break;
	}
}

int data_student (struct student s[],int n)
{
	cout<<"enter student data :\n\n";
	
	for (int i=0;  i<n ; i++)
	{ 
		cout<<"enter sgpa :";
		cin>>s[i].sgpa;
		
		
		cout<<"enter name :";
		cin>>s[i].name;
		
		
		cout<<"enter roll_no :";
		cin>>s[i].roll_no;
		
		cout<<"\n"<<"\n";
	}
}	

int display_student (struct student s[],int n)
{
cout<<"entered student data :\n";
cout<<"sgpa\t"<<"name\t"<<"roll_no\n";
	
	for (int i=0;  i<n; i++)
	{
		cout<<s[i].sgpa<<"\t";
		
		cout<<s[i].name<<"\t";
		
		cout<<s[i].roll_no<<"\n";
		
		cout<<"\n";
	}
}

int search(struct student s[],int n)
{	
	int flag=0;
	float my_sgpa;
	
	cout<<"enter sgpa to search :";
	cin>>my_sgpa;
	
	
	for (int i=0; i<n ;i++)
	{
		if(s[i].sgpa==my_sgpa)
		{
		    flag=1;
		    
			cout<<"Location of given search :"<<i<<"\n";
			
			cout<<"sgpa\t"<<"name\t"<<"roll_no\n";
			
			cout<<s[i].sgpa<<"\t";
			
			cout<<s[i].name<<"\t";
			
			cout<<s[i].roll_no<<"\n";
		}
	}
	if(flag==0)
	cout<<"Entered sgpa is not found!\n";
}
	
int main()
{
	string sname;
	string flag="y";
	int n;

	cout<<"enter no. of student : ";	
	cin>>n;
			
	student s[n];
				
	int data;
	
	do
     	{
     		cout<<"\n";
     		cout<<"1:data\n"<<"2:display data\n"<<"3:to search by sgpa\n"<<"4:sorted data(By name)\n"<<"5:Iter binary search\n"<<"6:insertion sort(By roll no.)\n"<<"7:quick sort(Toppers by sgpa)\n";
     
     		cout<<"\nenter your choice: ";
     
     		cin>>data;
     		
     		switch(data)
     		{
     			case 1:
     				data_student(s,n);
     				break;
     				
     			case 2:
     				display_student(s,n);
     				break;
     				
     			case 3:
     				search(s,n);
     				break;
     				
     			case 4:
     				cout<<"sorted data";
     				b_sort(s,n);
     				display_student(s,n); 
    				break;
     				
     			case 5:
     				cout<<"Enter name you want to iter binary search  :";
     				cin>>sname;
     				b_sort(s,n);
     				iterating_binary_search( s ,0,n-1,sname,n);
     				break;
     				
     			case 6:
     				cout<<"insertion sorted data\n";
     				insertion(s,n);
     				display_student(s,n); 
    				break;
     				
     			case 7:
     				cout<<"Toppers by quick sort\n";
     				quick(s,n,0,n-1);
     				display_student(s,10); 
     				break;
     					
     			default:
     				cout<<"invalid input";	
     		}
		    cout<<"do you want to continue ?(Y/N)";
     		cin>>flag;
     	
     	}while(flag=="Y"|| flag=="y");
     			     
     	return 0;
}



/*OUTPUT :-


enter no. of student : 15

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 1
enter student data :

enter sgpa :8
enter name :Aha  yan
enter roll_no :1


enter sgpa :8.9
enter name :d Sumit
enter roll_no :2


enter sgpa :9.5
enter name :Farukh
enter roll_no :3


enter sgpa :7
enter name :Sonali
enter roll_no :4


enter sgpa :8.2
enter name :Hrutik
enter roll_no :5


enter sgpa :9.2
enter name :Dhruv
enter roll_no :6


enter sgpa :5.9
enter name :Jayant
enter roll_no :7


enter sgpa :4.9
enter name :Bhavna
enter roll_no :8


enter sgpa :9
enter name :Usha
enter roll_no :9


enter sgpa :6.8
enter name :Rahul
enter roll_no :10


enter sgpa :8.2
enter name :Y TI ina
enter roll_no :11


enter sgpa :8
enter name :Ishan
enter roll_no :12


enter sgpa :5.9
enter name :Ayush
enter roll_no :13


enter sgpa :5.9
enter name :Komal
enter roll_no :14


enter sgpa :9
enter name :John
enter roll_no :15


do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 2
entered student data :
sgpa	name	roll_no
8	Ayan	1

8.9	Sumit	2

9.5	Farukh	3

7	Sonali	4

8.2	Hrutik	5

9.2	Dhruv	6

5.9	Jayant	7

4.9	Bhavna	8

9	Usha	9

6.8	Rahul	10

8.2	Tina	11

8	Ishan	12

5.9	Ayush	13

5.9	Komal	14

9	John	15

do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 3
enter sgpa to search :7
Location of given search :3
sgpa	name	roll_no
7	Sonali	4
do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 3
enter sgpa to search :6
Entered sgpa is not found!
do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 4
sorted dataentered student data :
sgpa	name	roll_no
8	Ayan	1

5.9	Ayush	13

4.9	Bhavna	8

9.2	Dhruv	6

9.5	Farukh	3

8.2	Hrutik	5

8	Ishan	12

5.9	Jayant	7

9	John	15

5.9	Komal	14

6.8	Rahul	10

7	Sonali	4

8.9	Sumit	2

8.2	Tina	11

9	Usha	9

do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 5
Enter name you want to iter binary search  :Tina
location of binary search :13
sgpa	name	roll_no
8.2	Tina	11

do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 5
Enter name you want to iter binary search  :Isha
Record not found 
do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 6
insertion sorted data
entered student data :
sgpa	name	roll_no
8	Ayan	1

8.9	Sumit	2

9.5	Farukh	3

7	Sonali	4

8.2	Hrutik	5

9.2	Dhruv	6

5.9	Jayant	7

4.9	Bhavna	8

9	Usha	9

6.8	Rahul	10

8.2	Tina	11

8	Ishan	12

5.9	Ayush	13

5.9	Komal	14

9	John	15

do you want to continue ?(Y/N)y

1:data
2:display data
3:to search by sgpa
4:sorted data(By name)
5:Iter binary search
6:insertion sort(By roll no.)
7:quick sort(Toppers by sgpa)

enter your choice: 7
Toppers by quick sort
entered student data :
sgpa	name	roll_no
9.5	Farukh	3

9.2	Dhruv	6

9	John	15

9	Usha	9

8.9	Sumit	2

8.2	Tina	11

8.2	Hrutik	5

8	Ishan	12

8	Ayan	1

7	Sonali	4
do you want to continue ?(Y/N)n
*/
