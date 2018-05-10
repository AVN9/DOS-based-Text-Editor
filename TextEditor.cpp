#include<iostream.h>        //INCLUDING THE VARIOUS HEADER FILES
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
//#include<dos.h>
#include<stdlib.h>



//*************************************************************
//*	CLASS NAME    : lines                                 *
//*	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND   *
//*			    DRAWS THE BOX FOR EDITOR          *
//*************************************************************
class lines
{
public :
		void line_hor (int, int, int, char) ;
		void line_ver (int, int, int, char) ;
		void box (int,int,int,int,char) ;
}l11;   //GLOBALLY DECLARING THE OBJECT OF THE CLASS



 /**************************************************************
 *	CLASS NAME    : lines                                  *
 *	FUNCTION NAME : line_hor                               *
 *	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND    *
 *				 DRAW THE HORIZONTAL LINE      *
 ***************************************************************/
void lines :: line_hor(int column1, int column2, int row, char c)
{
   for ( column1; column1<=column2; column1++ )
   {
      gotoxy(column1,row) ;
      cout <<c;
   }
}


//**********************************************************
//	CLASS NAME    : lines
//	FUNCTION NAME : line_ver
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE VERTICAL LINE
//**********************************************************

void lines :: line_ver(int row1, int row2, int column, char c)
{
   for ( row1; row1<=row2; row1++ )
   {
      gotoxy(column,row1) ;
      cout <<c ;
   }
}

//**********************************************************
//	CLASS NAME    : lines
//	FUNCTION NAME : box
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE BOX
//**********************************************************

void lines :: box(int column1, int row1, int column2, int row2, char c)
{

   char c1, c2, c3, c4 ;
     char l1, l2 ;

   {
     /*RECEIVING THE PATTERN USED FOR MAKING THE SIDE BOX
       THE VALUE IS ASSIGNED TO DIFFERENT CHARACTER VARIABLES */

	c1 = c ;
	c2 = c ;
	c3 = c ;
	c4 = c ;
	l1 = c ;
	l2 = c ;
   }

   /*CREATING THE BOX WITH THE DESIRED CHARACTER AS BOUNDARY*/
   gotoxy(column1,row1) ;
   cout <<c1 ;
   gotoxy(column2,row1) ;
   cout <<c2 ;
   gotoxy(column1,row2) ;
   cout <<c3 ;
   gotoxy(column2,row2) ;
   cout <<c4 ;

   column1++ ;
   column2-- ;

   /*CALLING THE FUNCTION FOR HORIZONTAL BOUNDARY*/
   line_hor(column1,column2,row1,l1) ;   //CALLING THE VALUES
   line_hor(column1,1,row2,l1) ;

   /*TRAVERSING THE SCREEN BOUNDARIES TO CREATE THE BOX*/
   column1-- ;
   column2++ ;

   row1++ ;
   row2-- ;

   /*CALLING THE FUNCTION FOR VERTICAL BOUNDARY*/
   line_ver(row1,row2,column1,l2) ;
   line_ver(row1,row2,column2,l2) ;
}


//*******************************************************
//**********************************************************
//	CLASS NAME    : MODES
//	DETAILS       : IT ACCEPTS THE CHOICES FOR
//			    DIFFERENT MODES IN TEXT EDITOR
//**********************************************************//
class modes{
               public:
               	int options1(void);
                void options(char ctr[],char ch[],int) ;
                }M ;            //GLOBALLY DECLARING THE OBJECT




/*******************************************************
       CLASS NAME  : CURSOR_FILE
       DETAILS     : CONTROLS CURSOR MOVEMENT AND
                     FILE HANDLING JOB
//*******************************************************/

class cursor_file{

                int i,j,m,v,i1,a;
                char ch[80],ctr[50],cc;

		public:

                /* CONSTRUCTOR OF THE CLASS*/
                cursor_file()
              {
		  i=0;
		  i1=0;
                  j=0;
		  a=0;
                  m=0;
                  v=0;
                  }

                void file_cursor(void);
                };


/**********************************************************
//	CLASS NAME    : cursor_file
//	FUNCTION NAME : file_cursor
//	DETAILS       : IT DOES THE FILE HANDLING AND
//			CONTROLS THE CURSOR
//**********************************************************/

