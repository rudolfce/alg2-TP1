#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){
    int n, i, size;

    if(argc<3){
        printf("Use %s <numero> <numero>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    n = atoi(argv[1]);
    size = atoi(argv[2]);

    printf("%d\n", n);
    for(i=0; i<n; i++){
        printf("%d ", rand() % size);
    }
    printf("\n");
    printf("%d\n", n);
    for(i=0; i<n; i++){
        printf("%d ", rand() % size);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
