// list/list.c
//
// Implementation for linked list.
//
// Alonte Cuffee

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


list_t *list_alloc()
{
    list_t *t = (list_t *)malloc(sizeof(list_t));
    return t;
}


void list_free(list_t *l)
{
    node_t *node = l->head;
    while (node != NULL)
    {
        node_t *temp = node;
        node = node->next;
        free(temp);
    }
    free(node);
    return;
}


void list_print(list_t *l)
{
    node_t *t = l->head;
    while (t)
    {
        printf("%d \n", t->value);
        t = t->next;
    }
}


int list_length(list_t *l)
{
    node_t *t = l->head;
    int length = 0;

    if (t == NULL)
    { // if there isnt a list
        return -1;
    }

    while (t != NULL)
    {
        length++;
        t = t->next;
    }
    return length;
}


void list_add_to_back(list_t *l, elem value)
{
    node_t *t = malloc(sizeof(node_t));
    t->value = value;
    t->next = NULL;
    if (l->head == NULL)
    {
        l->head = t;
    }
    else
    {
        node_t *ptr = l->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = t;
    }
}


void list_add_to_front(list_t *l, elem value)
{
    node_t *t = l->head;
    l->head = (node_t *)malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = t;
}


void list_add_at_index(list_t *l, elem value, int index)
{

    if (index == 0)
    {
        list_add_to_front(l, value);
    }

    node_t *currNode = l->head;

    int i = 0;
    for (i = 0; i < index - 1; i++)
    {

        if (currNode->next == NULL)
        {
            return;
        }

        currNode = currNode->next;
    }

    node_t *t = (node_t *)malloc(sizeof(node_t));

    t->value = value;
    t->next = currNode->next;
    currNode->next = t;
}


elem list_remove_from_back(list_t *l)
{

    elem value;
    if (l->head == NULL)
    {
        return -1;
    }

    if (l->head->next == NULL)
    {
        value = l->head->value;
        free(l->head);
        return value;
    }

    node_t *currNode = l->head;

    while (currNode->next->next != NULL)
    {
        currNode = currNode->next;
    }

    value = currNode->next->value;
    free(currNode->next);
    currNode->next = NULL;
    return value;
}


elem list_remove_from_front(list_t *l)
{
    elem value;
    if (l->head == NULL)
    {
        return -1;
    }

    node_t *t = l->head->next;
    value = l->head->value;
    free(l->head);
    l->head = t;

    return value;
}


elem list_remove_at_index(list_t *l, int index)
{
    elem value;
    if (index == 0)
    {
        return list_remove_from_front(l);
    }

    node_t *currNode = l->head;
    node_t *t = NULL;

    int i = 0;
    for (i = 0; i < index - 1; i++)
    {

        if (currNode->next == NULL)
        {
            return -1;
        }
        currNode = currNode->next;
    }

    t = currNode->next;
    value = t->value;
    currNode->next = t->next;
    free(t);

    return value;
}


bool list_is_in(list_t *l, elem value)
{

    node_t *currNode = l->head;

    while (currNode != NULL)
    {

        if (currNode->value == value)
        {
            return true;
        }
        currNode = currNode->next;
    }

    return false;
}


elem list_get_elem_at(list_t *l, int index)
{

    node_t *currNode = l->head;

    int i = 0;
    for (i = 0; i < index; i++)
    {

        if (currNode->next == NULL)
        {
            return -1;
        }
        currNode = currNode->next;
    }

    return currNode->value;
}


int list_get_index_of(list_t *l, elem value)
{

    int i = 0;
    node_t *currNode = l->head;

    while (currNode != NULL)
    {

        if (currNode->value == value)
        {
            return i;
        }
        i++;
        currNode = currNode->next;
    }

    return -1;
}
