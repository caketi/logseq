#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printlist(node *head){
    node *temp = head;

    while( temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node *create_new_node(int value){
    node *result = malloc(sizeof(node));
    result->value = value;
    result->next = NULL;
    return result;
}

node *insert_at_head(node **head, node *nodeo_insert){
    nodeo_insert->next = *head;
    *head = nodeo_insert;
    return nodeo_insert;
}

void insert_after_node(node *nodeo_insert_after, node *newnode){
    nodeo_insert_after->next = newnode;
    newnode->next = nodeo_insert_after->next;
}

node *finde_node(node *head, int value){
    node *tmp = head;
    while(tmp!=NULL){
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void remove_value(node **head,int value){
    node *tmp = *head;

    if (*head != NULL && (*head)->value == value){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    while (tmp != NULL){
        if (tmp->next && tmp->next->value == value){
            node *result = tmp->next;
            tmp->next = tmp->next->next;
            free(result);
            return;
        }
        tmp = tmp->next;
    }
    return;
}