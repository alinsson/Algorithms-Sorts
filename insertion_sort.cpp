/*INSETION SORT
**O insertion sort, ou ordena��o por inser��o, � um simples algoritmos
**de ordena��o, eficiente quando aplicado a um pequeno n�mero de
**elementos. Em termos gerais, ele percorre um vetor de elementos da
**esquerda para a direita e � medida que avan�a vai deixando os
**elementos mais � esquerda ordenados. O algoritmo de inser��o funciona
**da maneira com que muitas pessoas ordenam carta em um jogo de baralho
**como p�quer. Ele � Est�vel.
**Complexidade do pior e m�dio caso: O(n^2) e do melhor caso: O(n)
*/

void insertion_sort(int qnt, int a[]);

void insertion_sort(int qnt, int a[])
{
    int i, j;
    int chave;

    for (i = 0; i < qnt; i++)
    {
        chave = a[i];
        for (j = i-1; (j >= 0) && (a[j] > chave); j--)
        {
           a[j+1] = a[j];
        }

        a[j+1] = chave;
    }
}
