#include <stdio.h>
#include <stdlib.h>

//Funcao especifica para setar as variaveis
int SetVariables(
	float* temperatura,
	int* dias_de_febre,
	int* mancha_pele_dia,
	int* dor_musculos_freq,
	int* dor_articulacao_freq,
	int* intensidade_dor_articular,
	int* dor_de_cabeca,
	int* coceira,
	int* hipertrofia_ganglionar,
	int* discrasia_hemorragica,
	int* acolhimento_neurologico,
	int* edema_articulacao,
	int* conjuntivite
)
{
	int neonato = 0;
	*dias_de_febre = 0;

	printf("Digite sua temperatura: \n");
	scanf("%f", temperatura);
	if(*temperatura >= 37.5){
		printf("Quantos dias de febre o paciente teve?\n");
		scanf("%d", dias_de_febre);
	}
	printf("A partir de qual dia comecaram a aparecer manchas na sua pele (Digite 0 se não se aplica.): \n");
	scanf("%d", mancha_pele_dia);
	printf("De uma escala de 0 a 3, qual a frequencia de dores nos musculos?\n");
	scanf("%d", dor_musculos_freq);
	printf("De uma escala de 0 a 3, qual a frequencia de dores nas ariticulacoes?\n");
	scanf("%d", dor_articulacao_freq);
	printf("Qual a intensidade da dor articular?\n0 - Nenhuma\n1 - Leve\n2 - Moderada\n3 - Intensa\n\n");
	scanf("%d", intensidade_dor_articular);
	printf("De uma escala de 0 a 3 qual a frequencia e a intensidade da dor de cabeca?\n");
	scanf("%d", dor_de_cabeca);
	printf("Qual a intensidade da coceira?\n0 - Nenhuma\n1 - Leve\n2 - Moderada\n3 - Intensa\n\n");
	scanf("%d", coceira);
	printf("Qual a frequencia da hipertrofia ganglionar?\n0 - Nenhuma\n1 - Leve\n2 - Moderada\n3 - Intensa\n\n");
	scanf("%d", hipertrofia_ganglionar);
	printf("Qual a frequencia da discrasia hemorragica?\n0 - Nenhuma\n1 - Leve\n2 - Moderada\n3 - Intensa\n\n");
	scanf("%d", discrasia_hemorragica);
	printf("Houve necessidade de acolhimento neurologico?\n0 - Não\n1 - Sim\n\n");
	scanf("%d", acolhimento_neurologico);
	if(*acolhimento_neurologico){
		printf("O paciente eh neonato?\n");
		scanf("%d", &neonato);
	}
	printf("Houve edema na articulacao?\n0 - Não\n1 - Sim\n\n");
	scanf("%d", edema_articulacao);
	if(*edema_articulacao){
		printf("Qual a intensidade do edema na articulacao?\n1 - Leve\n2 - Moderada\n3 - Intensa\n\n");
		scanf("%d", edema_articulacao);
	}
	printf("O paciente aprensentou conjuntivite?\n0 - Não\n1 - Sim\n\n");
	scanf("%d", conjuntivite);

	return neonato;
}

//funcao para calcular a pontuacao de probabilidade do paciente nao ter nenhuma das doencas
float PontuacaoSaudavel(
	float temperatura,
	int mancha_pele_dia,
	int dor_musculos_freq,
	int dor_articulacao_freq,
	int intensidade_dor_articular,
	int dor_de_cabeca,
	int coceira,
	int hipertrofia_ganglionar,
	int discrasia_hemorragica,
	int acolhimento_neurologico,
	int edema_articulacao,
	int conjuntivite
)
{
	float pont = 0;

	if(temperatura < 37,5){
		pont++;
	}
	if(!mancha_pele_dia){
		pont++;
	}
	if(!dor_musculos_freq){
		pont++;
	}
	if(!dor_articulacao_freq){
		pont++;
	}
	if(!intensidade_dor_articular){
		pont++;
	}
	if(!dor_de_cabeca){
		pont++;
	}
	if(!coceira){
		pont++;
	}
	if(!hipertrofia_ganglionar){
		pont++;
	}
	if(!discrasia_hemorragica){
		pont++;
	}
	if(!acolhimento_neurologico){
		pont++;
	}
	if(!edema_articulacao){
		pont++;
	}
	if(!conjuntivite){
		pont++;
	}

	return pont;
}

