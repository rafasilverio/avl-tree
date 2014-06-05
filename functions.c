/*===============================================================================*/
/* Autores: Rafael Silvério da Silva - https://github.com/rafasilverio/avl-tree  */
/*===============================================================================*/

#include "avl.h"
#include "functions.h"

#define OPTION_MIN 1
#define OPTION_MAX 6
#define OPTION_MAX_DISPLAY 3
#define INSERT 1
#define REMOVE 2
#define FIND 3
#define DISPLAY_TREE 4
#define FREE_TREE 5
#define EXIT 6
#define PRE_ORDER 1
#define IN_ORDER 2

/*Menu*/
avl_node* menu(avl_node* full_tree){
  int option = 0;
  while(option != OPTION_MAX) {
	  printf("\n\t\t***MENU***\n\tEDITOR DO DIÁRIO DE CLASSES: \n\t1 – INSERIR \n\t2 – REMOVER \n\t3 – PESQUISAR \n\t4 – EXIBIR A ÁRVORE \n\t5 – ESVAZIAR A ÁRVORE \n\t6 – SAIR \n");
	  printf("\tDigite sua opção: ");
	  scanf("%d", &option);

	  if(option >= OPTION_MIN && option <= OPTION_MAX)
		  full_tree = select_option(option, full_tree);
	  else
		  printf("OPÇÃO INVÁLIDA! \n");
	}
	return full_tree;
}

/*Select Option*/
avl_node* select_option(int option, avl_node* full_tree){
  if(option == INSERT){
  	printf("INSERCAO");
  	full_tree = option_insert(full_tree);
  }

  if(option == REMOVE){
  	printf("REMOVER");
  	full_tree = option_remove(full_tree);
  }

  if(option == FIND){
  	printf("PESQUISAR");
  	full_tree = option_find(full_tree);
  }

  if(option == DISPLAY_TREE){
  	printf("EXIBIR\n");
  	option_display_tree(full_tree);
  }

  if(option == FREE_TREE){
  	printf("LIBERAR");
  	full_tree = option_free_tree(full_tree);
  }

  if(option == EXIT){
  	printf("SAIR\n");
  	exit(1);
  }

  return full_tree;
}

/*insert*/
avl_node* option_insert(avl_node* full_tree){
  int i = 0;

  Student student;
  printf("\nMatricula do aluno: ");
	scanf("%d", &student.matriculation);

  printf("\nNome do aluno: ");
	scanf("%s", student.name);

  for(i = 0; i < 3; i++){
	  printf("\nNota aluno: ");
	  scanf("%d", &student.notes[i]);
	}

  return full_tree = insert(full_tree, student);
}

/*remove*/
avl_node* option_remove(avl_node* full_tree){
  Student student;
  printf("\nMatricula do aluno: ");
	scanf("%d", &student.matriculation);
  return full_tree = remove_node(full_tree, student);
}

/*find*/
avl_node* option_find(avl_node* full_tree){
  int find_matriculation;
  printf("\nMatricula do aluno: ");
	scanf("%d", &find_matriculation);

  avl_node* tree_search = find(full_tree, find_matriculation);

  if(tree_search != NULL){
  	printf("\n**Encontrado**\n");
  	printf("Matricula: %d\n", tree_search->data.matriculation);
  	printf("Nome: %s\n", tree_search->data.name);
  	int i = 0;
  	for(i = 0; i < 3; i++){
		  printf("Nota %d: %d\n", i+1, tree_search->data.notes[i]);
		}
  }else{
  	printf("Não encontrado!\n");
  }

  return full_tree;
}

/*display*/
void option_display_tree(avl_node* full_tree){
	int option;

  printf("\n\t\t***MENU***\n\tEXIBIR ARVORE\n1 - PRE-ORDEM\n2 - EM-ORDEM\n3 - POS-ORDEM");
  printf("\n\tDigite sua opção: ");
  scanf("%d", &option);

  if(option >= OPTION_MIN && option <= OPTION_MAX_DISPLAY){
    if(empty_node(full_tree)){
      printf("\nArvore vazia!");
    }
    else if(option == PRE_ORDER){
      display_pre_order(full_tree);
    }
    else if(option == IN_ORDER){
      display_in_order(full_tree);
    }
    else{
      display_post_order(full_tree);
    }
  }
  else{
	  printf("OPÇÃO INVÁLIDA! \n");
	}
}

/*free*/
avl_node* option_free_tree(avl_node* full_tree){
  printf("\nArvore esvaziada!");
  return full_tree = free_tree(full_tree);;
}
