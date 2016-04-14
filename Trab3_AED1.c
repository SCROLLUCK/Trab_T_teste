#include <stdio.h>
#include <stdlib.h>

typedef struct tipoLivro{

    char Nome_Autor[40];
    char Nome_Livro[40];

}tipoLivro;

typedef struct tipoNo{
    tipoLivro Livro;
    struct tipoNo *Prox;
    struct tipoNo *Ant;
}tipoNo;

typedef struct tipoLista{
    struct tipoNo *Inicio;
}tipoLista;

/*-------------------------------------------------------------*/

    void Mostra_Lista(tipoLista *Lista){
        tipoNo *Aux = Lista->Inicio;
        while(Aux != NULL){
            printf(" - %s",Aux->Livro.Nome_Livro);
        Aux = Aux->Prox;
        }
    }

/*-------------------------------------------------------------*/

    tipoNo* Remove_da_Lista(tipoLista* Lista, tipoLivro LIVRO){
        tipoNo *Aux = Lista->Inicio;
        while((strcmp(Aux->Livro.Nome_Livro,LIVRO.Nome_Livro) != 0) && Aux != NULL)
        Aux = Aux->Prox;
    return Aux;
}
/*-------------------------------------------------------------*/

    void Insere_na_Lista(tipoLista *LISTA,tipoNo *NO){
        tipoNo *Aux =  LISTA->Inicio;
        if(Aux == NULL)
            Aux = NO;
        else{
            while(Aux->Prox != NULL)
            Aux = Aux->Prox;
            if(Aux->Prox == NULL)
                Aux->Prox = NO;
        }
    }

/*-------------------------------------------------------------*/

    void Emprestar_Livro(char* Nome_Livro,tipoLista* Lista_Acervo,tipoLista* Lista_Emprestimo){
        tipoNo *Aux = Lista_Acervo->Inicio;
        while((strcmp(Aux->Livro.Nome_Livro,Nome_Livro) != 0) && (Aux->Prox != NULL))
            Aux = Aux->Prox;
         //Remove_Livro(Lista_Acervo,Aux);
         //Insere_na_Lista(Lista_Emprestimo);
    }

    void Procura_Livro(char* Nome_Livro,tipoLista* Lista_Arcevo,tipoLista* Lista_Emprestimo,tipoLista* Consulta_Local){
        tipoNo* Aux = Lista_Arcevo->Inicio;

        while( strcmp(Nome_Livro,Aux->Livro.Nome_Livro) != 0)
            Aux = Aux->Prox;
        if(strcmp(Aux->Livro.Nome_Livro,Aux->Prox->Livro.Nome_Livro) == 0)
            Emprestar_Livro(Nome_Livro,Lista_Arcevo,Lista_Emprestimo);
        else
            printf("Este livro so esta disponivel para consulta local");
            //Insere_na_Lista(Consulta_Local,Aux);
            //Remove_da_Lista(Lista_Arcevo,Aux->Livro);
    }



int main(){

tipoLista ACERVO_BIBLIOTECA;    // contem todos os livros.
tipoLista EMPRESTIMO;           //contém os livros emprestados
tipoLista CONSULTA_LOCAL;       //Contém os livros apenas paraq consutas locais.
 char Nome[10] = "Lucas";
//Busca_na_Lista(Nome);

}