void cursor_file::file_cursor(void){
       fstream fout,fout1;
        modes M;                // OBJECT OF THE CLASS MODES
	int n=M.options1();
        int a1,l,a2;
       	clrscr();
	gotoxy(5,5);
	cout<<"enter the name of the file : ";  //ENTER THE NAME OF THE FILE
	cin>>ctr;
       	clrscr();
        l11.box(1,1,80,50,219) ;            //CALLING THE BOX FUNCTION
        gotoxy(5,5);
	if(n==1){
	fout.open(ctr,ios::out);            //CONNECTING TO THE OUTPUT MODE
		}
	 else if(n==2)
	 {
	  a=1;
	 fout.open(ctr,ios::app|ios::nocreate|ios::in);
	 if(fout.fail()){                     //IF FILE DOES NOT OPENS
	 cout<<"file does not exist " ;
	 getch();
	 exit(0);
			}

           /* DISPLAYING THE CONTENTS OF THE FILE OPENED*/
	 while(fout){
               fout.get(cc);
               if(cc=='\n')
	       {
	       i1++;
	       gotoxy(5,i1+5);
	       }
	      else
	      cout<<cc;
	       }
	 }
                 j=i1;

	if(n==1)
	gotoxy(5,5);
       a2=a1=0;
	      while(1)
	      {
        while(i!=79)
	{

                if(m<=70)
		{
             /* TEXT ATTRIBUTE FOR REVERSE
                THIS ATTRIBUTE IS CALLED WHEN CTRL-R IS PRESSED
                RETURN TO NORMAL MODE WHEN CTRL-R IS AGAIN PRESSED*/
        	ch[i]=getch();
                if(ch[i]==18)
		{
                	a1=!a1;
                        textattr(67);
                        l=i;
                        }

                /* TEXT ATTRIBUTE FOR BLINKING
                THIS ATTRIBUTE IS CALLED WHEN CTRL-B IS PRESSED
                RETURN TO NORMAL MODE WHEN CTRL-B IS AGAIN PRESSED*/

                if(ch[i]==2)
		{
                	a2=!a2;
                        textattr(135);
                        l=i;
                        }



             //CURSOR MOVEMENT IN DIFFERENT DIRECTIONS

             if(ch[i]=='M'|| ch[i]=='P'|| ch[i]=='K'|| ch[i]=='H')
             {
                if(ch[i]== 'M'){
		gotoxy(++m+5,j+5);
			}             //right
if(ch[i]=='P')
{                l11.line_ver(1,50,1,219);
                  l11.line_ver(1,50,80,219);
		if(j==45)
                {
		cout<<"\n";

		gotoxy(5,50);m=5;
		}
		else
		{
		j++;
		gotoxy(m+5,5+j);
		}
		}                 //down

                if(ch[i]== 'K')
		{
		if(m>0)
		m--;
		gotoxy(m+5,j+5);
		}                //left

                if(ch[i]=='H')
		{
		{
		j--;
		gotoxy(m+5,5+j);
		}
		}                //up

                if(ch[i]=='P')
		gotoxy((--m)+5,j+5);     //soln for down

                if(ch[i]=='H')
		gotoxy((--m)+5,j+5);     //sol for up

                if(ch[i]=='M')
		gotoxy((--m)+5,j+5);     //sol for rt

              if(ch[i]=='K')
	      gotoxy((--m)+5,j+5);       //sol for left
              v=1;
	       }

               else
               {
	        if(v!=1&&!a1&&l!=i&&!a2)         //CALLING THE PROPER MODE
		cout<<ch[i];

	       else if
	       (v!=1&&a1&&l!=i)
	       cprintf("%c",ch[i]);

               else if(v!=1&&a2&&l!=i)
	       cprintf("%c",ch[i]);
                 v=0;

                 if(j!=45)
                 {
		 gotoxy(++m+5,j+5);
		 }
		 }

             	if(ch[i]==8) //backspace
		{
		m=m-2;
		if(m<0)
		{
		j--;
		m=65;
		}
		  gotoxy(m+5,j+5);

                 if(m>0){
			 cout<<" ";
		 	 i--;
			 i--;
		 	}
                         gotoxy(m+5,j+5);	       			   			}
                  }
		else
		{
		cout<<"\n";
		m=0;
		j++;
		gotoxy(5,j+5);
		ch[i]='\n';
		}

	if(ch[i]==13){                //enter key
		if(j==45)
		{
		cout<<"\n";
		gotoxy(5,50);
		}
	else{
	 j++;
	 gotoxy(5,j+5);
	 m=0;
	 ch[i]='\n';
	 	}
			}
		if(ch[i]==27) //escape
		{
		ch[i]='\0';
		break;
		}
		i++;
		}
            if(i!=79)
	    M.options(ctr,ch,a);
	    fout<<ch;
	    fout.close();
	    i=0;

	   fout.open(ctr,ios::app);
		    }
		        }

