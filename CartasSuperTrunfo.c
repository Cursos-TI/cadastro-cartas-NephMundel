#include <stdio.h>
#include <string.h>


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

struct cartas { //variaveis usando o comando struct que serve pra juntar as informaçoes ao invez de separa-las
   
    char pais[50];
    char estado;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;
    char codigo[5];
};

void entradados(struct cartas carta[32]){ // função para a entrada dos dados 
    
 char estados[] = {'A','B','C','D','E','F','G','H'};// array com as letras pra formar o codigo do estado
 int indice = 0; // variavel para Contar as posiçoes dos arrays e adicionar e salvar as cartas   

 //laço for duplo que acabei de descobri, feito pra por os codigos da carta e pegar informaçoes das cartas
 for(int i = 0; i < 8; i++) {
  for(int j = 1; j <= 4; j++) {
   /*descobri essa função chamada sprintf que 
   mostra a informação na tela mas tambem salva em string*/
   // aqui é para pedir os dados das cartas
   //usei o fgets para ler strings com espaços

   carta[indice].estado = estados[i];
   sprintf(carta[indice].codigo, "%c%02d", estados[i], j);

   printf("Digite o nome do País: \n");
   fgets(carta[indice].pais, sizeof(carta[indice].pais), stdin);
   carta[indice].pais[strcspn(carta[indice].pais, "\n")] = '\0';
   // Remove o caractere de nova linha lido pelo fgets

    printf("Digite o nome da cidade: \n");
    fgets(carta[indice].cidade, sizeof(carta[indice].cidade), stdin);
    carta[indice].cidade[strcspn(carta[indice].cidade, "\n")] = '\0'; // Remove o caractere de nova linha lido pelo fgets

     printf("Qual a população da cidade?: \n");
     scanf("%d", &carta[indice].populacao);

     getchar(); // Limpa o buffer do teclado

     printf("Qual a area em KM² da cidade?: \n");
     scanf("%f", &carta[indice].area);
            
     getchar(); // Limpa o buffer do teclado

     printf("Digite o PIB: \n");
     scanf("%f", &carta[indice].pib);
            
     getchar(); // Limpa o buffer do teclado

     printf("Numero de pontos turísticos?: \n");
     scanf("%d", &carta[indice].pontosturisticos);

     getchar(); // Limpa o buffer do teclado 

     indice++; // incrementa o indice para a próxima carta
           
    }
  }
}

void saidadados(struct cartas carta[32]){ //chama a função para mostrar os dados
        
   //mostrar as cartas cadastradas     
   printf("\nCartas cadastradas:\n");

  for(int k = 0; k < 32; k++) { 
  printf("Código: %s \n", carta[k].codigo);
  printf("Estado: %c \n", carta[k].estado);
  printf("Cidade: %s \n", carta[k].cidade);
  printf("População: %d \n", carta[k].populacao);
  printf("Área: %.2f KM² \n", carta[k].area);
  printf("PIB: %.2f \n", carta[k].pib);
  printf("Pontos Turísticos: %d \n", carta[k].pontosturisticos);
  printf("-------------------------\n");
 }
  
}

int main(){  
    struct cartas carta[32]; // cria o array de cartas
    entradados(carta);
    saidadados(carta);
    return 0;
};

//fim do código}
  
