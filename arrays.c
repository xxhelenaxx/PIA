//За решавање на првата задача на испит мора да ги сфатиме низите и сите возможни движења во нив бидејќи таа се состои од низа, покажувачи и функции
//1. Линеарно движење од почеток кон крај
for (int i = 0; i < n; i++) {
    // обработка на element[i]
}
//2. Линеарно движење од крај кон почеток
for (int i = n - 1; i >= 0; i--) {
    // обработка на element[i]
}
//3. Движење со повеќе индекси (две или повеќе позиции одеднаш)
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        // спореди element[i] и element[j]
    }
}
//4. Движење со поместување/бришење елементи
for (int i = 0; i < n; i++) {
    if (condition_for_deletion(element[i])) {
        for (int j = i; j < n - 1; j++) {
            element[j] = element[j + 1];
        }
        n--;  // намалување на големината
        i--;  // да не го прескокнеш новиот елемент на позицијата i
    }
}
//5. Движење со чекори (преминување повеќе позиции одеднаш)
for (int i = 0; i < n; i += 2) {
    // обработи секој втор елемент
}
//6. Движење и модификација на елементи додека се движиш
//7. Рекурзивно движење низ низа
void processArray(int element[], int n) {
    if (n == 0) return;
    // обработка на element[0]
    processArray(element + 1, n - 1);
}
//8. Движење со два покажувачи (two pointers technique)
int left = 0, right = n - 1;
while (left < right) {
    // обработка или споредба на element[left] и element[right]
    if (condition) left++;
    else right--;
}
//9. Циклично движење низ низата
int i = 0;
for (int step = 0; step < k; step++) {
    i = (i + 1) % n;
    // обработка на element[i]
}
//Функции со низи во C
#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//или
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

