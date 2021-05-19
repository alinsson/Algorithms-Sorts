void selectionsort(Lista* l);

void selectionsort(Lista* l){
    Lista* lMin;
    Lista* lAux1;
    Lista* lAux2;

    for(lAux1 = l; lAux1->prox != NULL; lAux1 = lAux1->prox){
        lMin = lAux1;
        for(lAux2 = lAux1->prox; lAux2 != NULL; lAux2 = lAux2->prox){
            if(lAux2->info < lMin->info){
                lMin = lAux2;
            }
        }
        if(lAux1 != lMin){
            int swap = lAux1->info;
            lAux1->info = lMin->info;
            lMin->info = swap;
        }
    }
}
