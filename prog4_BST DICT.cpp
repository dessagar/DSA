#include<iostream>
using namespace std;


class node
{
    public:
        node *left,*right;
        int data;
        node()
        {
            left=right=NULL;
        }
};

class BST
{
    public:
        node *root;
        BST()
        {
            root=NULL;
        }
        int isempty()
        {
            return(root==NULL);
        }
        void insert();
        void pre_order(node* root);
        void in_order(node* root);
        void post_order(node* root);
        void search(node *,int);
        void min();
        void max();
        int height(node *root);
        void swap(node *root);
        node* getroot();
};

node* BST :: getroot()
{
    return root;
}

void BST::insert()
{
    node *temp=new node;
    node *parent=new node;
    node *curr=new node;
    
    cout<<"Enter the element";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    
    curr=root;
    parent=curr;
    
    if(isempty())
    {
        root=temp;
    }
    else
    {
        while(curr!=NULL)
        {
            if(temp->data<curr->data)
            {
                parent=curr;
                curr=curr->left;
            }
            else
            {
                parent=curr;
                curr=curr->right;
            }
        }
        if(temp->data<parent->data)
        {
            parent->left=temp;
        }
        else
        {
            parent->right=temp;
        }
    }
}
void BST::pre_order(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"\t";
        pre_order(root->left);
        pre_order(root->right);
    }
}
void BST::in_order(node *root)
{
    if(root!=NULL)
    {
        in_order(root->left);
        cout<<root->data<<"\t";
        in_order(root->right);
    }
}
void BST::post_order(node *root)
{
    if(root!=NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout<<root->data<<"\t";
    }
}
void BST::search(node *troot,int ele)
{
    node *temp1=new node;
    temp1=troot;
    if(root==NULL)
    {
        cout<<"Tree is empty";
    }
    if(temp1==NULL)
        cout<<"Element not found";
    else if(temp1->data>ele)
    {
        temp1=temp1->left;
        search(temp1,ele);
    }
    else if(temp1->data<ele)
    {
        temp1=temp1->right;
        search(temp1,ele);
    }
    else if(temp1->data==ele)
    {
        cout<<"Element found";
    }
}
void BST::min()
{
    node *root1=new node;
    root1=root;
    if(root==NULL)
    {
        cout<<"Tree is empty";
    }
    else
    {
        while(root1->left!=NULL)
        {
            root1=root1->left;
        }
        cout<<"Smallest element is:"<<root1->data;
    }
}
void BST::max()
{
    node *root1=new node;
    root1=root;
    if(root==NULL)
    {
        cout<<"Tree is empty";
    }
    else
    {
        while(root1->right!=NULL)
        {
            root1=root1->right;
        }
        cout<<"Largest element is:"<<root1->data;
    }
}
int BST::height(node *troot)
{
    if(troot==NULL)
        return 0;
    else
    {
        int ldepth=height(troot->left);
        int rdepth=height(troot->right);
        if(ldepth>rdepth)
            return(ldepth+1);
        else
            return(rdepth+1);
    }
}
void BST::swap(node *troot)
{
    node *temp;
    if(troot!=NULL)
    {
        temp=new node;
        temp=troot->left;
        troot->left=troot->right;
        troot->right=temp;
        swap(troot->left);
        swap(troot->right);
    }
}
int main()
{
    node *troot;
    BST b;
    char f;
    int ch;
    int e,res;
    do
    {
        cout<<" 1:Creating a BST\n 2:Pre-order Traversal\n 3:In-order Traversal\n 4:Post-OrderTraversal\n5:Search \n 6:min\n 7:max\n 8:Height\n 9:Mirror \n";
        cout<<"Enter your choice \n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                b.insert();
                break;
            case 2:
                b.pre_order(b.getroot());
                break;
            case 3:
                b.in_order(b.getroot());
                break;
            case 4:
                b.post_order(b.getroot());
                break;
            case 5:
                cout<<"Enter the element to be searched \n";
                cin>>e;
                b.search(b.getroot(),e);
                break;
            case 6:
                b.min();
                break;
            case 7:
                b.max();
                break;
            case 8:
                res=b.height(b.getroot());
                if(res==0)
                {
                    cout<<"NULL Tree";
                }
                else
                {
                    cout<<"The height of the tree is: "<<res;
                }
                break;
            case 9:
                b.swap(b.getroot());
                break;
            default:
                cout<<"Wrong choice";
        }
        cout<<" \n Do you want to continue?";
        cin>>f;
    }while(f=='y'||f=='Y');
    return 0;
}



// https://justpaste.it/jp4




