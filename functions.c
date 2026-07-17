#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    char num_plaque[20];
    char model[20];
    int available; // 0 = not available, 1 = available
    struct Node* next;
};

//-----------------------------------------------------Partie 1-----------------------------------------------------
Node* add_taxi(Node* head, const char* num_plaque, const char* model, const int available)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    strncpy(new_node->num_plaque, num_plaque, sizeof(new_node->num_plaque) - 1);
    new_node->num_plaque[sizeof(new_node->num_plaque) - 1] = '\0'; // Ensure null-termination

    strncpy(new_node->model, model, sizeof(new_node->model) - 1);
    new_node->model[sizeof(new_node->model) - 1] = '\0'; // Ensure null-termination

    new_node->available = available;
    new_node->next = NULL;

    if(head == NULL)
        head = new_node;
    else
    {
        Node* current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
    }

    return head;
}

Node* remove_taxi(Node* head, const char* num_plaque)
{
    if (head == NULL) {
        printf("The list is empty. Cannot remove taxi.\n");
        return NULL;
    }
    else if (strcmp(head->num_plaque, num_plaque) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    } else {
        Node* current = head;
        while (current->next != NULL && strcmp(current->next->num_plaque, num_plaque) != 0) {
            current = current->next;
        }
        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            printf("Taxi with plaque number %s not found.\n", num_plaque);
        }
    }
    return head;
}

Node* find_taxi(Node* head, const char* num_plaque)
{
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->num_plaque, num_plaque) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Taxi not found
}

Node* update_taxi(Node* head, const char* num_plaque, const char* new_model, const int new_available)
{
    Node* taxi = find_taxi(head, num_plaque);
    if (taxi != NULL) {
        strncpy(taxi->model, new_model, sizeof(taxi->model) - 1);
        taxi->model[sizeof(taxi->model) - 1] = '\0'; // Ensure null-termination
        taxi->available = new_available;
    } else {
        printf("Taxi with plaque number %s not found.\n", num_plaque);
    }
    return head;
}

void print_taxis_available(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        if (current->available == 1) {
            printf("Taxi Plaque: %s, Model: %s\n", current->num_plaque, current->model);
        }
        current = current->next;
    }
}

void print_taxis_unavailable(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        if (current->available == 0) {
            printf("Taxi Plaque: %s, Model: %s\n", current->num_plaque, current->model);
        }
        current = current->next;
    }
}

void print_all_taxis(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        printf("Taxi Plaque: %s, Model: %s, Available: %d\n", current->num_plaque, current->model, current->available);
        current = current->next;
    }
}

void free_taxis(Node* head, Node* start)
{
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    current = start;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

//-----------------------------------------------------Partie 2-----------------------------------------------------
Node* reservation(Node* head, Node* start, const char* num_plaque)
{
    Node* taxi = find_taxi(head, num_plaque);
    if (taxi != NULL) {
        if (taxi->available == 1) {
            taxi->available = 0; // Mark as not available
            Node* new_node = (Node*)malloc(sizeof(Node));
            if (new_node == NULL) {
                printf("Memory allocation failed.\n");
                return start;
            }
            strncpy(new_node->num_plaque, taxi->num_plaque, sizeof(new_node->num_plaque) - 1);
            new_node->num_plaque[sizeof(new_node->num_plaque) - 1] = '\0'; // Ensure null-termination
            strncpy(new_node->model, taxi->model, sizeof(new_node->model) - 1);
            new_node->model[sizeof(new_node->model) - 1] = '\0'; // Ensure null-termination
            new_node->available = taxi->available;
            Node* ptr = start;
            if (ptr == NULL) {
                start = new_node; // If the reserved list is empty, set start to the new node
                new_node->next = start;
            } else {
                new_node->next = start;
                while (ptr->next != start) {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                start = new_node; // Update start to point to the new node
            }
            printf("Taxi with plaque number %s has been reserved.\n", num_plaque);
        } else {
            printf("Taxi with plaque number %s is already reserved.\n", num_plaque);
        }
    } else {
        printf("Taxi with plaque number %s not found.\n", num_plaque);
    }
    return start;
}

Node* cancel_reservation(Node* head, Node* start, const char* num_plaque)
{
    Node* taxi = find_taxi(head, num_plaque);
    if (taxi != NULL) {
        if (taxi->available == 0) {
            taxi->available = 1; // Mark as available
            Node* current = start;
            Node* prev = NULL;
            while (current != NULL && strcmp(current->num_plaque, num_plaque) != 0) {
                prev = current;
                current = current->next;
            }
            if (current != NULL) {
                if (prev == NULL) {
                    start = current->next; // Update start if the first node is removed
                } else {
                    prev->next = current->next; // Bypass the node to be removed
                }
                free(current);
                printf("Reservation for taxi with plaque number %s has been canceled.\n", num_plaque);
            } else {
                printf("Taxi with plaque number %s is not in the reserved list.\n", num_plaque);
            }
        } else {
            printf("Taxi with plaque number %s is not reserved.\n", num_plaque);
        }
    } else {
        printf("Taxi with plaque number %s not found.\n", num_plaque);
    }
    return start;
}

void print_reserved_taxis(Node* start)
{
    Node* current = start;
    if (current == NULL) {
        printf("No taxis are currently reserved.\n");
        return;
    }
    do {
        printf("Reserved Taxi Plaque: %s, Model: %s\n", current->num_plaque, current->model);
        current = current->next;
    } while (current != start);
}