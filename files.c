//ДАТОТЕКИ
//Во C програмскиот јазик, датотеки (files) се начин за читање и запишување податоци надвор од програмата – обично на хард диск.
//Наместо податоците да се внесуваат од тастатура или да се печатат на екран, можат да се зачуваат или прочитаат од датотека.

//Основни чекори за работа со датотеки

//1.Дефинирање покажувач кон датотека:
FILE *f;
//2.Отворање датотека:
f = fopen("ime_na_dokument.txt", "r"); // "r" за читање
//Режими за отворање:
/*
| Режим  | Опис                                                       |
| `"r"`  | чита постоечка датотека (read)                             |
| `"w"`  | пишува нова датотека (write) – старата се брише ако постои |
| `"a"`  | додава на крај од постоечка (append)                       |
| `"r+"` | чита и пишува                                              |
| `"w+"` | пишува и чита (брише старата)                              |
| `"a+"` | чита и додава                                              |

*/
//3.Читање/пишување:
fscanf(f, "%d", &broj); // чита број
fprintf(f, "%s", niza); // пишува текст
//4.Затворање датотека:
fclose(f);


//пример:
//за текстуална датотека чие име се внесува како аргумент од командната линија ќе ги најдесите редови кои имаат повеќе од 10 мали букви
//на крај да се запише и вкупниот број на таквите редови
//во втора датотека чие име се внесува исто како аргумент ќе ги запише редните броеви на пронајдените редови.
//програмата треба да провери дали корисникот внел влезна и излезна дат валидно, доколку не да се испечати грешка
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[]){ //Ова е посебна верзија на main() функцијата која дозволува корисникот да му прати податоци на програмот од командната линија.
  //мора ако сакаш твојата програма да користи надворешни податоци
  FILE *in_dat, *out_dat; //in_dat, out_dat се покажувачи кон датотеки.
  char c; //c е карактер што ќе го читаме од датотеката.
  int red, mali, vkupno;

  if (argc!=3){ //Ако нема точно три аргументи (име на програма + 2 фајла), испиши грешка и прекини.
//Тоа значи дека програмата очекува точно 3 аргументи:
//argv[0] → името на програмата (автоматски се додава)
//argv[1] → влезна датотека
//argv[2] → излезна датотека
    printf("Imash greshka vo vnesuvanje na dat!");
    return -1;
  }
if ((in_dat=fopen(argv[1], "r")==NULL){ //Обиди се да ја отвориш влезната датотека (argv[1]) за читање "r".
// Ако не може (не постои фајлот), испиши грешка и прекини.
   printf("Datoteka so ova ime ne postoi!");
    return -1;
  }
if ((out_dat=fopen(argv[w], "w")==NULL){//Отвори ја излезната датотека (argv[2]) за запишување "w".
//Ако не можеш да ја креираш (немаш дозвола, итн.), испиши грешка.
   printf("Vo ovaa papka nemam privilegii da kreiram file!");
    return -1;
  }
red=1; //почнуваме од првиот ред
mali=vkupno=0; 
while (c=fgetc(in_dat)!=EOF){ //Чита еден по еден карактер од датотеката, сè додека не стигнеме до крај (EOF = End of File).
  if (isalpha(c) && islower(c)){ //Ако карактерот е буква и е мала, зголеми го бројачот mali.
    mali++;
  }
  if (c=='\n'){ // Кога ќе наидеш на крај на ред (\n):
    if (mali>=10){ //Ако има најмалку 10 мали букви → запиши го бројот на редот во out_dat.
      fprintf(out_dat, "red &d\n", red);
      vkupno++;//Зголеми vkupno (вкупен број на такви редови).
    }
    mali=0;
    red++;
    //Ресетирај го бројачот на мали букви и премини на следен ред
  }
}
fprintf(out_dat, "vkupno vakvi redovi imashe %d\n", vkupno); //На крај, испиши во излезната датотека вкупно колку редови го исполнуваат условот.
  //Затвори ги двете датотеки.
fclose(out_dat);
fclose (in_dat);
return 0;
}

//Треба да се прочита од текст дат со име matrica1.txt-да се прочитаат елементите на една матрица
//-редици
//-колони
//да се направи транспонирање на матрицата, кога ќе се добие да се напише во matrica2.txt
#include <stdio.h>
#include <stdlib.h>
#define max 100
int main (){
  FILE *in_dat, *out_dat;
  float a[max][max], b[max][max];
  int i, j, n, m;

  if (in_dat=fopen("matrica1.txt", "r")==NULL){
    printf("Datoteka so ova ime ne postoi!");
    return -1;
  }
  if (!feof(in_dat)){ //feof()	Проверува дали е стигнат крајот на датотеката
    fscanf(in_dat, "%d", &n); 
  }
 if (!feof(in_dat)){
    fscanf(in_dat, "%d", &m);
  }
if (m>max || n>max){
  return -1;
}
for (i=0; i<n && !feof(in_dat); i++){
  for (j=0; j<m&&!feof(in_dat); j++){
    fscanf(in_dat, "%f", &a[i][j]);
  }
}
fclose (in_dat);
if(i!=n&&j!=m){
  printf("Nema vneseno dovolno elementi!!");
  return -1;
}
//se e ok mozhe da se pravi transponiranje na mat
for (i=0; i<n; i++) {
  for (j=0; j<m; j++){
    b[j][i]=a[i][j];
  }
}

  if (out_dat=fopen("matrica2.txt", "w")==NULL){
     printf("Vo ovaa papka nemam privilegii da kreiram file!");
     return -1;
  }
//sega ja zpaishuvame novata matrica vo drugata dat ama naopaku redovi i koloni
fprintf(out_dat, "%d", m);
fprintf(out_dat, "%d", n);
for (i=0; i<m; i++){
  for (j=0; j<n; j++){
   fprintf(out_dat, "&f\n", b[i][j]);
  }
}

fclose(out_dat);
return 0; 
}
