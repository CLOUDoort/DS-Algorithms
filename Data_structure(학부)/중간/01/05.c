#include <stdio.h>

int fibo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo(n-1)+fibo(n-2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0;
}
// 계산할 수 있는 n의 최댓값은 46