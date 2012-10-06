#include <stdio.h>
#include <math.h>
void main(){
          int p,e,i,d,j,no=1;
          scanf("%d %d %d %d\n",&p,&e,&i,&d);
          while(p!=-1 && e!=-1 && i!=-1 && d!=-1){
                for(j=d+1; j<=21252; j++)     if ((j-p)%23 == 0) break;
                for( ; j<=21252; j=j+23)         if ((j-e)%28 == 0) break;
                for( ; j<=21252; j=j+23*28)  if ((j-i)%33 == 0) break;
                printf("Case %d: the next triple peak occurs in %d days.\n",no,j-d);       
                scanf("%d %d %d %d\n",&p,&e,&i,&d);
                no++;
         }
}