/*
 * Nome: Yuri Jose dos Santos Serrano
 * TIA:  4141434-9
 * Nome: Gustavo Santarsieri
 * TIA:  Não Informado
 *
 * Descrição do Programa
 *
 * Este programa simula uma máquina de estado finito,que consegue
 * reconhecer qualquer autômato finito.
 * Quando todas as suas transições são especificadas , não precisa
 * ser acrescentado um estado a mais para representar o estado de erro
 * como nos exercícios 2 e 3, agora no exercício 1 é preciso , pois a transições
 * que vão para o estado de erro.
 * Todos os 3 exercícios funcionaram neste programa.
 * Provas do funcionamento em prints na pasta do problema
 * A include locale permite a acentuação das palavras na linguagem C.
*/



#include <stdio.h>
#include <conio.h>
#include <locale.h> //necessário para usar setlocale


int nentradas; 

int verificar_automato(char,int ); //Declaração da Função
int automato[100][100];
char c[100], palavra[100];

int main()
{
	 setlocale(LC_ALL, "Portuguese"); // Permite a acentuação das palavras
	 printf("Versão 1.0 --------- Coder Yuri Serrano --------\n\n\n\n\n");
     int nestados, nfinais;
     int f[10];
     int i,j,s,final;
     printf("Entre com o número de estados que esse autômato tem \n");
     scanf("%d",&nestados);
     printf("Entre com o número de símbolos que esse autômato tem \n");
     scanf("%d",&nentradas);
     printf("\n Entre com os símbolos de entrada\t");

     for(i=0; i<nentradas; i++) 
     {
           printf("\n\n %d Entrada\t", i+1);
           printf("%c",c[i]=getch());
     }

     printf("\n\nEntre com o número de estados finais\t");
     scanf("%d",&nfinais);

     for(i=0;i<nfinais;i++)
     {
          printf("\n\nEstado Final %d : q",i+1);
          scanf("%d",&f[i]);
     }

     printf("-----------------------------------------------------------------------");
     printf("\n\nA regra de transição é definida do seguinte modo\n");
	 printf("(Estado inicial , Símbolo) => estado final \n\n");
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
          printf("\n Palavra Válida "); 
          else
          printf("Palavra Inválida ");
          getch();

          printf("\nVocê quer sair ?   \n(y) ");
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
     	printf("autômato[%d][%d] = %d\n", d,j,automato[d][j]);
		return(automato[j][d]);
	 }
		return -1;
    
}
