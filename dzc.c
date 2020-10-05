/* Universidade de Brasília
Departamento de Ciência da Computação
Projeto 2 , Introdução à Inteligência Artificial, Turma  A, 1/2020
Prof. Díbio
Sistema Especialista para diagnóstico de Dengue, Zika e Chicungunya
Ana Luísa Salvador Alvarez 160048036
Gabriel Rodrigues Diógenes Macêdo 150126808
Liguagem utilizada: C */

#include <stdio.h>
#include <stdlib.h>

/*variáveis referentes a dengue, zika e chicungunya, que receberão acréscimos conforme indícios de ocorrência*/
int d,z,c;

/*variável que recebe código para diagnóstico*/
int diagnostico;

/*função que faz a abertura da comunicação com o usuário*/
int abertura(){
  d=0;/*no início, variáveis começam com zero*/
  z=0;
  c=0;
  printf("Bem vindo ao Sistema Especialista de Diagnostico\n");
  printf("Responda as perguntas abaixo para obter um diagnostico\n");
  return 0;
}

/*função que verifica dados sobre febre*/
int teve_febre(){
  int febre=0;
  int temp=0;

  printf("\nVoce teve febre? \nResponda 1 para SIM ou 0 para NAO: ");
  scanf("%d", &febre);

  if (febre == 1){
    printf("\nQual a temperatura? \n Responda 1 se foi menor de 38 graus ou 2 se foi 38 graus ou mais: ");
    scanf("%f", &temp);
    if (temp == 2){
      z++;
    }
    if (temp == 1) {
      d++;
      c++;
    }
  }
  else{
    z++;
  }

  return 0;
}

/*função que verifica a respeito de dor muscular*/
int dor_muscular(){

  int dmuscular=0;

  printf("\nVoce teve dor muscular? \nResponda 0 para nenhuma dor, 1 para dor pouco frequente, 2 frequencia moderada ou 3 para bastante frequente: ");
  scanf("%d", &dmuscular);

  if (dmuscular==1){
    c++;
  }
  if (dmuscular==2){
    z++;
  }
  if (dmuscular ==3){
    d++;
  }
}

/*função que avalia dor articular*/

int dor_articular(){

  int darticularfreq=0, darticularintens=0;

  printf("\nVoce teve dor articular? \nResponda 0 para nenhuma dor, 1 para dor pouco frequente, 2 frequencia moderada ou 3 para bastante frequente: ");
  scanf("%d", &darticularfreq);

  if (darticularfreq !=0){
    printf("\nQual a intensidade da dor articular? \nResponda 1 para dor articular leve, 2 para dor articular moderada ou 3 para dor articular intensa: ");
    scanf("%d", &darticularintens);
    if (darticularintens == 1){
      d++;
      z++;
    }
    if (darticularintens == 2){
      z++;
      c++;
    }
    if (darticularintens == 3){
      c++;
    }
  }
  if(darticularfreq== 1){
    d++;
  }
  if (darticularfreq==2){
    z++;
  }
  if(darticularfreq==3){
    c++;
  }

  return 0;
}

/*função que avalia edema articular*/
int edema_articular(){

  int edemafreq=0, edemaintens=0;

  printf("\nVoce teve edema articular? \nResponda 0 para nenhum, 1 para pouco frequente, 2 para frequencia moderada ou 3 para bastante frequente: ");
  scanf("%d", &edemafreq);

  if (edemafreq !=0){
    printf("\nQual a intensidade do edema articular? \nResponda 1 para edema articular leve, 2 para edema articular moderado ou 3 para edema articular intenso: ");
    scanf("%d", &edemaintens);
    if(edemafreq==1){
      d++;
    }
    if (edemafreq==3){
      if(edemaintens ==1){
        z++;
      }
      if(edemaintens==2 || edemaintens ==3){
        c++;
      }
    }
  }
  return 0;
}

