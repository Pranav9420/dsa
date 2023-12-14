#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

struct Node
{
    char ch;
    Node *left;
    Node *right;
};

stack <Node*> s1;

Node * create(char *prefix , int size)
{
    int i=size-1;
    Node *nnode = NULL;
    Node *temp;
    while(i >= 0)
    {
        char ch = prefix[i];
        nnode = new Node;
        nnode -> ch = ch;
        nnode -> left = nnode -> right = NULL;
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        {
            s1.push(nnode);
        }
        else
        {
            temp = s1.top();
            nnode->left = temp;
            s1.pop();
            if(!s1.empty())
            {
                temp = s1.top();
                nnode -> right = temp;
                s1.pop();
            }
            s1.push(nnode);
        }
        i--;
    }
    temp = s1.top();
    s1.pop();
    return temp;
}

void display(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree Not exist"<<endl;
    }
    stack <Node*> s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp -> left != NULL)
        {
            s1.push(temp -> left);
        }
        if(temp -> right != NULL)
        {
            s1.push(temp -> right);
        }
    }
    while(!s2.empty())
    {
        cout<<s2.top()->ch;
        s2.pop();
    }
}

void deleteTree(Node *root)
{
    stack <Node*> s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp -> left != NULL)
        {
            s1.push(temp -> left);
        }
        if(temp -> right != NULL)
        {
            s1.push(temp -> right);
        }
    }
    while(!s2.empty())
    {
        delete s2.top();
        s2.pop();
    }
}

int main()
{
    char prefix[20];
    cout<<"enter prefix expression"<<endl;
    cin>>prefix;
    Node *root = create(prefix,strlen(prefix));
    display(root);
    deleteTree(root);
}