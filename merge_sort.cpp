/*MERGE SORT
**O merge sort, ou ordenação por mistura, é um exemplo de algoritmo do
**tipo dividir-para-conquistar. Sua idéia básica é muito fácil: criar
**uma sequência ordenada a partir de duas outros também ordenadas.
**Para isso, ele divide a sequência original em pares de dados,
**ordena-as, depois as agrupa em sequências de quatro elementos, e
**assim por diante, até ter toda a sequência dividida em apenas duas
**partes.
**Os três passos úteis dos algoritmos dividir-para-conquistar, ou divide
**and conquer, que se aplicam ao merge sort são:
**1. Dividir: Divider os dados em subsequências pequenas;
**2. Conquistar: Juntar as duas metades recursivamnete aplicando o merge sort;
**3. Combinar: Juntar as duas metades em um único conjunto já classificado.
**Complexidade do pior, médio e melhor caso: Teta(nlogn).
*/

void merge_sort(int p, int r, int v[]);
void merge(int p, int q, int r, int v[]);

void merge_sort(int p, int r, int v[])
{
    if(p < r-1)
    {
        int q = (p + r)/2;
        merge_sort(p, q, v);
        merge_sort(q, r, v);
        merge(p, q, r, v);
    }
}

void merge(int p, int q, int r, int v[])
{
    int i, j, k, *w;

    w = (int*)malloc((r-p) * sizeof(int));
    for (i = 0, k = p; k < q; ++i, ++k)
        w[i] = v[k];
    for (j = r-p-1, k = q; k < r; --j, ++k)
        w[j] = v[k];

    i = 0;
    j = r - p - 1;

    for (k = p; k < r; ++k)
        if (w[i] <= w[j])
            v[k] = w[i++];
        else
            v[k] = w[j--];

    free(w);
}
/*
void merge_sort(int n, int v[])
{
    int p, r;
    int b = 1;

    while(b < n)
    {
        p = 0;
        while(p + b < n)
        {
            r = p + 2*b;
            if(r > n)
                r = n;

            merge(p, p+b, r, v);
            p = p + 2*b;
        }

        b = 2*b;
    }
}

void merge(int p, int q, int r, int v[])
{
    int i, j, k;
    int *w;

    w = (int*)malloc((r-p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r) {
        if (v[i] <= v[j])  w[k++] = v[i++];
        else  w[k++] = v[j++];
    }

    while(i < q)
        w[k++] = v[i++];

    while(j < r)
        w[k++] = v[j++];

    for(i = p; i < r; ++i)
        v[i] = w[i-p];

    free(w);
}
*/

