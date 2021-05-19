#include<stdlib.h>
#include<iostream>

using namespace std;
#define MAX 10 //N�mero M�ximo de digitos que o inteiro pode ter
#define SHOWPASS

void print(int *a,int n) //Fun��o que percorre o vetor e imprime o mesmo.
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
}

void radixsort(int *a,int n)//Fun��o de ordena��o radix sort.
{
    int i,b[n],m=0,exp=1, j = 1;
    for(i=0;i<n;i++) //Guarda o maior valor digitado
    {
        if(a[i]>m)
            m=a[i];
    }

    while(m/exp>0) //Condi��o enquanto existir casa decimal unit�ria.
    {
        int bucket[10]={0}; //Vetor de 10 espa�os todos preenchidos com 0, como se fosse uma caixa com n�meros de 0 a 9.

        for(i=0;i<n;i++) //Percorre o vetor adicionando +1, onde o indice significa o n�mero.
            bucket[a[i]/exp%10]++;
        for(i=1;i<10;i++) //Adiciona pesos ao vetor.
            bucket[i]+=bucket[i-1];
        for(i=n-1;i>=0;i--) //Percorre o vetor de tr�s para frente ordenando.
            b[--bucket[a[i]/exp%10]]=a[i];
        for(i=0;i<n;i++) //Vetor a recebe a ordena��o.
            a[i]=b[i];
        exp*=10; //Incrementa a condi��o, de forma a percorrer a pr�xima casa decimal.
#ifdef SHOWPASS
        cout<<"\nPASSO "<<j<<": "; //Imprime o passo junto com o n�mero dele.
        print(a,n); //Utiliza a fun��o de imprimir.
        j++; //incrementa o passo
#endif
    }
}

int main(void)
{
    int arr[MAX];
    int i,n;
    cout<<"Entre com o total de elementos ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Entre com o elemento "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"\nARRAY  : ";
    print(&arr[0],n); //Imprime o vetor digitado
    radixsort(&arr[0],n); //Ordena e Imprime o Vetor digitado
    cout<<"\nSORTED : ";
    print(&arr[0],n); //Imprime o vetor ordenado.
    cout<<"\n";

    return 0;
}
