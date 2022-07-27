#include <stdio.h>  //Inclui cabe�alho de biblioteca e fun��es de entrada/sa�da, respectivamente.
#include <stdlib.h> //Inclui cabe�alho de biblioteca e fun��es de uso geral, respectivamente.
#include <string.h> //Inclui cabe�alho de biblioteca e fun��es de manipula��o de strings, respectivamente.

struct PLAYLIST {  //Vari�vel especial para armazenar outras vari�veis e dados na playlist dentro da estrutura(struct).  
	char nome[30]; //Vari�vel para armazenar caracteres dentro da string.
	char artista[30];
	char duracao[5];
	PLAYLIST* prox; //Vari�vel que aponta para a pr�xima posi��o da playlist.
} *head;

int menu(); //Declara��o das fun��es: int (vari�vel para armazenar n�meros inteiros, void (vari�vel para armazenar nada).
void insert(char* n, char* a, char* d); //Fun��o para inserir caracteres.
void show(); //Fun��o para mostrar caracteres.

int main() { //Fun��o de execu��o que devolve o valor inteiro.
	int op;
	char nome[30], artista[30], duracao[5];
	while (1) { //La�o de repeti��o com menu e switch para escolha de op��es.
		op = menu();
		switch (op) { 
		case 1: //Recebe os dados e os coloca nas vari�veis especificadas, printf exibi��o e inser��o de dados, fgets permite a leitura dos dados.
			printf("\n\tDigite o nome da musica: ");
			fgets(nome, 30, stdin);
			printf("\n\tDigite o nome do artista: ");
			fgets(artista, 30, stdin);
			printf("\n\tDigite a duracao da faixa (no formato mm:ss): ");
			fgets(duracao, 5, stdin);

			insert(nome, artista, duracao); //Inser��o de dados na estrutura (struct), for�ando a sa�da do la�o de repeti��o com o break.
			break;

		case 2:
			show(); //Exibe a lista da playlist e for�a a sa�da do la�o de repeti��o com o break.
			break;

		case 3:
			return 0; //Finaliza a execu��o do programa.

		default:
			printf("\n\tOPCAO INVALIDA\n"); //Ao digitar nenhuma das op��es apresentadas ou inv�lida, pausa a execu��o do programa. 
			system("pause");
		}
	}
	return 0; //Instru��o que encerra a execu��o do programa retomando para a fun��o de chamada no come�o do la�o. 

}

int menu() { //Fun��o de menu para inser��o de valores inteiros.
	int op, c;
	system("cls"); //Fun��o que permite executar um programa dentro de outro, com o camando cls para limpar a tela.
	printf("\t**************PLAYER DE MUSICA**************\n");
	
	printf("\n\t1. Inserir nova musica na playlist");  //Exibi��o e inser��o de dados. 
	printf("\n\t2. Listar todas as musicas da playlist");
	printf("\n\t3. Sair do player\n");

	printf("\n\tEscolha sua opcao: ");
	scanf_s("%d", &op); //L� o fluxo de dados de entrada.
	while ((c = getchar()) != '\n' && c != EOF); //Limpeza do cache. 

	system("cls");
	return op; //Retorna para a op��o escolhida. 
}
void insert(char* n, char* a, char* d) { //Fun��o de inser��o dos caracteres. 
	PLAYLIST* novo; //Armazenamento,utiliza��o e execu��o na mem�ria. 
	novo = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	strcpy_s(novo->nome, n); //Copia valores a string de forma segura ao buffer.
	strcpy_s(novo->artista, a);
	strcpy_s(novo->duracao, d);
	
	if (head == NULL) { //Se head n�o est� atribu�do a nenhum local da mem�ria volta a ser novo. 
		head = novo; 
		head->prox = NULL;
	}
	else { //Sen�o, head � atribu�do ao pr�ximo head, voltando a ser novo. 
		novo->prox = head;
		head = novo;
	}
}
void show() { //Fun��o para a exibi��o da lista.
	PLAYLIST* scan; //Armazenamento,utiliza��o e execu��o na mem�ria. 
	scan = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	scan = head; //Scan copia os dados inseridos em head.
	
	if (scan == NULL) { //Se head � nulo, a lista n�o cont�m dados. 
		printf("\n\tPlaylist vazia!\n\n");
		system("pause");
		return;
	}
	
	while (scan != NULL) { //La�o que obt�m os dados na struct inseridos nas intera��es.
		printf("**************************************************\n");
		printf("\n\tNome da musica: %s", scan->nome);
		printf("\n\tArtista: %s", scan->artista);
		printf("\n\tDuracao: %s\n", scan->duracao);
		printf("\n**************************************************\n");

		scan = scan->prox; //Faz a intera��o com ponteiro para o pr�ximo.
	}

	system("pause");
	return;
}