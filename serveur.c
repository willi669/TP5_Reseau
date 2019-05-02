/******************************************************************************/
/*			Application: ....			              */
/******************************************************************************/
/*									      */
/*			 programme  SERVEUR 				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs :  ....						      */
/*		Date :  ....						      */
/*									      */
/******************************************************************************/

#include<stdio.h>
#include <curses.h>

#include<sys/signal.h>
#include<sys/wait.h>
#include<stdlib.h>

#include "fon.h"     		/* Primitives de la boite a outils */

#define SERVICE_DEFAUT "1111"

void serveur_appli (char *service);   /* programme serveur */


/******************************************************************************/
/*---------------- programme serveur ------------------------------*/

int main(int argc,char *argv[])
{

	char *service= SERVICE_DEFAUT; /* numero de service par defaut */


	/* Permet de passer un nombre de parametre variable a l'executable */
	switch (argc)
 	{
   	case 1:
		  printf("defaut service = %s\n", service);
		  		  break;
 	case 2:
		  service=argv[1];
            break;

   	default :
		  printf("Usage:serveur service (nom ou port) \n");
		  exit(1);
 	}

	/* service est le service (ou numero de port) auquel sera affecte
	ce serveur*/

	serveur_appli(service);
}


/******************************************************************************/
void serveur_appli(char *service)

/* Procedure correspondant au traitemnt du serveur de votre application */

{

	int id_socket, id_new, pid;
	struct sockaddr_in adr_socket_out, adr_socket_in;

	id_socket = h_socket(AF_INET, SOCK_STREAM);
	adr_socket(service, INADDR_ANY, "tcp", &adr_socket_out);
	h_bind(id_socket, &adr_socket_out);

	while(1){
		h_listen(id_socket, 5);
		printf("\nConnexion client...\n");
		id_new = h_accept(id_socket, &adr_socket_in);
		pid = fork();

		if (pid == 0){
			printf("Connexion établie!\n");
			app(id_socket, id_new);
		}
		close(id_new);
	}
}

int app(int id_socket, int id_new){

	/* écrire l'app ici*/

	return 0;
	
}

/******************************************************************************/
