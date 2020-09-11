#include <stdio.h>

#include "list.h"

int main()
{
    printf("Tests...\n");
    printf("Allocating memory...\n");
    list_t *list_test = list_alloc(4);
    printf("Add elements...\n");
    list_add_to_front(list_test, 1);
    list_add_to_front(list_test, 2);
    list_add_to_front(list_test, 3);
    list_add_to_back(list_test, 4);
    list_add_to_back(list_test, 5);
    list_add_to_back(list_test, 6);
    list_add_at_index(list_test, 10, 1);
    list_print(list_test);
    int length = list_length(list_test);
    printf("Length: %d\n", length);
    printf("Remove from back...\n");
    list_remove_from_back(list_test);
    list_print(list_test);
    printf("Remove front...\n");
    list_remove_from_front(list_test);
    list_print(list_test);
    printf("Removing at index 2...\n");
    list_remove_at_index(list_test, 2);
    list_print(list_test);
    printf("Check if 10 is in list...\n");
    bool is10in = list_is_in(list_test, 10);
    printf("%s\n", is10in ? "true" : "false");
    printf("Check if 4 is in list...\n");
    bool is4in = list_is_in(list_test, 4);
    printf("%s\n", is4in ? "true" : "false");
    printf("Get index of 5...\n");
    int index = list_get_index_of(list_test, 5);
    printf("%d\n", index);
    elem elementat5 = list_get_elem_at(list_test, 5);
    printf("Element at index 5 is %d\n", elementat5);

    return 0;
}