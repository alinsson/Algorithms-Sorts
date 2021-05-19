/*SELECTION SORT
**O selection sort(do ingl�s, ordena��o por sele��o) � um algoritmo
**de ordena��o baseado em se passar sempre o menor valor do vetor
**para a primeira posi��o (ou o maior dependendo da ordem requerida),
**depois o de segundo valor para a segunda posi��o, e assim � feito
**sucessivamente com (n - 1) elementos restantes, at� os �ltimos
**dois elementos.
**Complexidade do pior, m�dio e melhor caso: O(n^2).
*/

void selection_sort(int tam, int num[]);

void selection_sort(int tam, int num[])
{
    int i, j, min;

    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }

        if (i != min)
        {
            int swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
}
