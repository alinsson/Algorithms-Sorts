/*HEAP SORT
**Tem um desempenho em tempo de execução muito bom em conjuntos ordenados aleatoriamente, tem um uso
**de memória bem comportado e o seu desempenho em pior cenário é praticamente igual ao desempenho em
**cenário médio. Alguns algoritmos de ordenação rápidos têm desempenhos espectacularmente ruins no pior
**cenário, quer em tempo de execução, quer no uso da memória. O Heapsort trabalha no lugar e o tempo de
**execução em pior cenário para ordenar n elementos é de O (n lg n). Lê-se logaritmo (ou log) de "n"
**na base 2. Para valores de n, razoavelmente grande, o termo lg n é quase constante, de modo que o
**tempo de ordenação é quase linear com o número de itens a ordenar.
**O heapsort utiliza uma estrutura de dados chamada heap, para ordenar os elementos a medida que os
**insere na estrutura. Assim, ao final das inserções, os elementos podem ser sucessivamente removidos
**da raiz da heap, na ordem desejada, lembrando-se sempre de manter a propriedade de max-heap.
**A heap pode ser representada como uma árvore (uma árvore binária com propriedades especiais[2]) ou
**como um vetor. Para uma ordenação crescente, deve ser construído um heap máximo (o maior elemento
**fica na raiz). Para uma ordenação decrescente, deve ser construído um heap mínimo(o menor elemento
**fica na raiz).
**Complexidade no pior, médio e melhor caso: Teta(nlogn)
*/

void heap_sort(int n, int v[]);
void heap(int v[], int root, int bottom);

void heap_sort(int n, int v[])
{
    int i, temp;

    for (i = (n / 2); i >= 0; i--)
        heap(v, i, n - 1);

    for (i = n-1; i >= 1; i--)
    {
        temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heap(v, 0, i-1);
  }
}


void heap(int v[], int p, int n)
{
    int done, maxChild, temp;
    done = 0;
    while ((p*2 <= n) && (!done))
    {
    if (p*2 == n)
        maxChild = p * 2;

    else if (v[p * 2] > v[p * 2 + 1])
        maxChild = p * 2;

    else
        maxChild = p * 2 + 1;

    if (v[p] < v[maxChild])
    {
        temp = v[p];
        v[p] = v[maxChild];
        v[maxChild] = temp;
        p = maxChild;
    }

    else
        done = 1;
  }
}
