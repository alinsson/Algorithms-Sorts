/*BUBBLE SORT
**O bubble sort, ou ordena��o por flutua��o (literalmente "por bolha"), � um algoritmo de ordena��o dos mais simples. A ideia � percorrer o vector
**diversas vezes, a cada passagem fazendo flutuar para o topo o maior elemento da sequ�ncia. Essa movimenta��o lembra a forma como as bolhas em um
**tanque de �gua procuram seu pr�prio n�vel, e disso vem o nome do algoritmo. No melhor caso, o algoritmo executa n2 opera��es relevantes, onde n
**representa o n�mero de elementos do vector. No pior caso, s�o feitas n2 opera��es. A complexidade desse algoritmo � de Ordem quadr�tica. Por isso,
**ele n�o � recomendado para programas que precisem de velocidade e operem com quantidade elevada de dados.
**Complexidade do pior e m�dio caso: O(n^2) e o melhor caso: O(n).
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
