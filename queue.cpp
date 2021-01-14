
#include "queue.h"
#include <iostream>
#include <string>


QueueList *QueueList_new() {
    QueueList *l = new QueueList;
    l->head = nullptr;
    l->tail = nullptr;
    l->lenght = 0;
    return l;
}

int QueueList_lenght(QueueList *l){
    return  l->lenght;
}

void QueueList_delete(QueueList *l){
    while(l->head!=nullptr){
        Cell *temp=l->head;
        l->head=l->head->next;
        delete temp;
    }
    // l->tail = nullptr;
    delete l;
}
void  QueueList_print(QueueList *l){
    Cell *aux = l->head;
    while(aux != nullptr){
        std::cout << aux->value << std::endl;
        aux = aux->next;
    }
}

void QueueList_pushback(QueueList *l, int x){
    
    if(l->head==nullptr){
        Cell *primo = new Cell;
        primo->value = x;
        primo->next=nullptr;
        l->head = primo;
        l->lenght = 1;
        l->tail = primo;
        return;
    }
    Cell *cur = new Cell;
    cur->value = x;
    cur->next = nullptr;
    l->tail->next = cur;
    l->tail = cur;
    l->lenght++;
}

int QueueList_popback(QueueList *l){
    if(l->head==nullptr){
        std::string err = "lista vuota";
        throw err;
    }
    
    if(l->lenght==1){
        int value = l->head->value;
        Cell *unico = l->head;
        l->head = nullptr;
        l->tail = nullptr;
        delete unico;
        l->lenght--;
        return value;
    }
    Cell *prev = l->head;
    Cell *cur = l->head;
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    int value = cur -> value;
    l->tail = prev;
    prev -> next = nullptr;
    delete cur;
    l->lenght--;
    return value;
}
int QueueList_popfront(QueueList *l){
    if(l->head==nullptr){
        std::string err = "lista vuota";
        throw err;
    }
    
    Cell *cur = l->head;
    int value = cur -> value;
    l->head = l->head->next;
    delete cur;
    l->lenght--;
    return value;
}


void QueueList_pushfront(QueueList *l,int v){
    Cell *aux = new Cell;
    aux->value = v;
    aux->next = l->head;
    l->head = aux;
    l->lenght ++;
}

QueueList *QueueList_copy (QueueList *l){
    if (l->head==nullptr){
        QueueList *b=QueueList_new();
        return b;
    }
    QueueList *b = QueueList_new();
    Cell *copia = l->head;
    Cell *current = new Cell;
    current->value = l->head->value;
    current->next = nullptr;
    b->head = current;
    copia = copia->next;
    while(copia != nullptr){
        
        Cell *Aux = new Cell;
        Aux->value = copia->value;
        Aux->next = nullptr;
        current->next = Aux;
        current = Aux;
        copia = copia->next;
    }
    b->lenght = l->lenght;
    b->tail = l->tail;
    return b;
}


QueueList *QueueList_Merge(QueueList *A, QueueList *B){
    QueueList *Mergiato= QueueList_new();
    if(A->head==nullptr && B->head==nullptr)
        return Mergiato;
    if(A->head==nullptr)
    {
        Cell *merge = B->head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        merge = merge->next;
        Mergiato->head = current;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        Mergiato->lenght = B->lenght;
        Mergiato->tail = current;
        return Mergiato;
        
    }
    else{
        Cell *merge = A->head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        merge = merge->next;
        Mergiato->head = current;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        if(B->head==nullptr){
            Mergiato -> lenght = A->lenght; 
            Mergiato->tail = current;
            return Mergiato;
        }
        merge = B->head;
        while(current->next!=nullptr)
            current = current->next;
        current->next = B->head;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        Mergiato->tail = current;
    } 
    Mergiato->lenght = A->lenght + B->lenght;
    return Mergiato;
}

void reverse_print_cell(Cell *c){
    if (c -> next == nullptr)
        return;
    
    c = c -> next;
    reverse_print_cell(c);
    std::cout << c-> value << std::endl;
    
}  

void rec_print_cell(Cell *c){
    if (c -> next == nullptr)
        return;
    
    c = c -> next;
    std::cout << c-> value << std::endl;
    rec_print_cell(c);
    
    
}  
void QueueList_reverse_print(QueueList *l){
    Cell *c = l-> head;
    if(l -> head == nullptr)
        return;
    
    reverse_print_cell(c);
    std::cout << c -> value << std::endl;
}
void QueueList_recoursive_print(QueueList *l){
    Cell *c = l-> head;
    if(l -> head == nullptr)
        return;
    std::cout << c -> value << std::endl;
    rec_print_cell(c);
    
}
QueueList * QueueList_from_array(int a[], int c){
    QueueList *l= QueueList_new();
    if (c==0)
        return l;
    Cell *Cur = new Cell;
    Cur -> value = a[0];
    Cur -> next=nullptr;
    l -> head = Cur;
    for (int i=1; i < c; i++){
        Cell *aux  =  new Cell;
        aux -> value = a[i];
        aux -> next = nullptr;
        Cur -> next = aux;
        Cur = aux;
        l->tail = aux;
    }
    l -> lenght = c;
    
    return l;
}
int * array_from_list(QueueList *l){
    if(l->head==nullptr){
        int *b=new int[0];
        return b;
    }
    int n = l-> lenght;
    int *b = new int[n];
    Cell *cur = l-> head;
    for(int i=0;i<n;i++){
        b[i] = cur-> value;
        cur = cur->next;
    }
    return b;
}

void selectionSort(int arr[], int n)  
{  
    int min_idx;  
    
    // One by one move boundary of unsorted subarray  
    for (int i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (int j = i+1; j < n; j++)  
            if (arr[j] < arr[min_idx])  
                min_idx = j;  
            
            // Swap the found minimum element with the first element  
            int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }  
}  



void QueueList_Sort(QueueList *l){
    if(l->head==nullptr)
        return;
    Cell *scorrimento = l->head;
    while(scorrimento->next != nullptr){
        Cell *min = scorrimento;
        Cell *s2 = scorrimento->next;
        while(s2 !=nullptr){
            if(s2->value < min->value)
                min = s2;
            s2 = s2->next;
        }
        Cell *aux;
        aux->value = scorrimento->value;
        scorrimento->value = min->value;
        min->value = aux-> value;
        scorrimento = scorrimento->next;
        
    }
}








