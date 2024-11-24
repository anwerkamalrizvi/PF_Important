#include<stdio.h>

void toA(int, char, char, char);


void toA(int disk, char src, char temp, char dest){
    if (disk == 1){
        printf("Move %d disk from tower %c to tower %c\n",disk, src, dest);
        return;
    } 

    toA(disk-1, src, dest, temp);
    printf("Move %d disk from tower %c to tower %c\n",disk,src,temp);
    toA(disk-1, temp, src, dest );
    return;
}//end toA

int main(int argc, const char *argv[]){
    int n; printf("\nEnter n rings: ");
    scanf("%d",&n);
    toA(n,'A','B','C');
    return 0;
}//end main



