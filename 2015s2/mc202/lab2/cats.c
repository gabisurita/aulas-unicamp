/****************************************************
Aluno: Gabriel Lopes de Cicco
RA: 140622

Descricao: Programa que le planta de um apartamento
e retangulariza seus comodos de acordo com enunciado

https://susy.ic.unicamp.br:9999/mc202gh/02/lab02.pdf
****************************************************/


#include <stdio.h>
#include <stdlib.h>


/*funcao que conta o numero de comodos da planta*/
int quantos_comodos(char** matriz, int m, int n);

/*funcao que transforma espacos de um comodo em paredes*/
void destroi_comodo(char*** matriz, int i, int j);

/*funcao que calcula a area de um comodo*/
void area_comodo(char*** matriz, int i, int j, int* area);

/*funcao que imprime a area de cada comodo*/
void imprime_areas(char** matriz, int m, int n);

/*funcao que destroi as paredes da planta*/
void demolir(char*** matriz, int m, int n, int* npd); 




int main() {
	
	/*declaracao de variaveis*/
	int m, n, npd, i, j;
	char** matriz;
	
	/*leitura dos indices m e n*/
	scanf("%d ", &m);
	scanf("%d\n", &n);
	
	/*alocacao de memoria para vetor de vetores*/
	matriz = (char**) malloc((m)*sizeof(char*));
	if (matriz == NULL) exit(1);
	
	/*alocacao de memoria para cada vetor*/
	for (i=0; i<m; i++){
		matriz[i] = (char*) malloc(n*sizeof(char)); 
		if (matriz[i] == NULL) exit(1); }
	
	
	/*le e armazena cada elemento na matriz*/
	for (i=0; i<m; i++) {
	for (j=0; j<n; j++) {
		char aux;
		scanf("%c", &aux); 
		/*armazena apenas pontos e asteriscos*/
		if (aux != '.' && aux != '*') scanf("%c", &aux);
		matriz[i][j] = aux;
	}}
	
	/*imprime numero de comodos antes da demolicao*/
	printf("%d\n", quantos_comodos(matriz, m, n));
	
	/*imprime area de cada comodo antes da demolicao*/
	imprime_areas(matriz, m, n);
	
	/*inicializa em zero o contador de paredes demolidas*/
	npd = 0;
	
	/*realiza a demolicao*/
	demolir(&matriz, m, n, &npd);
	
	/*imprime numero de comodos depois da demolicao*/
	printf("%d\n", quantos_comodos(matriz, m, n));
	
	/*imprime numero de paredes demolidas*/
	printf("%d\n", npd);
}





/*funcao que conta o numero de comodos da planta*/
int quantos_comodos(char** matriz, int m, int n) {
	
	int i, j; /*declara variaveis auxiliares*/
	int ncom=0; /*declara e inicializa em zero a variavel 'numero de comodos'*/
	char** copia; /*declara matriz auxiliar*/
	
	/*alocacao de memoria para vetor de vetores*/
	copia = (char**) malloc((m)*sizeof(char*));
	if (matriz == NULL) exit(1);
	
	/*alocacao de memoria para cada vetor*/
	for (i=0; i<m; i++){
		copia[i] = (char*) malloc(n*sizeof(char)); 
		if (copia[i] == NULL) exit(1); }
	
	/*percorre a matriz*/
	for (i=0; i<m; i++){
	for (j=0; j<n; j++){
		/*copia cada elemento para a matriz auxiliar*/
		copia[i][j]=matriz[i][j]; }}
		
	/*percorre a planta*/
	for (i=0; i<m-1; i++){ 
	for (j=0; j<n-1; j++){
		/*procura espacos vazios*/
		if (copia[i][j] != '*') {
			/*aumenta contador de comodos*/
			ncom++;
			/*destroi o comodo*/
			destroi_comodo(&copia, i, j);
			
	}}}
			
	/*retorna valor do contador de comodos*/
	return ncom;
}





/*funcao que transforma espacos de um comodo em paredes*/
void destroi_comodo(char*** matriz, int i, int j) {
	
	/*checa se o elemento da planta eh um espaco*/
	if ((*matriz)[i][j] == '.') { 
		/*transforma em parede*/
		(*matriz)[i][j] = '*';
		
		/*checa elementos adjacentes*/
		if ((*matriz)[i+1][j] == '.') destroi_comodo(matriz, i+1, j);
		if ((*matriz)[i][j+1] == '.') destroi_comodo(matriz, i, j+1);
		if ((*matriz)[i-1][j] == '.') destroi_comodo(matriz, i-1, j);
		if ((*matriz)[i][j-1] == '.') destroi_comodo(matriz, i, j-1);
	}
}





