//втората задача на испит е за матрици ова се сити возможни движења:
//1. Пристап до елементите
mat[2][3] = 10;
int x = mat[1][0];

//2. Пребарување во матрица
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        if (mat[i][j] == target) {
            // Нашол цел број target
        }
    }
}

//3. Бришење елементи (на пример, „нулирање“ на елемент)
mat[i][j] = 0;
//4. Додавање на елемент
//Матриците имаат фиксен број редови и колони, така што не можеш да додаваш елементи како кај динамичките низи. Но можеш да промениш вредност во одредена позиција.
//5. Пресметка по редици или колони
// Сума на елементи во ред i
int rowSum = 0;
for (int j=0; j<cols; j++) {
    rowSum += mat[i][j];
}

// Сума на елементи во колона j
int colSum = 0;
for (int i=0; i<rows; i++) {
    colSum += mat[i][j];
}
//6. Трансформирање на елементи (на пример, замена, промена на вредноста)
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        if (mat[i][j] < 0) {
            mat[i][j] = 0;  // заменуваме негативни броеви со 0
        }
    }
}
//7. Трансформација на матрица (нова матрица од постоечка)
int newMat[rows][cols];
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        newMat[i][j] = mat[i][j] * 2;  // пример двојно зголемување на вредност
    }
}
//8. Избришување на „ред“ или „колона“ (префрлање на вредности и намалување на големина)
// Да се избрише ред i
for (int r = i; r < rows-1; r++) {
    for (int c = 0; c < cols; c++) {
        mat[r][c] = mat[r+1][c];
    }
}
rows--;  // намалување на бројот на редови
//9. Пребарување на најмал или најголем елемент по ред, колона или цела матрица
int min = mat[0][0];
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        if (mat[i][j] < min) {
            min = mat[i][j];
        }
    }
}
//10. Специјални операции на главна дијагонала и споредна дијагонала (samo kvadratni matrici)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            printf("Главна дијагонала: %d\n", mat[i][j]);
        }
        if (i + j == n - 1) {
            printf("Споредна дијагонала: %d\n", mat[i][j]);
        }
    }
}

//11. Пребарување на „најблиска вредност“ до одреден број
for (int i=0; i<rows; i++) {
    double minDiff = fabs(mat[i][0] - X);
    int minIndex = 0;
    for (int j=1; j<cols; j++) {
        double diff = fabs(mat[i][j] - X);
        if (diff < minDiff) {
            minDiff = diff;
            minIndex = j;
        }
    }
    printf("Row %d closest column: %d\n", i, minIndex);
}
//12. Копирање на матрица
for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
        newMat[i][j] = mat[i][j];
    }
}
//Некои движења и примери кои можат да се паднат на испит
//1. Поместување на елементите на една матрица една позиција кон десно
pom=a[n-1][m-1];
    for (k=n*m-1; k>0; k--){
        a[k/m][k%m]=a[(k-1)/m][(k-1)%m];
    }
a[0][0]=pom;
//2.Сумата на елементите лево до споредната дијагонала да е еднаква на елементот од споредната дијагонала
proverka=1; //pretpostavuvame deka e ednakva
for (i=0; i<n-1; i++){
suma =0;
    for (j=0; j+i<n-1; j++){
        suma+=a[i][j];
    }
    if (suma!=a[i][j]) { //suma!=a[i][j<n-1-i]
    proverka=0;
    break;
    }
}
//3. Дали е симетрична?? само квадратна
//услов a[i][j]=a[j][i] && i!=j
pretpostavka=1;
for (i=0; i<n-1; i++){
    for (j=i+1; j<n; j++){
        if (a[i][j]!=a[j][i]) {
        s=0;
        break;
        }
    }
}
//4. Огледално пресликување (по хоризонтала)
for (i=0; i<n/2; i++){
    for (j=0; j<m; j++){
    temp=a[i][j];
    a[i][j]=a[n-1-i][j];
    a[n-1-i][j]=temp;
    }
}
//5.Дали некој број се повторува во секој ред
kolku=0;
for (k=0; k<m; k++){
    for (i=1; i<n; i++){
    proverka=0;
        for (j=0; j<m; j++){
        if (a[0][k]==a[i][j]){
        proverka=1;
        break;
        }
        }
    if (proverka==0){
    break;
    }
    }
    if (proverka ==1){
    printf ("Elementot %d go ispolnuva uslovot!", a[0][k]);
        kolku++;
    }
}
if (kolku==0){
printf("Nema broj koj se povtoruva vo sekoja kolona");
}

