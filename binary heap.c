#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAXHEAPSIZE 100
#define MAXHEAP 1
#define MINHEAP 0

typedef struct heap{
    int HeapSize;
    int* h;
    bool mode;
} heap;

void initializeHeap(heap* aheap, bool amode){
    aheap->h = malloc(MAXHEAPSIZE*sizeof(int));
    aheap->HeapSize = 0;
    aheap->mode = amode;
}

void add(int n, heap* aheap){
    int i = aheap->HeapSize, p = (i-1)/2;
    aheap->h[i] = n;
    while ((p >= 0) && (i > 0)){
        if ((aheap->h[i] > aheap->h[p]) && (aheap->mode)){
            int t = aheap->h[i];
            aheap->h[i] = aheap->h[p];
            aheap->h[p] = t;
        }
        i = p;
        p = (i-1)/2;
    }
    aheap->HeapSize++;
}

void heapArrsyPrint(heap* aheap){
    for (int i = 0; i < aheap->HeapSize; ++i){
        printf("%d ",aheap->h[i]);
    }
}

int main() {
    heap testheap;
    initializeHeap(&testheap,MAXHEAP);
    add(11,&testheap);
    add(9,&testheap);
    add(5,&testheap);
    add(8,&testheap);
    add(6,&testheap);
    add(16,&testheap);
    add(1,&testheap);
    add(4,&testheap);
    add(2,&testheap);
    heapArrsyPrint(&testheap);
    printf("Hello, World!\n");
    return 0;
}
