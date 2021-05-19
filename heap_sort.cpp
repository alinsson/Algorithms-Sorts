/*HEAP SORT
**Tem um desempenho em tempo de execu��o muito bom em conjuntos ordenados aleatoriamente, tem um uso
**de mem�ria bem comportado e o seu desempenho em pior cen�rio � praticamente igual ao desempenho em
**cen�rio m�dio. Alguns algoritmos de ordena��o r�pidos t�m desempenhos espectacularmente ruins no pior
**cen�rio, quer em tempo de execu��o, quer no uso da mem�ria. O Heapsort trabalha no lugar e o tempo de
**execu��o em pior cen�rio para ordenar n elementos � de O (n lg n). L�-se logaritmo (ou log) de "n"
**na base 2. Para valores de n, razoavelmente grande, o termo lg n � quase constante, de modo que o
**tempo de ordena��o � quase linear com o n�mero de itens a ordenar.
**O heapsort utiliza uma estrutura de dados chamada heap, para ordenar os elementos a medida que os
**insere na estrutura. Assim, ao final das inser��es, os elementos podem ser sucessivamente removidos
**da raiz da heap, na ordem desejada, lembrando-se sempre de manter a propriedade de max-heap.
**A heap pode ser representada como uma �rvore (uma �rvore bin�ria com propriedades especiais[2]) ou
**como um vetor. Para uma ordena��o crescente, deve ser constru�do um heap m�ximo (o maior elemento
**fica na raiz). Para uma ordena��o decrescente, deve ser constru�do um heap m�nimo(o menor elemento
**fica na raiz).
**Complexidade no pior, m�dio e melhor caso: Teta(nlogn)
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
