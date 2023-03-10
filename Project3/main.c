#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



typedef struct file {
    char name[256];
    char *creation_time;
    struct file *next;
    int size;
} File;

typedef struct node {
    char name[256];
    int size;
    int is_dir;
    char *creation_time;
    struct node *next;
    struct node *child;
    struct file *files;
} Node;


Node *root = NULL;



File *create_file(Node *directory, char *name) {
    if (directory == NULL) {
        printf("NULL DIRECTORY!!!!");
    }

    //get time
    time_t now = time(NULL);
    char *timeNow = ctime(&now);
    char *newline = strchr(timeNow, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    // make pointers
    File *current_file = malloc(sizeof(File));

    // set file attributes
    strcpy(current_file->name, name);
    current_file->creation_time = timeNow;
    current_file->size = rand();

    return current_file;
}

void add_to_list(Node *head, Node *node_to_add) {
    if (head == NULL) {
        head = node_to_add;
    } else {
        Node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = node_to_add;
    }
}

// If is_directory is 0 its a directory, if its 1 its a file
Node *create_node(char *name, int is_directory) {
    Node *node = malloc(sizeof(Node));

    time_t now = time(NULL);
    char *timeNow = ctime(&now);

    strcpy(node->name, name);
    node->creation_time = timeNow;
    node->is_dir = is_directory;
    node->child = NULL;
    node->next = NULL;
    node->files = NULL;

    return node;
}

void print_list(Node *head) {
    Node *pointer = head->next;
    while (pointer != NULL) {
        printf("Name of file: %s\n", pointer->name);
        pointer = pointer->next;
    }
    printf("\n");
}

void print_files(Node directory) {
    File *pointer = directory.files;

    while (pointer != NULL) {
        printf("Name of file: %s\n", pointer->name);
        printf("Date of Creation: %s\n", pointer->creation_time);
        printf("Size: %lu\n", pointer->size);
        pointer = pointer->next;
    }
    printf("\n");
}

// traverse through linked list
void add_child(Node *parent, Node *child) {

    if (parent == NULL || child == NULL) return;

    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node *pointer = parent->child;

        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->child = child;
    }
}

void delete_node(Node *head, Node *node_to_be_deleted) {
    Node *pointer = head;

    char *to_be_found = node_to_be_deleted->name;

    while (pointer->next != NULL) {
        char *name = pointer->next->name;
        if (strcmp(name, to_be_found) == 0) {
            break;
        }
        pointer = pointer->next;
    }
}


    void delete_file(File *head, char *to_be_found) {
        File *prev = head;
        File *curr = head->next;

        if (prev == NULL) {
            return;
        }

        if (strcmp(prev->name, to_be_found) == 0) {
            head = curr;
            free(prev);
            return;
        }

        while (curr != NULL && strcmp(curr->name, to_be_found) != 0) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }




    int main(int argc, char *argv[]) {
        root = malloc(sizeof(Node));
        char *command[10];
        char *file;



        Node *node1 = create_node("Randy", 1);
        File *pointer = node1->files;
        File *file1 =create_file(node1, "file1");
        add
        printf("Name: %s\n", file1->name);
        printf("Date created: %s\n", file1->creation_time);
        printf("size: %d\n", file1->size);







        return 0;
    }

