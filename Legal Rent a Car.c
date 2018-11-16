//Declaracao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//Fim da declaracao das bibliotecas

//Declaracao das variaveis globais
char nome[200][50];
char placa[200][8];
char placadevolucao[8];
char parceiro[200];
char alugado[200];

int idade[200];
int quantidadediarias[200];

double valordiaria[200];
double valortotal[200];

struct tm *info;
time_t horarioalugado[200];
time_t previsaodevolucao[200];
time_t horariodevolucao[200];
time_t diariasalugado[200];
char op;


//Fim da declaracao das variaveis globais

//Inicio da struct para coleta de data
// struct tm {
//    int tm_sec;         /* seconds,  range 0 to 59          */
//    int tm_min;         /* minutes, range 0 to 59           */
//    int tm_hour;        /* hours, range 0 to 23             */
//    int tm_mday;        /* day of the month, range 1 to 31  */
//    int tm_mon;         /* month, range 0 to 11             */
//    int tm_year;        /* The number of years since 1900   */
//    int tm_wday;        /* day of the week, range 0 to 6    */
//    int tm_yday;        /* day in the year, range 0 to 365  */
//    int tm_isdst;       /* daylight saving time             */	
// };
//Final da struct para coleta de data


//Inicializa funcoes
void aluguel();
void devolucao();
//void pesquisa();
void lista();