//**********************************************************
//	CLASS NAME    : modes
//	FUNCTION NAME : options
//	DETAILS       : IT GIVES THE OPTIONS FOR
//			QUIT,SAVE AND SAVE AS
//**********************************************************

void modes:: options(char ctr[],char ch[],int a)
{
	int i;
	char nfile[20],c;
       	fstream fout1,fout2;    // CREATING FILESTREAMS AS FOUT1 AND FOUT2
	 clrscr();
	 gotoxy(33,5);
         cout<<"Exit Window";
         gotoxy(24,45);
         cout<<"Thank you for using the Text Editor";
         gotoxy(5,10);
	cout<<"1. quit \n";
	gotoxy(5,11);
	cout <<"2. save and quit \n";
        gotoxy(5,12);
	cout<<"3. save as \n";
	gotoxy(5,14);         //GIVING THE OPTIONS FOR QUIT,SAVE AND SAVE AS
	cin>>i;
	switch(i)
	{
		case 1:if(a==0)
	        	remove(ctr);
			exit(0);

		case 2:fout1.open(ctr,ios::app);
		       fout1<<ch;      //CONNECTING THE FOUT TO APPEND MODE
                	fout1.close();
			exit(0);

		case 3: fout1.open(ctr,ios::app);//CONNECTING THE FOUT1 TO APPEND MODE
		        fout1<<ch;
			fout1.close();
			cout<<"enter the name " ;//ENTER THE NEW NAME FOR THE FILE
			cin>>nfile;
			fout1.open(ctr,ios::in);
			fout2.open(nfile,ios::out);
			while(fout1)
			{
			fout1.get(c);          //COPYING THE DATA FROM ONE
			cout<<c;               //    FILE TO NEW FILE
			fout2.put(c);
			}
			fout1.close();
			fout2.close();
			exit(0);

	       }

              	}



//**********************************************************
//	CLASS NAME    : modes
//	FUNCTION NAME : options1
//	DETAILS       : IT GIVES THEOPTIONS FOR
//			 NEW AND OPEN
//**********************************************************
int modes::options1(void){
clrscr();
  int i;char ch[20];
  gotoxy(27,3);
  cout<<"---------------------------------" ;
  gotoxy(27,4);
  cout<<"*******TEXT EDITOR PROJECT*******";
  gotoxy(27,5);
  cout<<"---------------------------------";
  gotoxy(5,8);
  cout<<"Choose any option from the following to proceed:\n";
  gotoxy(5,11);
  cout<<"1. new \n";
  gotoxy(5,12);
  cout<<"2. open\n";
  gotoxy(45,40);
  cout<<"project made by :";
  gotoxy(63,40);
  cout<<"AVN9";
  gotoxy(63,41);



  gotoxy(5,15);
  cin>>i;

     switch(i){
	case 1:
	return 1;
	break;

	case 2:
	return 2;
	break;

	default:
	exit(0);
		}
			}


void main(){
	textbackground(LIGHTCYAN); //SETS THE BACKGROUND COLOR IN TEXT MODE
	textcolor(RED) ;	   // SETS THE TEXT COLOR FOR THE TEXT
	clrscr();
        cursor_file C;             //   CREATING THE OBJECT FOR THE CLASS cursor_file
        C.file_cursor();           //   CALLING THE FUNCTION file_cursor
            }