float PontuacaoDengue(
	float temperatura,
	int dias_de_febre,
	int mancha_pele_dia,
	int dor_musculos_freq,
	int dor_articulacao_freq,
	int intensidade_dor_articular,
	int dor_de_cabeca,
	int coceira,
	int hipertrofia_ganglionar,
	int discrasia_hemorragica,
	int acolhimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura > 38){
		pont+=0.5;
	}
	if(dias_de_febre >= 4 && dias_de_febre <= 7){
		pont+=0.5;
	}
	if(mancha_pele_dia >= 4){
		pont+= 0.35;
	}
	if(dor_musculos_freq == 3){
		pont++;
	}
	if(dor_articulacao_freq == 1){
		pont++;
	}
	if(intensidade_dor_articular == 1){
		pont++;
	}
	if(dor_de_cabeca == 3){
		pont++;
	}
	if(coceira == 1){
		pont++;
	}
	if(hipertrofia_ganglionar == 1){
		pont++;
	}
	if(discrasia_hemorragica == 2){
		pont++;
	}
	if(acolhimento_neurologico){
		if(!neonato){
			pont+=0.1;
		}
	}
	if(!edema_articulacao){
		pont+=0.1;
	}
	if(conjuntivite){
		pont+=0.1;
	}

	return pont;
}

float PontuacaoZika(
	float temperatura,
	int dias_de_febre,
	int mancha_pele_dia,
	int dor_musculos_freq,
	int dor_articulacao_freq,
	int intensidade_dor_articular,
	int dor_de_cabeca,
	int coceira,
	int hipertrofia_ganglionar,
	int discrasia_hemorragica,
	int acolhimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura < 38){
		pont+=0.5;
	}
	if(dias_de_febre == 1 || dias_de_febre == 2){
		pont+=0.5;
	}
	if(mancha_pele_dia == 1 || mancha_pele_dia == 2){
		pont+= 0.95;
	}
	if(dor_musculos_freq == 2){
		pont++;
	}
	if(dor_articulacao_freq == 2){
		pont++;
	}
	if(intensidade_dor_articular == 1 || intensidade_dor_articular == 2){
		pont++;
	}
	if(dor_de_cabeca == 2){
		pont++;
	}
	if(coceira == 2 || coceira == 3){
		pont++;
	}
	if(hipertrofia_ganglionar == 3){
		pont++;
	}
	if(!discrasia_hemorragica){
		pont++;
	}
	if(acolhimento_neurologico){
		if(!neonato){
			pont+=0.5;
		}
	}
	if(edema_articulacao == 1){
		pont++;
	}
	if(conjuntivite){
		pont+=0.7;
	}

	return pont;
}

float PontuacaoChikungunya(
	float temperatura,
	int dias_de_febre,
	int mancha_pele_dia,
	int dor_musculos_freq,
	int dor_articulacao_freq,
	int intensidade_dor_articular,
	int dor_de_cabeca,
	int coceira,
	int hipertrofia_ganglionar,
	int discrasia_hemorragica,
	int acolhimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura >= 38){
		pont+=0.5;
	}
	if(dias_de_febre == 2 || dias_de_febre == 3){
		pont+=0.5;
	}
	if(mancha_pele_dia >= 2 || mancha_pele_dia <= 5){
		pont+= 0.5;
	}
	if(dor_musculos_freq == 1){
		pont++;
	}
	if(dor_articulacao_freq == 3){
		pont++;
	}
	if(intensidade_dor_articular == 2 || intensidade_dor_articular == 3){
		pont++;
	}
	if(dor_de_cabeca == 2){
		pont++;
	}
	if(coceira == 1){
		pont++;
	}
	if(hipertrofia_ganglionar == 2){
		pont++;
	}
	if(discrasia_hemorragica == 1){
		pont++;
	}
	if(acolhimento_neurologico){
		if(neonato){
			pont+=1;
		}
	}
	if(edema_articulacao == 2 || edema_articulacao == 3){
		pont++;
	}
	if(conjuntivite){
		pont+=0.3;
	}

	return pont;
}

