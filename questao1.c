#include <stdio.h>
#include <stdlib.h>



void printbits(unsigned char c){
  unsigned int bit;
  for(bit = 128; bit!=0; bit>>=1){
    if((c & bit) != 0) printf("1");
    else printf("0");
  }
}
int main(){
    unsigned char m[8][8];
    unsigned long long r, *pr;
    pr = &r;

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            m[i][j]=rand()%2;
        }
    }
     for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d",m[i][j]);
        }
    printf("\n");
    }
    int i=0;
    for(int byte = 7;byte>=0;byte--){
     // printf("byte = %d ",byte);
        int j= 0;
        
         for(unsigned int bit = 128; bit!=0; bit>>=1){
          //printf("\nbit = %d\n",bit);
            if(m[i][j]==1){
                pr[byte] = pr[byte] | bit;
                
            }
           else
           {pr[byte] = pr[byte] & ~bit;

            }
          
          //  printf("j = %d\n",j);
            j++;
         }
      //  printf("     i = %d\n",i);
         i++;

 
    }

printf("\n");

for(int byte = 7;byte>=0;byte--){
  //printf("byte = %d ",byte);
    printbits(*(pr+byte));
    printf(" ");

}
//printf("\n\n\n%d",m[0][0]);
    return 0;
}