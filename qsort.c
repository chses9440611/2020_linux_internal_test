#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

list *q_new(int d)
{
    list *tmp = malloc(sizeof(list));
    tmp->data = d;
    tmp->next = NULL;
    return tmp;
}

// void q_insert(list* target, int d)
//{
//	target->next = malloc(sizeof(list));
//	target = target->next;
//	target->data = d;
//	target->next = NULL;
//}

void q_free(list *head)
{
    while (head != NULL) {
        list *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void q_show(list *target)
{
    while (target != NULL) {
        printf("%d ", target->data);
        target = target->next;
    }

    printf("\n");
}

bool q_compare(list *target, int *ans, int size)
{
    for (int i = 0; i < size; i++) {
        if (target == NULL)
            return false;
        if (target->data != ans[i])
            return false;

        target = target->next;
    }

    if (target)
        return false;

    return true;
}

bool qs_compare(list *q1, list *q2)
{
    while ((q1 != NULL) && (q2 != NULL)) {
        if (q1->data != q2->data) {
            printf("Data inconsistece\n");
            return false;
        }
        q1 = q1->next;
        q2 = q2->next;
    }
    if (q1 != NULL) {
        printf("q2 is Shorter\n");
        return false;
    }
    if (q2 != NULL) {
        printf("q1 is Shorter\n");
        return false;
    }

    return true;
}

list *sort(list *start, int version)
{
    if (!start || !start->next)
        return start;
    list *left = start;
    list *right = left->next;
    left->next = NULL;

    left = sort(left, version);
    right = sort(right, version);

    for (list *merge = NULL; left || right;) {
        if (!right || (left && left->data < right->data)) {
            if (!merge) {
                if (version == 0)
                    start = merge = left;
                else
                    merge = left;
            } else {
                merge->next = left;
                merge = merge->next;
            }
            left = left->next;
        } else {
            if (!merge) {
                start = merge = right;
            } else {
                merge->next = right;
                merge = merge->next;
            }
            right = right->next;
        }
    }
    return start;
}
