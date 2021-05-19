/*INSETION SORT
**O insertion sort, ou ordenação por inserção, é um simples algoritmos
**de ordenação, eficiente quando aplicado a um pequeno número de
**elementos. Em termos gerais, ele percorre um vetor de elementos da
**esquerda para a direita e à medida que avança vai deixando os
**elementos mais à esquerda ordenados. O algoritmo de inserção funciona
**da maneira com que muitas pessoas ordenam carta em um jogo de baralho
**como pôquer. Ele é Estável.
**Complexidade do pior e médio caso: O(n^2) e do melhor caso: O(n)
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
