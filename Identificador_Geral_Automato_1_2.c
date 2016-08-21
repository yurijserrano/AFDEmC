/*
 * Nome: Yuri Jose dos Santos Serrano
 * TIA:  4141434-9
 * Nome: Gustavo Santarsieri
 * TIA:  N�o Informado
 *
 * Descri��o do Programa
 *
 * Este programa simula uma m�quina de estado finito,que consegue
 * reconhecer qualquer aut�mato finito.
 * Quando todas as suas transi��es s�o especificadas , n�o precisa
 * ser acrescentado um estado a mais para representar o estado de erro
 * como nos exerc�cios 2 e 3, agora no exerc�cio 1 � preciso , pois a transi��es
 * que v�o para o estado de erro.
 * Todos os 3 exerc�cios funcionaram neste programa.
 * Provas do funcionamento em prints na pasta do problema
 * A include locale permite a acentua��o das palavras na linguagem C.
*/



#include <stdio.h>
#include <conio.h>
#include <locale.h> //necess�rio para usar setlocale


int nentradas; 

int verificar_automato(char,int ); //Declara��o da Fun��o
int automato[100][100];
char c[100], palavra[100];

int main()
{
	 setlocale(LC_ALL, "Portuguese"); // Permite a acentua��o das palavras
	 printf("Vers�o 1.0 --------- Coder Yuri Serrano --------\n\n\n\n\n");
     int nestados, nfinais;
     int f[10];
     int i,j,s,final;
     printf("Entre com o n�mero de estados que esse aut�mato tem \n");
     scanf("%d",&nestados);
     printf("Entre com o n�mero de s�mbolos que esse aut�mato tem \n");
     scanf("%d",&nentradas);
     printf("\n Entre com os s�mbolos de entrada\t");

     for(i=0; i<nentradas; i++) 
     {
           printf("\n\n %d Entrada\t", i+1);
           printf("%c",c[i]=getch());
     }

     printf("\n\nEntre com o n�mero de estados finais\t");
     scanf("%d",&nfinais);

     for(i=0;i<nfinais;i++)
     {
          printf("\n\nEstado Final %d : q",i+1);
          scanf("%d",&f[i]);
     }

     printf("-----------------------------------------------------------------------");
     printf("\n\nA regra de transi��o � definida do seguinte modo\n");
	 printf("(Estado inicial , S�mbolo) => estado final \n\n");
     for(i=0; i<nentradas; i++)
     {
          for(j=0; j<nestados; j++)
          {
               printf("\n(q%d , %c ) = q",j,c[i]);
               scanf("%d",&automato[i][j]);
          }
     }

     do
     {
          i=0,final=0,s=0;
          printf("\n\nEntre com a palavra.. ");
          scanf("%s",palavra);

          while(palavra[i]!= '\0')
          if((s=verificar_automato(palavra[i++],s))<0)
          break;
          for(i=0 ;i<nfinais ;i++)
          if(f[i] ==s )
          final=1;
          if(final==1)
          printf("\n Palavra V�lida "); 
          else
          printf("Palavra Inv�lida ");
          getch();

          printf("\nVoc� quer sair ?   \n(y) ");
     }
     while(getch()!= 'y');

     getch();
}
int verificar_automato(char b,int d)
{
     int j;
     for(j=0; j<nentradas; j++)
     if(b==c[j])
     {
     	printf("aut�mato[%d][%d] = %d\n", d,j,automato[d][j]);
		return(automato[j][d]);
	 }
		return -1;
    
}
