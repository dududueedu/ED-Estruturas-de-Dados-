#include <stdio.h>
#include "Ordens.h"

int main(){
	int v[] = {36, 83, 81, 22, 96, 0, 9, 15, 42, 28, 97, 20, 17, 54, 21, 49, 75, 88, 76, 38, 23, 48, 78, 46, 47, 
	72, 57, 52, 12, 85, 91, 41, 65, 73, 59, 87, 64, 66, 34, 89, 19, 67, 61, 40, 69, 31, 44, 1, 11, 98, 43, 45, 
	62, 7, 86, 39, 3, 26, 6, 50, 5, 37, 74, 18, 82, 56, 16, 2, 27, 99, 68, 70, 33, 32, 35, 13, 58, 80, 53, 79, 
	24, 63, 93, 8, 25, 55, 84, 92, 71, 77, 10, 90, 94, 4, 60, 51, 95, 30, 14, 29};
   	int k;
    bubbleSort(v, 100);
    printf("** BubbleSort: \n");
    for (k = 0; k < 100; k++) printf("%i ", v[k]);

    insertionSort(v, 99);
    printf("\n\n** InsertionSort: \n");
    for (k = 0; k < 100; k++) printf("%i ", v[k]);

    selectionSort(v, 99);
    printf("\n\n** SelectionSort: \n");
    for (k = 0; k < 100; k++) printf("%i ", v[k]);

    mergesort(v, 0,99);
    printf("\n\n** MergeSort: \n");
   	for (k = 0; k < 100; k++) printf("%i ", v[k]);

    printf("\n");
    return 0;
}