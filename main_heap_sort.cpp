#include<stdio.h>
#include<stdlib.h>
#include<iostream>

void peneira (int p, int m, int v[]);
void heapsort (int n, int v[]);

int main(){
   int n, *v, p;

   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &n);

   v = (int*)malloc(n*sizeof(int));
   if(v==NULL){
      printf("\nMemoria Insuficinte!!\n");
      exit(1);
   }

   //leitura do vetor...
   for(int i=1; i<=n; i++){
      printf("Digite o numero de v[%d]: ", i);
      scanf("%d", &v[i]);
   }

   //chamada da funcao heapsort
   printf("\n\n\nVetor ordenado pelo HEAPSORT:\n");
   for (p = n/2; p >= 1; --p)
      heapsort(n, v);

   //impressao do vetor ordenado...
   for(int i=1; i<=n; i++)
      printf("%d ", v[i]);

   free(v);
   return 0;
}


void peneira (int p, int n, int v[]){
    int f = 2*p, x;
    while (f <= n) {
        if (f < n && v[f] < v[f+1]){
              ++f;
        }

       // f é o filho "mais valioso" de p
       if (v[f/2] >= v[f]){
          break;
       }
       x = v[f/2];
       v[f/2] = v[f];
       v[f] = x;
       f *= 2;
    }
}

void heapsort (int n, int v[]){
   int p, m, x;
   for (p = n/2; p >= 1; --p)
      peneira (p, n, v);
   for (m = n; m >= 2; --m) {
      x = v[1];
      v[1] = v[m];
      v[m] = x;
      peneira (1, m-1, v);
   }
}
