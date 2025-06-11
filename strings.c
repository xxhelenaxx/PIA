//sekoja tekstualna niza e pointer sama po sebe
//sekoja tekst niza na krajot sodrzhi \0 shto go obelezhuva krajot
//opsht primer za deklaracija na tekst niza i mini operacija
#include <stdio.h>
#include <ctype.h>

int strlen(const char *str){ //---> strlen postoi vo string.h
  int n;
  for (n=0; *str!='\0'; str++){
      n++;
  }
return n;
}
void change (char *str){
  int i;
  i=strlen(str);

  for (i--; i>=0 && isspace(str[i]); i--){ //pochni od krajot i dvizhi se se dodeka ne dojdesh do pochetokot ili do char shto ne e space
  } //->>isspace postoi vo ctype.h
  str[i+1]='\0';//stavi NULL
  
}
int main (){
  char s[max], c;
  int i=0;
  while ((i<max-1) && (c=getchar()!='\n')){
    s[i++]=c;
  }
  s[i]='\0';
change(s);
printf ("Sodrzhinata na nizata e: %s \n", s);
return 0;
}
//sega kje gi opfatam funkciite koi kje gi koristime vo bibliotekite 
//ctype.h – Функции за проверка и трансформација на карактери
/*
Функции за проверка:
 Функција	        Опис
isalpha(c)	Дали е буква (A–Z или a–z) 
isdigit(c)	Дали е бројка (0–9)
isalnum(c)	Дали е буква или бројка
isspace(c)	Дали е празно место (space, tab, newline...)
islower(c)	Дали е мала буква (a–z)
isupper(c)	Дали е голема буква (A–Z)
ispunct(c)	Дали е интерпункциски знак

Функции за трансформација:
Функција	           Опис
tolower(c)	Го претвора во мала буква
toupper(c)	Го претвора во голема буква

*/
//string.h – Функции за работа со низи од карактери (char[])
/*
Функции за копирање и поставување:
  Функција                            Опис                                           
strcpy(dest, src)`      Копира `src` во `dest` (без проверка)          
strncpy(dest, src, n)`  Копира најмногу `n` карактери                  
strcat(dest, src)`      Додава `src` на крај од `dest`                
strncat(dest, src, n)`  Додава најмногу `n` карактери    

Функции за споредба:

| Функција                | Опис                              |
| `strcmp(s1, s2)`        | Споредува два стринга (целосно)   |
| `strncmp(s1, s2, n)`    | Споредува првите `n` карактери    |

Функции за должина и пребарување:
| Функција                   | Опис                                           |
| `strlen(s)`                | Ја враќа должината на стрингот                 |

има многу повеќе функции, но овие се најбитни кои се користат во задачи

*/

//Пример задача: Дали е палиндром и да се исфрлат сите празни места и да не се прави разлика меѓу мали и големи букви
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 100
void change (char *str){
  char *a=str, *b=str;
  while (*a){
    if (isalpha(*a)){
        if (isupper(*a)){
          *b=tolower(*a);
         } else {
            *b=*a;
           }
          b++;
    }
    a++;
  }
*b='\0';
}
int palindrom (char *str){
  int i, lenght, p=1; //pretpostavuvame deka e palindrom
  change(str);
  lenght=strlen(str);
  for (i=0; i<lenght/2; i++){
    if (*(str + i) != *(str + lenght - 1 - i)){
      p=0;
      break;
    }
  }
  
  return p;
}
int main (){
  char s[max];
  printf ("Vnesi ja s:");
  gets(s);//polesno od prviot nachin ->ni vchituva cel string(go pravi seto ona sto go pravi while gore)

  if (palindrom(s)){
  printf ("Da, %s e palindrom. \n", s);
  }
  else {
  printf ("Ne, %s ne e palindrom. \n", s);
  }
return 0;
}
/*
Од тастатура (stdin):
getchar() → чита char
scanf() → чита int, float, char, string
fgets() → чита ред (стринг)

 На екран (stdout):
putchar() → печати char
printf() → печати int, float, char, string
puts() → печати цел стринг со \n

Од датотека (FILE *f):
fgetc(f) / getc(f) → чита char
fscanf(f, ...) → чита int, float, string, итн.
fgets(str, n, f) → чита ред од текст

 Во датотека:
fputc(c, f) / putc(c, f) → пишува char
fprintf(f, ...) → пишува секакви типови
fputs(str, f) → пишува стринг*/
