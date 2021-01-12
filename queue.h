#ifndef queue_h
#define queue_h

struct Cell {
    int value;
    Cell *next;
};

struct QueueList {
    Cell *head;
    int lenght;
    Cell *tail;
};

QueueList *QueueList_new();
int QueueList_lenght(QueueList *l);
void QueueList_delete(QueueList *l);
void QueueList_print(QueueList * l);
void QueueList_pushback(QueueList *l, int x);
int QueueList_popback(QueueList *l);
void QueueList_pushfront(QueueList *l,int v);
int QueueList_popfront(QueueList *l);
QueueList *QueueList_Merge(QueueList *A, QueueList *B);
QueueList *QueueList_copy (QueueList *l);
void reverse_print_cell(Cell *c);
void rec_print_cell(Cell *c);
void QueueList_reverse_print(QueueList *l);
void QueueList_recoursive_print(QueueList *l);
QueueList * QueueList_from_array(int a[], int c);
int * array_from_list(QueueList *l);
void selectionSort(int arr[], int n);
void QueueList_Sort(QueueList *l);
#endif 
