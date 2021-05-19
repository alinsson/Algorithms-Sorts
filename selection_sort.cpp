/*SELECTION SORT
**O selection sort(do inglês, ordenação por seleção) é um algoritmo
**de ordenação baseado em se passar sempre o menor valor do vetor
**para a primeira posição (ou o maior dependendo da ordem requerida),
**depois o de segundo valor para a segunda posição, e assim é feito
**sucessivamente com (n - 1) elementos restantes, até os últimos
**dois elementos.
**Complexidade do pior, médio e melhor caso: O(n^2).
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
