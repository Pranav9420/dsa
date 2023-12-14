#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class student
{
	
	public:
	string name,add;
	int roll;
	char div;
		void getdata()
		{
            cout<<"\nEnter roll number :- ";
			cin>>roll;
			cout<<"\nEnter the name of student :- ";
			cin>>name;
			cout<<"\nEnter address :- ";
			cin>>add;
			cout<<"\nEnter division :- ";
			cin>>div;
		}
		
		void putdata()
		{
			cout<<roll<<"\t"<<name<<"\t"<<div<<"\t"<<add<<endl;
		}
};

int main()
{
	student s[10];
	int ch,n;
	
    char chs;
    do
    {
        cout<<"\nEnter operations :";
        cout<<"\n1.Write\n2.read\n3.Search\n4.Delete";
        cout<<"\nEnter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    {
                        cout<<"\nEnter how many students :";
                        cin>>n;
                        ofstream fout("a.txt",ios::app);
                        for(int i=0;i<n;i++)
                        {
                            s[i].getdata();
                            fout.write((char*)& s[i],sizeof(s[i]));

                        }
                        fout.close();
                         break;
                    }
                   
            case 2:
                    {
                        ifstream fin;
                        fin.open("a.txt");
                      
                        student s1;
                        while(fin.read((char*) &s1,sizeof(s1)))
                        {
                            s1.putdata();
                        }
                        fin.close();
                        break;
                    }
                    
                   
            case 3:
            	{
            		ifstream fin;
            		int flag=0;
                        fin.open("a.txt");
                        int r;
                        cout<<"\nEnter roll number you want to search :- ";
                        cin>>r;
                      
                         student s1;
                        while(fin.read((char*) &s1,sizeof(s1)))
                        {
                        	if(s1.roll==r)
                        	{
                        		s1.putdata();
                        		flag=1;
                        		break;
                        	}
                            
                        }
                        fin.close();
                        if(flag==0)                             
                        {
                        	cout<<"\nData of student not available ";
                        }
                        fin.close();
                        break;
            	}
            	
            case 4:
            	{
                        int r;
                        cout<<"\nEnter roll number you want to delete :- ";
                        cin>>r;
                        ifstream fin("a.txt");
                        ofstream of("new.txt",ios::app);
                        student s1;
                        while(fin.read((char*) &s1,sizeof(s1)))
                        {
                        	if(s1.roll!=r)
                        	{
                        		of.write((char*)&s1, sizeof(s1));
                        	}
                            
                        }
                    remove("a.txt");
            	    rename("new.txt","a.txt");
            	break;
            	}
           
        }
    
    cout<<"\nDo you want to continue(y/n) :";
    cin>>chs;
    }while(chs=='y');

}
