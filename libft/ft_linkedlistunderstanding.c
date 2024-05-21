/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlistunderstanding.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:11:44 by abeh              #+#    #+#             */
/*   Updated: 2024/05/21 15:32:43 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in the linked list
typedef struct node {
    int data; // The data stored in the node
    struct node *next; // A pointer to the next node in the list
} node_t;

// Function to print the elements of the linked list
void print_list(node_t *head) {
    node_t *current = head; // Start at the head of the list
    while (current!= NULL) { // Loop until we reach the end of the list
        printf("%d -> ", current->data); // Print the data in the current node
        current = current->next; // Move to the next node
    }
    printf("NULL\n"); // Print a null terminator to indicate the end of the list
}

int main() {
    node_t *head = NULL; // Initialize the head of the list to null
    node_t *second = NULL; // Initialize the second node to null
    node_t *third = NULL; // Initialize the third node to null

    // Allocate memory for the nodes
    head = malloc(sizeof(node_t));
    second = malloc(sizeof(node_t));
    third = malloc(sizeof(node_t));

    // Assign data values to the nodes
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // Link the nodes together
    head->next = second; // The head node points to the second node
    second->next = third; // The second node points to the third node
    third->next = NULL; // The third node points to null, indicating the end of the list

    // Print the list
    print_list(head);

    // Free the memory used by the list
    free(head);
    free(second);
    free(third);

    return 0;
}