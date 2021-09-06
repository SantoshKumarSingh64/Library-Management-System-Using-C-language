void finepayment()
{
 FILE *fp,*fp1;
 int pr,fine;
 char id[15],ch;
 color();
  setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"FINE PAYMENT PAGE");
 gotoxy(30,10);
 printf("ENTER STUDENT ID : ");
 scanf("%s",&id);
 fp=fopen("fine.txt","rb");
 fread(&f,sizeof(f),1,fp);
 while(!feof(fp))
 {
   if((strcmp(f.studentid,id))==0)
   {
    clrscr();
    color();
     setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"FINE PAYMENT PAGE");
    gotoxy(30,10);
    printf("STUDENT ID : %s",f.studentid);
    gotoxy(30,12);
    printf("FINE       : %d",f.price);
    fine=f.price;
    fclose(fp);
    goto out;
   }
   fread(&f,sizeof(f),1,fp);
 }
  fclose(fp);
  color();
     setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"FINE PAYMENT PAGE");
  gotoxy(30,10);
  printf("STUDENT ID : %s",id);
  gotoxy(30,12);
  printf("FINE       : 0");
  gotoxy(40,16);
  getch();
  studentid1();
  out :
  gotoxy(25,14);
  printf("DO YOU WANT TO PAY FINE : ");
  fflush(stdin);
  scanf("%s",&ch);
  if(ch=='y'||ch=='Y')
  {
    gotoxy(25,16);
    printf("      PAYMENT IN RUPEES : ");
    fflush(stdin);
    scanf("%d",&pr);
    fine=fine-pr;
    gotoxy(10,10);
   printf("%d",fine);
   gotoxy(10,10);
   printf("%d",fine);
   gotoxy(10,10);
   printf("    ");
   fp1=fopen("fine1.txt","wb");
   fp=fopen("fine.txt","rb");
   fread(&f,sizeof(f),1,fp);
   while(!feof(fp))
   {
    if((strcmp(f.studentid,id))!=0)
     {
	fwrite(&f,sizeof(f),1,fp1);
     }
    if((strcmp(f.studentid,id))==0)
    {

	 f.price=fine;
	fwrite(&f,sizeof(f),1,fp1);
     }
     fread(&f,sizeof(f),1,fp);
   }
   fclose(fp);
  fclose(fp1);
  remove("fine.txt");
  rename("fine1.txt","fine.txt");
  gotoxy(10,10);
  printf("    ");
  gotoxy(35,19);
  printf("PAID");
  gotoxy(38,21);
  getch();
  studentid1();
  }
  gotoxy(35,19);
  printf("UNPAID");
  gotoxy(38,21);
  getch();
  studentid1();
}
