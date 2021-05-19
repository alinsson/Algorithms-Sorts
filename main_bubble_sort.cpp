#include<stdlib.h>
#include<iostream>

using namespace std;

void swapbubble(int v[],int i);
void buble(int v[],int qtd);
void exibenumeros(int v[],int qtd);

int main(void){
   int n;
   int *A;

   cout<<"\nDigite a quantidade de elementos: ";
   cin>>n;

   A=(int*)malloc(n*sizeof(int));

   if(A==NULL){
      cout<<"\nMemoria Insuficiente!";
      exit(1);
   }

   cout<<endl;
   for(int i=0;i<n;i++){
      cin>>A[i];
   }

   buble(A,n);
   exibenumeros(A,n);

   free(A);
}

void swapbubble(int v[],int i){
   int aux=0;
   aux=v[i];
   v[i]=v[i+1];
   v[i+1]=aux;
}

//BURBLE-SORT
void buble(int v[], int qtd){
   int i,trocou;
   do{
      qtd--;
      trocou=0;
      for(i=0;i<qtd;i++)
         if(v[i]>v[i+1]){
            swapbubble(v,i);
            trocou=i;
         }
   }while(trocou);
}

//IMPRIME VETORES
void exibenumeros(int v[],int qtd){
   cout<<"\nA ordenacao eh:";
   for(int i=0;i<qtd;i++)
      cout<<" "<<v[i];
}
