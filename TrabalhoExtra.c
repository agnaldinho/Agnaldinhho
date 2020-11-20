#include <stdio.h>
#include <locale.h>
/*Ap�s o analista de sistemas entrar em contato com o cliente, � necess�rio criar:	�Uma estrutura que armazene:
o Cliente (c�digo,nome, endere�o,telefone)
oCard�pio (c�digo, nome, ingredientes, pre�o, tipo)
oVenda (c�digo do cliente, c�digo do card�pio, quantidadede itens iguais)
O programa deve ter um menu que possibilite a manipula��o do sistema:
oInserir cliente
oInserir item no card�pio
oInserir venda
oListar clientes
oListar card�pio
oListar vendas
oSalvar base em arquivo
oAbrir base do arquivo
oCalcular o pre�o total vendido at� o momento
oListar quantos lanches cada cliente j� comprou at� o momento
oSair do programa
�O programa n�o deve finalizar enquanto o usu�rio n�o selecionar �Sair do Programa�. Sempre que uma op��o for escolhida, 
ela deve ser realizada e deve-se voltar ao menu.*/

typedef struct
{
	int codigo;
	char nome[50];
	char rua[50];
	char cidade[50];
	char estado[50];
	int numero;
	int cep;
}CLIENTE;

typedef struct
{
	int codigo;
	char nome[50];
	char ingredientes[500];
	float preco;
	int tipo;
	
}CARDAPIO;

typedef struct
{	
	int CodigoCliente;
	int CodigoCardapio;
	int QuantidadeItensIguais;
}VENDA;

