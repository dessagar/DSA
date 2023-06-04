#include<iostream>
#define MAX 100
using namespace std;

class graph1
{
    int nov,noe,g_matrix[10][10],i,j,weight;
    public:
        graph1();
        void get_graph1();
        void print_graph1();
};
graph1::graph1()
{
    nov=0;
    noe=0;
    for(i=0; i<10 ;i++)
    {
        for(j=0; j<10 ; j++)
        {
            g_matrix[i][j]=0;
        }
    }
}

void graph1:: get_graph1()
{
    char c;
    cout<<"\nENTER THE NUMBER OF VERTICES:";
    cin>>nov;
    
    for(i=0;i<nov;i++)
    {
        for(j=0;j<nov;j++)
        {
            if(i==j) //since self loops are not allowed in graphs.
                break;
            else
            {
                cout<<"IF EDGE PRESENT BETWEEN "<<i<<" AND "<<j<<" THEN ENTER Y:";
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    cout<<"\nEnter The Weight of the Edge:";
                    cin>>weight;
                    g_matrix[i][j]=weight;
                    g_matrix[j][i]=weight;
                }
                else
                {
                    g_matrix[i][j]=0;
                }
            }
        }
    }
}
void graph1 :: print_graph1()
{
    cout<<"ADJECENCY MATRIX:"<<endl;
    for(i=0;i<nov;i++)
    {
        for(j=0;j<nov;j++)
        {
            cout<<g_matrix[i][j]<<"\t";
        }
           cout<<endl;
    }
}

class graph_node
{
    public:
        int vertex;
        graph_node *next;
        graph_node();
};

graph_node::graph_node()
{
    vertex=0;
    next=NULL;
}

class graph
{
    private:
        graph_node *headnode[MAX];
        int nov;
    public:
        void create();
        void display();
};

void graph::create()
{
    int noc;
    graph_node *curr,*prev;
    cout<<"ENTER THE NUMBER OF VERTICES: ";
    cin>>nov;
    for(int i=0;i<nov;i++)
    {
        headnode[i]=new graph_node;
        prev=headnode[i];
        headnode[i]->vertex=i+1;
        cout<<"ENTER THE NUMBER OF VERTICES CONNCETED TO THE VERTEX "<<i+1<<":";
        cin>>noc;
        for(int i=0;i<noc;i++)
        {
            curr=new graph_node;
            cout<<"ENTER THE NODE CONNECTED TO THE VERTEX:\n ";
            cin>>curr->vertex;
            curr->next=NULL;
            prev->next=curr;
            prev=curr;
        }
    }
}
void graph::display()
{
    graph_node *temp= new graph_node;
    for(int i=0;i<nov;i++)
    {
        temp=headnode[i];
        while(temp!=NULL)
        {
            cout<<temp->vertex<<"-->";
            temp=temp->next;
        }cout<<"NULL\n";
    }
}

int main()
{
    int n;
    char ans;

    do
    {
        cout<<"\nGraph REPRESENTATION USING \n1.LIST\n2.MATRIX\nENTER YOUR CHOICE:";
        cin>>n;
        switch(n)
        {
            case 1: 
                graph G;
                G.create();
                G.display();
                break;
            case 2: 
                graph1 obj1;
                obj1.get_graph1();
                obj1.print_graph1();
                break;
        }
        cout<<"DO YOU WANT TO CONTINUE(Y/N)";
        cin>>ans;
    }while(ans=='y'|| ans=='Y');
    return 0;
}


// https://justpaste.it/jp6




