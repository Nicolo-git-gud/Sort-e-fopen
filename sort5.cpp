#include "queue.h"
#include <iostream>
#include <string>

int main(){
    QueueList *q= QueueList_new();
    QueueList_pushback(q,2);
    QueueList_Sort(q);
    QueueList_print(q);
    QueueList_delete(q);
}
