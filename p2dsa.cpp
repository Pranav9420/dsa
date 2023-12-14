#include<iostream>
using namespace std;
#define size 30

template<class T>
class set
{
  T S[size];
  T point,count;
  public:
    set()
    {
        point=-1;
        count=0;
    }
    void Add(T ele);
    void Remove(T ele);
    bool Contains(T element);
    int Size();
    void display();
    template<class s>
    friend  set<s> Intersection(set<s> s1,set<s> s2);
    template<class s>
    friend  set<s> Union(set<s> s1,set<s> s2);
    template<class s>
    friend  set<s> Diffrence(set<s> s1,set<s> s2);
};
template <class T>
void set<T> :: Add(T ele)
{
    if(point<size)
    {
        point++;
       S[point]=ele;
       count++;
    }
    else
    {
        cout<<"\nSet is Full ";
    }
}
template<class T>
void set<T>:: Remove(T ele)
{
    int i;
    if(Contains(ele))
    {
    for(i=0;i<=point;i++)
    {
        if(ele==S[i])
        break;
    }
    for(int j=i+1;j<size;j++)
    {
        S[j-1]=S[j];
    }
    count--;
    point--;
    }
    else
    {
        cout<<"\nElement not Present ";
    }
}
template <class T>
bool set<T> ::  Contains(T ele)
{
        int flag=0;
        for(int i=0;i<=point;i++)
        {
            if(S[i]==ele)
            {
                flag=1;
                return true;
            }
        
        }
     return false;
   
}
template <class T>
int set<T> :: Size()
{
    return count;
}
template <class T>
void set<T> :: display()
{
    
    for(int i=0;i<=point;i++)
    {
        cout<<"\t"<<S[i];
    }
    cout<<endl;
}
template<class s>
set<s>  Intersection(set<s> s1,set<s> s2)
{
    set<s> s3;
    int flag;
    for(int i=0;i<=s1.point;i++)
    {
        flag=0;
        for(int j=0;j<=s2.point;j++)
        {
            if(s1.S[i]==s2.S[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            s3.Add(s1.S[i]);
        }
    }
    return s3;
}
template<class s>
set<s>  Union(set<s> s1,set<s> s2)
{
     set<s> s3;
    int flag,k,i,j;
    for( k=0;k<=s1.point;k++)
    {
        s3.Add(s1.S[k]);
    }
    for( i=0;i<=s2.point;i++)
    {
        flag=0;
        for( j=0;j<=s3.point;j++)
        {
            if(s3.S[j]==s2.S[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            s3.Add(s2.S[i]);
        }
    }
    return s3;
}
template<class s>
set<s>  Diffrence(set<s> s1,set<s> s2)
{
     set<s> s3;
    int flag;
  
    for(int i=0;i<=s1.point;i++)
    {
        flag=0;
        for(int j=0;j<=s2.point;j++)
        {
            if(s1.S[i]==s2.S[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            s3.Add(s1.S[i]);
        }
    }
    return s3;
}

int main()
{   
    set<int> s1,s2,s3;
    int ch,ele;
    do
    {
        
    
    cout<<"\n1.Add in set 1\n2.Add in set 2\n3.Remove from set 1\n4.Remove from set 2";
    cout<<"\n5.Cointains in set 1\n6.cointains in set 2\n7.Size of set 1\n8.Size of set 2\n9.Intersection\n10.Union\n11.Diffrence\n12.Display\n0.Exit"<<endl;
    cout<<"\nEnter your choice:- ";
    cin>> ch; 
    switch(ch)
    {
        case 1:
              
              cout<<"\nEnter element to add :- ";
              cin>>ele;
              s1.Add(ele);
              break;
        case 2:
                 
              cout<<"\nEnter element to add :- ";
              cin>>ele;
              s2.Add(ele);
              break;
        case 3:
            
                
              cout<<"\nEnter element to remove :- ";
              cin>>ele;
              s1.Remove(ele);
              break;
        case 4:
            
               
              cout<<"\nEnter element to remlove :- ";
              cin>>ele;
              s2.Remove(ele);
              break;
        case 5:
            
        
              cout<<"\nEnter element to check :- ";
              cin>>ele;
             if( s1.Contains(ele))
             {
                cout<<"\nElement Present "<<endl;
             }
             else
             {
                cout<<"\nElement Absent "<<endl;
             }
              break;
        case 6:
              
              cout<<"\nEnter element to check :- ";
              cin>>ele;
             if( s2.Contains(ele))
             {
                cout<<"\nElement Present "<<endl;
             }
             else
             {
                cout<<"\nElement Absent "<<endl;
             }
              break;
        case 7:
            cout<<"\nSize of set 1 is "<<s1.Size()<<endl;
            break;
        case 8:
            cout<<"\nSize of set 2 is "<<s2.Size()<<endl;
            break;
        case 9:
                s3=Intersection(s1,s2);
                cout<<"\nSet intersection is :-";
                s3.display();
                break;
        case 10:
                s3= Union( s1, s2);
                cout<<"\nSet union is:- ";
                s3.display();
                break;
        case 11:
                s3= Diffrence( s1, s2);
                cout<<"\nSet diffrence is :- ";
                s3.display();
                break;
        case 12:
                cout<<"\nSet 1:- ";
                s1.display();
                cout<<"\nSet 2:- ";
                s2.display();
                break;
        default:
                cout<<"\nEnter valid choice ";
                break;
    }
    }while(ch!=0);
}






