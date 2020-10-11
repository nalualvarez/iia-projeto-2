#include <stdio.h>
#include <stdlib.h>

//Funcao especifica para setar as variaveis
int Formulario(
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
	int* acometimento_neurologico,
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
	printf("Houve acometimento neurologico?\n0 - Não\n1 - Sim\n\n");
	scanf("%d", acometimento_neurologico);
	if(*acometimento_neurologico){
		printf("O paciente eh neonato?\n0 - Não\n1 - Sim\n\n");
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
	int dor_de_cabeca,
	int coceira,
	int hipertrofia_ganglionar,
	int discrasia_hemorragica,
	int acometimento_neurologico,
	int edema_articulacao,
	int conjuntivite
)
{
	float pont = 0;

	if(temperatura < 37,5){ 			//Caso o paciente nao tenha febre, um ponto eh adicionado
		pont++;
	}
	if(!mancha_pele_dia){				//Manchas na pele são sintomas que nao sao muito usuais, visto isso, caso o paciente nao apresente manchas na pele, apenas meio ponto é adicionado
		pont+=0.5;
	}
	if(!dor_musculos_freq){				//Caso o paciente nao tenha dor nos musculos um ponto eh adicionado
		pont++;
	}
	if(!dor_articulacao_freq){			//Caso o paciente nao tenha dor nas articulacoes um ponto eh adicionado
		pont++;
	}
	if(!dor_de_cabeca){					//Caso o paciente nao tenha dor de cabeca um ponto eh adicionado
		pont++;
	}
	if(!coceira){						//Caso o paciente nao tenha coceira um ponto eh adicionado
		pont++;
	}
	if(!hipertrofia_ganglionar){		//Caso o paciente nao tenha coceira um ponto eh adicionado
		pont++;
	}
	if(!discrasia_hemorragica){			//Caso o paciente nao discrasia hemorragica um ponto eh adicionado
		pont++;
	}
	if(!acometimento_neurologico){		//Caso o paciente nao tenha acometimento 0,2 ponto eh adicionado, visto que eh um sintoma raro dentre as doencas
		pont+=0.2;
	}
	if(!edema_articulacao){				//Caso o paciente nao tenha edema na articulacao 0,3 ponto eh adicionado, visto que eh um sintoma raro dentre as doencas
		pont+=0.3;
	}
	if(!conjuntivite){					//Caso o paciente nao tenha conjuntivite 0,4 ponto eh adicionado, visto que eh um sintoma menos frequente dentre as doencas
		pont+=0.4;
	}

	return pont;
}

//funcao para calcular a pontuacao de probabilidade do paciente ter dengue
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
	int acometimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura > 38){								//Caso o paciente apresente febre maior que 38 graus, 0,5 ponto eh adicionado. Se a febre ocorrer no numero de dias corretos mais 0,5 ponto eh adicionados
		pont+=0.5;
	}
	if(dias_de_febre >= 4 && dias_de_febre <= 7){		//Caso a febre ocorra entre 4 e 7 dias, 0,5 ponto eh adiciondo
		pont+=0.5;
	}
	if(mancha_pele_dia >= 4){							//Caso tenha mancha na pele a partir do 4° dia, 0,4 ponto eh adicionado visto que esse sintoma ocorre apenas de 30% a 50% dos infectados
		pont+= 0.4;
	}
	if(dor_musculos_freq == 3){							//caso tenha dor nos musculos de intensidade 3, um ponto eh adicionado
		pont++;
	}
	if(dor_articulacao_freq == 1){						//caso a dor na articulacao seja de frequencia 1, um ponto eh adicionado
		pont++;
	}
	if(intensidade_dor_articular == 1){					//caso a intensidade da dor na articulacao seja leve , um ponto eh adicionado
		pont++;
	}
	if(dor_de_cabeca == 3){								//caso a intensidade da dor de cabeca seja 3, um ponto eh adicionado
		pont++;
	}
	if(coceira == 1){									//caso a intensidade da coceira seja leve , um ponto eh adicionado
		pont++;
	}
	if(hipertrofia_ganglionar == 1){					//caso a frequencia hipertrofia seja leve , um ponto eh adicionado
		pont++;
	}
	if(discrasia_hemorragica == 2){						//caso a frequencia da discrasia hemorragica seja moderada , um ponto eh adicionado
		pont++;
	}
	if(acometimento_neurologico){						//caso o paciente apresente acometimento neuroloico e nao seja neonato, visto que eh um sintoma raro, apenas 0,1 ponto eh adicionado
		if(!neonato){
			pont+=0.1;
		}
	}
	if(!edema_articulacao){								//caso o paciente apresente edema na articulacao, visto que eh um sintoma raro, apenas 0,1 ponto eh adicionado
		pont+=0.1;
	}
	if(conjuntivite){									//caso o paciente apresente conjuntivite, visto que eh um sintoma raro, apenas 0,1 ponto eh adicionado
		pont+=0.1;
	}

	return pont;
}