int main(){
	float temperatura; 					//temperatura do paciente
	int dias_de_febre = 0,				//caso o paciente tenha febre, isso contem os dias de febre
		mancha_pele_dia, 				//dia que as manchas na pele comecaram a aparecer / 0 = nao apresentou manchas
		dor_musculos_freq, 				//escala de 0 a 3 das dores dos musculos
		dor_articulacao_freq, 			//esclada de 0 a 3 das dores nas articulacoes
		intensidade_dor_articular, 		//intensidade da dor articular - 0 - Nenhuma, 1 - Leve, 2 - Moderada, 3 - Intensa
		dor_de_cabeca, 					//escala de 0 a 3 das dores de cabeca
		coceira, 						//intensidade da coceira - 0 - Nenhuma, 1 - Leve, 2 - Moderada, 3 - Intensa
		hipertrofia_ganglionar,			//frequencia da hipertrofia ganglionar - 0 - Nenhuma, 1 - Leve, 2 - Moderada, 3 - Intensa
		discrasia_hemorragica,			//frequencia da discrasia hemorragica - 0 - Nenhuma, 1 - Leve, 2 - Moderada, 3 - Intensa
		edema_articulacao,				//intensidade da discrasia hemorragica - 0 - Nenhuma, 1 - Leve, 2 - Moderada, 3 - Intensa
		acolhimento_neurologico,		//booleano apontando se houve necessidade de acolhimento neurologico
		conjuntivite,					//booleano apontando se o paciente apresentou conjuntivite
		neonato;						//booleano apontando se o paciente eh neonato - importante no caso de acolhimento neurologico

	float pontuacao_saudavel, pontuacao_zika, pontuacao_dengue, pontuacao_chikungunya, total;

	//funcao seta as variaveis e caso o paciente tenha tido necessidade de acompanhamento neurologico, ele retorna se o paciente eh neonato ou nao
	neonato = SetVariables(
		&temperatura,
		&dias_de_febre,
		&mancha_pele_dia,
		&dor_musculos_freq,
		&dor_articulacao_freq,
		&intensidade_dor_articular,
		&dor_de_cabeca,
		&coceira,
		&hipertrofia_ganglionar,
		&discrasia_hemorragica,
		&acolhimento_neurologico,
		&edema_articulacao,
		&conjuntivite
	);

	//calcula a pontuacao de cada sintoma. Se o paciente nao apresentar o sintoma, a probabbilidade dele nao ter nenhuma das tres doenças aumenta.
	pontuacao_saudavel = PontuacaoSaudavel(temperatura, mancha_pele_dia, dor_musculos_freq,
							dor_articulacao_freq,
							intensidade_dor_articular,
							dor_de_cabeca,
							coceira,
							hipertrofia_ganglionar,
							discrasia_hemorragica,
							acolhimento_neurologico,
							edema_articulacao,
							conjuntivite
						);

	pontuacao_dengue = PontuacaoDengue(
							temperatura,
							dias_de_febre,
							mancha_pele_dia,
							dor_musculos_freq,
							dor_articulacao_freq,
							intensidade_dor_articular,
							dor_de_cabeca,
							coceira,
							hipertrofia_ganglionar,
							discrasia_hemorragica,
							acolhimento_neurologico,
							edema_articulacao,
							conjuntivite,
							neonato
						);

	pontuacao_zika = PontuacaoZika(
							temperatura,
							dias_de_febre,
							mancha_pele_dia,
							dor_musculos_freq,
							dor_articulacao_freq,
							intensidade_dor_articular,
							dor_de_cabeca,
							coceira,
							hipertrofia_ganglionar,
							discrasia_hemorragica,
							acolhimento_neurologico,
							edema_articulacao,
							conjuntivite,
							neonato
						);

	pontuacao_chikungunya = PontuacaoChikungunya(
							temperatura,
							dias_de_febre,
							mancha_pele_dia,
							dor_musculos_freq,
							dor_articulacao_freq,
							intensidade_dor_articular,
							dor_de_cabeca,
							coceira,
							hipertrofia_ganglionar,
							discrasia_hemorragica,
							acolhimento_neurologico,
							edema_articulacao,
							conjuntivite,
							neonato
						);

	total = pontuacao_saudavel + pontuacao_dengue + pontuacao_zika + pontuacao_chikungunya;

	system("clear");
	printf("Saudavel: %.1f\n", pontuacao_saudavel);
	printf("Dengue: %.1f\n", pontuacao_dengue);
	printf("Zika: %.1f\n", pontuacao_zika);
	printf("Chikungunya: %.1f\n\n\n", pontuacao_chikungunya);

	printf("Probabilidades:\n");
	printf("Saudavel: %.1f%%\n", (pontuacao_saudavel/total)*100);
	printf("Dengue: %.1f%%\n", (pontuacao_dengue/total)*100);
	printf("Zika: %.1f%%\n", (pontuacao_zika/total)*100);
	printf("Chikungunya: %.1f%%\n\n\n", (pontuacao_chikungunya/total)*100);


	return(0);
}