#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

typedef struct DLinkListNode {
    int val;
    struct DLinkListNode *prev, *next;
} DLinkListNode;

typedef struct {
    DLinkListNode *head, *tail;
    int capacity;
    int size;
} MyCircularDeque;

DLinkListNode *dLinkListNodeCreat(int val) {
    DLinkListNode *obj = (DLinkListNode *) malloc(sizeof(DLinkListNode));
    obj->val = val;
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}

MyCircularDeque *myCircularDequeCreate(int k) {
    MyCircularDeque *obj = (MyCircularDeque *) malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->size = 0;
    obj->head = obj->tail = NULL;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    DLinkListNode *node = dLinkListNodeCreat(value);
    if (obj->size == 0) {
        obj->head = obj->tail = node;
    } else {
        node->next = obj->head;
        obj->head->prev = node;
        obj->head = node;
    }
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    DLinkListNode *node = dLinkListNodeCreat(value);
    if (obj->size == 0) {
        obj->head = obj->tail = node;
    } else {
        obj->tail->next = node;
        node->prev = obj->tail;
        obj->tail = node;
    }
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj) {
    if (obj->size == 0) {
        return false;
    }
    DLinkListNode *node = obj->head;
    obj->head = obj->head->next;
    if (obj->head) {
        obj->head->prev = NULL;
    }
    free(node);
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj) {
    if (obj->size == 0) {
        return false;
    }
    DLinkListNode *node = obj->tail;
    obj->tail = obj->tail->prev;
    if (obj->tail) {
        obj->tail->next = NULL;
    }
    free(node);
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->head->val;
}

int myCircularDequeGetRear(MyCircularDeque *obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->tail->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque *obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque *obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque *obj) {
    for (DLinkListNode *curr = obj->head; curr;) {
        DLinkListNode *node = curr;
        curr = curr->next;
        free(node);
    }
    free(obj);
}