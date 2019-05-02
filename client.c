/******************************************************************************/
/*			Application: ...					*/
/******************************************************************************/
/*									      */
/*			 programme  CLIENT				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs : ... 					*/
/*									      */
/******************************************************************************/


#include <stdio.h>
#include <curses.h> 		/* Primitives de gestion d'ecran */
#include <sys/signal.h>
#include <sys/wait.h>
#include<stdlib.h>

#include "fon.h"   		/* primitives de la boite a outils */

#define SERVICE_DEFAUT "1111"
#define SERVEUR_DEFAUT "127.0.0.1"

void client_appli (char *serveur, char *service);


/*****************************************************************************/
/*--------------- programme client -----------------------*/

int main(int argc, char *argv[])
{

	char *serveur= SERVEUR_DEFAUT; /* serveur par defaut */
	char *service= SERVICE_DEFAUT; /* numero de service par defaut (no de port) */


	/* Permet de passer un nombre de parametre variable a l'executable */
	switch(argc)
	{
 	case 1 :		/* arguments par defaut */
		  printf("serveur par defaut: %s\n",serveur);
		  printf("service par defaut: %s\n",service);
		  break;
  	case 2 :		/* serveur renseigne  */
		  serveur=argv[1];
		  printf("service par defaut: %s\n",service);
		  break;
  	case 3 :		/* serveur, service renseignes */
		  serveur=argv[1];
		  service=argv[2];
		  break;
    default:
		  printf("Usage:client serveur(nom ou @IP)  service (nom ou port) \n");
		  exit(1);
	}

	/* serveur est le nom (ou l'adresse IP) auquel le client va acceder */
	/* service le numero de port sur le serveur correspondant au  */
	/* service desire par le client */

	client_appli(serveur,service);
}

/*****************************************************************************/

void vider_string(char string[100]){
	for (int i = 0; i<100; i++){
		string[i] = ' ';
	}
}

void client_appli (char *serveur,char *service)

/* procedure correspondant au traitement du client de votre application */

{
  int id_socket;
	struct sockaddr_in adr_socket_in, adr_socket_out;
	char niveau, test, string[100];

	id_socket = h_socket(AF_INET, SOCK_STREAM);
	adr_socket(service, serveur, protocole, &adr_socket_out);

	h_connect(id_socket, &adr_socket_out);

	h_reads(id_socket, string, 100);
	printf("%s\n",string);

	do{
		h_reads(id_socket, buffer, 100);
		printf("\n%s",string);

		scanf(" %c",string);
		h_writes(id_socket, string, 100);

		h_reads(id_socket, string, 100);
	} while (strcmp(string,""))

 }

/*****************************************************************************/
