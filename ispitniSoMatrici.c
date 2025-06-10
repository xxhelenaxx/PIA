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
/*4.	Да се напише програма со која од стандарден влез се читаат димензии на квадратна матрица
(макс 100х100), а потоа и нејзините елементи кои треба да се целобројни вредности. Да се состави
нова матрица во која секој елемент од споредната дијагонала да се замени со сумата на елементи
од истиот ред десно од елементот и елементите кои се во истата колона под елементот.
Елементите кои не се наоѓаат на споредната дијагонала не треба да се променат.
Влез (А) и излез (B):
А = _
1 2 3
4 5 6
7 8 9

Б = _
1 2 15
4 14 6
17 8 9
_
*/
#include <stdio.h>
int main (){
    int n, j, i;
    printf("Vnesi golemina na kvadratna matrica: ");
    scanf("%d", &n);
    if (n > 100) {
        printf("Goleminata na matricata ne sme da bide pogolema od 100.\n");
        return 1; // Излез од програмата ако е поголема од 100
    }
    int A[n][n], B[n][n];
    printf("Vnesi elementi na matricata A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    // Креирање на матрицата B
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (i + j == n - 1){
                int suma = 0;
                // Елементи десно во истиот ред
                for (int k = j + 1; k < n; k++) {
                    suma += A[i][k];
                }
                // Елементи подолу во истата колона
                for (int k = i + 1; k < n; k++) {
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
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*5.	Да се напише програма која ќе дозволи внесување на димензиите на една матрица (од
тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на матрицата
(реални броеви). Исто така, по внесувањето на елементите на матрицата, треба да се внесе од
тастатура реален број Х. Потоа, програмата треба да ја измине матрицата по редици и да види во
која колона на секоја редица, разликата на два соседни елементи од редицата е поголема од
вредноста на Х. Доколку се најде вакви два соседни елементи во редицата, се печати редниот број
на редицата, редниот број на колоната на десниот елемент (од двата. Разликата на два соседни
броеви се пресметува по апсолутна вредност. Доколку во редицата има повеќе вакви соседни
броеви, само првиот пат се печати редицата, а после тоа се печати само колоната.
А = _
1.7  2.0 10.1 0.5
7.3  2.2 3.4  1.01
6.0  5.1 5.2   4.1
4.4  1.0 0.0   1.2
 Х = 4.5    На екран:
redica 0 kolona 2 3
redica 1 kolona 1
*/
#include <stdio.h>
#include <math.h> // за fabs()

int main() {
    int n, m;
    printf("Vnesi broj na redici i koloni: ");
    scanf("%d %d", &n, &m);

    double A[n][m]; // реални броеви
    printf("Vnesi elementi na matricata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    double X;
    printf("Vnesi vrednost za X: ");
    scanf("%lf", &X);

    for (int i = 0; i < n; i++) {// за секоја редица
        int first = 1; // знаменце за печатење на редица
        for (int j = 0; j < m - 1; j++) {// проверка до m-1 за да не излеземе од границите
            if (fabs(A[i][j] - A[i][j + 1]) > X) { //fabs e за апсолутна вредност
                // Ако разликата е поголема од X, печати редица и колона
                if (first) {// ако е прв пат наоѓање
                    printf("redica %d kolona %d", i, j + 1);// +1 бидејќи колони се бројат од 1
                    first = 0;// означи дека веќе е печатено
                } else {// ако не е прв пат
                    // само печати колона
                    printf(" %d", j + 1);
                }
            }
        }
        if (!first) {// ако имало печатење
            printf("\n"); // нов ред ако имало печатење
        }
    }

    return 0;
}
/*6.	Да се напише програма која ќе дозволи внесување на димензиите на една матрица (од
тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на матрицата
(реални броеви). Исто така, по внесувањето на елементите на матрицата, треба да се внесе од
тастатура реален број Х. Потоа, програмата треба да ја измине матрицата по редици и да види во
која колона на секоја редица (т.е. кој елемент од редицата) има најблиску вредност до вредноста
на Х. Доколку се најдат повеќе елементи во истата редица кои што се исто блиску до вредноста на
Х, тогаш се печатат редните броеви на сите колони во редицата за кои е исполнет условот.
Близината на елементите до вредноста на Х се пресметува како апсолутна вредност од разликата
на двете вредности (елементот и Х).
_А= _
1.7 2.0 7.1 1.9
7.3 2.2 3.4 1.01
6.0 5.1 5.2 4.1
4.4 1.0 0.0 1.2
 _Х= 4.5  На екран:
redica 0 kolona 2 3
redica 1 kolona 2
redica 2 kolona 3
redica 3 kolona 0
*/
#include <stdio.h>
#include <math.h> // за fabs()

int main () {
    int n, m, i, j;
    double X;
    printf("Vnesi broj na redici i koloni: ");
    scanf("%d %d", &n, &m);

    double A[n][m];
    printf("Vnesi elementi na matricata:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%lf", &A[i][j]);

    printf("Vnesi vrednost za X: ");
    scanf("%lf", &X);

    for (i = 0; i < n; i++) {
        double min_diff = fabs(A[i][0] - X);

        // Најди ја минималната апсолутна разлика во редот
        for (j = 1; j < m; j++) {
            double diff = fabs(A[i][j] - X);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        // Испечати ги сите колони со таа минимална разлика
        printf("redica %d kolona", i);
        for (j = 0; j < m; j++) {
            if (fabs(fabs(A[i][j] - X) - min_diff) < 1e-6) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }

    return 0;
}

/******************************************************************************
7.	Да се напише програма која ќе дозволи внесување на димензиите на една матрица (од
тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на матрицата
(цели броеви). Програмата треба, за секоја редица од матрицата, да провери дали има дупликат
редица т.е. редица со ист редослед и исти вредности на елементите. Доколку најде една (или
повеќе) такви редици во матрицата, тогаш на првата дупликат редица елементите и се
зголемуваат за вредност 1, на втората дупликат редица (од истата оригинална редица) елементите
се зголемуваат за вредност 2 и т.н. По изминување на матрицата, се печати бројот на редици што
биле трансформирани и се печати матрицата по трансофрмација. Доколку немало ниту една
промена, тогаш не се печати новата верзија на матрицата.
_А=
_ _ _ _ _
1 2 10 0
7 2 3 1
1 2 10 0
7 2 3 1
1 2 10 0_
_
_
_
_
Х = 3 
по трансформација
А =
_ _ _ _ _
1 2 10 0
7 2 3 1
2 3 11 1
8 3 4 2
3 4 12 2_


*******************************************************************************/
#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX][MAX], n, m;
    int i, k, l;
    int dvojnici[MAX] = {0};
    int promeneti = 0;

    // Внес на димензии
    printf("Vnesi broj na redovi: ");
    scanf("%d", &n);
    printf("Vnesi broj na koloni: ");
    scanf("%d", &m);

    // Внес на елементите
    printf("Vnesi elementi:\n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < m; k++) {
            scanf("%d", &a[i][k]);
        }
    }

    for (i = 0; i < n - 1; i++) { //pochnuva da go sporeduva prviot red so ostanatite, pa vtoriot..itn se do pretposledniot
        for (int red = i + 1; red < n; red++) { //pochnuva od naredniot red i odi do posledniot
            int isti = 1;//pretpostavuvame deka se isti
            for (k = 0; k < m; k++) { //odime posekoj element po kolona od toj red
                if (a[i][k] != a[red][k]) { //ako elementot od redicata i ne e ednakov od drugata redica red
                    isti = 0; //znachi ne se isti
                    break;//izleguvame od ciklusot bidejkji nema potreba da prodolzhime da gi sporeduvame ostanatite el od redot
                }
            }
            if (isti) {//ako isti(pretpostavkata)e 1->znachi se isti
                dvojnici[i]++;//kako brojach niza koja gleda kolku redovi se promeneti(duplikati)
                for (l = 0; l < m; l++) {//ciklus niz kolonite
                    a[red][l] += dvojnici[i]; // ja zgolemuva vrednosta na el od redot za redniot broj na duplikatot
                }
                promeneti++;//brojach koj sodrzhi kolku redovi se promeneti
            }
            /*Ред 0: 1 2 3 (za i=0 za prviot red) ------------------------->1 2 3 ->i++------------------------->1 2 3 
              Ред 1: 4 5 6  red =1; i=0; ->ne se isti --------------------->4 5 6 ->i=1;------------------------>4 5 6
              Ред 2: 1 2 3 ← дупликат на ред 0  red=2; i=0; dvojnici[0]=1;->2 3 4 ->red=2; i=1; ne se isti------>2 3 4
              Ред 3: 1 2 3 ← дупликат на ред 0  red=3; i=0; dvojnici[0]=2-->3 4 5 ->red=3; i=1; ne se isti------>3 4 5
              Ред 4: 4 5 6 ← дупликат на ред 1  red=4; i=0; ne se isti----->4 5 6 ->red=4; i=1; dvojnici[1]=1--->5 6 7
*/
        }
    }

    if (promeneti > 0) {
        printf("\nBroj na transformirani redovi: %d\n", promeneti);
        printf("Matrica po transformacija:\n");
        for (i = 0; i < n; i++) {
            for (k = 0; k < m; k++) {
                printf("%d ", a[i][k]);
            }
            printf("\n");
        }
    } else {
        printf("Nema dvojnici.\n");
    }

    return 0;
}
/******************************************************************************
8.	Да се напише програма која ќе дозволи внесување на димензиите на една матрица (од
тастатура), a потоа (исто така од тастатура) ќе овозможи да се внесуваат елементите на матрицата
(цели броеви). Програмата треба, за секоја колона од матрицата, да провери дали има дуплкат
колона т.е. колона со ист редослед и исти вредности на елементите. Доколку најде една (или
повеќе) такви колони во матрицата, тогаш на првата дупликат колона елементите и се намалуваат
за вредност 1, на втората дупликат колона (од истата оригинална колона) елементите се
намалуваат за вредност 2 и т.н. По изминување на матрицата, се печати бројот на колони што
биле трансформирани и се печати матрицата по трансформацијата. Доколку немало ниту една
промена, тогаш не се печати новата верзија на матрицата.
_А=
_ _ _ _ _
1 2 1 2 2
7 2 7 2 2
1 2 1 2 2
7 2 7 2 2
1 2 1 2 2_
Х = 3
 по трансформација
А =
_ _ _ _ _
1 2 0 1 0
7 2 6 1 0
1 2 0 1 0
7 2 6 1 0
1 2 0 1 0_


*******************************************************************************/
#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX][MAX], n, m;
    int i, j, k, l;
    int dvojnici[MAX] = {0};
    int promeneti = 0;
    int isti;

    // Внес на димензии
    printf("Vnesi broj na redovi: ");
    scanf("%d", &n);
    printf("Vnesi broj na koloni: ");
    scanf("%d", &m);

    // Внес на елементите
    printf("Vnesi elementi:\n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < m; k++) {
            scanf("%d", &a[i][k]);
        }
    }

    // Проверка за дупликат колони
    for (j = 0; j < m - 1; j++) { 
        for (k = j + 1; k < m; k++) {
            isti = 1;
            for (i = 0; i < n; i++) {
                if (a[i][j] != a[i][k]) {
                    isti = 0;
                    break;
                }
            }
            if (isti) {
                dvojnici[j]++;
                for (l = 0; l < n; l++) {
                    a[l][k] -= dvojnici[j]; 
                }
                promeneti++;
            }
        }
    }

    if (promeneti > 0) {
        printf("\nBroj na transformirani koloni: %d\n", promeneti);
        printf("Matrica po transformacija:\n");
        for (i = 0; i < n; i++) {
            for (k = 0; k < m; k++) {
                printf("%d ", a[i][k]);
            }
            printf("\n");
        }
    } else {
        printf("Nema dvojnici.\n");
    }

    return 0;
}
