#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

struct funcionario{

 int registro;
 char nome[20];
 char sobrenome[20];
 char idade[10];
 char salario[20];
 char cargo[20];

};

// prótotipo das funções
int menu();
void novo();
void pesquisar();
void modificar();
void deletar();

int menu(int y){

    printf("\nDigite o que deseja fazer:\n");
    printf("1 - Criar um novo Registro de Funcionario\n");
    printf("2 - Pesquisar Registro de Funcionario\n");
    printf("3 - Modificar Registro de Funcionario\n");
    printf("4 - Excluir Registro de Funcionario\n");
    printf("0 - Finalizar programa\n");
    scanf("%d", &y);
    

   return y;
    }



int main(void){

    int a;
    int b;
    int c;
    int d;
    int e;
    int y = 0;
    int x = 0;
    int reg;
    char name[20];
    char last_name[20];
    char age[10];
    char salary[20];
    char occupation[20];
    
    struct funcionario n_registro = {0,"","","","",""};

    FILE *arquivo;
    if((arquivo = fopen("Data_Bank.dat", "ab+")) == NULL){

        printf("Arquivo nao pode ser aberto\n");
    }else{
            
            printf("\n               Registro de Funcionario SCORPION S/A              \n");
            printf("=================================================================\n\n");
            

                fwrite(&n_registro, sizeof(struct funcionario), 1, arquivo);
            }
            fclose(arquivo);
        
            
       
       while((x = menu(y))!= 0){
        switch(x){
                    

                    case 1:
                    novo(reg, name, last_name, age, salary, occupation);
                                       
                    break;

                    case 2:                    
                    pesquisar(reg, name, last_name, age, salary, occupation);
                    
                    break;

                    case 3:                    
                    modificar(reg, name, last_name, age, salary, occupation);
                    
                    break;
                    
                    case 4:                    
                    deletar(reg, name, last_name, age, salary, occupation);
                    
                    break;

                    default:
                    printf("Escolha incorreta\n");
                    printf("Digite a opcao desejada\n");
                    
                    break;

                }
           
            }
        
            return 0;
        }

                   
     
void novo(int registro, char nome[20], char sobrenome[20], char idade[10], char salario[20], char cargo[20]){
   
    
    struct funcionario n_registro = {0, "","", "", "",""};

    FILE *arquivo;
    if((arquivo = fopen("Data_Bank.dat", "rb+")) == NULL){

        printf("Arquivo nao pode ser aberto\n");
    }else{

            printf("Digite numero do Novo Registro do funcionario""(1-100 ou 0 para encerrar)\n");
            fflush(stdin);
            scanf("%d", &n_registro.registro);
            while(n_registro.registro != 0){


                printf("Digite Nome, Sobrenome, Idade, Salario e Cargo\n");
                fflush(stdin);
                fscanf(stdin, "%s%s%s%s%s", n_registro.nome, n_registro.sobrenome, n_registro.idade, n_registro.salario, n_registro.cargo);
                fseek(arquivo, (n_registro.registro - 1)* sizeof(struct funcionario), SEEK_SET);

                fwrite(&n_registro, sizeof(struct funcionario), 1, arquivo);

                printf("Deseja Cadastrar um novo Registro?\n");
                printf("Digite: 1-100 para novo Cadastro\n");
                printf(" 0 - para Retornar ao menu principal\n");
                scanf("%d", &n_registro.registro);
                fflush(stdin);
                               
                      
                }
                fclose(arquivo);
                 }
                
            
        }


void pesquisar(int registro, char nome[20], char sobrenome[20], char idade[10], char salario[20], char cargo[20]){
    
    struct funcionario n_registro = {0, "", "", "", "", ""};

    FILE *arquivo;
    if((arquivo = fopen("Data_Bank.dat", "rb+")) == NULL){

        printf("Arquivo nao pode ser aberto\n");
    }else{

            printf("%s%11s%16s%10s%15s%15s\n","Reg", "Nome", "sobrenome","Idade","Salario", "Cargo");
            
            while(!feof(arquivo)) {
                fread(&n_registro, sizeof(struct funcionario), 1, arquivo);

                if(n_registro.registro != 0){

                printf("%d%13s%16s%10s%15s%15s\n", n_registro.registro, n_registro.nome, n_registro.sobrenome, n_registro.idade, n_registro.salario, n_registro.cargo);


                }

            }
          
                fclose(arquivo);
            }


     }

void modificar(int registro, char nome[20], char sobrenome[20], char idade[10], char salario[20], char cargo[20]){


    
    int mod_reg;

    struct funcionario n_registro;
    
    struct funcionario registro_branco = {0,"","","","",""};

    FILE *arquivo;
    if((arquivo = fopen("Data_Bank.dat", "rb+")) == NULL){

        printf("Arquivo nao pode ser aberto\n");
    }else{

            printf("Digite numero de Registro a Modificar""(1-100 ou 0 para encerrar)\n");
            fflush(stdin);
            scanf("%d", &mod_reg);
            
                fseek(arquivo, (mod_reg - 1) *sizeof(struct funcionario), SEEK_SET);

                fread(&n_registro, sizeof(struct funcionario), 1, arquivo);

                if(n_registro.registro == 0){


                    printf("Registro %d não existe\n", mod_reg);

                }else{
                    fseek(arquivo, (mod_reg - 1) *sizeof(struct funcionario), SEEK_SET);
                    fwrite(&registro_branco, sizeof(struct funcionario), 1, arquivo);
                   
                    while(n_registro.registro != 0){
                
                printf("Digite Nome, sobrenome, Idade, Salario e Cargo \n");
                fflush(stdin);
                fscanf(stdin, "%s%s%s%s%s", n_registro.nome, n_registro.sobrenome, &n_registro.idade, n_registro.salario, n_registro.cargo);
                fseek(arquivo, (n_registro.registro - 1)* sizeof(struct funcionario), SEEK_SET);

                fwrite(&n_registro, sizeof(struct funcionario), 1, arquivo);

                printf(" \nDeseja Modificar um novo registro?\n");
                printf("Digite: 1-100 para Modificar Cadastro\n");
                printf("0 - para Retornar ao menu principal\n");
                scanf("%d", &n_registro.registro);
                }
                
            }
        

                fclose(arquivo);
            }
            
}

void deletar(int registro, char nome[20], char sobrenome[20], char idade[10], char salario[20], char cargo[20]){

    int s = 0;
    int reg;
    struct funcionario n_registro;
    
    struct funcionario registro_branco = {0, "","", "", "", ""};

    FILE *arquivo;
    if((arquivo = fopen("Data_Bank.dat", "rb+")) == NULL){

        printf("Arquivo nao pode ser aberto\n");
    }else{

            printf("Digite numero de Registro de funcionario a excluir""(1-100):\n");
            fflush(stdin);
            scanf("%d", &reg);
            fseek(arquivo, (reg - 1) *sizeof(struct funcionario), SEEK_SET);
            fread(&n_registro, sizeof(struct funcionario), 1, arquivo);

            if(n_registro.registro == 0){


                    printf("Registro %d não existe\n", reg);
                }else{

                    fseek(arquivo, (reg - 1) *sizeof(struct funcionario), SEEK_SET);
                    fwrite(&registro_branco, sizeof(struct funcionario), 1, arquivo);
                    
                }

            
                fclose(arquivo);
            }
               
}




















	       