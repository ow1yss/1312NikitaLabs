#include "lr.h"
#include <stdio.h>

void calc(int v,int v1,int v2){
 int t = v/(v1-v2);
 printf("time opustosheniya of pool: %d minut\n", t);
}

int lab1(){
    int v, v1, v2;
 printf("enter ob'em: ");
 scanf("%d", &v);
 printf("enter v1: ");
 scanf("%d", &v1);
 printf("enter v2: ");
 scanf("%d", &v2);
 if(v1-v2==0){
 printf("error");
 return 1;
 }
 calc(v, v1, v2);
 return 0;
}

void calcc(int v,int v1,int v2){
 int t = v/(v1-v2);
 printf("Время опустошения бассейна: %d минут\n", t);
}
int lab1dop(){
 int v, v1, v2;
 printf("Введите объём: ");
 scanf("%d", &v);
 printf("Введите v1: ");
 scanf("%d", &v1);
 printf("Введите v2: ");
 scanf("%d", &v2);
 if(v1-v2==0){
 printf("error");
 return 1;
 }
 calcc(v, v1, v2);
 return 0;
}

int lab2(){
    float eps;
        float a=30001, b=1, i=1, sum;

        printf("vvedite eps: ");
        scanf("%f", &eps);

        while(a > eps){
                a = i/b;
                i = i * (i+2);
                b = b * (b+3);
                sum = sum+a;
        }
        printf("%f", sum);

        return 0;
}
int lab2dop(){
}

int lab3(){
    int pwl = 0;
    int cwl = 0;
    char ch;

    while ((ch = getchar()) != '\n') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            cwl++;
        } else{
            if (pwl == 0) {
                pwl = cwl;
            } else if(pwl != cwl){
                printf("Ne vse words odinakovoi dlin.\n");
                return 0;
            }

            cwl = 0;
        }
    }

    printf("vse words odinakovoi dlini.\n");

    return 0;
}
int lab3dop(){}

int lab4(){
    char input[100];
    int i = 0;

    printf("vvedite stroky: ");

    while ((input[i] = getchar()) != '\n') {
        if ((input[i] < '0' || input[i] > '9')) {
            i++;
        }
    }
    input[i] = '\b';

    printf("result posle deleted chisel: %s\n", input);

    return 0;
}
int lab4dop(){
 char input[100];
 int i = 0;
 int inx_last_deleted=0;
 printf("введите строку: ");
 while ((input[i] = getchar()) != '\n') {
    if ((input[i] < '0' || input[i] > '9')) {
        inx_last_deleted = i;
        i++;
        }
    }
 input[i] = '\0';
 printf("Результат после удаления чисел: %s\n", input);
 printf("Индекс последнего удаленного числа: %d\n", inx_last_deleted);
 return 0;
}

int lab5(){
    int arr[10];

    printf("Введите 10 элементов массива:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int sum_chet = 0, sum_nechet = 0;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            sum_chet += arr[i];
        } else {
            sum_nechet += arr[i];
        }
    }

    if (sum_chet < sum_nechet) {
        for (int i = 1; i < 10; i += 2) {
            arr[i] = 0;
        }
    } else {
        for (int i = 0; i < 10; i += 2) {
            arr[i] = 0;
        }
    }

    printf("Массив после обнуления элементов:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
int lab5dop(){
}

int lab6(){
    int N,K;
    int sum_all = 0;
    int count_all = 0;
    scanf("%d %d",&N,&K);
    int arr[N][K];
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            scanf("%d",&arr[i][j]);
            sum_all+=arr[i][j];
            count_all++;
        }
    }

    for (int i = 0; i < N; i++) {
        float sum = 0;
        float count = 0;

        for (int j = 0; j < K; j++) {
            sum += arr[i][j];
            count++;
        }
        float average=0;
        average = sum/count;
        if (average < (sum_all / count_all)) {
            for (int j = 0; j < K; j++) {
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int lab6dop(){
    int N,M;
    scanf("%d %d",&N,&M);
    int shag = N * M;
    float koef = 1.27;
    int flag = 0;
    int arr[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (!flag) {
        shag = (int)(shag / koef);
        if (shag <= 1) {
            shag = 1;
            flag = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int stepi = i * M + j + shag;
                if (stepi < N * M) {
                    if (arr[i][j] > arr[stepi / M][stepi % M]) {
                        int temp = arr[i][j];
                        arr[i][j] = arr[stepi / M][stepi % M];
                        arr[stepi / M][stepi % M] = temp;
                        flag = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
return 0;
}

unsigned long ZerkBits(long x) {
    unsigned long y = 0;
    int CountBitov = sizeof(x) * 8;
    for (int i = 0; i < CountBitov; i++) {
        y <<= 1;
        if (x & 1) {
            y |= 1;
        }
        x >>= 1;
    }
    return y;
}

int lab7() {
    unsigned long N;
    printf("Vvedite Chislo: ");
    scanf("%lu", &N);
    unsigned long ZerkN = ZerkBits(N);
    printf("Zerkal'noe chislo: %lu\n", ZerkN);
    return 0;
}
int lab7dop(){}
