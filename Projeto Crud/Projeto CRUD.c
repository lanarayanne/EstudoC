/*  Projeto  */

/*
Opcao 2: Onibus
-Numero do carro:
-Empresa:
-Placa:
-Cor:
-Linha:
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// #include<conio.h>

#define MAX_ONIBUS 1000

void imprimir_linha() {
	printf ("\n----------------------------------\n");
}

//-- Essa funcao so funciona para Linux --
void limpar_tela() {
	system("clear");
}

//Uso essa funcao para transformar a placa toda em maiusculo.
char letra_maiuscula(char letra) {
	if(letra >= 97 && letra <=122) {
		letra=letra-32;
	}
	return letra;
}

//Uso essa funcao para padronizar as strings: 1 letra em maiuscula e demais em minusculo
char maiusculo_e_minusculo(char letra, int posicao) {
	if (posicao == 0) {
		if(letra >= 97 && letra <=122) {
			letra=letra-32;
		}
	}
	else {
		if(letra >= 65 && letra <=90) {
			letra=letra+32;
		}
	}
	return letra;
}

//Esse e o tipo de variavel chamado Onibus
struct Onibus {
	char placa[7];
	int num_carro;
	char empresa[50];
	char cor[10];
	int linha;
};

//Validacao para ver se a quantidade de onibus cadastrados e maior que o maximo definido
int conferir_quantidade_max_onibus(int quantidade) {
	if (quantidade > MAX_ONIBUS) {
		return 0;
	}
	else {
		return 1;
	}
}

//Validacao para ver se existem onibus cadastrados
int conferir_quantidade_onibus_dif_zero(int quantidade) {
	if (quantidade == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Ver se a placa segue a padronizacao certa EX XXX0000 ou XXX0X00
int validar_placa(char *placa) {
	int i;
	int cont=0;

	for (i=0; i<3; i++) {
		if ((placa[i] >= 65 && placa[i] <=90) || placa[i] >= 97 && placa[i]<= 122) {
			cont++;
		}
	}

	for (i=3; i<7; i++) {
		if (i==4) {
			if ((placa[i] >= 48 && placa[i] <=57) || (placa[i] >= 65 && placa[i] <=90) || (placa[i] >= 97 && placa[i]<= 122) ) {
				cont++;
			}
		}
		else {
			if (placa[i] >= 48 && placa[i] <=57) {
				cont++;
			}
		}

	}

	if (cont == 7) {
		return 1;
	}

	else {
		return 0;
	}

}

//Conferir se a placa ja existe
int conferir_placa(char *placa_nova, char *placa) {
	int i, cont=0;

	for (i=0; i<7; i++) {
		if (placa_nova[i] == placa[i]) {
			cont++;
		}
	}

	if(cont == 7) {
		return 1;
	}
	else {
		return 0;
	}
}

//MENU
void menu() {

	imprimir_linha();
	printf("Cadastro de Onibus");
	imprimir_linha();
	printf("(1) Adicionar Item\n"); //ok
	printf("(2) Mostrar itens cadastrados\n"); //ok
	printf("(3) Atualizar item cadastrado\n");//ok
	printf("(4) Excluir item cadastrado\n");
	printf("(5) Salvar e sair\n"); //ok
	imprimir_linha();
	printf("Escolha uma opcao: ");
}

//Funcao para adicionar um novo onibus -- Retorna um struct Onibus
struct Onibus adicionar() {
	int i;

	imprimir_linha();
	printf("\nAdicionar Item\n");
	imprimir_linha();

	//cria uma variavel do tipo stuct Onibus que se chama onibus
	struct Onibus onibus;

	//limpar buffer teclado
	while (getchar() != '\n');

	//Ler placa
	printf("Placa (Ex: XXX0000 ou XXX0X00): ");
	scanf("%8s", onibus.placa);

	while(!validar_placa(onibus.placa)) {
		printf("ERRO: Placa Invalida");
		while (getchar() != '\n');
		printf("\nPlaca: ");
		scanf("%8s", onibus.placa);
	}

	//Quando inserir uma placa valida ele tranforma em maiusculo
	for(i=0; i<7; i++) {
		onibus.placa[i] = letra_maiuscula(onibus.placa[i]);
	}

	while (getchar() != '\n');

	//Ler numero do carro
	printf("Numero do carro: ");
	scanf("%d", &onibus.num_carro);

	while (getchar() != '\n');

	//Ler nome da empresa
	printf("Empresa: ");
	scanf("%50[^\n]", onibus.empresa);

	//Padroniza o nome
	i=0;
	while(onibus.empresa[i] != '\0') {
		onibus.empresa[i] = maiusculo_e_minusculo(onibus.empresa[i], i);
		i++;
	}

	while (getchar() != '\n');

	//Ler cor do onibus
	printf("Cor: ");
	scanf("%50[^\n]", onibus.cor);

	//Padronizar cor do onibus
	i=0;
	while(onibus.cor[i] != '\0') {
		onibus.cor[i] = maiusculo_e_minusculo(onibus.cor[i], i);
		i++;
	}

	while (getchar() != '\n');

	//Ler numero da linha
	printf("Numero da linha: ");
	scanf("%d", &onibus.linha);
	while (getchar() != '\n');

	//Retorna o onibus criado;
	return onibus;
}

//Funcao para listar onibus cadastrados -- Nao retorna nada -- Recebe um struct Onibus e chama ele de onibus
void mostrar(struct Onibus onibus) {
	int i=0;

	printf("\nPlaca: %s", onibus.placa);
	printf("\nNumero do carro: %d", onibus.num_carro);
	printf("\nEmpresa: ");
	while(onibus.empresa[i] != '\0') {
		printf("%c", onibus.empresa[i]);
		i++;
	}
	printf("\nCor: ");
	i=0;
	while(onibus.cor[i] != '\0') {
		printf("%c", onibus.cor[i]);
		i++;
	}
	printf("\nNumero da linha: %d\n", onibus.linha);

	imprimir_linha();
}

void menu_atualizar() {
	printf("Escolha a opcao que deseja atualizar");
	printf("\n(1) Placa");
	printf("\n(2) Numero do carro: ");
	printf("\n(3) Empresa");
	printf("\n(4) Cor");
	printf("\n(5) Numero da linha");
	printf("\nOpcao: ");
}

//Funcao atualizar um item -- retorna nada e recebe um ponteiro para um struct Onibus chamdo onibus --
//acessa diretamente o que esta sendo passado
void atualizar(struct Onibus *onibus) {
	int opcao = 0;
	int i=0;

	imprimir_linha();
	printf("Atualizar item");
	imprimir_linha();

	menu_atualizar();

	scanf("%d", &opcao);

	while (opcao < 1 || opcao >5) {
		printf("Escolha uma opcao valida: ");
		scanf("%d", &opcao);
	}

	switch(opcao) {
	case 1:

		char nova_placa[7];

		while (getchar() != '\n');
		printf("Nova placa: ");
		scanf("%s", nova_placa);

		while(!validar_placa(nova_placa)) {
			printf("ERRO: Placa Invalida");
			while (getchar() != '\n');
			// getchar();
			printf("Placa: ");
			scanf("%7s", nova_placa);
		}

		if(validar_placa(nova_placa)) {
			for(i=0; i<7; i++) {
				onibus->placa[i] = nova_placa[i];
			}
		}

		for(i=0; i<7; i++) {
			onibus->placa[i] = letra_maiuscula(onibus->placa[i]);
		}

		printf("Placa atualizada com sucesso!");
		break;

	case 2:
		while (getchar() != '\n');
		printf("Novo numero do carro: ");
		scanf("%d", &onibus->num_carro);
		printf("Numero do carro atualizado com sucesso!");
		break;

	case 3:
		while (getchar() != '\n');
		printf("Nova empresa: ");
		scanf("%50[^\n]", onibus->empresa);
		i=0;
		while(onibus->empresa[i] != '\0') {
			onibus->empresa[i] = maiusculo_e_minusculo(onibus->empresa[i], i);
			i++;
		}
		printf("Empresa atualizada com sucesso!");
		break;

	case 4:
		while (getchar() != '\n');
		printf("Nova cor: ");
		scanf("%s", onibus->cor);
		i=0;
		while(onibus->cor[i] != '\0') {
			onibus->cor[i] = maiusculo_e_minusculo(onibus->cor[i], i);
			i++;
		}
		printf("Cor atualizada com sucesso!");
		break;

	case 5:
		while (getchar() != '\n');
		printf("Novo numero da linha: ");
		scanf("%d", &onibus->linha);
		printf("Linha atualizada com sucesso!");
		break;
	}
}

//Funcao excluir onibus -- recebe um ponteiro para uma variavel tipo Onibus, a quantidade total de onibus cadastrados e indice do onibus a ser excluido
void excluir(struct Onibus *onibus, int quantidade, int localizador) {
	int i;
	int encontrar = 0;

	imprimir_linha();
	printf("Excluir item");
	imprimir_linha();

	//O loop roda enquanto houver onibus cadastrados-1 e quando encontra o indice do onibus pra escluir, substitui ele pelo proximo atC) o final
	for(i=0; i<quantidade-1; i++) {
		if (i == localizador) {
			onibus[i] = onibus[i+1];
			encontrar=1;
		}
		if (encontrar==1) {
			onibus[i] = onibus[i+1];
		}
	}
}

//Funcao para sair do programa
int sair() {
	int fechar;
	printf ("\nEncerrar programa ?\n(1) Para confirmar\n(2) Para retornar ao menu\nOpcao: ");
	scanf("%d", &fechar);
	if (fechar==1) {
		return 1;
	}
	else {
		return 0;
	}

}

// int retornar_ao_menu(int opcao) {
//     printf("(0) Para retornar ao menu principal\n");
// 		scanf("%d", &opcao);
// 	while(opcao != 0) {
// 		retornar_ao_menu(opcao);
// 	}
// 	return 0;
// }

//FILE
int file_onibus_salvos(struct Onibus *onibus, int tamanho) {
	//receber um onibus
	FILE *file_onibus_salvos = fopen("file_onibus_salvos.txt", "w");

	int i;

	if (file_onibus_salvos==NULL) {
		printf("O arquivo nao pode ser aberto");
		return (EXIT_FAILURE);
	}

	for(i=0; i<tamanho; i++) {
		fprintf(file_onibus_salvos,"\n----------------------------------\n");
		fprintf(file_onibus_salvos, "Placa: %s\n", onibus[i].placa);
		fprintf(file_onibus_salvos, "Numero do carro: %d\n", onibus[i].num_carro);
		fprintf(file_onibus_salvos, "Empresa: %s\n", onibus[i].empresa);
		fprintf(file_onibus_salvos, "Cor: %s\n", onibus[i].cor);
		fprintf(file_onibus_salvos, "Numero da linha: %d\n", onibus[i].linha);
	}

	fclose(file_onibus_salvos);
	return (EXIT_SUCCESS);
}

int main()
{
	int opcao=0;
	int nada;
	int cont_onibus=0; //quantidade de onibus
	int i=0;
	struct Onibus onibus[MAX_ONIBUS];
	memset(&onibus, 0x0, sizeof(onibus)); //Zerar a onibus;
	int fechar = 0;
	
	/*
	onibus[0] = (struct Onibus){"FST2319", 2309, "Vila galvao", "Vermelho", 434};
	onibus[1] = (struct Onibus){"FJN0630", 2320, "Vila galvao", "Vermelho", 434};
	onibus[2] = (struct Onibus){"CUC5125", 3138, "Campos dos ouros", "Amarelo", 732};
	onibus[3] = (struct Onibus){"EHH7189", 3113, "Campos dos ouros", "Amarelo", 731};
	onibus[4] = (struct Onibus){"SOB9E74", 2425, "Mobibrasil sao lourenco", "Roxo", 2060};
	onibus[5] = (struct Onibus){"PCF6569", 602, "Transcol", "Azul", 330};
	cont_onibus=6;
	*/
	

	printf ("\n\t\tOLA!\n");

	do {
		switch(opcao) {

		case 0:
			limpar_tela();
			menu();
			scanf("%d", &opcao);
			limpar_tela();
			break;

		case 1:
// 			limpar_tela();

			if(conferir_quantidade_max_onibus(cont_onibus)) {
				onibus[cont_onibus] = adicionar();
				int teste;
				i=0;

				while(i<cont_onibus) {
					teste = conferir_placa(onibus[cont_onibus].placa, onibus[i].placa);
					if (teste) {
						printf("\nOnibus ja cadastrado!\n");
						break;
					}
					else {
						i++;
					}
				}
				if(!teste) {
					printf("\nOnibus cadastrado com sucesso\n");
					cont_onibus++;
				}
			}
			else {
				printf("\nNao e possivel cadastrar mais que %d onibus", MAX_ONIBUS);
			}

// 			getchar();
			printf("\nQualquer tecla para retornar ao menu principal\n");
			getchar();
			opcao=0;

			break;

		case 2:
// 			limpar_tela();
			imprimir_linha();
			printf("Itens cadastrados");
			imprimir_linha();
			if (!conferir_quantidade_onibus_dif_zero(cont_onibus)) {
				for(i=0; i<cont_onibus; i++) {
					mostrar(onibus[i]);
				}
			}
			else {
				printf("Nao ha onibus cadastrados");
			}
			getchar();
			printf("\nQualquer tecla para retornar ao menu principal\n");
			getchar();
			opcao=0;
			break;

		case 3:
// 			limpar_tela();
			char nova_placa[7];
			int localizador, cont=0;
			int teste=0;

			printf("Informe a placa do Onibus que deseja atualizar: ");
			scanf("%s", nova_placa);
			for(i=0; i<7; i++) {
				nova_placa[i] = letra_maiuscula(nova_placa[i]);
			}

			for(i=0; i<cont_onibus; i++) {
				teste = conferir_placa(nova_placa, onibus[i].placa);
				if (teste) {
					localizador=i;
					break;
				}
				else {
					cont++;
				}
			}
			if (cont == cont_onibus) {
				printf("\nOnibus nao cadastrado!\n");
				opcao=3;
			}
			else {
				atualizar(&onibus[localizador]);
				getchar();
				printf("\nQualquer tecla para retornar ao menu principal\n");
				getchar();
				opcao=0;
			}

			break;

		case 4:
// 			limpar_tela();
			cont=0;
			printf("Informe a placa do Onibus que deseja excluir: ");
			scanf("%s", nova_placa);
			for(i=0; i<7; i++) {
				nova_placa[i] = letra_maiuscula(nova_placa[i]);
			}

			for(i=0; i<cont_onibus; i++) {
				teste = conferir_placa(nova_placa, onibus[i].placa);
				if (teste) {
					localizador=i;
					break;
				}
				else {
					cont++;
				}
			}
			if (cont == cont_onibus) {
				printf("\nOnibus nao cadastrado!\n");
				opcao=4;
			}
			else {
				excluir(onibus, cont_onibus, localizador);
				cont_onibus--;
				printf("\nOnibus excluido com sucesso\n");
			}
			getchar();
			printf("\nQualquer tecla para retornar ao menu principal\n");
			getchar();
			opcao=0;
			break;

		case 5:
// 			limpar_tela();
            file_onibus_salvos(onibus, cont_onibus);
			fechar=sair();
			if (!fechar) {
				opcao=0;
			}
			break;

		default:
// 			limpar_tela();
			getchar();
			printf("\nOpcao Invalida!\n");
			printf("\nQualquer tecla para retornar ao menu principal\n");
			getchar();
			opcao=0;
			break;
		}


	}
	while(fechar !=1);

	imprimir_linha();
	printf("Programa Encerrado com Sucesso !");
	imprimir_linha();

	return 0;
}

