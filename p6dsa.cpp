#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
class matrix
{
    public :
    int n;
    int count = 0;
    int m[10][10];
    string a[10];
    queue<int> q;
    void getdata();
    void show();
    void bfs();
};
void matrix :: getdata()
{
	 int y;
    int i,j;
    cout<<"\nEnter the nuber of cities : ";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            m[i][j]=0;
        }
    }
    char name[20];
    for(int i = 0; i < n; i++)
    {
        cout<<"\nEnter name of cities : ";
        cin>>name;
        a[i]=name;
    }
    char s[20];
    char d[20];
    do
    {
        cout<<"\nEnter source name : ";
        cin>>s;
        cout<<"\nEnter destinstion name : ";
        cin>>d;
        int r,c1;
        for(int k = 0; k < n; k++)
        {
            if(a[k]==s)
            {
            	 r=k;
                break;
            }
        }
        for(int l = 0; l < n; l++)
        {
            if(a[l]==d)
            {
            	 c1=l;
                break;
            }
        }
        int c;
        cout<<"\nEnter cost require : ";
        cin>>c;
        m[r][c1]=c;
        m[c1][r]=c;
        cout<<"\nDo you wnat to continue(1.y/2.n) : ";
        cin>>y;
    }while(y == 1);
}
void matrix :: show()
{
    cout<<"\t";
    for(int k = 0;k < n; k++ )
    {
        cout<<a[k]<<"\t";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
        for(int j = 0; j < n; j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void matrix :: bfs()
{
    q.push(0);
    int vis[10]={0};
    vis[0]=1;
    count++;
    cout<<"\nBFS traversal :"<<endl;
    while(!q.empty())
    {
    		int v;
         v=q.front();
         cout<<a[v]<<"\t";
         for(int i = 0; i < n; i++)
         {
              if(m[v][i] != 0)
              {
              		if(vis[i] == 0)
              		{
              			q.push(i);
              			vis[i] = 1;
              			count++;
              		}
              }
         }
         q.pop();
    }
    if(count == n)
    {
         cout<<"\nGraph is connected !!"<<endl;
    }
    else
    {
         cout<<"\nGraph is not connected !!!"<<endl;
    }
}
int main()
{
    matrix m1;
    m1.getdata();
    m1.show();
    m1.bfs();
}
