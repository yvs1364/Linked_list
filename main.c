#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
typedef struct List List;

#define PRESENT(list, element)({        \
 if(list == NULL || element == NULL){   \
        exit(EXIT_FAILURE);             \
    }                                   \
})                                      \

struct Element{
    int data;
    Element *next;
};

struct List{
    Element *first;
};


List *init();
int sizeOfList(List *list);
void insert(List *list, int newdata);
void InsertInList(List *list);
void deleteFirst(List *list);
void deleteInList(List *list);
void destroyList(List *list);
void showList(List *list);
void replaceInList(List *list);


int main() {
    List *myList = init();


    for(int i=1; i<10; i++){
        insert(myList, i+7);
        showList(myList);
    }
    printf("------------------------------------\n");
    replaceInList(myList);
    showList(myList);
    printf("Il y a %i d'element dans la list\n", sizeOfList(myList));
    printf("------------------------------------\n");
    InsertInList(myList);
    showList(myList);
    printf("Il y a %i d'element dans la list\n", sizeOfList(myList));
    printf("------------------------------------\n");
    deleteInList(myList);
    showList(myList);
    printf("Il y a %i d'element dans la list\n", sizeOfList(myList));

    destroyList(myList);

    return 0;
}

List *init() {
    // Initiliase la liste chainee
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

   PRESENT(list,element);
    element->data = 0;          // Initialise le premier élement à 0;
    element->next = NULL;       // Met le prochain élement à NULL pour annoncer la fin
    list->first   = element;    // Met l'element initialisé en premier position de la liste

    return list;
}

void insert(List *list, int newdata) {
    Element *new = malloc(sizeof(*new));
    PRESENT(list,new);
    new->data = newdata;        // Pointe le nouvel Element vers son futur successeur
    new->next = list->first;    // Fait pointer le prochain Element vers le first Element
    list->first = new;          // Fait pointer le point first vers le nouvel Element

}

void InsertInList(List *list) {
    Element *temp = list->first, *new = malloc(sizeof(*new));
    int newdata, position, i=0;
    PRESENT(list,new);

    printf("Quel valeur voulez-vous rajouter : ");
    scanf("%d", &newdata);

    printf("Entre la position de l'element a ajouter : ");
    scanf("%d", &position);

     while(temp != NULL) {          // Itere sur temp
        if(i == position-1){        // jusqu'a que i == position-1
            new->data = newdata;    // Stock la nouvel data dans la nouvelle struct element
            new->next = temp->next; // L'element suivant de la nouvelle struct devient le prochain element qui a été temporise
            temp->next = new;       // L'element suivant temporise devient le nouvelle element
        }
        temp = temp->next;
        ++i;
    }
}

void replaceInList(List *list) {
    Element *new = list->first, *temp;
    int newdata, position, i=0;
    PRESENT(list,new);

    printf("Quel valeur voulez-vous rajouter : ");
    scanf("%d", &newdata);

    printf("Entre la position de l'element a remplacer : ");
    scanf("%d", &position);

     while(new != NULL) {
        if(i == position-1){
            temp = new->next;       // Temporise le next element de la list dans la var temp
            new->next= temp->next;    // Pointe le nouvel Element vers son futur successeur
            new->data = newdata;
        }
        new = new->next;
        i++;
    }
}

void deleteFirst(List *list) {
    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    if(list->first != NULL) {
        Element *toDelete = list->first;
        list->first = list->first->next;
        free(toDelete);
    }
}

void deleteInList(List *list) {
    int position, i=0;
    Element *current = list->first;
    Element *temp;

    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Entre la position de l'element a supprimer : ");
    scanf("%d", &position);
    while(current != NULL) {
        if(i == position-1){
            temp = current->next;           // Temporise le prochain element de la list dans temp
            current->next = temp->next;     // Défini le prochain element de current
            free(temp);
        }
        current = current->next;
        i++;
    }
    printf("\n");
}

void destroyList(List *list) {
    while(list->first != NULL) {
        Element *toDelete = list->first;
        list->first = list->first->next;
        free(toDelete);
    }
    list = NULL;
    if(list == NULL) {
       printf("La liste a ete detruite\n");
    }

}

void showList(List *list) {
    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;

    printf("{ ");
    while (current != NULL){
        printf("(%d) -> ", current->data);
        current = current->next;
    }
    printf("NULL }\n");

}

int sizeOfList(List *list) {
    int sizeList = 0;
    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    while (current != NULL){
        sizeList++;
        current = current->next;
    }

    return sizeList;
}