/*funcao que calcula a area de um comodo*/
void area_comodo(char*** matriz, int i, int j, int* area) {
	
	/*checa se elemento da planta eh um espaco*/
	if ((*matriz)[i][j] == '.') { 
		/*aumenta o contador da area medida*/
		(*area)++;
		/*transforma em parede*/
		(*matriz)[i][j] = '*';
		
		/*checa elementos adjacentes*/
		if ((*matriz)[i+1][j] == '.') area_comodo(matriz, i+1, j, area);
		if ((*matriz)[i][j+1] == '.') area_comodo(matriz, i, j+1, area);
		if ((*matriz)[i-1][j] == '.') area_comodo(matriz, i-1, j, area);
		if ((*matriz)[i][j-1] == '.') area_comodo(matriz, i, j-1, area);
	}
}





/*funcao que imprime a area de cada comodo*/
void imprime_areas(char** matriz, int m, int n) {
		
	int i, j, aux, temp; /*declara variaveis auxiliares*/
	int* areas; /*declara vetor de areas*/
	char** copia; /*declara matriz auxiliar*/
	
	/*salva numero de comodos na variavel auxiliar*/
	aux = quantos_comodos(matriz, m, n);
	
	/*alocacao de memoria para vetor de areas*/
	areas = calloc(aux, sizeof(int));
	if (areas == NULL) exit(1);
	
	
	/*alocacao de memoria para vetor de vetores*/
	copia = (char**) malloc((m)*sizeof(char*));
	if (matriz == NULL) exit(1);
	
	/*alocacao de memoria para cada vetor*/
	for (i=0; i<m; i++){
		copia[i] = (char*) malloc(n*sizeof(char)); 
		if (copia[i] == NULL) exit(1); }
	
	/*percorre a matriz*/
	for (i=0; i<m; i++){
	for (j=0; j<n; j++){
		/*copia cada elemento para a matriz auxiliar*/
		copia[i][j]=matriz[i][j]; }}
	
	/*inicializa contador de comodos em zero*/
	aux = 0;	
	
	/*percorre a planta*/
	for (i=0; i<m-1; i++){ 
	for (j=0; j<n-1; j++){	
		/*procura espacos vazios*/
		if (copia[i][j] != '*') {
			/*calcula tamanho da area do comodo*/
			area_comodo(&copia, i, j, &(areas[aux]));
			/*incrementa contador de comodos*/
			aux++;			
	}}}
	
	/*algoritmo de bubble sort no vetor*/
	for (i=aux-1; i>0; i--){
	for (j=0; j<i; j++){
		if (areas[j]>areas[j+1]) {
			temp = areas[j];
			areas[j] = areas[j+1];
			areas[j+1] = temp; }}}
	
	/*imprime o valor de cada area*/
	for (i=0; i<aux-1; i++) printf("%d ", areas[i]);
	printf("%d\n", areas[aux-1]);
}





/*funcao para demolir paredes da planta*/
void demolir(char*** matriz, int m, int n, int* npd) {

	int i, j; /*declaracao de variaveis auxiliares*/
	
	/*percorre a planta*/
	for (i=0; i<m-2; i++){ 
	for (j=0; j<n-2; j++){
		
		int nast = 0; /*declaracao da variavel 'numero de asteriscos'*/
		
		/*conta quantos asteriscos tem no quadrado 2x2 adjacente*/
		if ((*matriz)[i][j] == '*') nast++;
		if ((*matriz)[i+1][j] == '*') nast++;
		if ((*matriz)[i][j+1] == '*') nast++;
		if ((*matriz)[i+1][j+1] == '*') nast++;
		
		/*caso haja apenas 1 asterisco no quadrado, a parede sera demolida*/
		if (nast==1) {
			
			/*substitui o asterisco*/
			(*npd)++;
			if ((*matriz)[i][j] == '*') (*matriz)[i][j] = '.';
			if ((*matriz)[i+1][j] == '*') (*matriz)[i+1][j] = '.';
			if ((*matriz)[i][j+1] == '*') (*matriz)[i][j+1] = '.';
			if ((*matriz)[i+1][j+1] == '*') (*matriz)[i+1][j+1] = '.';
			
			/*percorre novamente a matriz*/
			if(m>2 && n>2) demolir(matriz, m, n, npd);
		}
	}}
}
