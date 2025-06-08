/*1.	Да се напише програма која ќе дозволи внесување на димензиите на две квадратни матрици
(од тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на
матриците (цели броеви). Потоа, програмата треба да провери дали со транспонирање (менување
редиците да станат колони а колоните редици) на првата матрица може да се добие втората
матрица. Доколку може, тогаш на екран да се отпечати порака дека може. Доколку не може,
тогаш на екран да се отпечати во колку елементи тие се разликуваат.
А = 1 2 10 0        
        7 2 3 1
        6 0 5 4
        4 1 1 0
Б=  1 7 6 0
       2 2 0 1
       10 3 5 0
        0 1 4 7  Za ovie matrici ne e ispolnet uslovot za 2 elementi
*/
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Vnesi golemina na kvadratnite matrici (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n];

    printf("Vnesi elementite na matricata A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Vnesi elementite na matricata B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int razlicni = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != B[j][i]) {
                razlicni++;
            }
        }
    }

    if (razlicni == 0) {
        printf("Moze da se dobie B so transponiranje na A.\n");
    } else {
        printf("Ne moze da se dobie B so transponiranje na A. Razlicni se vo %d elementi.\n", razlicni);
    }

    return 0;
}
/*2.	Да се напише програма која ќе дозволи внесување на димензиите на две квадратни матрици
(од тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на
матриците (цели броеви). Потоа, програмата треба да провери дали со промена на првата
матрица може да се добие втората матрица. Менувањето на првата матрица значи првата редица
да се замени со последната, втората со претпоследната и така натаму. (доколку има непарен број
на редици и колони, тогаш редицата на средина останува иста). Доколку може, тогаш на екран да
се отпечати порака дека може. Доколку не може, тогаш на екран да се отпечати во колку
елементи се исти матриците после промената на првата.
А = 
1 2 10 0
7 2 3 1
6 0 5 4
4 1 0 1
Б = 
4 1 0 1
6 0 5 4
7 2 2 1
1 1 10 0
_Za ovie matrici ne e ispolnet uslovot. Ist broj na elementi 14
*/
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Vnesi golemina na kvadratnite matrici (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n];

    printf("Vnesi elementite na matricata A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Vnesi elementite na matricata B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int isti = 0;

    // Проверка: дали променета A (со сменети редици) == B
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[n - 1 - i][j] == B[i][j]) {
                isti++;
            }
        }
    }

    if (isti == n * n) {
        printf("Moze da se dobie B so promena na A.\n");
    } else {
        printf("Ne moze da se dobie B so promena na A. Isti se vo %d elementi.\n", isti);
    }

    return 0;
}
/*3.	Да се напише програма со која од стандарден влез се читаат димензии на квадратна матрица
(макс 100х100), а потоа и нејзините елементи кои треба да се целобројни вредности. Во
програмата треба да се состави нова матрица во која секој елемент од главната дијагонала ќе
биде заменет со сумата на сите елементи од истиот ред десно од елементот и елементите кои се
во истата колона над елементот. Елементите кои не се наоѓаат на главната дијагонала не треба да
се променат.
Влез (А) и излез (B):
А = _
1 2 3
4 5 6
7 8 9
Б = _
5 2 3
4 8 6
7 8 9
_
*/
#include <stdio.h>

int main() {
    int n;
    int A[100][100], B[100][100];

    // Внесување на димензија
    printf("Vnesi golemina na kvadratna matrica: ");
    scanf("%d", &n);

    // Внесување на матрицата A
    printf("Vnesi elementi na matricata A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Креирање на матрицата B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {  // Главна дијагонала
                int suma = 0;

                // Елементи десно во истиот ред
                for (int k = j + 1; k < n; k++) {
                    suma += A[i][k];
                }

                // Елементи погоре во истата колона
                for (int k = 0; k < i; k++) {
                    suma += A[k][j];
                }

                B[i][j] = suma; // Се заменува со сумата
            } else {
                B[i][j] = A[i][j]; // Се копира како што е
            }
        }
    }

    // Печатење на резултатната матрица B
    printf("Matrica B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
