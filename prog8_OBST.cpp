#include<iostream>
using namespace std;
#define INT_MAX 100


int sum(int freq[], int i, int j);

int optCost(int freq[], int i, int j)
{
    if (j < i)
        return 0; //range is invalid
    if (j == i)
        return freq[i];

    int fsum = sum(freq, i, j);

    int min = INT_MAX;
    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
        if (cost < min)
            min = cost;
    }
    return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    return optCost(freq, 0, n-1);
}

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
    s += freq[k];
    return s;
}

int main()

{
    // int keys[] = {10, 12, 20};
    // int freq[] = {34, 8, 50};
    
    int i,j,rec,keys[10],freq[10];
    cout<<"How many records you want to insert in tree ? : ";
    cin>>rec;
    
    for(i=0;i<rec;i++)
    {
        cout<<"\tEnter key for Record "+i+1;
        cin>>keys[i];
        cout<<"\tEnter frequency for Record "+(i+1);
        cin>>freq[i];
    }
    
    
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<"Cost of Optimal BST is "<<
    optimalSearchTree(keys, freq, n);
    return 0;
}


// The given code is an implementation of the Optimal Binary Search Tree problem using dynamic programming. 

// 1. The code includes the necessary header file `iostream` and defines the macro `INT_MAX` as 100.
// 2. There is a function prototype for `sum`, which calculates the sum of frequencies between indices `i` and `j`.
// 3. The `optCost` function calculates the cost of the optimal binary search tree for a given range of keys.
// It takes an array `freq` representing the frequencies of keys and the indices `i` and `j` representing the range.
// 4. The base cases are checked: if `j` is less than `i`, the range is invalid, and 0 is returned. If `j` is equal to `i`, the frequency at index `i` is returned.
// 5. The function calculates the sum of frequencies in the given range using the `sum` function.
// 6. It initializes a variable `min` to store the minimum cost and sets it to `INT_MAX`.
// 7. It iterates over all possible roots within the given range (`r` from `i` to `j`).
// 8. For each root, it recursively calculates the cost of the left and right subtrees using the `optCost` function.
// 9. The total cost of the tree with the current root is the sum of the costs of the left and right subtrees plus the frequency sum.
// 10. If the current cost is smaller than the minimum cost (`min`), it updates `min` with the current cost.
// 11. After iterating over all possible roots, it returns the minimum cost plus the frequency sum.
// 12. The `optimalSearchTree` function takes an array of keys, an array of frequencies, and the number of elements `n`. It calls the `optCost` function to calculate the optimal cost of the binary search tree.
// 13. The `sum` function calculates the sum of frequencies between indices `i` and `j` using a loop.
// 14. In the `main` function, the user is prompted to enter the number of records (`rec`) they want to insert into the tree.
// 15. It then loops over the number of records and prompts the user to enter the key and frequency for each record, storing them in the `keys` and `freq` arrays.
// 16. The size of the `keys` array is determined using the `sizeof` operator, and the `optimalSearchTree` function is called with the arrays and their sizes.
// 17. The result is printed as the cost of the optimal binary search tree.
// 18. The program ends with a return statement.
 
// In summary, this code calculates the optimal cost of a binary search tree given keys and their frequencies using dynamic programming and recursion.



// https://justpaste.it/8jp
