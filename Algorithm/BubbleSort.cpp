#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort(&v[0], v.size());
    printArray(&v[0], v.size());
    return 0;
}