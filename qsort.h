#ifndef QSORT_H
#define QSORT_H

#include<stdbool.h>

typedef struct __list {
  int data;
  struct __list *next;
} list;

list *q_new(int);
void q_insert(list *, int);
void q_free(list *);
void q_show(list*);
bool q_compare(list *, int *, int);
bool qs_compare(list *, list *);
list *sort(list *, int);
#endif
