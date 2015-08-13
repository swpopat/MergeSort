//
//  main.c
//  MergeSort
//
//  Created by Shehzad Popat on 8/13/15.
//  Copyright (c) 2015 Shehzad. All rights reserved.
//

#include <stdio.h>


/*The idea behind merge sort is to compare individual items from two lists (list A and list B)
 ordered from least to greatest, remove the lesser of the two items and append it to a third
 list (list C). Once either list A or list B has no other items, append all items from the
 remaining list to list C in order. List C is now sorted list.*/


int num[20];

int main(int argc, const char * argv[]) {
    
    int n, i;
    
    printf("how many numbers?\n");
    scanf("%d",&n);
    printf("Pick numbers");
    
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    mergeSort(num, 0, n-1);
    
    for (i = 0; i < n; i++)
        printf("%d", num[i]);
    
    
    return 0;
}

int mergeSort(int num[], int low, int hi) {
    
    static int counter = 0;
    
    int mid;
    if (low < hi) {
        mid = (low + hi)/2;
        
        printf("\nms call 1 count = %d\n",counter++);
        mergeSort(num, low, mid);
        
        printf("\nms call 2 count = %d\n",counter++);
        mergeSort(num, mid+1, hi);
        
        printf("\nmerge call count = %d\n",counter++);
        merging(num, low, mid, hi);
    }
    return 0;
}

int merging(int num[], int low, int mid, int high) {
    
    int num1[10], num2[10];
    int n1, n2, i, j, k;
    n1 = mid-low+1;
    n2 = high-mid;
    
    
    for(i=0; i < n1; i++) {
        num1[i] = num[low +i];
    }
    
    for(j=0; j< n2; j++) {
        num2[j] = num[mid+j+1];
    }
    
    num1[i] = 1000;
    num2[j] = 1000;
    i = 0;
    j = 0;
    
    for(k = low; k <= high; k++)   {
        if(num1[i] <= num2[j]) {
            num[k] = num1[i++];
        } else {
            num[k] = num2[j++];
        }
    }
    return 0;
}
