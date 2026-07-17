# Linked Lists in C – Singly & Circular Linked Lists

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Data%20Structures](https://img.shields.io/badge/Data%20Structures-Linked%20Lists-orange.svg)

A C project demonstrating the implementation of **Singly Linked Lists** and **Circular Linked Lists** through a real-world taxi reservation system.

This project was developed as part of a **Data Structures** practical assignment and demonstrates how dynamic memory allocation can be used to create flexible collections of objects without fixed-size arrays.

---

## 📖 Overview

Traditional arrays require a predefined size and contiguous memory allocation.

**Linked Lists** solve this limitation by dynamically allocating memory for each element. Each element (called a **node**) stores data and a pointer to the next node.

This project uses two different linked list types:

- **Singly Linked List**
  - Stores all taxis in the company.
  - Supports insertion, deletion, searching and updating.

- **Circular Linked List**
  - Stores reserved taxis currently in service.
  - The last node points back to the first node, making continuous rotation easy.

---

# Why use Linked Lists?

Instead of creating an array like:

```c
Taxi taxis[100];
```

where the maximum number of taxis must be known in advance, we can create taxis dynamically:

```c
Node *head = NULL;

head = add_taxi(head, "12345-A", "Toyota", 1);
head = add_taxi(head, "87562-B", "Dacia", 1);
head = add_taxi(head, "45678-C", "Hyundai", 0);
```

Each call allocates memory using:

```c
malloc(sizeof(Node))
```

which means the list can grow as much as available memory allows.

---

# Node Structure

Each taxi is represented by a node.

```c
struct Node {
    char num_plaque[20];
    char model[20];
    int available;
    struct Node *next;
};
```

Where:

| Field | Description |
|--------|-------------|
| num_plaque | Taxi license plate |
| model | Taxi model |
| available | 1 = Available, 0 = Reserved |
| next | Pointer to next node |

---

# Singly Linked List

The list of available taxis is implemented as:

```
Head
 │
 ▼
+------+     +------+     +------+
|Taxi1 | --> |Taxi2 | --> |Taxi3 | --> NULL
+------+     +------+     +------+
```

Supported operations:

- Add taxi
- Remove taxi
- Search taxi
- Update taxi
- Print available taxis
- Print unavailable taxis
- Print all taxis

---

# Circular Linked List

Reserved taxis are stored inside a circular linked list.

Unlike a normal linked list, the last node points back to the first one.

```
      +---------+
      |         |
      ▼         |
+------+ --> +------+ --> +------+
|Taxi1 |     |Taxi2 |     |Taxi3 |
+------+ <-- +------+ <-- +------+
```

This structure is useful for:

- Round-robin scheduling
- Process scheduling
- Multiplayer games
- Music playlists
- Taxi dispatch systems

The taxi rotation never reaches NULL.

---

# Project Features

## Part 1 – Singly Linked List

✔ Add taxis

✔ Remove taxis

✔ Update taxi information

✔ Search taxis

✔ Display available taxis

✔ Display unavailable taxis

✔ Display all taxis

---

## Part 2 – Circular Linked List

✔ Reserve a taxi

✔ Cancel reservation

✔ Display reserved taxis

✔ Continuous taxi rotation

---

# Dynamic Memory Allocation

Each new taxi is created dynamically:

```c
Node *new_node = (Node *)malloc(sizeof(Node));
```

When a taxi is removed, its memory is released:

```c
free(node);
```

This avoids memory leaks and allows unlimited list size.

---

# Advantages of Linked Lists

- Dynamic size
- Efficient insertion
- Efficient deletion
- No wasted memory
- No need to shift elements
- Easy implementation of queues and stacks
- Excellent for dynamic applications

---

# Complexity

| Operation | Time Complexity |
|------------|----------------|
| Insert at end | O(n) |
| Search | O(n) |
| Delete | O(n) |
| Update | O(n) |
| Print | O(n) |

---

# Project Structure

```
.
├── main.c
├── functions.c
├── functions.h
└── README.md
```

---

# Example

```c
Node *head = NULL;
Node *reserved = NULL;

head = add_taxi(head, "AA-123", "Toyota", 1);
head = add_taxi(head, "BB-456", "Dacia", 1);
head = add_taxi(head, "CC-789", "Hyundai", 1);

print_all_taxis(head);

reserved = reservation(head, reserved, "BB-456");

print_reserved_taxis(reserved);
```

---

# Educational Objectives

This project demonstrates:

- Dynamic memory allocation
- Pointer manipulation
- Structures in C
- Singly Linked Lists
- Circular Linked Lists
- CRUD operations
- Real-world implementation of linked lists

---

# Practical Application

The taxi management system follows the assignment specifications:

- Available taxis are stored in a **Singly Linked List**.
- Reserved taxis are stored in a **Circular Linked List** to simulate continuous vehicle rotation for dispatching. :contentReference[oaicite:0]{index=0}

---

# Future Improvements

- Save data to files
- Sort taxis by model
- Search by multiple criteria
- Queue of customer requests
- Graphical user interface
- Multi-threaded reservation system

---

# License

This project is released under the MIT License.

---

## Author

**Imourig**

GitHub: https://github.com/musta-007