/*RADIX SORT
**O Radix sort é um algoritmo de ordenação rápido e estável que pode ser usado para ordenar itens que estão identificados por chaves únicas. Cada chave
**é uma cadeia de caracteres ou número, e o radix sort ordena estas chaves numa qualquer ordem relacionada com a lexicografia. Na ciência da computação,
**radix sort é um algoritmo de ordenação que ordena inteiros processando dígitos individuais. Como os inteiros podem representar strings compostas de
**caracteres (como nomes ou datas) e pontos flutuantes especialmente formatados, radix sort não é limitado somente a inteiros. Computadores, na sua
**maioria, representam internamente todos os tipo de dados como números binários, por isso processar os dígitos na forma de inteiros em grupos
**representados por dígitos binários se torna mais conveniente. Existem duas classificações do radix sort, que são:
**- Least significant digit (LSD – Dígito menos significativo) radix sort;
**- Most significant digit (MSD – Dígito mais significativo) radix sort.
**O radix sort LSD começa do dígito menos significativo até o mais significativo, ordenando tipicamente da seguinte forma: chaves curtas vem antes de
**chaves longas, e chaves de mesmo tamanho são ordenadas lexicograficamente. Isso coincide com a ordem normal de representação dos inteiros, como a
**seqüência "1, 2, 3, 4, 5, 6, 7, 8, 9, 10". Os valores processados pelo algoritmo de ordenação são frequentemente chamados de “chaves”, que podem
**existir por si próprias ou associadas a outros dados. As chaves podem ser strings de caracteres ou números. Já o radix sort MSD trabalha no sentido
**contrário, usando sempre a ordem lexicográfica, que é adequada para ordenação de strings, como palavras, ou representações de inteiros com tamanho
**fixo. A seqüência "b, c, d, e, f, g, h, i, j, ba" será ordenada lexicograficamente como "b, ba, c, d, e, f, g, h, i, j". Se essa ordenação for usada
**para ordenar representações de inteiros com tamanho variável, então a representação dos números inteiros de 1 a 10 terá a saída "1, 10, 2, 3, 4, 5, 6,
**7, 8, 9". O radix sort LSD opera na notação Big O, em O(nk), onde "n" é o número de chaves, e "k" é o comprimento médio da chave. É possível garantir
**esse desempenho para chaves com comprimento variável agrupando todas as chaves que tem o mesmo comprimento e ordenando separadamente cada grupo de
**chaves, do mais curto para o mais comprido, de modo a evitar o processamento de uma lista inteira de chaves em cada passo da ordenação. Em muitas
**aplicações em que é necessário velocidade, o radix sort melhora as ordenações por comparação, como heapsort e o mergesort, que necessitam de
**Teta(nlogn) comparações, onde "n" é o número de itens a serem ordenados. Em compensação, algoritmos de ordenação baseados em comparações oferecem
**flexibilidade por serem aptos a ordenar de outras formas que não a lexicográfica. No entanto, essa habilidade é de pouca importância em várias
**aplicações práticas. O algoritmo de ordenação radix foi originalmente usado para ordenar cartões perfurados. Um algoritmo computacional para o radix
**sort foi inventado em 1954 no MIT por Harold H. Seward.
**Complexidade do pior, médio e melhor caso: Teta(nk).
*/
void radix_sort(int n, int a[]);

void radix_sort(int n, int a[])
{
    int i,b[n],m=0,exp=1, j = 1;
    for(i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];
    }

    while(m/exp>0)
    {
        int bucket[10]={0};

        for(i=0;i<n;i++)
            bucket[a[i]/exp%10]++;
        for(i=1;i<10;i++)
            bucket[i]+=bucket[i-1];
        for(i=n-1;i>=0;i--)
            b[--bucket[a[i]/exp%10]]=a[i];
        for(i=0;i<n;i++)
            a[i]=b[i];
        exp*=10;
        j++;
    }
}
