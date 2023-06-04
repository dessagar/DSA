#include<iostream>
using namespace std;

class hp
{
    int heap[20],heap1[20],x,n1,i;
    public:
        hp()
        {
            heap[0]=0; heap1[0]=0;
        }
        void getdata();
        void insert1(int heap[],int);
        void upadjust1(int heap[],int);//max-heap property
        void insert2(int heap1[],int);
        void upadjust2(int heap1[],int);//min-heap property
        void minmax();
};

void hp::getdata()
{
    cout<<"\nEnter the no. of students :\n ";
    cin>>n1;
    cout<<"\nEnter the marks :\n ";
    for(i=0;i<n1;i++)
    {
        cin>>x;
        insert1(heap,x);
        insert2(heap1,x);
    }
}

void hp::insert1(int heap[20],int x)
{
    int n;
    n=heap[0];
    heap[n+1]=x;
    heap[0]=n+1;
    upadjust1(heap,n+1);
}

void hp::upadjust1(int heap[20],int i)
{
    int temp;
    while(i>1&&heap[i]>heap[i/2])
    {
        temp=heap[i];
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        i=i/2;
    }
}

void hp::insert2(int heap1[20],int x)
{
    int n;
    n=heap1[0];
    heap1[n+1]=x;
    heap1[0]=n+1;
    upadjust2(heap1,n+1);
}

void hp::upadjust2(int heap1[20],int i)
{
    int temp1;
    while(i>1&&heap1[i]<heap1[i/2])
    {
        temp1=heap1[i];
        heap1[i]=heap1[i/2];
        heap1[i/2]=temp1;
        i=i/2;
    }
}

void hp::minmax()
{
    cout<<"\nMaximum marks : "<<heap[1];
    cout<<"\nMinimum marks : "<<heap1[1];
}

int main()
{
    hp h;
    h.getdata();
    h.minmax();
    return 0;
}




// This program represents a class `hp` that performs operations on two heaps (`heap` and `heap1`) to find the maximum and minimum marks among a group of students.

// Here's a breakdown of the program:

// 1. The class `hp` is defined, and two arrays `heap` and `heap1` are declared as private members, along with other variables `x`, `n1`, and `i`.

// 2. The constructor `hp()` initializes the first elements of `heap` and `heap1` to 0.

// 3. The member function `getdata()` is responsible for getting the number of students and their marks from the user. It prompts the user for the number of students (`n1`) and then asks for the marks of each student using a loop. For each mark, it calls the `insert1()` and `insert2()` functions to insert the mark into the two heaps.

// 4. The member function `insert1()` inserts an element (`x`) into the `heap` array. It first determines the current size of the heap (`n`) by accessing `heap[0]`, then adds the element at the next available index (`n+1`). After that, it increments `heap[0]` to reflect the increased size and calls the `upadjust1()` function to restore the heap property by adjusting the element upward if necessary.

// 5. The member function `upadjust1()` performs the up-heap adjustment for the `heap` array. It compares the element at index `i` with its parent and swaps them if the parent is smaller. This process continues until the element reaches its correct position in the heap or reaches the root.

// 6. The member function `insert2()` and `upadjust2()` work similarly to `insert1()` and `upadjust1()`, respectively, but they operate on the `heap1` array and maintain a min-heap property instead of a max-heap.

// 7. The member function `minmax()` prints the maximum and minimum marks by accessing the first elements of `heap` and `heap1`, respectively.

// 8. In the `main()` function, an instance `h` of the class `hp` is created. The `getdata()` function is called to input the data, and then `minmax()` is called to display the maximum and minimum marks.

// In summary, the program creates two heaps to store student marks, one maintaining a max-heap property and the other a min-heap property. It then finds and displays the maximum and minimum marks among the given set of students.


// https://justpaste.it/10jp
