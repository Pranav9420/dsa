#include<iostream>
using namespace std;
struct node
{
  int data;
  node*left,*right;

};

class tree
{
    public:
    int h1,h2;
    
    node *nnode,*temp,*root,*temp2,*temp3;
    tree()
    {
      root=NULL;
    }
    
    node* creation();
    void bst();
    void display(node* root);
    void min(node* root);
    void max(node* root);
    void search(node* root);
    int countleaf(node* root);
    void mirroring(node* root);
    int height(node* root);

};

node* tree::creation()
{
  nnode=new node;
  if(nnode==NULL)
  {
    cout<<"\nNo any Node  created";
  } 
  else
  {
     nnode->left=nnode->right=NULL;
     cout<<"\nEnter the node: ";
     cin>>nnode->data;
     return nnode; 
  }
    
  
}
void tree::bst()
{
   temp=NULL;
   temp=creation();
 if(root==NULL)
   {
      root=temp;
   }
   else 
   { 
        temp2=root;
        while(1)
     {
       if(temp2->data>temp->data)
       {
           if(temp2->left==NULL)
           {
            temp2->left=temp;
            break;
           }
         else
         {
            temp2=temp2->left;
            }
      }
    else{
          if(temp2->right==NULL)
        {
          temp2->right=temp;
          break;
        }
      else{
        temp2=temp2->right;
        }

    }
   }
   }

}
void tree::display(node* root)
{    if(root!=NULL)
    {
      display(root->left);
      cout<<root->data<<"->";
      display(root->right);
    }
}
void tree ::min(node* root)
{
   temp=root;
   while(temp->left!=NULL)
   {
    temp=temp->left;
   }
   cout<<"\nminimum:"<<temp->data;
}


void tree ::max(node* root)
{
   temp=root;
   while(temp->right!=NULL)
   {
    temp=temp->right;
   }
   cout<<"\nmaximum node is "<<temp->data;
}


void tree::search(node*root)
{
  int n;
  cout<<"\nEnter the node to search";
  cin>>n;
  temp=root;
  int flag=0;
  while(temp!=NULL)
  {
    if(temp->data==n)
    {
       cout<<"\nNode is  found";
       flag=1;
       break;
    }
    else{
      if(temp->data>n)
      {
        temp=temp->left;      }
        else{
          temp=temp->right;
        }
    }
  }
  if(flag==0)
  {
    cout<<"\nNode is  not found ";
  }
}

void tree::mirroring(node* root)
{
  
  if(root!=NULL)
  {
    temp3=root->left;
    root->left=root->right;
    root->right=temp3;
    mirroring(root->left);
    mirroring(root->right);

  }
}
int tree::countleaf(node* root)
{
  if(root==NULL)
    return 0;
   else if(root->right==NULL &&root->left==NULL)
   {
    return 1;
   }
   else
   {
    return(countleaf(root->left)+countleaf(root->right));
   }
}

int tree::height(node* root)
{
  if(root==NULL)
  {
    return(0);
  }
   if(root->left==NULL && root->right==NULL)
  {
    return(0);

  }
     h1=height(root->left);
     h2=height(root->right);
     if(h1>h2)
     {
      return(h1+1);

     }
     else
     {
        return(h2+1);
     }
}
int main()
{

 tree t1;
int n,m;
int count;
char ch;
do
{
cout<<"\n1.Insert node \n2.Display tree\n3.Search node\n4.Minimum node\n5.Maximum node\n6.Count leaf node \n7.Mirroring the nodes \n8.Height of the tree\n";
cout<<"Enter your choice ";
cin>>n;
switch(n)
    {
      case 1:
        cout<<" \nTotal number of node you want to enter ";
        cin>>m;
        for(int i=0;i<m;i++)
        {
            t1.bst();

        }
          break;
         case 2:
                t1.display(t1.root);
                break;

        case 3:
          t1.search(t1.root);
          break;

          case 4:
                  t1.min(t1.root);
                  break;
          case 5:
                  t1.max(t1.root);
                  break;
          case 6:
                  
                  count= t1.countleaf(t1.root);
                  cout<<"\nLeaf node:"<<count;
                   
                   break;
          case 7:
                    t1.mirroring(t1.root);
                     t1.display(t1.root);
                     break;
            case 8:
                  t1.height(t1.root);
                  cout<<"\nthe height of the tree is "<<1+t1.height(t1.root);
                  break;
          default:
                cout<<"\nEnter valid choice ";


      
    }
    cout<<"\nDo you want to continue (y/n) ";
    cin>>ch;

}while(ch=='y');
return(0);
}