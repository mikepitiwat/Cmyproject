#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR 20  // Use type string

char* AllocateStint(int n){
    char *p;
    p = (char *)calloc(n, STR);   // (n*STR) = ? byte      
    if(p == NULL){
        printf("error \n");
        exit(1);
    }else
        return p;
}

int main(){
    char *p;
    char name[STR]="";
    int num;

    printf("DO you have many studen:");
    scanf("%d",&num);
    getchar(); 								// bug enter effect to function gets()
    p = AllocateStint(num);

    for (int i = 0; i < num; ++i) {
        printf("Name studen(%d): ", i);
      //  scanf("%s",(p + i * STR));          //you can input string format scanf(); by (comment  ROW 29, 30) 
        									//!!!but string you will can't specbar 																				 
        gets(name);
        strcpy((p + i * STR), name);
    }
    
    printf("-------------------------------------------------\n");

    for (int j = 0; j < num; ++j) {
        printf("stden(%d): adress %d is %s \n", j, (p + j * STR), (p + j * STR));
    }

    free(p);
    
    return 0;
}
