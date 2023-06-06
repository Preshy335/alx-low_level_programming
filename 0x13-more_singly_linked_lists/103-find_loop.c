#include <stdio.h>
#include <stdlib.h>

/* Define the structure for listint_t */
typedef struct listint_s {
    int data;
    struct listint_s *next;
} listint_t;

/* Function to add a new node at the beginning of a listint_t list */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        perror("malloc failed");
        return NULL;
    }

    new_node->data = n;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}

int main()
{
    listint_t *head = NULL;  // Initialize an empty list

    // Add nodes to the list
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);

    // Print the list
    listint_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}