void main()
{
	setlocale(LC_ALL,"portuguese");
	
	CLIENTE Cliente;
	CARDAPIO Cardapio;
	VENDA Venda;
	
	int parar = -1, VendasQuantidade = 0;
	float Vendas = 0;
	
	//Criando arquivo pra cada struct
	FILE *ClienteRestaurante;
	FILE *CardapioRestaurante;
	FILE *VendaRestaurante;
	
	do{
		//O menu DO restaurante
		
		printf("\n---------------MENU----------------");
		printf("\n\nOQUE VOCE DESEJA?\n");
		printf("\n1 - Inserir cliente "); //OK
		printf("\n2 - Inserir item no card�pio "); //OK
		printf("\n3 - Inserir venda "); //OK
		printf("\n4 - Listar clientes "); //OK
		printf("\n5 - Listar card�pio"); //OK
		printf("\n6 - Listar vendas ");//OK
		printf("\n7 - Calcular o pre�o total vendido at� o momento ");//OK
		printf("\n8 - Listar quantos lanches cada cliente j� comprou at� o momento ");//OK
		printf("\n0 - Sair do programa "); //OK
		
		printf("\nDigite a Op�ao que desejar: ");
		scanf("%d", &parar);
		
		//SE ELE DIGITAR 1 ELE CADASTRA O CLIENTE
		if(parar == 1)
		{
			
			ClienteRestaurante = fopen("DadosCliente.ag", "a+b");
			system("CLS");
			
			printf("\n------------Cadastro do CLiente---------------");
			printf("\n\nQual � o codigo do cliente: ");
			scanf("%d", &Cliente.codigo);
			
			printf("\nNome do cliente: ");
			scanf("%s", &Cliente.nome);
			
			printf("\n---------ENDERE�O------------");
			printf("\nDigite o Cep da rua: ");
			scanf("%d", &Cliente.cep);
			
			printf("\nDigite o estado: ");
			scanf("%s", &Cliente.estado);
			
			printf("\nDigite a Cidade: ");
			scanf("%s", &Cliente.cidade);
			
			printf("\nDigite o nome da rua: ");
			scanf("%s", &Cliente.rua);
			
			printf("\nDigite o numero da casa: ");
			scanf("%d", &Cliente.numero);
			
			//Esta salvando tudo no arquivo
			fwrite(&Cliente, sizeof(CLIENTE), 1, ClienteRestaurante);
			fclose(ClienteRestaurante);
			
			printf("\nCLIENTE CADASTRADO!!!\n");
	
	
		}
		
		//Se ELE DIGITAR 2 ELE VAI CRIAR UM PRODUTO NO CARDAPIO
		else if(parar == 2)
		{
			CardapioRestaurante = fopen("DadosCardapio.ag","a+b");
			system("CLS");
			printf("\n1 - Lanche \n2 - Bebidas: ");
			scanf("%d", &Cardapio.tipo);
		
			//SE O TIPO FOR == 1 ELE VAI CADASTRAR UM LANCHE
			
			if(Cardapio.tipo == 1)
			{
				
				system("CLS");
				printf("\n\n--------Cadastro do Cardapio-------");
				printf("\nDigite o codigo do Lanche: ");
				scanf("%s", &Cardapio.codigo);
				
				printf("\nDigite o Nome do Lanche: ");
				scanf("%s", &Cardapio.nome);
				
				printf("\nDigite os ingredientes: (coloque virgula)"); 
				scanf("%s",Cardapio.ingredientes);
							
				printf("\nDigite o pre�o do Lanche: ");
				scanf("%f", &Cardapio.preco);
				
				printf("\n----Lanche Cadastrado------");				
			}
			
			//SE TIPO FOR ==2 ELE VAI CADASTRAR UMA BEBIDA
			else if(Cardapio.tipo == 2)
			{
				
				system("CLS");
				printf("\n\n--------Cadastro do Cardapio-------");
				printf("\nDigite o codigo da bebida: ");
				scanf("%s", &Cardapio.codigo);
				
				printf("\nDigite o Nome da bebida: ");
				scanf("%s", &Cardapio.nome);
				
				printf("\nDigite os ingredientes: (coloque virgula)"); 
				scanf("%s",Cardapio.ingredientes);
							
				printf("\nDigite o pre�o da bebida: ");
				scanf("%f", &Cardapio.preco);
				printf("\n------Bebida Cadastrada------");
				
			
			}
				//Esta salvando no arquivo
				fwrite(&Cardapio, sizeof(CARDAPIO), 1, CardapioRestaurante);
				fclose(CardapioRestaurante);
			
		
		}
			//Se for == 3 ELE CADASTRA UMA VENDA
			else if(parar == 3)
			{
				VendaRestaurante = fopen("DadosVenda.ag", "a+b");
				system("CLS");
				
				printf("---------VENDA----------");
				printf("\nDigite o codigo do cliente: ");
				scanf("%d", &Venda.CodigoCliente);
				
				printf("\nDigite o codigo do cardapio: ");
				scanf("%d", &Venda.CodigoCardapio);
				
				printf("\nDigite a quantidade: ");
				scanf("%d", &Venda.QuantidadeItensIguais);
				
				printf("\n--------VENDA CADASTRADA---------");
				
				//ESSE CALCULA E PRA SABER QUANTOS LANCHER E BEBIDAS FORAM COMPRADOS
				VendasQuantidade = VendasQuantidade + Venda.QuantidadeItensIguais;
				
				//PRA SABER QUAL E O PRE�O TOTAL
				if(Venda.CodigoCliente == Cliente.codigo)
				Vendas = Venda.QuantidadeItensIguais * Cardapio.preco + Vendas;
			
			//salver o arquivo			
			fwrite(&Venda, sizeof(VENDA), 1, VendaRestaurante);
			fclose(VendaRestaurante);
						
			}
			
			//SE FOR == 4 ELE MOSTRA OS CLIENTES CADASTRADOS
			else if(parar == 4)
			{
			
			system("CLS");
			printf("\n-------Clientes Cadastrados---------\n");
			ClienteRestaurante = fopen("DadosCliente.ag", "r+b");
			
				while( !feof(ClienteRestaurante) )
				{
					if( fread(&Cliente, sizeof(CLIENTE),  1   ,ClienteRestaurante) )
					{
						printf("\nCodigo: %d / Nome: %s / CEP: %d / Endere�o RUA: %s / N�: %d / Cidade: %s / Estado: %s",Cliente.codigo, Cliente.nome, Cliente.cep, Cliente.rua, Cliente.numero, Cliente.cidade, Cliente.estado);
					}		
					
							
				}
				printf("\n");
				system("pause");
				fclose(ClienteRestaurante);		
					
			}
			
			//SE FOR == 5 ELE MOSTRA O CARDAPIO
			else if(parar == 5)
			{
				system("CLS");
				printf("-----CARDAPIO-----------");
				CardapioRestaurante = fopen("DadosCardapio.ag", "r+b");
	
				while( !feof(CardapioRestaurante) )
				{
					if( fread(&Cardapio,sizeof(CARDAPIO),  1   ,CardapioRestaurante) )
					{
						printf("\nNome: %s / Ingredientes: %s / Pre�o: %.2f / tipo: %d ",Cardapio.nome, Cardapio.ingredientes, Cardapio.preco, Cardapio.tipo);
					}		
				
				}
				printf("\n");
				system("pause");
				fclose(CardapioRestaurante);
			}
			
			//NAO SEI COMO VOU FAZER
			else if(parar == 6)
			{
				VendaRestaurante = fopen("DadosVenda.ag", "r+b");
	
				while( !feof(VendaRestaurante) )
				{
					if( fread(&Venda, sizeof(VENDA),  1   ,VendaRestaurante) )
					{
						system("CLS");
						printf("-----Lista de Vendas----------");
						printf("\n Codigo Cardapio: %d  Codigo Cliente: %d \n\n",Venda.CodigoCardapio, Venda.CodigoCliente);

					}		
				
				}
					printf("\n");
					system("pause");
					fclose(VendaRestaurante);
			
				
			}
			
			else if(parar == 7)
			{
				
				VendaRestaurante = fopen("DadosVenda.ag", "r+b");
	
				while( !feof(VendaRestaurante) )
				{
					if( fread(&Venda,sizeof(VENDA),  1   ,VendaRestaurante) )
					{
						system("CLS");
						printf("Quantidade total de vendas de lanche foi: %d",VendasQuantidade);
						printf("\nPre�o total: %.2f",Vendas);
					}		
				
				}
					printf("\n");
					system("pause");
					fclose(VendaRestaurante);

			}
			
			else if(parar == 8)
			{
				VendaRestaurante = fopen("DadosVenda.ag", "r+b");
				
					while( !feof(VendaRestaurante) )
				{
					if( fread(&Venda, sizeof(VENDA),  1   ,VendaRestaurante) )
					{
						printf("\n Codigo Cardapio: %d  Codigo Cliente: %d",Venda.CodigoCardapio, Venda.CodigoCliente);
						printf("\n Quantidade de lanches: %i \n\n\n",Venda.QuantidadeItensIguais);
					}		
				}
					printf("\n");
					system("pause");
					fclose(VendaRestaurante);

				
				
			}
	}while(parar != 0);
}

