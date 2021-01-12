
#include "queue.h"
#include <iostream>
#include <string>

int main(){
    QueueList *q= QueueList_new();
    QueueList_pushback(q,5);
    QueueList_pushback(q,4);
    QueueList_pushback(q,6);
    QueueList_pushback(q,3);
    QueueList_pushback(q,7);
    QueueList_print(q);
    std::cout << "Ora provo la stampa con il sort " << std::endl;
    QueueList_Sort(q);
    QueueList_print(q);
    QueueList_delete(q);
}
