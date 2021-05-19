/*BUBBLE SORT
**O bubble sort, ou ordenação por flutuação (literalmente "por bolha"), é um algoritmo de ordenação dos mais simples. A ideia é percorrer o vector
**diversas vezes, a cada passagem fazendo flutuar para o topo o maior elemento da sequência. Essa movimentação lembra a forma como as bolhas em um
**tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo. No melhor caso, o algoritmo executa n2 operações relevantes, onde n
**representa o número de elementos do vector. No pior caso, são feitas n2 operações. A complexidade desse algoritmo é de Ordem quadrática. Por isso,
**ele não é recomendado para programas que precisem de velocidade e operem com quantidade elevada de dados.
**Complexidade do pior e médio caso: O(n^2) e o melhor caso: O(n).
*/

void bubble_sort(int qtd, int v[]);
void swapbubble(int i, int v[]);

void bubble_sort(int qtd, int v[])
{
    int i, trocou;
    do
    {
        qtd--;
        trocou = 0;
        for(i = 0; i < qtd; i++)
            if(v[i] > v[i+1])
            {
                swapbubble(i, v);
                trocou = i;
            }
    }while(trocou);
}

void swapbubble(int i, int v[])
{
    int aux = 0;
    aux = v[i];
    v[i] = v[i+1];
    v[i+1] = aux;
}