//Inicio da funcao de aluguel de automoveis
void aluguel(){
	static int linha;
	do{
		system("cls");
		printf("\n--- Cadastro de aluguel ---\n");
		printf("\nDigite o nome do cliente: ");
		scanf("%s", &nome[linha]); //Recebe o nome do cliente
		printf("\nDigite a idade: ");
		scanf("%d", &idade[linha]);//Recebe a idade do cliente
		printf("\nEssa pessoa pertence a alguma empresa parceira da ONG? (S/N) ");
		fflush(stdin);
		scanf("%c", &parceiro[linha]);//Recebe a resposta se o cliente pertence a alguma ONG parceira
		printf("\nDigite a placa do automovel que o cliente ira alugar (ABC0000): ");
		scanf("%s", &placa[linha]);//Recebe a placa do automovel
		alugado[linha]='S';//Altera o status do automovel para ´alugado´, assim nao sera possivel alugar novamente o mesmo automovel
		printf("\nDigite o valor da diaria: R$ ");
		scanf("%g", &valordiaria[linha]);//Recebe o valor da diaria
		printf("\nDigite a quantidade de diarias: ");
		scanf("%d", &quantidadediarias[linha]);//Recebe a quantidade de diarias previstas que o cliente vai alugar o automovel
		horarioalugado[linha] = time(NULL) - (2 * 60 * 60);// data hoje com gmt -2 (horario de verao)
		info = gmtime(&horarioalugado[linha]);
		previsaodevolucao[linha]=horarioalugado[linha] + (quantidadediarias[linha] * 24 * 60 * 60);//Calcula a data prevista para a devolucao do automovel
		printf("\nCarro alugado dia %d/%d/%d as %d:%d\n", (info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Imprime o horario local que o cliente esta retirando o automovel
		if (quantidadediarias[linha]>=5){//Verifica se a quantidade de diarias e maior que 5
			printf("\nCliente ganha 1 diaria a mais, deseja utiliza-la? (S/N) ");//Pergunta se o cliente gostaria da diaraia adicional
			fflush(stdin);
			scanf("%c", &op);//Recebe a opcao do cliente
			if (op=='S'||op=='s'){
				previsaodevolucao[linha]=horarioalugado[linha] + ((quantidadediarias[linha] +1)  * 24 * 60 * 60);//Se sim, adiciona 1 dia na previsao de devolucao
				info = gmtime(&previsaodevolucao[linha]);
			}
			}else{
				previsaodevolucao[linha]=horarioalugado[linha] + (quantidadediarias[linha] * 24 * 60 * 60);//Se não, mantem a previsao de devolucao
				info = gmtime(&previsaodevolucao[linha]);
			}
		printf("\nPrevisao para devolucao dia %d/%d/%d as %d:%d\n", (info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Imprime a data pevista para devolucao
		printf("\nCadastro realizado com sucesso!\n");
		printf("\nDeseja incluir outro cadastro de aluguel? (S/N) ");//Pergunta se deseja realizar outro aluguel
		fflush(stdin);
		scanf("%c", &op);//Recebe variavel de opcao
		linha++;
	}while(op=='S'||op=='s');//Repete o cadastro até que a opcao seja diferente de 'S' ou 's'
}
 //Fim da funcao de aluguel de automoveis
 
 void devolucao(){
 	int i;
	static int linha;
	do{
		system("cls");
		printf("\n--- Devolucao de automovel ---\n");
		printf("\nDigite a placa do automovel que o cliente esta devolvendo (ABC0000): ");
		scanf("%s", &placadevolucao);//Recebe a placa do automovel a ser devolvido
		for (i=0;i<=200;i++){//Faz a busca pela placa dentro do vetor
			if(strcmp(placa[i],placadevolucao)==0){//Verifica se a placa digitada e a mesma contida no vetor
				printf("\nNome: %s\nIdade: %d\nPertence a alguma empresa parceira da ONG?: %c\nPlaca: %s\n", nome[i], idade[i], parceiro[i],placa[i]);//Mostra os dados do cliente para confirmacao
				info = gmtime(&horarioalugado[i]);//Resgata o horario em que o automovel foi alugado
				printf("\nData retirada: %2d/%2d/%2d as %2d:%2d\n",(info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Imprime a data da retirada para confirmacao
				info = gmtime(&previsaodevolucao[i]);//Resgata a data prevista para devolucao do automovel
				printf("\nDevolucao prevista: %2d/%2d/%2d as %2d:%2d\n",(info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Imprime a data prevista para devolucao para confirmacao
				horariodevolucao[i] = time(NULL) - (2 * 60 * 60);//Coleta o horaro do sistema
				info = gmtime(&horariodevolucao[i]);//Resgata o horario do sistema para que seja o horario da devolucao
				printf("\nHorario da devolucao: %2d/%2d/%2d as %2d:%2d\n",(info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Imprime o horario da devolucao
				diariasalugado[i]=(horariodevolucao[i] - horarioalugado[i]);//Calcula o horario real que o cliente alugou o carro, sendo (horario de devolucao - horario de retirada)
				info = gmtime(&diariasalugado[i]);//Regata o horario to total de diárias
				printf("\nTotal de diarias com o automovel: %2d/%2d/%2d as %2d:%2d\n",(info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));//Mostra o total de diarias com o automovel
				printf("\nPreco da diaria: %g\n", valordiaria[i]);//Mostra o valor digitado da diaria, somente para confirmacao
				valortotal[i]= valordiaria[i]*diariasalugado[i];//Calcula o valor total a ser pago 
				printf("\nValor total: %g\n", valordiaria[i]);//Imprime o total a ser pago
				getchar();
				getchar();
			}else{
				break;
			 }
		}
		linha++;
	}while(op=='S'||op=='s');
}
 


//Inicio da funcao de lista de clientes
void lista(){
	int i;
	system("cls");
	for (i=0;i<=200;i++){
		if(idade[i]>0){
			printf("\nNome: %s\nIdade: %d\nPertence a alguma empresa parceira da ONG?: %c\n\n", nome[i], idade[i], parceiro[i]);
			getchar();
			getchar();
	}	else{
			break;
		}
	}
}

//Programa principal
int main(void){
	do{
		system("cls");
		printf("\n--- Legal Rent a Car ---\n1- Cadastrar\n2- Devolucao\n3- Listar\n4- Sair\n\nOpcao desejada: ");
		fflush(stdin);
		scanf("%c", &op);
		switch(op){
			case '1':
				aluguel();
				break;
			case '2':
				devolucao();
				break;
			case '3':
				lista();
				break;
			case '4':
				system("exit");
				break;
			default:
				printf("\nOpcao invalida!");
				getchar();
				break;
		}
	}while(op!='4');
}