//funcao para calcular a pontuacao de probabilidade do paciente ter Zika
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
	int acometimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura < 38){													//Caso o paciente apresente febre menor que 38 graus ou sem febre, 0,5 ponto eh adicionado. Se a febre ocorrer no numero de dias corretos mais 0,5 ponto eh adicionados
		pont+=0.5;
	}
	if(dias_de_febre == 1 || dias_de_febre == 2 || dias_de_febre == 0){		//Caso a febre ocorra entre 1 e 2 dias ou nao ocorra febre, 0,5 ponto eh adiciondo
		pont+=0.5;
	}
	if(mancha_pele_dia == 1 || mancha_pele_dia == 2){						//Caso tenha mancha na pele entre o 1° e o 2° dia, 0,95 ponto eh adicionado visto que esse sintoma ocorre de 90% a 100% dos infectados
		pont+= 0.95;
	}
	if(dor_musculos_freq == 2){												//caso tenha dor nos musculos de intensidade 2, um ponto eh adicionado
		pont++;
	}
	if(dor_articulacao_freq == 2){											//caso a dor na articulacao seja de frequencia 2, um ponto eh adicionado
		pont++;
	}
	if(intensidade_dor_articular == 1 || intensidade_dor_articular == 2){	//caso a intensidade da dor na articulacao seja leve/moderada , um ponto eh adicionado
		pont++;
	}
	if(dor_de_cabeca == 2){													//caso a intensidade da dor de cabeca seja 2, um ponto eh adicionado
		pont++;
	}
	if(coceira == 2 || coceira == 3){										//caso a intensidade da coceira seja moderada/intensa , um ponto eh adicionado
		pont++;
	}
	if(hipertrofia_ganglionar == 3){										//caso a frequencia hipertrofia seja intensa , um ponto eh adicionado
		pont++;
	}
	if(!discrasia_hemorragica){												//caso nao tenha discrasia hemorragica , um ponto eh adicionado												
		pont++;
	}
	if(acometimento_neurologico){											//caso o paciente apresente acometimento neuroloico e nao seja neonato, visto que eh mais frequente que a dengue e a Chikungunya, 0,5 ponto eh adicionado
		if(!neonato){
			pont+=0.5;
		}
	}
	if(edema_articulacao == 1){												//caso o paciente apresente edema na articulacao com de leve intensidade, 1 ponto eh adicionado
		pont++;
	}
	if(conjuntivite){														//caso o paciente apresente conjuntivite, visto que eh um sintoma que ocorre de 50-90% dos casos, 0,7 ponto eh adicionado
		pont+=0.7;
	}

	return pont;
}

//funcao para calcular a pontuacao de probabilidade do paciente ter Chikungunya
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
	int acometimento_neurologico,
	int edema_articulacao,
	int conjuntivite,
	int neonato
)
{
	float pont = 0;

	if(temperatura >= 38){														//Caso o paciente apresente febre maior que 38 graus, 0,5 ponto eh adicionado. Se a febre ocorrer no numero de dias corretos mais 0,5 ponto eh adicionados
		pont+=0.5;
	}
	if(dias_de_febre == 2 || dias_de_febre == 3){								//Caso a febre ocorra entre 2 a 3 dias, 0,5 ponto eh adiciondo
		pont+=0.5;
	}
	if(mancha_pele_dia >= 2 || mancha_pele_dia <= 5){							//Caso tenha mancha na pele entre o 2° e o 5° dia, 0,5 ponto eh adicionado visto que esse sintoma ocorre com 50% dos infectados
		pont+= 0.5;
	}
	if(dor_musculos_freq == 1){													//caso tenha dor nos musculos de intensidade 1, um ponto eh adicionado
		pont++;
	}
	if(dor_articulacao_freq == 3){												//caso a dor na articulacao seja de frequencia 3, um ponto eh adicionado
		pont++;
	}
	if(intensidade_dor_articular == 2 || intensidade_dor_articular == 3){		//caso a intensidade da dor na articulacao seja moderada/intensa , um ponto eh adicionado
		pont++;
	}
	if(dor_de_cabeca == 2){														//caso a intensidade da dor de cabeca seja 2, um ponto eh adicionado
		pont++;
	}
	if(coceira == 1){															//caso a intensidade da coceira seja leve , um ponto eh adicionado
		pont++;
	}
	if(hipertrofia_ganglionar == 2){											//caso a frequencia hipertrofia seja moderada , um ponto eh adicionado
		pont++;
	}
	if(discrasia_hemorragica == 1){												//caso a frequencia da discrasia hemorragica seja leve , um ponto eh adicionado					
		pont++;
	}
	if(acometimento_neurologico){												//caso o paciente apresente acometimento neuroloico e nao neonato, 1 ponto eh adicionado
		if(neonato){
			pont++;
		}
	}
	if(edema_articulacao == 2 || edema_articulacao == 3){						//caso o paciente apresente edema na articulacao com de intensidade de moderada a intensa, 1 ponto eh adicionado
		pont++;
	}
	if(conjuntivite){															//caso o paciente apresente conjuntivite, visto que eh um sintoma que ocorre de 30% dos casos, 0,3 ponto eh adicionado
		pont+=0.3;
	}

	return pont;
}


