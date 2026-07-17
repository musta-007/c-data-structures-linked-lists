#ifndef FUN_H_
#define FUN_H_

typedef struct Node Node;

Node* add_taxi(Node* head, const char* num_plaque, const char* model, const int available);
Node* remove_taxi(Node* head, const char* num_plaque);
Node* find_taxi(Node* head, const char* num_plaque);
Node* update_taxi(Node* head, const char* num_plaque, const char* new_model, const int new_available);  
void print_taxis_available(Node* head);
void print_taxis_unavailable(Node* head);
void print_all_taxis(Node* head);
void free_taxis(Node* head, Node* start);
Node* reservation(Node* head, Node* start, const char* num_plaque);
Node* cancel_reservation(Node* head, Node* start, const char* num_plaque);
void print_reserved_taxis(Node* start);

#endif