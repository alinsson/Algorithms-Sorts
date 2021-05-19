/*PRINT SORT
**Imprime na tela os vetores ordenados.
*/

void print_sort(int qnt, int vet[])
{
	 system("clear");	
	
    std::cout << "\n\tSORT:  ";
    for(int i = 0; i < qnt; i++)
        std::cout << "\t" << vet[i];
    std::cout << "\n";
}
