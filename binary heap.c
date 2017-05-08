#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAXHEAPSIZE 1000000
#define MAXHEAP 1
#define MINHEAP 0

#define SWAP(a, b) do { typeof(a) tmp = a; a = b; b = tmp; } while (0)

typedef struct heap{
    int HeapSize;
    int* h;
    bool mode;
} heap;

void heapInitialize(heap* aheap, bool amode){
    aheap->h = malloc(MAXHEAPSIZE*sizeof(int));
    aheap->HeapSize = 0;
    aheap->mode = amode;
}

void heapSiftUp(heap* aheap, int i){
    while(aheap->mode ? (aheap->h[i] > aheap->h[(i-1)/2]) : (aheap->h[i] < aheap->h[(i-1)/2])){
        SWAP(aheap->h[i], aheap->h[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapSiftDown(heap* aheap, int i){
    int l,r,j;
    while (2*i + 1 < aheap->HeapSize){
        l = 2*i + 1;
        r = 2*i + 2;
        j = l;
        if ((r < aheap->HeapSize) && (aheap->mode ? (aheap->h[r] > aheap->h[l]) : (aheap->h[r] < aheap->h[l]))){
            j = r;
        }
        if (aheap-> mode ? aheap->h[i] >= aheap->h[j] : aheap->h[i] <= aheap->h[j]){
            break;
        }
        SWAP(aheap->h[i], aheap->h[j]);
        i = j;
    }
}

void heapAdd(int n, heap* aheap){
    aheap->HeapSize++;
    aheap->h[aheap->HeapSize-1] = n;
    heapSiftUp(aheap,aheap->HeapSize-1);
}

int heapDeleteRoot(heap* aheap){
    int root = aheap->h[0];
    aheap->h[0] = aheap->h[aheap->HeapSize - 1];
    aheap->HeapSize--;
    heapSiftDown(aheap,0);
    return (root);
}

int heapGetRoot(heap* aheap){
    return(aheap->h[0]);
}

void heapArrayPrint(heap* aheap){
    for (int i = 0; i < aheap->HeapSize; ++i){
        printf("%d ",aheap->h[i]);
    }
}

void heapPrint(heap* aheap){
    int i = 0, k = 1;
    while (i < aheap->HeapSize){
        while ((i < aheap->HeapSize) && (i < k)){
            printf("%d ",aheap->h[i]);
            ++i;
        }
        printf("\n");
        k = k*2 + 1;
    }
}

int main() {
    heap myheap;
    heapInitialize(&myheap,MAXHEAP);
    heapAdd(3,&myheap);
    heapAdd(1,&myheap);
    heapAdd(15,&myheap);
    heapAdd(4,&myheap);
    heapAdd(-5,&myheap);
    heapDeleteRoot(&myheap);
    heapPrint(&myheap);
    return 0;
}
