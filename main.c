#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

int *random_array(int);
void show_numbers(int *, int);
void bubble_sort(int *, int);
void swap(int *a, int *b);
list *q_insert_lot(list *, int *, int);
int main()
{
    int scores = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        int *numbers = random_array(LENGTH);
        if (numbers == NULL) {
            printf("The %d-th malloc failed!\n", i);
            break;
        }
        show_numbers(numbers, LENGTH);

        list *q_tail, *q2_tail;
        q_tail = q2_tail = NULL;
        list *q_head = q_insert_lot(q_tail, numbers, LENGTH);
        list *q2_head = q_insert_lot(q2_tail, numbers, LENGTH);

        bubble_sort(numbers, LENGTH);

        q_head = sort(q_head, 0);
        q2_head = sort(q2_head, 1);

        printf("Queue1 after sort: ");
        q_show(q_head);

        printf("Queue2 after sort: ");
        q_show(q2_head);
        printf("Are two queues same?\n");
        if (qs_compare(q_head, q2_head)) {
            printf("Same queues\n");
            scores++;
        } else {
            printf("Different queues\n");
            break;
        }

        printf("Compare queue1 and array with same result: ");
        if (q_compare(q_head, numbers, LENGTH))
            printf("Same\n");
        else
            printf("Different\n");

        free(numbers);
        q_free(q_head);
        q_free(q2_head);
        printf("-----------------------\n");
    }
    printf("The total scores: %d/100\n", scores);
    return 0;
}

int *random_array(int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (tmp == NULL) {
        printf("Malloc int array fail!\n");
        return NULL;
    }
    int i;
    for (i = 0; i < size; i++)
        tmp[i] = rand() % 100;

    return tmp;
}

void show_numbers(int *array, int length)
{
    int i;
    printf("The array numbers are: ");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}

list *q_insert_lot(list *tail, int *data, int length)
{
    int i;
    list *tmp;
    tmp = tail = q_new(data[0]);
    if (!tail) {
        printf("Insert first node failed\n");
        return NULL;
    }

    for (i = 1; i < length; i++) {
        tail->next = q_new(data[i]);
        if (!tail->next) {
            printf("Insert %d-th node failed\n", i);
            q_free(tmp);
            return NULL;
        }
        tail = tail->next;
    }

    return tmp;
}

void bubble_sort(int *numbers, int length)
{
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 1; j < length - i; j++) {
            if (numbers[j - 1] > numbers[j])
                swap(&numbers[j - 1], &numbers[j]);
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
