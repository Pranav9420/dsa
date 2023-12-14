#include<iostream>
#include<cstring>
using namespace std;
struct book
{
	char name[20];
	long int tel;
};   
book table[10];
int size=10;
void insert()
{
	for(int i=0;i<size;i++)
	{
		strcpy(table[i].name,"none");
		table[i].tel=0;
	}
    long int tele;
	int sum=0;
    char n[20];
    char d;
    do
	{
		cout<<"enter name :";
		cin>>n;
		int comp=0;
		int flag=0;
		int sum=0;
		int home=0;
		int i=0;
		while(n[i]!='\0')
		{
			sum=sum+int(n[i]);
			i++;
		}
		home=sum%size;
		cout<<"enter telephone no. : ";
		cin>>tele;
		char b[10];
		strcpy(b,"none");
		i=home;
		do
		{
			if(strcmp(table[i].name,b)==0)
			{
				strcpy(table[i].name,n);
				table[i].tel=tele;
				flag=1;
				break;
			}
			else
			{
				i=(i+1)%10;
				comp++;

			}
		} while (i!=home);
		cout<<"No. of comparison requires for adding element : "<<comp<<endl;
		if(flag==0)
		{
			cout<<"cann't insert !!"<<endl;
		}
		cout<<"Do you want to add more data (y/n)";
		cin>>d;
	}while(d=='y');
}
void search()
{
    char n[20];
    cout<<"enter name you want to search : ";
	cin>>n;
	int flag=0;
	for (int i = 0; i < size; i++)
	{
		if(strcmp(table[i].name,n)==0)
		{
			cout<<"Name : "<<table[i].name<<endl;
			cout<<"Telephone No. : "<<table[i].tel<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"wrong name entered !!";
	}
	
}
void quadratic()
{
	for(int i=0;i<size;i++)
	{
		strcpy(table[i].name,"none");
		table[i].tel=0;
	}
    long int tele;
    int sum=0;
    char n[20];
    char d;
    do
	{
		cout<<"enter name :";
		cin>>n;
		int comp=0;
		int flag=0;
		int sum=0;
		int home=0;
		int i=0;
		while(n[i]!='\0')
		{
			sum=sum+int(n[i]);
			i++;
		}
		home=sum%size;
		cout<<"enter telephone no. : ";
		cin>>tele;
		i=0;
		int k=home;
		while(i<=(size-1)/2)
		{
			if(strcmp(table[k].name,"none")==0)
			{
				strcpy(table[k].name,n);
				table[k].tel=tele;
				flag=1;
				break;
			}
			else
			{
				i++;
				k=(home+(i*i))%size;
				comp++;
			}
		}
		cout<<"No. of comparison requires for adding element : "<<comp<<endl;
		if(flag==0)
		{
			cout<<"not inserted!!";
		}
		cout<<"Do you want to add more data (y/n)";
		cin>>d;
	}while(d=='y');
}
void display()
{
	cout<<"Name"<<"\t"<<"telephone no."<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<table[i].name<<"\t"<<table[i].tel<<endl;
	}
}
int main()
{
	cout<<"\n*******Linear probing********"<<endl;
    insert();
    //search();
    display();
    cout<<"\n*******Quadratic probing********"<<endl;
    quadratic();
    display();
    return(0);
}
