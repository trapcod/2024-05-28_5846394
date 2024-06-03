#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* last;
} CircularLinkedList;

CircularLinkedList* create_list() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->last = NULL;
    return list;
}

int is_empty(CircularLinkedList* list) {
    return list->last == NULL;
}

void add_to_empty(CircularLinkedList* list, int data) {
    if (!is_empty(list)) return;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    list->last = new_node;
    list->last->next = list->last;
}

void add_to_beginning(CircularLinkedList* list, int data) {
    if (is_empty(list)) {
        add_to_empty(list, data);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->last->next;
    list->last->next = new_node;
}

void add_to_end(CircularLinkedList* list, int data) {
    if (is_empty(list)) {
        add_to_empty(list, data);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->last->next;
    list->last->next = new_node;
    list->last = new_node;
}

void delete_first_node(CircularLinkedList* list) {
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->last->next;
    if (list->last->next == list->last) {
        free(temp);
        list->last = NULL;
        return;
    }
    list->last->next = temp->next;
    free(temp);
}

void delete_last_node(CircularLinkedList* list) {
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->last->next;
    if (list->last->next == list->last) {
        free(list->last);
        list->last = NULL;
        return;
    }
    while (temp->next != list->last) {
        temp = temp->next;
    }
    temp->next = list->last->next;
    free(list->last);
    list->last = temp;
}

void print_list(CircularLinkedList* list) {
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->last->next;
    Node* head = list->last->next;
    do {
        printf("-> %d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    CircularLinkedList* list = create_list();
    int choice, data;

    while (1) {
        printf("\nMenu\n");
        printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
        printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
        printf("3. ����Ʈ ó�� ��� ����\n");
        printf("4. ����Ʈ ������ ��� ����\n");
        printf("5. ����Ʈ ����Ʈ\n");
        printf("6. ����\n");
        printf("�޴�����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("���� �Է�: ");
            scanf("%d", &data);
            add_to_beginning(list, data);
            break;
        case 2:
            printf("���� �Է�: ");
            scanf("%d", &data);
            add_to_end(list, data);
            break;
        case 3:
            delete_first_node(list);
            break;
        case 4:
            delete_last_node(list);
            break;
        case 5:
            print_list(list);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
