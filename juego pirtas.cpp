/*	Explicación ejercicio de matrices
	1. El Pirata Pata de Palo desea conseguir el Gran Tesoro sin morir ahogado. La Isla que
	consiste en un tablero cuadrado de NxN, rodeado de agua y con 2 puentes en dos esquinas
	se puede representar así:
	
	Mediante un menú con 3 opciones:
	1. inicializarTablero() que coloque sobre el tablero al Pirata y el Gran Tesoro en
	casillas distintas determinadas de forma aleatoria (averigüe cómo se usa el
	random para el lenguaje).
	El agua de debe colocar en los bordes y los puentes en las esquinas como
	indica el dibujo
	2. dibujarTablero() que dibuje el tablero como muestra la figura (no mostrando la
	ubicación del tesoro)
	3. BuscarTesoro() que permita al pirata buscar el tesoro en menos de 50
	movimientos. El pirata recorre los cuadros de uno en uno según la dirección
	ingresada (N, S, E, O) que se solicita cuando se ingresa a la opción. Se finaliza
	cuando se llegó al movimiento 50 o cuando encontró el Gran Tesoro.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
const int n=5;
int i,j,k,l,o,p,opcion, movimientos=50, ganaste;
char posicion;
char pos1 = 'N', pos2 = 'S', pos3='E', pos4='O';
int tablero[n][n];
int pirata[n][n];
int tesoro[n][n];
main ()
{
printf ("Bienvenido al juego del pirata!! \n");
//hace el menu y ejecuta la opcion que elija el usuario
	while (1) 
	printf ("1. inicializarTablero() que coloque sobre el tablero al Pirata y el Gran Tesoro en	casillas distintas determinadas de forma aleatoria (averigüe cómo se usa el	random para el lenguaje).	El agua de debe colocar en los bordes y los puentes en las esquinas como	indica el dibujo \n	2. dibujarTablero() que dibuje el tablero como muestra la figura (no mostrando laubicacion del tesoro) \n	3. BuscarTesoro() que permita al pirata buscar el tesoro en menos de 50	movimientos. El pirata recorre los cuadros de uno en uno segun la direccion	ingresada (N, S, E, O) que se solicita cuando se ingresa a la opcion. Se finaliza	cuando se llego al movimiento 50 o cuando encontro el Gran Tesoro.\n Ingrese la opcion que elige: ");
	scanf ("%d", &opcion);
	switch (opcion)
	{	
	//inicializarTablero() que coloque sobre el tablero al Pirata y el Gran Tesoro en casillas distintas determinadas de forma aleatoria (averigüe cómo se usa el random para el lenguaje).
		case 1:{
			printf ("se a aleatorizado la posicion del tesoro y el pirata");
			getch(); 
			//genera un numero aleatorio para la posicion del pirata y otro numero aleatorio para la posicion del tesoro
			//solamente en las casillas que son tierra (osea sin incluir los bordes de la matriz)
			srand(time(NULL));
			o=1+rand()%(n-1); 
			p=1+rand()%(n-1);
			//pirata o p 
			k=1+rand()%(n-1);	
			l=1+rand()%(n-1);	
			//tesoro k l
			//si el tesoro y el pirata estan en el mismo lugar vuelve a buscar una posicion aleatoria para el pirata
				while (i==k && l==j)
				{
				o=1+rand()%(n-1);
				p=1+rand()%(n-1);
				}
		break;
		}
		case 2:{
		//2. dibujarTablero() que dibuje el tablero como muestra la figura (no mostrando la ubicacion del tesoro)
			//si es un borde pone A de agua, si es una esquina un ▓ como si fuera un puente, los casilleros de tierra estan vacios y ☺ es el pirata
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
		//hago un for para dibujar los casilleros 1 por 1
				{
					//identifica si es un borde, si lo es pone agua
					if ((i==n)|| (i==0) || (j==n) || (j==0))
					{printf ("|A|");}
					//si es una esquina i=j y i = n o i = 0 pone un puente (▓)
					else if ( (i==j) && (i==0 || i==n) )
					{printf ("|▓|");}
					//si no es un borde y no esta el pirata dibuja un casillero vacio (tierra)
					if ( (i!=0 && i!=n && j!=0 && j!=n) && (tablero[i][j]!=pirata[o][p]) )
					{printf ("| |");}
					//dibuja al pirata en su lugar
					if (tablero[i][j]==pirata[o][p])
					{printf ("|☺|");}
				}
				printf ("\n");
			}
		break;
		}
		case 3:{
			//3. BuscarTesoro() que permita al pirata buscar el tesoro en menos de 50	movimientos. El pirata recorre los cuadros de uno en uno segun la direccion	ingresada (N, S, E, O) que se solicita cuando se ingresa a la opcion. Se finaliza	cuando se llego al movimiento 50 o cuando encontro el Gran Tesoro.\n Ingrese la opcion que elige: ");
			movimientos=50;
			while (movimientos!=0 && ganaste!=1)
			{
			printf ("\n tienes %d movimientos", movimientos);
			movimientos--;
			printf ("\n Ingrese la direccion en la que se quiere mover, N (Norte), S (Sur), E (este), O (Oeste): ");
			scanf ("%c",&posicion);
			//pos 1 arriba | pos 2 abajo | pos 3 derecha | pos 4 izquierda 
				if (posicion==pos1 && o!=n)
				{o=o+1;}
				//si ya esta arriba del todo, le pide otra direccion para no caer al agua
				while (posicion==pos2 && o==n)
				{
				printf ("\n hay agua, porfavor ingrese otro direccion");
				scanf ("%c", &posicion);
				}
				
				//pos2 S (abajo)
				else if(posicion==pos2 && o!=1)
				{o=o-1;}
				//si ya esta abajo del todo, le pide otra direccion para no caer al agua
				while (posicion==pos2 && o==1)
				{
				printf ("\n hay agua, porfavor ingrese otro direccion");
				scanf ("%c", &posicion);
				}
				//pos3 E (derecha)
				else if(posicion==pos3 && p!=n)
				{p=p+1;}
				//si ya esta a la derecha del todo, le pide otra direccion para no caer al agua
				while (posicion==pos3 && p==n)
				{
				printf ("\n hay agua, porfavor ingrese otro direccion");
				scanf ("%c", &posicion);
				}
				//pos4 O (izquierda)
				else if(posicion==pos4 && p!=1)
				{p=p-1;}	
				//si ya esta a la izquierda del todo, le pide otra direccion para no caer al agua
				while (posicion==pos4 && p==1)
				{
				printf ("\n hay agua, porfavor ingrese otro direccion");
				scanf ("%c", &posicion);
				}
				
				//si el pirata esta en el mismo lugar que el tesoro, ganas, si no mueves devuelta
				if (pirata[o][p]==tesoro[k][l])
				{
					printf ("\n Felicidades, haz encontrado el tesoro");
					ganaste=1;
				}
				//si te quedaste sin movimientos, pierdes y el juego termina
				if (movimientos==0)
				{
					printf ("\n Te haz quedado sin movimietos, perdiste");
				}
			}	
			break;
		}
		default: printf ("esa no es una opcion!!!"); //si ingresa un numero que no es una opcion
		
	}
	
}