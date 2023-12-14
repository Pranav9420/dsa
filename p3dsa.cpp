#include<iostream>
using namespace std;
struct node
{
    char name[20];
    int n;
    node *child[10];
};
class book
{
    public:
    node *root;
    void creation();
    void display();
};
void book::creation()
{
    root = new node;
    cout<<"\nEnter the name of book : ";
    cin.getline(root->name,20);
    cout<<"\nEnter number of chapter the book have : ";
    cin>>root->n;
    cin.ignore();
    for(int i=0;i<root->n;i++)
    {
        root->child[i] = new node;
        cout<<"\nEnter the chapter name : ";
        cin.getline(root->child[i]->name,20);
        cout<<"\nEnter number of sections the chapter have :";
        cin>>root->child[i]->n;
        cin.ignore();
        for(int j =0;j<root->child[i]->n;j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"\nEnter the name of section : ";
            cin.getline(root->child[i]->child[j]->name,20);
            cout<<"\nEnter number of subsection the section have : ";
            cin>>root->child[i]->child[j]->n;
            cin.ignore();
            for(int k =0;k<root->child[i]->child[j]->n;k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout<<"\nEnter the name of subsection : ";
                cin.getline(root->child[i]->child[j]->child[k]->name,20);
                root->child[i]->child[j]->child[k]->n=0;
            }
        }
    }
}
void book::display()
{
    cout<<"Book : "<<root->name;
    for(int i=0;i<root->n;i++)
    {
        cout<<"\n\tChapter : "<<root->child[i]->name;
        for(int j=0;j<root->child[i]->n;j++)
        {
            cout<<"\n\t\t~~"<<root->child[i]->child[j]->name;
            for(int k=0;k<root->child[i]->child[j]->n;k++)
            {
                cout<<"\n\t\t\t--"<<root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
int main()
{
    book b1;
    b1.creation();
    b1.display();
}