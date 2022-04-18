#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
struct boo
{char ab[10];
 int p;
};
void read(char a[])
{ printf("enter your expression in sop:\n");
scanf("%s",a);
}
int var(char a[],int l)
{
for(int i=0;i<l;i++)
{  if(a[i]=='+')
      return(i);
  }
return(0);
}
void sop(char a[])
{int i,x,i1,i2,j,L,M=0,*p,l,Q=0,d,N,count=0,k,temp=0;

 l=strlen(a);
 d=var(a,l);
 N=l/d;
 p=(int*)malloc((d+1)*sizeof(int));
 for(i=0;i<=d;i++)
 p[i]=0;
//printf("value of d is=%d, l=%d",d,l);
 struct boo ***A,B;
 A=(boo***)malloc((d+1)*sizeof(boo));
 for(i=0;i<=d;i++)
 A[i]=(boo**)malloc((d+1-i)*sizeof(boo));
 for(i=0;i<=d;i++)
  for(j=0;j<=d-i;j++)
  A[i][j]=(boo*)malloc(N*2*sizeof(boo));

   for(i=0;i<=d;i++)
    for(j=0;j<=d-i;j++)
     for(k=0;k<N*2;k++)
{ A[i][j][k].p=-1;
	 for(M=0;M<10;M++)
	 A[i][j][k].ab[M]=NULL;
       }
       //part 1
   for(k=0;k<l;k+=(d+1))
{ for(j=0;j<d;j++)
     {B.ab[j]=a[j+k];
     if(a[j+k]=='1')
       count++;

     }//  printf("\ncount=%d\n",count);
      L=p[count];
B.ab[j]=NULL;
     A[0][count][L].p=0;
strcpy(A[0][count][L].ab,B.ab);
    // printf("%s",A[L][count].ab);
     p[count]++;
     count=0;
    }

    Q=0;
     //part2
  for(x=0;x<d;x++)
   {
     for(i2=0;i2<=d;i2++)
     p[i2]=0;

    for(i=0;i<d-x;i++)
{ for(j=0;j<N*2;j++)
      {
	for(k=0;k<N*2;k++)
	{//compare A[0][i][j]==A[0][i+1][k];
	  count=0;
	    for(i1=0;i1<d;i1++)
	{ if(A[x][i][j].ab[i1]==A[x][i+1][k].ab[i1] && A[x][i][j].ab[i1]!=NULL)
	{ count++;
	       }
	    }
	       if(count==d-1)
		{  L=p[i]; temp=1;
		    A[x][i][j].p=1;
		    A[x][i+1][k].p=1;
		   for(i1=0;i1<d;i1++)
		{ if(A[x][i][j].ab[i1]==A[x][i+1][k].ab[i1])
		{ A[x+1][Q][L].ab[i1]=A[x][i][j].ab[i1];
		       }
		      else
		{ A[x+1][Q][L].ab[i1]='_';
		       }

		    }
		    p[i]++;
		    A[x+1][Q][L].ab[i1]=NULL;
		    A[x+1][Q][L].p=0;
		 }

	}
      }
      if(temp==1)
       {Q++;temp=0;}
    }
    Q=0;
    temp=0;
   }
printf("\n");
 char val[100][10];
 M=0;   temp=0;
  for(i=0;i<=d;i++)
    for(j=0;j<=d-i;j++)
     for(k=0;k<N*2;k++)
       {
	 if(A[i][j][k].p==0)
	  {strcpy(val[M],A[i][j][k].ab);
	  M++;}
       }
printf("result=");
    for(i=0;i<M;i++)
{  for(j=i+1;j<M;j++)
	 if(!strcmp(val[i],val[j]))
	  temp=1;
	if(temp==0)
	printf("%s, ",val[i]);
	 temp=0;
     }
}

void main()
{  clrscr();
char *a;
int c,s;
printf("enter 1 to read manual:\nenter 2 to proceed:\n");
scanf("%d",&s);
if(s==2)
{ raavan:
clrscr();
read(a);
sop(a);
getch();
}
else
{clrscr();
printf("1.THIS PROGRAM CAN PERFORM ONLY SOP MINIMIZATION:\n");
printf("2.ENTER THE EQUATION IN CANONICAL FORM:\n");
printf("3.ENTER THE EQUATION IN SUM OF BINARY NUMBER'S FORM\nEG:   FOR EQUATION XYZ+X'Y'Z'\n\t\tINSERT 111+000\n");
printf("4.OUTPUT WILL ALSO DISPLAYED IN SIMILAR FORM:\n");
printf("EG    FOR Y'Z'+X'Z'\n\t      PROGRAM WILL PRINT _00+0_0");
printf("\n*************PRESS ENTER TO PROCEED***************");
getch();
goto raavan;
}
getch();
}
