#include <stdio.h>

typedef struct _empInfo {
    int empNum;
    int age;
} EmpInfo;

// hash function의 역할은 넓은 범위의 키를 좁은 범위의 키로 변경하는 역할을 한다.
int GetHashValue(int empNum) {
    return empNum % 100;
}

int main(void) {
    EmpInfo empInfoArr[100];

    EmpInfo emp1 = {20120003, 42};
    EmpInfo emp2 = {20130012, 33};
    EmpInfo emp3 = {20170049, 27};
    EmpInfo r1, r2, r3;

    empInfoArr[GetHashValue(emp1.empNum)] = emp1;
    empInfoArr[GetHashValue(emp2.empNum)] = emp2;
    empInfoArr[GetHashValue(emp3.empNum)] = emp3;

    r1 = empInfoArr[GetHashValue(emp1.empNum)];
    r2 = empInfoArr[GetHashValue(emp2.empNum)];
    r3 = empInfoArr[GetHashValue(emp3.empNum)];

    printf("사번 : %d, 나이 : %d \n", r1.empNum, r1.age);
    printf("사번 : %d, 나이 : %d \n", r2.empNum, r2.age);
    printf("사번 : %d, 나이 : %d \n", r3.empNum, r3.age);
    return 0;
}