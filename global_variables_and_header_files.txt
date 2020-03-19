#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<process.h>
typedef struct book
{
  char id[15];
  char title[30];
  char author[30];
  int q,sn;
}bk;
bk books;
typedef struct student
{
  char id[15];
  char pass[15];
  char name[25];
  char branch[10];
  char book[50][10];
}
st;
st student;
typedef struct issuedetail
{
 char studentid[10];
 char bookid[10];
 int date;
 int month;
 int year;
}studentbook;
studentbook st1;
struct fine
{
 char studentid[10];
 int price;
};
struct fine f;
char  myuser[15];
char *adminusername[]={"Shashank@gmail.com","Saurabh@gmail.com","Santosh@gmail.com"};
char *adminpassward[]={"12345678","23456789","34567890"};
