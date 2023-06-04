//Threaded Binary Tree

#include<iostream>
using namespace std;

class node 
{
  public :
	int data;
	int lth,rth;
	node *right,*left;
};

class TBT 
{	
	public:
	    node * root,* head;
	
	TBT() //constructor
    {
		head = new node;
		head->right = head;
		head->left = head;
		head->lth = 0;
		head->rth = 1;
		root = NULL;
	}
	void create();
	void inorder();
	node * inorderSucc(node *);
};

void TBT :: create()
 {
	   node *temp,*curr;
		curr = new node;
		cout<<"\n Enter the data : ";
		cin>>curr->data;
		
		curr->right = NULL;
		curr->left = NULL;
		curr->lth = 0;
		curr->rth = 0;

		if(root == NULL) 
		{
          root = curr;
	       root->right =head;
		    root->left = head;
		    head->left = root;
		    head->lth = 1;	
		} 
        else 
		{
			temp = root;
			while(1) 
			{
                if(curr->data<temp->data)
                {				
                    if(temp->lth == 0) 
                    {
	                    curr->left = temp->left;		
	                    curr->right = temp;
	                    temp->lth = 1;
                        temp->left = curr;	
	                    break;	
	                } 
	                else 
	                {
	                    temp = temp->left;
	                }
                } 
                else 
                {				
                    if(temp->rth == 0) 
                    {
                        curr->right = temp->right;
                        curr->left = temp;
                        temp->rth = 1;
	                    temp->right = curr;
	                    break;
	                } 
	                else 
	                {					    
	                    temp = temp->right;	
	                }
                }
            }     				
        }
}

void TBT :: inorder() 
{
	node* temp;
	temp = head;
	do
    {
        temp = inorderSucc(temp);
        if(temp!= head)
	       cout<<temp->data<<" ";
	}while(temp != head);
}

node * TBT :: inorderSucc(node * temp) 
{
	node * p;
	p = temp->right;
	if(temp->rth == 1) 
	{
		while(p->lth == 1) 
		{
		    p = p->left;
	    }
	}
	return p;	
}

int main() 
{
	TBT t;
	int num;
	char ch;
	
	while(true)
	{
	cout<<"\n1.Create a binary tree ";
	cout<<"\n2.Inorder traversal  ";
	cout<<"\n3.Exit";
	
	cout<<"\nEnter choice : ";
	cin>>ch;
	
	switch(ch)
	{
	    case 49:
	        cout<<"\nEnter total nodes in a tree : ";
	        cin>>num;
	        for(int i=0;i<num;i++)
	        {
	            t.create();
	        }
	        break;
	    case 50:
	        cout<<"\nInorder traversal is : ";
	        t.inorder();
	        break;
	   case 51:
	        cout<<"\nEnd of program";
	        exit(0);
	   default:
	        cout<<"\nEnter valid choice";
	}
	
  }
return 0;
}



// https://justpaste.it/jp5


