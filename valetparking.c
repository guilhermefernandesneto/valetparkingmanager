#include <stdio.h>
#include <time.h>


struct Tveiculo{
char placa[7];
char data_sistema_entra[100];
char hora_sistema_entra[100];
char data_sistema_sai;
char hora_sistema_sai;} carro;


// FUNCAO PARA FORMATACAO DA HORA
char *format(int number);
// FUNCAO PARA RETORNAR DATA
char *data(void);
// FUNCAO PARA RETORNAR HORA
char *hora(void);


int main(){

  int opcao;

  while (opcao != 4){

  printf("Digite a opção desejada\n");
  printf("1. ENTRADA DE VEÍCULOS\n");
  printf("2. SAÍDA DE VEÍCULOS\n");
  printf("3. GERAR HISTÓRICO\n");
  printf("4. FECHAR ESTACIONEMENTO\n");
  scanf("%d", &opcao);

  switch(opcao){
  
  case 1: //ENTRADA DE VEÍCULOS
    printf("Digite a placa do veículo\n");
    scanf("%s", carro.placa);

    sprintf(carro.data_sistema_entra,"%s",data());
    sprintf(carro.hora_sistema_entra,"%s",hora());

    printf("%s\n",carro.data_sistema_entra);
    printf("%s\n",carro.hora_sistema_entra);
    break;

  case 2: //SAÍDA DE VEÍCULOS
    printf("Digite a placa do veículo\n");
    scanf("%s", carro.placa);
   
    sprintf(carro.data_sistema_sai,"%s",data());
    sprintf(carro.hora_sistema_sai,"%s",hora());

    printf("%s\n",carro.data_sistema_sai);
    printf("%s\n",carro.hora_sistema_sai);
    break;

  case 3: //GERA HISTÓRICO
    printf("Digite a placa do veículo\n");
    scanf("%s", carro.placa);
    break;

  case 4: //FIM DO PROGRAMA
    printf("ESTACIONAMENTO FECHADO\n");
    break;
  }
  }

}

// FUNCAO PARA FORMATACAO DA HORA
char *format(int number){      
   char    *retorno,
      ret[100];
   int    i;

   if (number < 10){
      sprintf(ret,"0%d",number);
      retorno = ret;
      return retorno;
   }
   else{
      sprintf(ret,"%d",number);
      retorno = ret;
      return retorno;
   }
}      



// FUNCAO PARA RETORNAR DATA
char *data(void){

   int dia,mes,ano;
   char   var1[100],
      var2[100],
      var3[100],
      var4[100],
      *dataPtr;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano = local -> tm_year + 1900;
     
   sprintf(var1,"%s",format(dia));
   sprintf(var2,"%s",format(mes));
   sprintf(var3,"%s",format(ano));
     
   sprintf(var4,"%s/%s/%s",var1,var2,var3);

   // retorna data no formato dd:MM:yyyy com um ponteiro
   dataPtr = var4;
   return dataPtr;
}

// FUNCAO PARA RETORNAR HORA
char *hora(void){
      
   int   hora,minuto,segundo;
   char   var1[100],
      var2[100],
      var3[100],
      var5[100],
      *retorno;
   
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);
      
   // obtem hora, minuto e segundo e os aloca em uma variavel do tipo inteiro
   hora   =   local -> tm_hour;
   minuto   =    local -> tm_min;
   
   // por algum motivo precisa converter os valores retornados pelos ponteiros
   // da funcao em variaveis do tipo char
   sprintf(var1,"%s",format(hora));
   sprintf(var2,"%s",format(minuto));
   
   // cria a variavel de retorno dos dados e cria um ponteiro para essa variavel
   sprintf(var5,"%s:%s",var1,var2);
   
   // retorna hora no formato hh:mm:ss com um ponteiro
   retorno = var5;
   return retorno;   
}
