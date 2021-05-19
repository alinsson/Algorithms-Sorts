#include<stdlib.h>
#include<iostream>

using namespace std;

void selection_sort(int tam, int num[]);

int main(void){
    int n;
    int *A;

    cout << "\n\tDigite a quantidade de elementos: ";
    cin >> n;

    A = (int*)malloc(n * sizeof(int));

    if(A == NULL){
        cout << "\n\tMemoria Insuficiente!";
        exit(1);
    }

    cout << endl;
    for(int i = 0;i < n; i++)
    {
         cout << "\tElemento numero " << i+1 << ": ";
         cin >> A[i];
    }

    cout << "\n\tARRAY:";
    for(int i = 0; i < n; i++)
        cout << "\t" << A[i];
    cout << "\n";

    selection_sort(n, A);

    cout << "\n\tSORT:";
    for(int i = 0; i < n; i++)
        cout << "\t" << A[i];
    cout << "\n";

	 free(A);
	 return 0;
}

void selection_sort(int tam, int num[])
{
    int i, j, max;

    for (i = tam-1; i >= 0; i--)
    {
        max = i;
        for (j = i-1; j >= 0; j--)
        {
            if (num[j] > num[max])
            {
                max = j;
            }
        }

        if (i != max)
        {
            int swap = num[i];
            num[i] = num[max];
            num[max] = swap;
        }
    }
}
