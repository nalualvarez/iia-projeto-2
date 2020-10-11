#include <stdio.h>

//Funcao especifica para setar as variaveis
int SetVariables(
	float* temperatura,
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
	int* conjuntivite)
{
	int neonato = 0;

	printf("Digite sua temperatura: \n");
	scanf("%f", temperatura);
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

int main(){
	float temperatura;
	int mancha_pele_dia,
		dor_musculos_freq,
		dor_articulacao_freq,
		intensidade_dor_articular,
		dor_de_cabeca,
		coceira,
		hipertrofia_ganglionar,
		discrasia_hemorragica,
		edema_articulacao,
		acolhimento_neurologico,
		conjuntivite,
		neonato;

		neonato = SetVariables(
			&temperatura,
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

}