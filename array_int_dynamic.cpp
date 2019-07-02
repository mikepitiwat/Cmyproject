#include <stdio.h>
#include <stdlib.h>

int *p;
int n;

int checkData();

int* Aollocate(){
    p = (int*)calloc(n, sizeof(int));
    return (p);
}

void inputData() {
    for (int i = 0; i < n; ++i) {
        printf("intput data(%d):", i);
        scanf("%d", &*(p + i));
    }
}

void disPlayData(){
	system("cls");
    printf("------------------------------\n");
    printf("DATA ALL %d\n", checkData());
    printf("NO DATA  %d\n\n", n-checkData());

    for (int i = 0; i < n; ++i) {
        printf("Read data(%d)\tAdress(%d) %d\n", i, (p+i), *(p+i));
    }
    printf("------------------------------\n");
}

void changeData(){
    int index;
    disPlayData();
    do {
        printf("You want to change index (0-%d) = ",n-1);
        scanf("%d", &index);
    } while (index > (n-1) || index < 0);
    printf("data(%d) = ", index);
    scanf("%d", &*(p + index));
    system("cls");
}

void addMemory(){
    int add;
    int n_old = n;
    system("cls");
    printf("Now you have %d Memory locations.\n",n);
    printf("How much do you want to add? :");
    scanf("%d", &add);
    p = (int*)realloc(p, (n += add) * sizeof(int));
    for (int i = n_old; i < n; ++i) {
        *(p + i) = -999;
    }
}

void Between(int pass){
    int indexstart, indexend;
    disPlayData();
 do {
        printf("!!!warning!!!\n");
        printf("!!!Between!!!\n");
        printf(" 0=< start < (end-1) <= %d\n", (n-1));
        printf("-------intput---------\n");
        printf("Strat: ");
        scanf("%d", &indexstart);
        printf("End: ");
        scanf("%d", &indexend);
    } while ((indexstart < 0 || indexstart>(n-2))||(indexend<=indexstart ||indexend > (n-1)));

    if(pass == 1){
        for (int i = indexstart; i <= indexend; ++i) {
            printf("input data(%d) is : ", i);
            scanf("%d", &*(p + i));
        }
    }
    if (pass == 2) {
        int delnumber;
        delnumber = (indexend - indexstart) + 1;

        for (int i = indexstart; i < n; ++i) {
            ++indexend;
            if (indexend > (n - 1)) {
                break;
            } else{
                *(p + (indexstart)) = *(p + indexend);
                indexstart++;
            }
   		}
        n -= delnumber;
        p=(int*)realloc(p,n*sizeof(int));
    }
    system("cls");
}

void delMemory(){
    int index;
    int *pint;
    disPlayData();
    do {
        printf("You want to delete the memory at\n");
        printf("(index) (0-%d) : ",(n-1));
        scanf("%d", &index);
    } while (index > (n-1) || index < 0);
        for (int i = index; i <n ; ++i) {
            if(index == (n-1)){
                break;
            }else
                *(p + (index)) = *(p + (index + 1));
            index++;
        }
    n = n - 1;
    p=(int*)realloc(p,n*sizeof(int));
}



int menu(){
    int menu;
    printf("menu\n");
    printf("\t(1.)'Display Data'\n\t(2.)'Change Data'\n\t(3.)'Add Memory'\n");
    printf("\t(4.)'Input Data between start to end'\n");
    printf("\t(5.)'Delete Memoty'\n");
    printf("\t(6.)'Delete Memoty Between start to end'\n");
    printf("\t(0.)'exit'\n");
    printf("Select:");
    scanf("%d", &menu);
    if(menu == 0)
        return (menu);

    switch (menu){
        case 1:
            disPlayData();
            break;
        case 2:
            changeData();
            break;
        case 3:
            addMemory();
            break;
        case 4:
            Between(1);
            break;
        case 5:
            delMemory();
            break;
        case 6:
            Between(2);
            break;
        default:
            printf("\n!!!!!Not meet the conditions!!!\n\n");
    }
    return (menu);
}


int main(){
    printf("you want size data: ");
    scanf("%d", &n);
    p = Aollocate();
    inputData();
    disPlayData();
    while (menu() != 0);
    free(p);
    return 0;
}

int checkData(){
    int havedata = 0;
    for (int i = 0; i < n; ++i) {
        if(*(p+i) != -999){
            havedata++;
        }
    }
    return (havedata);
}
