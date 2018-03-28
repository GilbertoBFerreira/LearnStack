#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*    
    Este código manipula uma stack.
    Inserção de valores "Push"
    Remoção de valores "Pop"
*/

// variáveis globais
int array[10];
int tamanho = 10;
int topo = 0;

// le valor a inserir na stack
int lerValor()
{
    int valor;

    printf("\nInsira valor: ");
    scanf("%d", &valor);

    // retorna valor lido
    return valor;
}

// inser valor no topo da stack
void push()
{    
    int valor;
    // verifica se a stack está vazia ou se está cheia e caso não cumpra um dos dois teste, adiciona o valor à stack
   if (topo >= tamanho)
        printf("\n\n * A stack está cheia!!!\n\n");        
    else
    {
        valor = lerValor();
        array[topo] = valor;
        topo++;
    }
}

// remove valor do topo da stack
void pop()
{
    // verifica se a stack está vazia, caso não esteja remove valor do topo
    if (topo > 0)
    {
        topo--;
        printf("\n\n * Valor removido do topo da stack!!!\n\n"); 
    }        
    else
       printf("\n\n * A stack está vazia!!!\n\n"); 
}

void mostrarStack()
{
    printf("\n\n[ ");
    for (int i = 0; i < topo; i++)
    {
        printf("  %d  ", array[i]);
    }
    printf(" ]\n\n");
}

// método para mostrar menu de opções
int mostrarMenu()
{
    int opcao;
 
    // mostrar valores
    printf("Insira o num(1) para inserir novo valor\n");
    printf("Insira o num(2) para remover valor\n");
    printf("Insira valor diferente para sair\n");   
    printf("Opcao: ");                     
    scanf("%d", &opcao);

    // retorna valore escolhido
    return opcao;
}

// método para controlar opções do utilizador
int controladorDeOpcoes()
{
    int opcao;

    opcao = mostrarMenu();

    // decisão da opção
    switch(opcao)
    {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            mostrarStack();
            break;
        }
        default:
        {
            opcao = 0;
            break;
        }
    }

    // retorna opção
    return opcao;
}




// função principal
int main ()
{
    // valor positivo para satisfazer condição verdadeira do ciclo principal
    int opcao = 1;

    // mensagens iniciais e leitura de valores
    printf("\n\nBem-Vindo ao Stack Tester\n\n");

    // ciclo do programa
    while (opcao > 0)
    {
        // invoca controlador de opções
        opcao = controladorDeOpcoes();
    }
   
    return 0;
}
