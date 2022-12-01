#include <stdio.h>
#include <stdlib.h>
 
void insert(int n, int tree[], int cap, int len){
    if( len > cap - 2){
     	fprintf(stderr, "No space!!\n");
	    exit(1);
    }
   
    tree[len] = n; 
    while( len > 0 && tree[len] < tree[(len-1)/2]){
    	int tmp = tree[len];
    	tree[len] = tree[(len - 1)/2];
    	tree[(len - 1)/2] = tmp;
    	len = (len - 1)/2;
    }
}
 
void swap(int * a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int extract(int heap[], int len){
	int return_value = heap[0];
	heap[0] = heap[len];
	int i = 0;
	while( 
		    (2 * i + 1 < len && heap[i] > heap[2 * i + 1])
		    || (2 * i + 2 < len && heap[i] > heap[2 * i + 2]) )
    {
	    if( heap[2 * i + 2] > heap[ 2 * i + 1]){
	        swap(&heap[i], &heap[2 * i + 1]);
	        i = 2 * i + 1;
	    } else {
	    	swap(&heap[i], &heap[2 * i + 2]);
	    	i = 2 * i + 2;
	    }
	}
	return return_value;
}
#define tree_len 512
int main(void) {
	//insert numbers to tree
	int num_to_sort[] ={1,4,7,3,9,25,23,17, 24, 6, 92, -1, -35};
	int tree [tree_len] = {0} ;
	int len = sizeof num_to_sort / sizeof num_to_sort[0];
    for( int i = 0; i < len; i += 1 ){
	    insert(num_to_sort[i], tree, tree_len, i);
    }
    /* print the heap */
    for( int i = 0; i < len; i += 1 ){
            printf("%d, ", tree[i]);
    }
    putchar('\n');
    /* pop the smallest until nothing is left, printing the array in order */
    while( len > 0 ){
    	printf("%d, ", extract(tree, len--));
    }
    putchar('\n');
	return 0;
}
