/*RADIX SORT
**O Radix sort � um algoritmo de ordena��o r�pido e est�vel que pode ser usado para ordenar itens que est�o identificados por chaves �nicas. Cada chave
**� uma cadeia de caracteres ou n�mero, e o radix sort ordena estas chaves numa qualquer ordem relacionada com a lexicografia. Na ci�ncia da computa��o,
**radix sort � um algoritmo de ordena��o que ordena inteiros processando d�gitos individuais. Como os inteiros podem representar strings compostas de
**caracteres (como nomes ou datas) e pontos flutuantes especialmente formatados, radix sort n�o � limitado somente a inteiros. Computadores, na sua
**maioria, representam internamente todos os tipo de dados como n�meros bin�rios, por isso processar os d�gitos na forma de inteiros em grupos
**representados por d�gitos bin�rios se torna mais conveniente. Existem duas classifica��es do radix sort, que s�o:
**- Least significant digit (LSD � D�gito menos significativo) radix sort;
**- Most significant digit (MSD � D�gito mais significativo) radix sort.
**O radix sort LSD come�a do d�gito menos significativo at� o mais significativo, ordenando tipicamente da seguinte forma: chaves curtas vem antes de
**chaves longas, e chaves de mesmo tamanho s�o ordenadas lexicograficamente. Isso coincide com a ordem normal de representa��o dos inteiros, como a
**seq��ncia "1, 2, 3, 4, 5, 6, 7, 8, 9, 10". Os valores processados pelo algoritmo de ordena��o s�o frequentemente chamados de �chaves�, que podem
**existir por si pr�prias ou associadas a outros dados. As chaves podem ser strings de caracteres ou n�meros. J� o radix sort MSD trabalha no sentido
**contr�rio, usando sempre a ordem lexicogr�fica, que � adequada para ordena��o de strings, como palavras, ou representa��es de inteiros com tamanho
**fixo. A seq��ncia "b, c, d, e, f, g, h, i, j, ba" ser� ordenada lexicograficamente como "b, ba, c, d, e, f, g, h, i, j". Se essa ordena��o for usada
**para ordenar representa��es de inteiros com tamanho vari�vel, ent�o a representa��o dos n�meros inteiros de 1 a 10 ter� a sa�da "1, 10, 2, 3, 4, 5, 6,
**7, 8, 9". O radix sort LSD opera na nota��o Big O, em O(nk), onde "n" � o n�mero de chaves, e "k" � o comprimento m�dio da chave. � poss�vel garantir
**esse desempenho para chaves com comprimento vari�vel agrupando todas as chaves que tem o mesmo comprimento e ordenando separadamente cada grupo de
**chaves, do mais curto para o mais comprido, de modo a evitar o processamento de uma lista inteira de chaves em cada passo da ordena��o. Em muitas
**aplica��es em que � necess�rio velocidade, o radix sort melhora as ordena��es por compara��o, como heapsort e o mergesort, que necessitam de
**Teta(nlogn) compara��es, onde "n" � o n�mero de itens a serem ordenados. Em compensa��o, algoritmos de ordena��o baseados em compara��es oferecem
**flexibilidade por serem aptos a ordenar de outras formas que n�o a lexicogr�fica. No entanto, essa habilidade � de pouca import�ncia em v�rias
**aplica��es pr�ticas. O algoritmo de ordena��o radix foi originalmente usado para ordenar cart�es perfurados. Um algoritmo computacional para o radix
**sort foi inventado em 1954 no MIT por Harold H. Seward.
**Complexidade do pior, m�dio e melhor caso: Teta(nk).
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