/*função que avalia dor de cabeça*/
int dor_cabeca(){

  int dcabeca = 0;

  printf("\nVoce teve dor de cabeca? \nResponda 0 para nenhuma, 1 para pouco frequente e intensa, 2 para frequencia e intensidade moderadas ou 3 para bastante frequente e intensa: ");
  scanf("%d", &dcabeca);

  if (dcabeca ==3){
    d++;
  }

  if(dcabeca ==2){
    z++;
    c++;
  }
  return 0;
}

/*função que avalia coceira*/
int coceira(){

  int coce = 0;

  printf("\nVoce teve coceira? \nResponda 0 para nenhuma, 1 para leve, 2 para moderada ou 3 para coceira intensa: ");
  scanf("%d", &coce);

  if (coce ==1){
    d++;
    c++;
  }
  if (coce == 2 || coce ==3){
    z++;
  }

  return 0;
}


/*função que avalia hipertrofia ganglionar*/
int hip_ganglionar(){

  int ingua = 0;

  printf("\nVoce teve hipertrofia ganglionar, mais conhecida como ingua? \nResponda 0 para NAO TIVE, 1 para ingua leve, 2 para moderada ou 3 para ingua intensa: ");
  scanf("%d", &ingua);

  if (ingua ==1){
    d++;
  }
  if (ingua ==2){
    c++;
  }
  if (ingua ==3){
    z++;
  }
  return 0;
}

/*função que avalia discrasia hemorrágica*/
int disc_hemorragica(){

  int roxo = 0;

  printf("\nVoce teve discrasia hemorragica, evidenciada por manchas roxas, pintinhas vermelho escuro ou sangramento nasal? \nResponda 0 para NAO TIVE, 1 para leve, 2 para moderada ou 3 para intensa: ");
  scanf("%d", &roxo);

  if (roxo == 1){
    c++;
  }
  if (roxo == 2){
    d++;
  }
  if (roxo == 0){
    z++;
  }
  return 0;
}

/*Falta avaliar manchas na pele, que talvez seja por Bayes.
  Falta avaliar conjuntivite, que talvez seja por Bayes também.
  Falta avaliar acometimento neurológico.*/

/*função que compara a quantidade de evidências acumuladas para cada doença*/
int compara(){
  diagnostico=0;

/*diagnostico 1 significa saudável
  diagnostico 2 significa dengue
  diagnostico 3 significa zika
  diagnostico 4 significa chicungunya*/

  if (d<4 && z<4 && c<4){
    diagnostico =1; /*saudável, não acumulou evidências suficientes de nenhuma doença*/
  }
  else{ /*mais de 3 evidências estamos considerando que o paciente tenha alguma das doenças*/

    /*se evidências para dengue forem maiores que para zika e para chicungunya, diagnostico passa a ser 2 (dengue)*/
    if ((d > z)&&(d>c)){
      diagnostico = 2;
    }
    /*se evidências para zika forem maiores que para dengue e para chicungunya, diagnostico passa a ser 3 (zika)*/
    if ((z > d)&& (z>c)) {
      diagnostico = 3;
    }
    /*se evidências para chicungunya forem maiores que para dengue e para zika, diagnostico passa a ser 4 (chicungunya)*/
    if ((c > d)&& (c> z)) {
      diagnostico = 4;
    }
  }
  return 0;
}

/*função que printa o resultado*/
int resultado (){
  if (diagnostico==1){
    printf("\nRESULTADO\nVoce nao parece ter tido Dengue, Zika ou Chicungunya.\n");
  }
  if (diagnostico==2){
    printf("\nRESULTADO\nVoce deve ter tido Dengue.\n");
  }
  if (diagnostico==3){
    printf("\nRESULTADO\nVoce deve ter tido Zika.\n");
  }
  if (diagnostico==4){
    printf("\nRESULTADO\nVoce deve ter tido Chicungunya.\n");
  }
  if (diagnostico==0){/*significa que houve empate entre quantidade de evidências*/
    printf("\nRESULTADO INCONCLUSIVO.\n");
  }

  return 0;
}

int main (){
  abertura();
  teve_febre();
  dor_muscular();
  dor_articular();
  edema_articular();
  dor_cabeca();
  coceira();
  hip_ganglionar();
  disc_hemorragica();
  compara();
  resultado();
  return 0;
}
