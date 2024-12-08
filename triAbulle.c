#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Element Element ;
struct Element{
    short int valeur;
    Element *suivant;
};


void append(Element **head, short int valeur){

    Element *element = malloc(sizeof(Element));
    element->valeur = valeur;
    element->suivant = NULL;

    if(*head == NULL){
        *head = element;
        return ;
    }else{
        Element *tmp = *head;
        while(tmp->suivant!=NULL){
            tmp = tmp->suivant;
        }
        tmp->suivant = element;
    }

}

void triAbulle(Element *tete){
    Element *ptr1;
    Element *lptr = NULL ; //Pour marquer la fin de la liste

    bool swapped;
    do{
        swapped = false;
        ptr1 = tete;

        while(ptr1->suivant != lptr){
            if(ptr1->valeur > ptr1->suivant->valeur){
                int tmp = ptr1->suivant->valeur;
                ptr1->suivant->valeur = ptr1->valeur;
                ptr1->valeur = tmp;
                swapped = true;
            }
            ptr1=ptr1->suivant;
        }
        lptr=ptr1;
    }while(swapped);
}

void afficher(Element *head){
    Element *tmp = head;

    while(tmp!=NULL){
        printf("%d -> ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}

int main(){

    Element *head = NULL ;
    append(&head,10);
    append(&head,20);
    append(&head,30);
    append(&head, 5);
    append(&head, 15);
    append(&head, 25);
    append(&head, 35);

    printf("Affichage avant le tri a bulle :\n\t");
    afficher(head);
    printf("Affichage apres le tri a bulle :\n\t");
    triAbulle(head);
    afficher(head);
    return 0;
}
