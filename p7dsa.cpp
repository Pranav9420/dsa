#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
struct list
{
    string area;
    list *next;
};
class adjacency
{
public:
    list *arr[10];
    list *nnode, *temp;
    adjacency()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] == NULL;
        }
    }
    string name[10];
    int n;
    int narea;
    void creation();
    void display();
    void bfs();
    void dfs();
};
void adjacency ::creation()
{
    cout << "\n********* creation *********";
    cout << "\nEnter how many areas are there : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new list;
        arr[i]->next = NULL;
        cout << "\nEnter name of area : ";
        cin >> arr[i]->area;
        cout << "\nEnter how many areas are connected to " << arr[i]->area << " :";
        cin >> narea;
        for (int j = 0; j < narea; j++)
        {
            nnode = new list;
            nnode->next = NULL;
            cout << "\nEnter the name of area which is connected : ";
            cin >> nnode->area;
            temp = arr[i];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nnode;
        }
    }
}
void adjacency::display()
{
    cout << "\n********* Display list ***********" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]->area << " -> ";
        temp = arr[i]->next;
        while (temp != NULL)
        {
            cout << temp->area << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
void adjacency::bfs()
{
    int i, j, k = 0;
    int index;
    cout << "\n********** BFS traversal ***********";
    int vis[10];
    string start, v1;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    queue<string> que;
    cout << "\n\nEnter starting vertex : ";
    cin >> start;
    for (int k = 0; k < n; k++)
    {
        if (start == arr[k]->area)
        {
            index = k;
            break;
        }
    }
    que.push(start);
    vis[index] = 1;
    while (!que.empty())
    {
        int i = 0;
        v1 = que.front();
        cout << v1 << "\t";
        for (i = 0; i < n; i++)
        {
            if (v1 == arr[i]->area)
            {
                break;
            }
        }
        temp = arr[i]->next;
        while (temp != NULL)
        {
            for (j = 0; j < n; j++)
            {
                if (temp->area == arr[j]->area)
                {
                    break;
                }
            }
            if (vis[j] == 0)
            {
                que.push(temp->area);
                vis[j] = 1;
            }
            temp = temp->next;
        }
        // int flag = 0,u;
        // for(u = 0;u<n;u++)
        // {
        //     if(vis[u]==0)
        //     {
        //         flag=1;
        //         break;
        //     }
        // }
        // if(flag==1)
        // {
        //     que.push(arr[u]->area);
        //     vis[u]=1;
        // }
        que.pop();
    }
}
void adjacency::dfs()
{
    int i, j, k = 0;
    int index;
    cout << "\n\n********** DFS traversal ***********";
    int vis[10];
    string start, v1;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    stack<string> st;
    cout << "\nEnter starting vertex : ";
    cin >> start;
    st.push(start);
    for (int k = 0; k < n; k++)
    {
        if (start == arr[k]->area)
        {
            index = k;
            break;
        }
    }
    cout<<start<<"\t";
    vis[k] = 1;
    while (!st.empty())
    {
        v1 = st.top();
        for (i = 0; i < n; i++)
        {
            if (v1 == arr[i]->area)
            {
                break;
            }
        }
        temp = arr[i]->next;
        if (temp != NULL)
        {
            while(temp != NULL)
            {
                for (j = 0; j < n; j++)
                {
                    if (temp->area == arr[j]->area)
                    {
                        break;
                    }
                }
                if (vis[j] == 0)
                {
                    st.push(temp->area);
                    cout<<temp->area<<"\t";
                    vis[j]=1;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
                if(temp == NULL)
                {
                    st.pop();
                }
            }
        }
    }
}
int main()
{
    adjacency b;
    b.creation();
    b.display();
    b.bfs();
    b.dfs();
}