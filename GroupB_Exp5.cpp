/*
Experiment No 5: Write a function template for Selection sort that inputs, sorts and outputs
an integer array and a float array.
*/

#include <iostream>
using namespace std;

#define max 100
int n;

template <class T>
void selectionSort(T A[max]) // Function template for Selection Sort
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int int_arr[max];
    float float_arr[max];
    int i;
    int ch;
    do
    {
        cout << "\n    SELECTION SORT SYSTEM";
        cout << "\n           MENU";
        cout << "\n 1. Sort for Integer Values";
        cout << "\n 2. Sort for Float Values";
        cout << "\n 3. Exit";
        cout << "\n\nEnter your choice (1-3): ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter no. of integer numbers to be sorted: ";
            cin >> n;
            cout << "\nEnter integer numbers (press enter after each number): " << endl;
            for (i = 0; i < n; i++)
            {
                cin >> int_arr[i];
            }
            selectionSort(int_arr);
            break;

        case 2:
            cout << "\nEnter no. of float numbers to be sorted (press enter after each number): ";
            cin >> n;
            cout << "\nEnter float numbers: " << endl;
            for (i = 0; i < n; i++)
            {
                cin >> float_arr[i];
            }
            selectionSort(float_arr);
            break;

        case 3:
            cout << "Program ended";
            exit(0);
        }
    } while (ch != 3);

    return 0;
}
