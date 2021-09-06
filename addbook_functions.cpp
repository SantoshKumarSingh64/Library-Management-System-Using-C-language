void addbooks()
{
   int choice;
   char ch,data[15];
   FILE *fp;
   color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(180,30,"ADD BOOK PAGE");
   gotoxy(30,8);
   printf("ENTER BOOK ID       : ");
   fflush(stdin);
   scanf("%s",data);
    fp=fopen("book.txt","ab");
   if(fp==NULL)
	{
		printf("Can't Open File");
		exit(1);
	}
   fclose(fp);
   fp=fopen("book.txt","rb");
   if(fp==NULL)
   {
      printf("Can't Open File");
      exit(1);
   }
   fread(&books,sizeof(books),1,fp);
   while(!feof(fp))
   {
     if((strcmp(data,books.id))==0)
     {
       gotoxy(27,12);
       printf("THIS BOOK ID HAVE BEEN ALREADY ADDED");
       gotoxy(35,14);
       printf("SELECT CHOICE ");
       gotoxy(35,16);
       printf("1) CREATE ID");
       gotoxy(35,18);
       printf("2) BACK MENU");
       gotoxy(40,20);
       scanf("%d",&choice);
       if(choice==1)
	    addbooks();
       else
	   adminmenu();
     }
	fread(&books,sizeof(books),1,fp);
   }
   fclose(fp);
   strcpy(books.id,data);
   gotoxy(30,10);
   printf("ENTER TITLE         : ");
   fflush(stdin);
   scanf("%[^\n]s",&books.title);
   fflush(stdin);
   gotoxy(30,12);
   printf("ENTER AUTHOR NAME   : ");
   fflush(stdin);
   scanf("%[^\n]s",&books.author);
   gotoxy(30,14);
   printf("ENTER QUANTITY      : ");
   fflush(stdin);
   scanf("%d",&books.q);
   gotoxy(30,16);
   printf("ENTER SHELF NO      : ");
   fflush(stdin);
   scanf("%d",&books.sn);
   gotoxy(30,18);
   printf("PRESS Y TO ADD BOOK : ");
   fflush(stdin);
   scanf("%s",&ch);
   if(ch=='y'|| ch=='Y')
     addbook("add");
   else
   {   gotoxy(45,21);
       printf("NOT ADDED");
    }
     adminmenu();
 }
void addbook(char status[10])
{
	FILE *fp;
	fp=fopen("book.txt","ab");
	if(fp==NULL)
	{
	    printf("Unable to open file!!!");
	    getch();
	    exit(0);
	}
       fwrite(&books,sizeof(books), 1, fp);
	fclose(fp);
	if((strcmp(status,"add"))==0)
     {  gotoxy(45,21);
       printf("ADDED");
       getch();
     }
}
