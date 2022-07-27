#include <stdio.h>  //Inclui cabeçalho de biblioteca e funções de entrada/saída, respectivamente.
#include <stdlib.h> //Inclui cabeçalho de biblioteca e funções de uso geral, respectivamente.
#include <string.h> //Inclui cabeçalho de biblioteca e funções de manipulação de strings, respectivamente.

struct PLAYLIST {  //Variável especial para armazenar outras variáveis e dados na playlist dentro da estrutura(struct).  
	char nome[30]; //Variável para armazenar caracteres dentro da string.
	char artista[30];
	char duracao[5];
	PLAYLIST* prox; //Variável que aponta para a próxima posição da playlist.
} *head;

int menu(); //Declaração das funções: int (variável para armazenar números inteiros, void (variável para armazenar nada).
void insert(char* n, char* a, char* d); //Função para inserir caracteres.
void show(); //Função para mostrar caracteres.

int main() { //Função de execução que devolve o valor inteiro.
	int op;
	char nome[30], artista[30], duracao[5];
	while (1) { //Laço de repetição com menu e switch para escolha de opções.
		op = menu();
		switch (op) { 
		case 1: //Recebe os dados e os coloca nas variáveis especificadas, printf exibição e inserção de dados, fgets permite a leitura dos dados.
			printf("\n\tDigite o nome da musica: ");
			fgets(nome, 30, stdin);
			printf("\n\tDigite o nome do artista: ");
			fgets(artista, 30, stdin);
			printf("\n\tDigite a duracao da faixa (no formato mm:ss): ");
			fgets(duracao, 5, stdin);

			insert(nome, artista, duracao); //Inserção de dados na estrutura (struct), forçando a saída do laço de repetição com o break.
			break;

		case 2:
			show(); //Exibe a lista da playlist e força a saída do laço de repetição com o break.
			break;

		case 3:
			return 0; //Finaliza a execução do programa.

		default:
			printf("\n\tOPCAO INVALIDA\n"); //Ao digitar nenhuma das opções apresentadas ou inválida, pausa a execução do programa. 
			system("pause");
		}
	}
	return 0; //Instrução que encerra a execução do programa retomando para a função de chamada no começo do laço. 

}

int menu() { //Função de menu para inserção de valores inteiros.
	int op, c;
	system("cls"); //Função que permite executar um programa dentro de outro, com o camando cls para limpar a tela.
	printf("\t**************PLAYER DE MUSICA**************\n");
	
	printf("\n\t1. Inserir nova musica na playlist");  //Exibição e inserção de dados. 
	printf("\n\t2. Listar todas as musicas da playlist");
	printf("\n\t3. Sair do player\n");

	printf("\n\tEscolha sua opcao: ");
	scanf_s("%d", &op); //Lê o fluxo de dados de entrada.
	while ((c = getchar()) != '\n' && c != EOF); //Limpeza do cache. 

	system("cls");
	return op; //Retorna para a opção escolhida. 
}
void insert(char* n, char* a, char* d) { //Função de inserção dos caracteres. 
	PLAYLIST* novo; //Armazenamento,utilização e execução na memória. 
	novo = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	strcpy_s(novo->nome, n); //Copia valores a string de forma segura ao buffer.
	strcpy_s(novo->artista, a);
	strcpy_s(novo->duracao, d);
	
	if (head == NULL) { //Se head não está atribuído a nenhum local da memória volta a ser novo. 
		head = novo; 
		head->prox = NULL;
	}
	else { //Senão, head é atribuído ao próximo head, voltando a ser novo. 
		novo->prox = head;
		head = novo;
	}
}
void show() { //Função para a exibição da lista.
	PLAYLIST* scan; //Armazenamento,utilização e execução na memória. 
	scan = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	scan = head; //Scan copia os dados inseridos em head.
	
	if (scan == NULL) { //Se head é nulo, a lista não contém dados. 
		printf("\n\tPlaylist vazia!\n\n");
		system("pause");
		return;
	}
	
	while (scan != NULL) { //Laço que obtém os dados na struct inseridos nas interações.
		printf("**************************************************\n");
		printf("\n\tNome da musica: %s", scan->nome);
		printf("\n\tArtista: %s", scan->artista);
		printf("\n\tDuracao: %s\n", scan->duracao);
		printf("\n**************************************************\n");

		scan = scan->prox; //Faz a interação com ponteiro para o próximo.
	}

	system("pause");
	return;
}