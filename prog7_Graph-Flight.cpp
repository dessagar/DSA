
#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class graph_matrix
{
    public:
        int dist[20][20],num,x,conn_name,weight;
        char a[7][50],ch;
        
        graph_matrix()
        {
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<7;j++)
                {
                    a[i][j] = 0;
                }
            }
        }
        void add()
        {
            cout<<"\n\tEnter the number of cities: ";
            cin>>num;
            for(int i=1;i<=num;i++)
            {
                cout<<"\n\t\tEnter the name of city:"<<i<<":";
                cin>>a[i];
            }
        }
        void route()
        {
            for(int i=1; i<=num; i++)
            {
                for(int j=i; j<=num; j++)
                {
                    if(i==j)
                    {
                        dist[i][j] = 0;
                    }
                    else{
                        cout<<"\nIs there flight path between cities "<<i<<"and"<<j<<"?(y/n): ";
                        cin>>ch;
                        if(ch=='y' || ch=='Y')
                        {
                            cout<<"Enter distance between City Airports(in kms): ";
                            cin>>dist[i][j];
                            dist[j][i] = dist[i][j];
                        }
                        else{
                            dist[i][j] = dist[j][i] = -1;
                        }
                    }
                }
            }
        }
        void display()
        {
            cout<<"\nDistance Matrix:\n";
            for(int i=1;i<=num;i++)
            {
                cout<<"\t";
                cout<<a[i]; //to print the city name
            }
            cout<<endl;
            for(int i=1;i<=num;i++)
            {
                cout<<a[i];
                for(int j=1;j<=num;j++)
                {
                    cout<<"\t"<<dist[i][j];
                }
                cout<<endl;
            }
        }
}m;

int main()
{
    char ch;
    while(true)
    {
        cout<<"---Operation Menu---";
        cout<<"\n\t1. Enter data";
        cout<<"\n\t2. Display Routes";
        cout<<"\n\t3. Exit";
        cout<<"\n\tEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 49:
                m.add();
                m.route();
                break;
            case 50:
                m.display();
                break;
            case 51:
                exit(0);
            default:
                cout<<"Invalid choice!!";
        }
    }
    return 0;
}



// https://justpaste.it/jp7
