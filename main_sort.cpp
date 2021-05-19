#include <stdlib.h>
#include <iostream>
#include <curses.h>

#include "print_sort.cpp"
#include "heap_sort.cpp"
#include "merge_sort.cpp"
#include "radix_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "selection_sort.cpp"
using namespace std;

int main(void){
    int a, b, n, op;
    int *A;

    cout << "\n\tDigite a quantidade de elementos para ordencao: ";
    cin >> n;

    A = (int*)malloc(n * sizeof(int));

    if(A == NULL){
       cout << "\n\tMemoria Insuficiente!";
       exit(1);
    }

    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "\tElemento numero " << i+1 << ": ";
        cin >> A[i];
    }

    do
    {
        cout << "\n\n\t|><><><><><><><  MENU  ><><><><><><><|\n"
                "\t|                                    |\n"
                "\t| (1) - Heap sort                    |\n"
                "\t| (2) - Merge sort                   |\n"
                "\t| (3) - Radix sort                   |\n"
                "\t| (4) - Bubble sort                  |\n"
                "\t| (5) - Selection sort               |\n"
                "\t| (6) - Insertion sort               |\n"
                "\t| (7) - Sair sem ordenar             |\n"
                "\t|                                    |\n"
                "\t|><><><><><><><><><><><><><><><><><><|\n\n"
                "\tQual o algoritmo de ordenacao: ";
        cin >> op;

        cout << "\n\tARRAY: ";
        for(int i = 0; i < n; i++)
            cout << "\t" << A[i];

        switch(op)
        {
            case 1: heap_sort(n, A);
                    print_sort(n, A);
                    break;

            case 2: cout << "\n\tDigite o indice do valor inicial (1, 2, ..., n-1, n): ";
                    cin >> a;
                    cout << "\n\tDigite o indice do valor final (1, 2, ..., n-1, n): ";
                    cin >> b;
                    merge_sort(a-1, b, A);
                    print_sort(n, A);
                    break;

            case 3: radix_sort(n, A);
                    print_sort(n, A);
                    break;

            case 4: bubble_sort(n, A);
                    print_sort(n, A);
                    break;

            case 5: selection_sort(n, A);
                    print_sort(n, A);
                    break;

            case 6: insertion_sort(n, A);
                    print_sort(n, A);
                    break;

            case 7: break;

            default: cout<<"\n\t***Opcao invalida, tente novamente***";
        }
    }while((op < 0)||(op > 7));

    free(A);
    return 0;
}