//Funcao que, dada a pontuacao de cada doenca, retorna o diagnostico mais provavel
void Diagnostico (float pontuacao_saudavel, float pontuacao_dengue, float pontuacao_zika, float pontuacao_chikungunya){
	float celling = 0;
	char diagnostico;
	
	if(pontuacao_saudavel > celling){
		celling = pontuacao_saudavel;
		diagnostico = 's';
	}
	if(pontuacao_dengue > celling){
		celling = pontuacao_dengue;
		diagnostico = 'd';
	}
	if(pontuacao_zika > celling){
		celling = pontuacao_zika;
		diagnostico = 'z';
	}
	if(pontuacao_chikungunya > celling){
		celling = pontuacao_chikungunya;
		diagnostico = 'c';
	}

	if(diagnostico == 's'){
		printf("Diagnostico provavel: Sem diagnostico exato.");
	}
	else if(diagnostico == 'd'){
		printf("Diagnostico provavel: Dengue.");
	}
	else if(diagnostico == 'z'){
		printf("Diagnostico provavel: Zika.");
	}
	else if(diagnostico == 'c'){
		printf("Diagnostico provavel: Chikungunya.");
	}
	printf("\n\n\n");
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
		acometimento_neurologico,		//booleano apontando se houve necessidade de acometimento neurologico
		conjuntivite,					//booleano apontando se o paciente apresentou conjuntivite
		neonato;						//booleano apontando se o paciente eh neonato - importante no caso de acometimento neurologico

	float pontuacao_saudavel, pontuacao_zika, pontuacao_dengue, pontuacao_chikungunya, total;

	//funcao seta as variaveis e caso o paciente tenha tido necessidade de acompanhamento neurologico, ele retorna se o paciente eh neonato ou nao
	neonato = Formulario(
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
		&acometimento_neurologico,
		&edema_articulacao,
		&conjuntivite
	);

	//Para calcular a probabilidade do paciente ter alguma ou nenhuma das 3 doencas, foi feito um sistema de score entre os 4 casos:
	//Para cada sintoma que o paciente apresente, ou nao, pontuacoes vao ser adicionadas as doencas correspondentes.
	//Se um sintoma for frequente em apenas uma determinada parcela da populacao de infectados, a pontuacao eh aumentada de acordo.
	//No final eh feita uma comparacao entre os pontos que cada uma das doencas fez e eh calculada a probabilidade do paciente ter cada uma dessas doencas.
	//A doenca que ter a maior probabilidade eh impressa.

	//calcula a pontuacao de cada sintoma. Se o paciente nao apresentar o sintoma, a probabbilidade dele nao ter nenhuma das tres doenças aumenta.
	pontuacao_saudavel = PontuacaoSaudavel(temperatura, mancha_pele_dia, dor_musculos_freq,
							dor_articulacao_freq,
							dor_de_cabeca,
							coceira,
							hipertrofia_ganglionar,
							discrasia_hemorragica,
							acometimento_neurologico,
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
							acometimento_neurologico,
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
							acometimento_neurologico,
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
							acometimento_neurologico,
							edema_articulacao,
							conjuntivite,
							neonato
						);

	total = pontuacao_saudavel + pontuacao_dengue + pontuacao_zika + pontuacao_chikungunya;

	system("clear");
	//printf("Sem diagnóstico exato: %.1f\n", pontuacao_saudavel);
	//printf("Dengue: %.1f\n", pontuacao_dengue);
	//printf("Zika: %.1f\n", pontuacao_zika);
	//printf("Chikungunya: %.1f\n\n\n", pontuacao_chikungunya);

	//Imprime a probabilidade de ser cada um das doencas ou de nao ser nenhuma delas
	printf("Probabilidades:\n");
	printf("Sem diagnóstico exato: %.1f%%\n", (pontuacao_saudavel/total)*100);
	printf("Dengue: %.1f%%\n", (pontuacao_dengue/total)*100);
	printf("Zika: %.1f%%\n", (pontuacao_zika/total)*100);
	printf("Chikungunya: %.1f%%\n\n\n", (pontuacao_chikungunya/total)*100);

	//Imprime o diagnostico mais provavel
	Diagnostico(pontuacao_saudavel, pontuacao_dengue, pontuacao_zika, pontuacao_chikungunya);

	return(0);
}