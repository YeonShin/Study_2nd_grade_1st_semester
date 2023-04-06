#include <stdio.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int [], int); /*선택정렬, int는 배열의 크기*/
void main(void)
{
    int i, n;
    int list[MAX_SIZE];

    printf("생성할 숫자를 입력하세요: ");
    scanf("%d", &n);

    if(n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "잘못된 n값\n");
        exit(1);
    }
    for (i = 0; i < n; i++) { /* 무작위로 숫자 생성해 배열에 저장 */
        list[i] = random()%1000;
        printf("%d", list[i]);
    }
    sort(list, n);
    printf("\n 정렬된 배열:\n");
    for(i = 0; i < n; i++){
        printf("%d", list[i]);
    }
}

void sort(int list[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n; i++){
        min = i;
        for(j = 0; j < i; j++){
            if(list[j] < list[min]){
                min = j;
            }
        }
        swap(list[i], list[j], temp);
    }
}