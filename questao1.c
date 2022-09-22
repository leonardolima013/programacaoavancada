//Aluno: Leonardo Barbosa Lima
//Questao 1


#include <stdio.h>
#include <stdlib.h>

void printbits(unsigned char c){ //Função para printar os bits de um byte de determinada variavel
  unsigned int bit;
  for(bit = 128; bit!=0; bit>>=1){
    if((c & bit) != 0) printf("1");
    else printf("0");
  }
}


int main(void) {
  unsigned char m[8][8]; //Matriz base a qual será convertida
  unsigned long long r; //Variavel que receberá os bits/bytes da matriz
  unsigned long long *pr; //Ponteiro necessario para manipular os bytes/bits da variavel
  pr =&r;

  for(int i=0;i<8;i++){    //Criação da matriz aleatoria contendo apenas '0' e '1'
    for(int j=0;j<8;j++){
      m[i][j]=rand()%2;
    }
  }

    for(int i=0;i<8;i++){    //Mostrando a matriz obtida na tela.
    for(int j=0;j<8;j++){
      printf("%d ",m[i][j]);
    }
    printf("\n");
  }
  printf("\n");

int linha=0, coluna;
  for(int byte=7;byte>=0;byte--)
  {  //preenchimento dos bytes da variavel unsigned long long
    coluna = 0;
      for(unsigned int bit=128;bit!=0;bit>>=1){
        if(m[linha][coluna]!=1){
          pr[byte]=pr[byte] & ~bit;
        }
        else{
          pr[byte]=pr[byte] | bit;
        }
        coluna++;
      }
    linha++;
    }      
  
for(int byte = 7;byte>=0;byte--){ //Mostrando os 8 bytes da variavel unsigned long long
    printbits(*(pr+byte));
    printf(" ");

}
  return 0;
}
