//programa: administrador de tareas...modo consola.....
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> //libreriass.....
#include<Windows.h>
#include <string>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string>
#include<string.h>
#include<cstring>//libreriass.....
#include "CabeceraAuxiliar.h" //invocacion del archivo auxiliar hederrr.....para la llamada de funciones.....
#define NUMPROCESOS    10 // establece la cantidad maxima de procesos a desplegar e incializar....................!!

using namespace std;
//funciones prototipo
void linea();
void cargarprocesos();
void mostrarProcesos();
void actualizarProcesos();
void despliegueproceso(int id);
void modificacionestado(int idb);
void modificarProceso();
void modificacioncarga(int idb, int ran);
void infosystem();
void infoswinlong();
void infowininit();
void infocsrss();
void infossmss();
void infoShellhost();
void infoexplorer();
void infodllhost();
void infolsass();
void infoservices();
void procesosFin();
void planificacionRoundRobin();
//varibles globales

//............................
struct procesos {//estructura de variables que almacenaran los datos..... 
	char letra[2];
	char pid[10];
	char nombre[15];
	double memoria;
	int cpu;
	int idestado;
	string estado = " ";
	string consumoe = " ";
	procesos* siguiente;
};

// incializazacion de la estructura datos predifinidoss......procesos que se visualizaran......!!
struct procesos procesosini[] = {
								 {"A","12256","System",8.61,13,1," "," "},
								 {"B","45625","winlong",8.61,2,1," "," "},
								 {"C","75363","wininit",8.61,6,1," "," "},
								 {"D","68943","csrss",8.61,6,1," "," "},
								 {"E","28933","Ssmss",8.61,6,1," "," "},
								 {"F","79943","Shellhost",8.61,6,1," "," "},
								 {"G","28963","explorer",8.61,6,1," "," "},
								 {"H","18953","dllhost",8.61,6,1," "," "},
								 {"I","68973","Lsass",8.61,6,1," "," "},
								 {"J","25963","services",8.61,6,1," "," "},
};


// funciones/procedemitos que  utiliza el programa.............................

void cargarprocesos() { // funcion que visualiza la carga de procesoss...a la aplicacion....
	//procesos *Procesocarga = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	//Procesocarga = procesosini; // carga los elementos inicializados a la estructura nodo creado......					
	system("color 0A");
	char tab = '\t';
	int porcentaje = 10;
	int idproc = 0;
	//"Bloqueado","Iniciando","Ejecuntado", "Terminado", "Prueba" ;
	cout << tab << tab << "  Cargando procesos................... ! espere....." << endl;
	cout << tab << tab << " _____________________________________________________" << endl;

	for (int i = 0; i < NUMPROCESOS; i++)
	{
		srand((unsigned)time(NULL));//obtener el numero aleatroio
		int ale = 1 + rand() % 4;
		modificacioncarga(idproc, ale);//carga el estado aleatroio
		idproc = idproc++;
		cout << tab << tab << tab << "Cargando ....... [" << porcentaje << "-% ]......." << endl;
		porcentaje = porcentaje + 10;
		Sleep(600);
	}

	cout << tab << tab << " ______________________________________________________" << endl;
	cout << tab << tab << "       Carga de procesos finalizado....!!!          " << endl;
	Sleep(600);
}

void cargarprocesosauto() { // funcion que visualiza la carga de procesoss...a la aplicacion....
	//procesos *Procesocarga = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	//Procesocarga = procesosini; // carga los elementos inicializados a la estructura nodo creado......					
	system("color 0A");
	char tab = '\t';
	int porcentaje = 10;
	int idproc = 0;
	cout << tab << tab << "  Reiniciando procesos........... ! espere....." << endl;
	for (int i = 0; i < NUMPROCESOS; i++)
	{
		srand((unsigned)time(NULL));//obtener el numero aleatroio
		int ale = 1 + rand() % 4;
		modificacioncarga(idproc, ale);//carga el estado aleatroio
		idproc = idproc++;
		cout << tab << tab << tab << "Cargando ....... [" << porcentaje << "-% ]......." << endl;
		porcentaje = porcentaje + 10;
		Sleep(100);
	}
	cout << tab << tab << " ______________________________________________________" << endl;
	cout << tab << tab << "       Carga de procesos finalizado....!!!          " << endl;
	Sleep(200);
}

void mostrarProcesos() {
	color(2);
	cout << endl;
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	int cantidadprocesos; // define la cantidad incial de procesos o registross.....
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	cout << ".........................................PROCESOS EN EJECUACION..........................................." << endl; //cabecera
	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |   IDESTADO     |" << endl;// titulo de columnas...
	cout << ("=========================================================================================================") << endl; //separdor....
	for (cantidadprocesos = 0; cantidadprocesos < NUMPROCESOS; cantidadprocesos++) //bucle que dibuja los procesos encontrados......
	{
		
			color(Elemento->idestado); //le implementa el color deacuerdo a su estado.
			//dibuaja la tabulacion y extrae el dato correpondiente de la estructura.....
			cout << tab << "-> " << Elemento->nombre << tab << "-> " << Elemento->pid << tab << "->" << Elemento->estado << tab << "->"
				<< setprecision(2) << Elemento->memoria << "-MB." << tab << "->" << Elemento->cpu << "-%" << tab << "-> " << Elemento->consumoe << tab << "-> " << Elemento->idestado << tab << endl;
		//pausa un lapso de tiempo de forma automatica.......
		Sleep(200);
		Elemento++; // incrementa el indice de la estructur para mostrar el seguiente.....
	}

}




void actualizarProcesos() {
	color(2);
	cout << endl;
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	int cantidadprocesos; // define la cantidad incial de procesos o registross.....
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	cout << ".........................................PROCESOS EN EJECUACION..........................................." << endl; //cabecera
	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |   IDESTADO     |" << endl;// titulo de columnas...
	cout << ("=========================================================================================================") << endl; //separdor....
	for (cantidadprocesos = 0; cantidadprocesos < NUMPROCESOS; cantidadprocesos++) //bucle que dibuja los procesos encontrados......
	{
		if (Elemento->idestado == 5)
		{
			color(3);
			cout << tab << "-> " << Elemento->nombre<<tab<< "...Finalizado"<<endl;
		}
		else
		{
			color(Elemento->idestado); //le implementa el color deacuerdo a su estado.
			//dibuaja la tabulacion y extrae el dato correpondiente de la estructura.....
			cout << tab << "-> " << Elemento->nombre << tab << "-> " << Elemento->pid << tab << "->" << Elemento->estado << tab << "->"
			<< setprecision(2) << Elemento->memoria << "-MB." << tab << "->" << Elemento->cpu << "-%" << tab << "-> " << Elemento->consumoe << tab << "-> " << Elemento->idestado  << endl;
		}
			
			//pausa un lapso de tiempo de forma automatica.......
			Sleep(200);	
		Elemento++; // incrementa el indice de la estructur para mostrar el seguiente.....
	}
		
}

void despliegueproceso(int id) {
	color(3);
	cout << endl;
	struct procesos* Procesodetalle; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesodetalle = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	Sleep(500);
	cout << ".........................................DETALLE DE PROCESO [" << Procesodetalle[id].nombre << "]....................." << endl; //cabecera

	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |     RAFAGA CPU     |" << endl;
	cout << ("=====================================================================================================================") << endl; //separdor....
	cout << tab << "-> " << Procesodetalle[id].nombre << tab << "-> " << Procesodetalle[id].pid << tab << "->" << Procesodetalle[id].estado << tab << "->"
		<< setprecision(2) << Procesodetalle[id].memoria << "-MB." << tab << "->" << Procesodetalle[id].cpu << "-%" << tab << "-> " << Procesodetalle[id].consumoe <<  endl;

}



void modificacioncarga(int idb, int ran) {
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini;// carga los elementos inicializados a la estructura nodo creado......
	char tab = '\t';
	switch (ran)
	{

	case 1: Procesobloq[idb].memoria = (ran / 1.3); Procesobloq[idb].cpu = (ran * 15); 
		Procesobloq[idb].idestado = 1; Procesobloq[idb].estado = "Nuevo....."; Procesobloq[idb].consumoe = "Alta"; break;
	case 2: Procesobloq[idb].memoria = (ran / 2.7); Procesobloq[idb].cpu = (ran * 18); 
		Procesobloq[idb].idestado = 2; Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta"; break;
	case 3: Procesobloq[idb].memoria = (ran / 3.3); Procesobloq[idb].cpu = (ran * 6); 
		Procesobloq[idb].idestado = 3; Procesobloq[idb].estado = "Bloqueado."; Procesobloq[idb].consumoe = "Baja"; break;
	case 4: Procesobloq[idb].memoria = (ran / 0.7); Procesobloq[idb].cpu = (ran * 20); 
		Procesobloq[idb].idestado = 4; Procesobloq[idb].estado = "Ejecucion."; Procesobloq[idb].consumoe = "Alta"; break;
	case 5: Procesobloq[idb].memoria = (ran / 3.6); Procesobloq[idb].cpu = (ran * 3); 
		Procesobloq[idb].idestado = 5; Procesobloq[idb].estado = "Terminado.."; Procesobloq[idb].consumoe = "Baja"; break;
	}
}
void actualizarEstados() {
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	int estadoactual;
	for (int row = 0; row < NUMPROCESOS; row++)
	{
		switch (Procesobloq->idestado)
		{
		case 1: Procesobloq->memoria = (25.2); Procesobloq->cpu = (45);
			Procesobloq->idestado = 2; Procesobloq->estado = "Listo....."; Procesobloq->consumoe = "Alta";
			break;
		case 2:	Procesobloq->memoria = (2.61); Procesobloq->cpu = (47);
			Procesobloq->idestado = 3; Procesobloq->estado = "Bloqueado."; Procesobloq->consumoe = "Alta";
			break;
		case 3: Procesobloq->memoria = (23.2); Procesobloq->cpu = (61);
			Procesobloq->idestado = 4; Procesobloq->estado = "Ejecucion."; Procesobloq->consumoe = "Alta";
			break;
		case 4: Procesobloq->memoria = (0.12); Procesobloq->cpu = (0);
			Procesobloq->idestado = 5; Procesobloq->estado = "Terminado.."; Procesobloq->consumoe = "Baja";
			break;
		case 5: Procesobloq->memoria = (0.12); Procesobloq->cpu = (0);
			Procesobloq->idestado = 5; Procesobloq->estado = "Terminado.."; Procesobloq->consumoe = "Baja";
			break;
		}

		Procesobloq++;
	}
	
}


void modificacionestado(int idb) {
	color(4);
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	string estadoactual;
	Sleep(300);
	estadoactual = Procesobloq[idb].estado;
	char mcomando;
	if (estadoactual == "Terminado..")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [n]'Nuevo'|" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'n')
			{
				Procesobloq[idb].memoria = (25.2); Procesobloq[idb].cpu = (45); Procesobloq[idb].idestado=1;
				Procesobloq[idb].estado = "Nuevo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El procesos cambio de estado a [Nuevo] ";
				cout << endl;
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Nuevo]" << endl << endl;
				return;
			}
		} while (mcomando != 'n');
	}

	if (estadoactual == "Nuevo.....")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [l]'Listo' |" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'l')
			{
				Procesobloq[idb].memoria = (2.61); Procesobloq[idb].cpu = (47);Procesobloq[idb].idestado =2;
				Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a [Listo]";
				cout << endl;
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Listo]" << endl << endl;
				return;
			}
		} while (mcomando != 'l');
	}

	if (estadoactual == "Listo.....")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [e]'Ejecutar'|" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'e')
			{
				Procesobloq[idb].memoria = (23.2); Procesobloq[idb].cpu = (61); Procesobloq[idb].idestado = 4;
				Procesobloq[idb].estado = "Ejecucion."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a: [Ejecucion]";
				cout << endl;
				
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Ejecutado]" << endl << endl;
				return;
			}
		} while (mcomando != 'e');
	}

	if (estadoactual == "Ejecucion.")
	{
		cout << endl;
		char tab = '\t';
		cout << tab << "| opcion de cambio: [t]'Terminar' | [b]'Bloquear' |" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 't')
			{
				Procesobloq[idb].memoria = (0.12); Procesobloq[idb].cpu = (0); Procesobloq[idb].idestado = 5;
				Procesobloq[idb].estado = "Terminado.."; Procesobloq[idb].consumoe = "Baja";
				Sleep(100);
				cout << "El proceso cambio de estado a [Terminado] ";
				cout << endl;
				
			}

			else if (mcomando == 'b')
			{
				Procesobloq[idb].memoria = (0.9); Procesobloq[idb].cpu = (11); Procesobloq[idb].idestado = 3;
				Procesobloq[idb].estado = "Bloqueado."; Procesobloq[idb].consumoe = "Baja";
				Sleep(100);
				cout << "El proceso cambio de estado a: [Bloqueado] ";
				cout << endl;
				
			}

			else
			{
				cout << "el proceso solo tiene la opcion [Terminado o Bloqueado]" << endl << endl;
				return;
			}
		} while (mcomando == ('t' || 'b'));
	}

	if (estadoactual == "Bloqueado.")
	{
		cout << endl;
		char tab = '\t';
		cout << tab << "| opcion de cambio: [l]'Listo' |" << endl;
		cout << ("[inserte-comando-modificacion]==>"); mcomando = getchar();

		do
		{
			if (mcomando == 'l')
			{
				Procesobloq[idb].memoria = (3.57); Procesobloq[idb].cpu = (25); Procesobloq[idb].idestado = 2;
				Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a [Listo] ";
				cout << endl;
				
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Listo]" << endl << endl;
				return;
			}
		} while (mcomando != 'l');
	}

}

//----------------------------MOUDULO DE ROUND ROBIN--------------------------
//variables globales
int ta, tb, tc, td, te, tf, tg, th, ti, tj, cuantum = 2;
int porprocesar[10] = { 'A','B','C','D','E','F','G','H','I','j' };
int procesados[10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
int ultimo = 0;
int sobran = 9;
int  filtot = 1, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0;



//funciones
void procesosFin() {
	cout << endl;
	color(4);
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......

	gotoxy(2, 32); cout << " |-----------------------ORDEN DE FINALIZACION DE PROCESOS -----------------------------|" << endl;// titulo de columnas...


	gotoxy(2, f1 + 33); cout << tab << "-> [" << Elemento[0].letra << "]" << tab << "-> " << Elemento[0].nombre << tab << "-> " << Elemento[0].pid << tab << "->"
		<< Elemento[0].memoria << "-MB." << tab << "->" << Elemento[0].cpu << "-%" << tab << "-> " << Elemento[0].consumoe << tab << "-> " << ta ;

	gotoxy(2, f2 + 33); cout << tab << "-> [" << Elemento[1].letra << "]" << tab << "-> " << Elemento[1].nombre << tab << "-> " << Elemento[1].pid << tab << "->"
		<< Elemento[1].memoria << "-MB." << tab << "->" << Elemento[1].cpu << "-%" << tab << "-> " << Elemento[1].consumoe << tab << "-> " << tb ;

	gotoxy(2, f3 + 33); cout << tab << "-> [" << Elemento[2].letra << "]" << tab << "-> " << Elemento[2].nombre << tab << "-> " << Elemento[2].pid << tab << "->"
		<< Elemento[2].memoria << "-MB." << tab << "->" << Elemento[2].cpu << "-%" << tab << "-> " << Elemento[2].consumoe << tab << "-> " << tc;

	gotoxy(2, f4 + 33); cout << tab << "-> [" << Elemento[3].letra << "]" << tab << "-> " << Elemento[3].nombre << tab << "-> " << Elemento[3].pid << tab << "->"
		<< Elemento[3].memoria << "-MB." << tab << "->" << Elemento[3].cpu << "-%" << tab << "-> " << Elemento[3].consumoe << tab << "-> " << td;
	gotoxy(2, f5 + 33);
	cout << tab << "-> [" << Elemento[4].letra << "]" << tab << "-> " << Elemento[4].nombre << tab << "-> " << Elemento[4].pid << tab << "->"
		<< Elemento[4].memoria << "-MB." << tab << "->" << Elemento[4].cpu << "-%" << tab << "-> " << Elemento[4].consumoe << tab << "-> " << te ;
	gotoxy(2, f6 + 33);
	cout << tab << "-> [" << Elemento[5].letra << "]" << tab << "-> " << Elemento[5].nombre << tab << "-> " << Elemento[5].pid << tab << "->"
		<< Elemento[5].memoria << "-MB." << tab << "->" << Elemento[5].cpu << "-%" << tab << "-> " << Elemento[5].consumoe << tab << "-> " << tf;
	gotoxy(2, f7 + 33);
	cout << tab << "-> [" << Elemento[6].letra << "]" << tab << "-> " << Elemento[6].nombre << tab << "-> " << Elemento[6].pid << tab << "->"
		<< Elemento[6].memoria << "-MB." << tab << "->" << Elemento[6].cpu << "-%" << tab << "-> " << Elemento[6].consumoe << tab << "-> " << tg;
	gotoxy(2, f8 + 33);
	cout << tab << "-> [" << Elemento[7].letra << "]" << tab << "-> " << Elemento[7].nombre << tab << "-> " << Elemento[7].pid << tab << "->"
		<< Elemento[7].memoria << "-MB." << tab << "->" << Elemento[7].cpu << "-%" << tab << "-> " << Elemento[7].consumoe << tab << "-> " << th;
	gotoxy(2, f9 + 33);
	cout << tab << "-> [" << Elemento[8].letra << "]" << tab << "-> " << Elemento[8].nombre << tab << "-> " << Elemento[8].pid << tab << "->"
		<< Elemento[8].memoria << "-MB." << tab << "->" << Elemento[8].cpu << "-%" << tab << "-> " << Elemento[8].consumoe << tab << "-> " << ti;
	gotoxy(2, f10 + 33);
	cout << tab << "-> [" << Elemento[9].letra << "]" << tab << "-> " << Elemento[9].nombre << tab << "-> " << Elemento[9].pid << tab << "->"
		<< Elemento[9].memoria << "-MB." << tab << "->" << Elemento[9].cpu << "-%" << tab << "-> " << Elemento[9].consumoe << tab << "-> " << tj;
	gotoxy(2, 44); cout << ("------------------------------------------------------------------------------------ ") << endl; //separdor....

}

void procesosIni() {
	cout << endl;
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	gotoxy(2, 18); cout << "..................................PROCESOS EN EJECUACION.................................." << endl; //cabecera
	gotoxy(2, 19); cout << " |IDENTIFICADOR |  NOMBRE      |   PID      |   MEMORIA    |   CPU  | CONSUMO   | RAFAGA |" << endl;// titulo de columnas...
	gotoxy(2, 20); cout << ("=========================================================================================") << endl; //separdor....

	if (ta == 0)
	{
		if (f1 == 0)
		{
			f1 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 21); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (ta < 4)
	{
		color(1);
		gotoxy(2, 21); cout << tab << "-> [" << Elemento[0].letra << "]" << tab << "-> " << Elemento[0].nombre << tab << "-> " << Elemento[0].pid << tab << "->"
			<< Elemento[0].memoria << "-MB." << tab << "->" << Elemento[0].cpu << "-%" << tab << "-> " << Elemento[0].consumoe << tab << "-> " << ta ;

	}
	else
	{


		color(4);
		gotoxy(2, 21); cout << tab << "-> [" << Elemento[0].letra << "]" << tab << "-> " << Elemento[0].nombre << tab << "-> " << Elemento[0].pid << tab << "->"
			<< Elemento[0].memoria << "-MB." << tab << "->" << Elemento[0].cpu << "-%" << tab << "-> " << Elemento[0].consumoe << tab << "-> " << ta ;
	}

	if (tb == 0)
	{
		if (f2 == 0)
		{
			f2 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 22); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (tb < 3)
	{
		color(1);
		gotoxy(2, 22);	cout << tab << "-> [" << Elemento[1].letra << "]" << tab << "-> " << Elemento[1].nombre << tab << "-> " << Elemento[1].pid << tab << "->"
			<< Elemento[1].memoria << "-MB." << tab << "->" << Elemento[1].cpu << "-%" << tab << "-> " << Elemento[1].consumoe << tab << "-> " << tb ;
	}
	else
	{
		color(4);
		gotoxy(2, 22); cout << tab << "-> [" << Elemento[1].letra << "]" << tab << "-> " << Elemento[1].nombre << tab << "-> " << Elemento[1].pid << tab << "->"
			<< Elemento[1].memoria << "-MB." << tab << "->" << Elemento[1].cpu << "-%" << tab << "-> " << Elemento[1].consumoe << tab << "-> " << tb;
	}

	if (tc == 0)
	{
		if (f3 == 0)
		{
			f3 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 23); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (tc < 10)
	{
		color(1);
		gotoxy(2, 23); cout << tab << "-> [" << Elemento[2].letra << "]" << tab << "-> " << Elemento[2].nombre << tab << "-> " << Elemento[2].pid << tab << "->"
			<< Elemento[2].memoria << "-MB." << tab << "->" << Elemento[2].cpu << "-%" << tab << "-> " << Elemento[2].consumoe << tab << "->  "<< tc;
	}
	else
	{

		color(4);
		gotoxy(2, 23); 
		
			cout << tab << "-> [" << Elemento[2].letra << "]" << tab << "-> " << Elemento[2].nombre << tab << "-> " << Elemento[2].pid << tab << "->"
				<< Elemento[2].memoria << "-MB." << tab << "->" << Elemento[2].cpu << "-%" << tab << "-> " << Elemento[2].consumoe << tab << "-> " << tc;

		
		
	}

	if (td == 0)
	{
		if (f4 == 0)
		{
			f4 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 24); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (td < 8)
	{
		color(1);
		gotoxy(2, 24); cout << tab << "-> [" << Elemento[3].letra << "]" << tab << "-> " << Elemento[3].nombre << tab << "-> " << Elemento[3].pid << tab << "->"
			<< Elemento[3].memoria << "-MB." << tab << "->" << Elemento[3].cpu << "-%" << tab << "-> " << Elemento[3].consumoe << tab << "-> " << td;
	}
	else
	{


		color(4);
		gotoxy(2, 24); cout << tab << "-> [" << Elemento[3].letra << "]" << tab << "-> " << Elemento[3].nombre << tab << "-> " << Elemento[3].pid << tab << "->"
			<< Elemento[3].memoria << "-MB." << tab << "->" << Elemento[3].cpu << "-%" << tab << "-> " << Elemento[3].consumoe << tab << "-> " << td;
	}
	//-----------------------------------
	if (te == 0)
	{
		if (f5 == 0)
		{
			f5 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 25); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (te  < 6)
	{
		color(1);
		gotoxy(2, 25); cout << tab << "-> [" << Elemento[4].letra << "]" << tab << "-> " << Elemento[4].nombre << tab << "-> " << Elemento[4].pid << tab << "->"
			<< Elemento[4].memoria << "-MB." << tab << "->" << Elemento[4].cpu << "-%" << tab << "-> " << Elemento[4].consumoe << tab << "-> " << te;
	}
	else
	{


		color(4);
		gotoxy(2, 25); cout << tab << "-> [" << Elemento[4].letra << "]" << tab << "-> " << Elemento[4].nombre << tab << "-> " << Elemento[4].pid << tab << "->"
			<< Elemento[4].memoria << "-MB." << tab << "->" << Elemento[4].cpu << "-%" << tab << "-> " << Elemento[4].consumoe << tab << "-> " << te;
	}
	//-----------------------------------
	if (tf == 0)
	{
		if (f6 == 0)
		{
			f6 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 26); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (tf == 1)
	{
		color(4);
		gotoxy(2, 26); cout << tab << "-> [" << Elemento[5].letra << "]" << tab << "-> " << Elemento[5].nombre << tab << "-> " << Elemento[5].pid << tab << "->"
			<< Elemento[5].memoria << "-MB." << tab << "->" << Elemento[5].cpu << "-%" << tab << "-> " << Elemento[5].consumoe << tab << "-> " << tf;
	}
	else
	{


		color(1);
		gotoxy(2, 26); cout << tab << "-> [" << Elemento[5].letra << "]" << tab << "-> " << Elemento[5].nombre << tab << "-> " << Elemento[5].pid << tab << "->"
			<< Elemento[5].memoria << "-MB." << tab << "->" << Elemento[5].cpu << "-%" << tab << "-> " << Elemento[5].consumoe << tab << "-> " << tf;
	}
	//-----------------------------------
	if (tg == 0)
	{
		if (f7 == 0)
		{
			f7 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 27); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (tg < 7)
	{
		color(1);
		gotoxy(2, 27); cout << tab << "-> [" << Elemento[6].letra << "]" << tab << "-> " << Elemento[6].nombre << tab << "-> " << Elemento[6].pid << tab << "->"
			<< Elemento[6].memoria << "-MB." << tab << "->" << Elemento[6].cpu << "-%" << tab << "-> " << Elemento[6].consumoe << tab << "-> " << tg;
	}
	else
	{


		color(4);
		gotoxy(2, 27); cout << tab << "-> [" << Elemento[6].letra << "]" << tab << "-> " << Elemento[6].nombre << tab << "-> " << Elemento[6].pid << tab << "->"
			<< Elemento[6].memoria << "-MB." << tab << "->" << Elemento[6].cpu << "-%" << tab << "-> " << Elemento[6].consumoe << tab << "-> " << tg;
	}
	//---------------------------------------------
	if (th == 0)
	{
		if (f8 == 0)
		{
			f8 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 28); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (th < 9)
	{
		color(1);
		gotoxy(2, 28);
		cout << tab << "-> [" << Elemento[7].letra << "]" << tab << "-> " << Elemento[7].nombre << tab << "-> " << Elemento[7].pid << tab << "->"
			<< Elemento[7].memoria << "-MB." << tab << "->" << Elemento[7].cpu << "-%" << tab << "-> " << Elemento[7].consumoe << tab << "-> " << th;

	}
	else
	{


		color(4);
		gotoxy(2, 28);
		cout << tab << "-> [" << Elemento[7].letra << "]" << tab << "-> " << Elemento[7].nombre << tab << "-> " << Elemento[7].pid << tab << "->"
			<< Elemento[7].memoria << "-MB." << tab << "->" << Elemento[7].cpu << "-%" << tab << "-> " << Elemento[7].consumoe << tab << "-> " << th ;

	}
	//---------------------------------------------
	if (ti == 0)
	{
		if (f9 == 0)
		{
			f9 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 29); cout << tab << "-> --------------------------------------------------------------------------->" << endl;

	}
	else if (ti < 2)
	{
		color(1);
		gotoxy(2, 29); cout << tab << "-> [" << Elemento[8].letra << "]" << tab << "-> " << Elemento[8].nombre << tab << "-> " << Elemento[8].pid << tab << "->"
			<< Elemento[8].memoria << "-MB." << tab << "->" << Elemento[8].cpu << "-%" << tab << "-> " << Elemento[8].consumoe << tab << "-> " << ti;
	}
	else
	{
		color(4);
		gotoxy(2, 29);cout << tab << "-> [" << Elemento[8].letra << "]" << tab << "-> " << Elemento[8].nombre << tab << "-> " << Elemento[8].pid << tab << "->"
			<< Elemento[8].memoria << "-MB." << tab << "->" << Elemento[8].cpu << "-%" << tab << "-> " << Elemento[8].consumoe << tab << "-> " << ti;
	}
	//---------------------------------------------
	if (tj == 0)
	{
		if (f10 == 0)
		{
			f10 = filtot;
			filtot = filtot++;
		}
		color(3);
		gotoxy(2, 30); cout << tab << "-> --------------------------------------------------------------------------->";

	}
	else if (tj == 1)
	{
		color(4);
		gotoxy(2, 30); cout << tab << "-> [" << Elemento[9].letra << "]" << tab << "-> " << Elemento[9].nombre << tab << "-> " << Elemento[9].pid << tab << "->"
			<< Elemento[9].memoria << "-MB." << tab << "->" << Elemento[9].cpu << "-%" << tab << "-> " << Elemento[9].consumoe << tab << "-> " << tj;
	}
	else
	{


		color(1);
		gotoxy(2, 30); cout << tab << "-> [" << Elemento[9].letra << "]" << tab << "-> " << Elemento[9].nombre << tab << "-> " << Elemento[9].pid << tab << "->"
			<< Elemento[9].memoria << "-MB." << tab << "->" << Elemento[9].cpu << "-%" << tab << "-> " << Elemento[9].consumoe << tab << "-> " << tj;
	}

	Sleep(100);
}

void actualizar(int tiempo)
{
	if (tiempo == 0)
	{
		procesados[ultimo++] = porprocesar[0];
		porprocesar[0] = porprocesar[1];
		porprocesar[1] = porprocesar[2];
		porprocesar[2] = porprocesar[3];
		porprocesar[3] = porprocesar[4];
		porprocesar[4] = porprocesar[5];
		porprocesar[5] = porprocesar[6];
		porprocesar[6] = porprocesar[7];
		porprocesar[7] = porprocesar[8];
		porprocesar[8] = porprocesar[9];
		porprocesar[9] = ' ';
		sobran--;
	}
	else
	{
		char tmp = porprocesar[0];
		porprocesar[0] = porprocesar[1];
		porprocesar[1] = porprocesar[2];
		porprocesar[2] = porprocesar[3];
		porprocesar[3] = porprocesar[4];
		porprocesar[4] = porprocesar[5];
		porprocesar[5] = porprocesar[6];
		porprocesar[6] = porprocesar[7];
		porprocesar[7] = porprocesar[8];
		porprocesar[8] = porprocesar[9];
		porprocesar[9] = ' ';
		porprocesar[sobran] = tmp;
	}
	gotoxy(31, 5); printf("บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ", procesados[0], procesados[1], procesados[2], procesados[3], procesados[4], procesados[5], procesados[6], procesados[7], procesados[8], procesados[9]);
	gotoxy(31, 12); printf("บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ %c บ", porprocesar[0], porprocesar[1], porprocesar[2], porprocesar[3], porprocesar[4], porprocesar[5], porprocesar[6], porprocesar[7], porprocesar[8], porprocesar[9]);
}
void procesara()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("A");
		gotoxy(20, 8);
		printf("Tiempo restante de A"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", ta); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (ta > 0 && cuantum > 0)
			ta--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(ta);
}

void procesarb()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("B");
		gotoxy(20, 8);
		printf("Tiempo restante de B"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", tb); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (tb > 0 && cuantum > 0)
			tb--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(tb);
}

void procesarc()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("C");
		gotoxy(20, 8);
		printf("Tiempo restante de C"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", tc); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (tc > 0 && cuantum > 0)
			tc--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(tc);
}

void procesard()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("D");
		gotoxy(20, 8);
		printf("Tiempo restante de D"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", td); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (td > 0 && cuantum > 0)
			td--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(td);
}

void procesare()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("E");
		gotoxy(20, 8);
		printf("Tiempo restante de E"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", te); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (te > 0 && cuantum > 0)
			te--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(te);
}

void procesarf()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("F");
		gotoxy(20, 8);
		printf("Tiempo restante de F"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", tf); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (tf > 0 && cuantum > 0)
			tf--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(tf);
}

void procesarg()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("G");
		gotoxy(20, 8);
		printf("Tiempo restante de G"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", tg); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (tg > 0 && cuantum > 0)
			tg--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(tg);
}

void procesarh()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("H");
		gotoxy(20, 8);
		printf("Tiempo restante de H"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", th); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (th > 0 && cuantum > 0)
			th--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(th);
}

void procesari()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("I");
		gotoxy(20, 8);
		printf("Tiempo restante de I"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", ti); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (ti > 0 && cuantum > 0)
			ti--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(ti);
}

void procesarj()
{
	color(4);
	do
	{
		gotoxy(50, 9); printf("J");
		gotoxy(20, 8);
		printf("Tiempo restante de J"); gotoxy(40, 9);
		printf(""); gotoxy(40, 10);
		printf("%d  ", tj); gotoxy(60, 8);
		printf("Tiempo restante de cuantum"); gotoxy(60, 9);
		printf(""); gotoxy(60, 10);
		printf("%d  ", cuantum);
		if (tj > 0 && cuantum > 0)
			tj--;
		cuantum--;
		Sleep(1000);
	} while (cuantum >= 0);
	cuantum = 2;
	actualizar(tj);
}
void dibuja()
{
	color(2);
	gotoxy(42, 3); printf("   PROCESADOS    ");
	gotoxy(31, 4); printf("ษอออหอออหอออหอออหอออหอออหอออหอออหอออหอออป");
	gotoxy(31, 5); printf("บ   บ   บ   บ   บ   บ   บ   บ   บ   บ ");
	gotoxy(31, 6); printf("ศอออสอออสอออสอออหอออหอออหอออหอออหอออหอออผ");
	gotoxy(42, 7); printf("    ษอออออออป    ");
	gotoxy(42, 8); printf("    บ C P U บ    ");
	gotoxy(42, 9); printf("    บ       บ    ");
	gotoxy(42, 10); printf("    ศอออออออผ    ");
	gotoxy(31, 11); printf("ษอออหอออหอออหอออหอออหอออหอออหอออหอออหอออป");
	gotoxy(31, 12); printf("บ A บ B บ C บ D บ E บ F บ G บ H บ I บ J");
	gotoxy(31, 13); printf("ศอออสอออสอออสอออหอออหอออหอออหอออหอออหอออผ");
	gotoxy(42, 14); printf("   POR PROCESAR  ");
}

//modulo Round Robin

void planificacionRoundRobin() {
	system("cls");
	gotoxy(40, 4); cout << " Cargando Procesos... espere..!";
	ta = 4;
	gotoxy(38, 6); cout << ("[===---------------------------]"); Sleep(200);
	tb = 3;
	gotoxy(38, 6); cout << ("[======-------------------------]"); Sleep(200);
	tc = 10;
	gotoxy(38, 6); cout << ("[=========----------------------]"); Sleep(200);
	td = 8;
	gotoxy(38, 6); cout << ("[============-------------------]"); Sleep(200);
	te = 6;
	gotoxy(38, 6); cout << ("[===============----------------]"); Sleep(200);
	tf = 1;
	gotoxy(38, 6); cout << ("[==================-------------]"); Sleep(200);
	tg = 7;
	gotoxy(38, 6); cout << ("[=====================----------]"); Sleep(200);
	th = 9;
	gotoxy(38, 6); cout << ("[========================-------]"); Sleep(200);
	ti = 2;
	gotoxy(38, 6); cout << ("[===========================----]"); Sleep(200);
	tj = 1;
	gotoxy(38, 6); cout << ("[===============================]"); Sleep(200);
	Sleep(200);
	Sleep(1000);
	system("cls");
	dibuja();
	procesosIni();
	do
	{
		if (ta > 0)
			procesara();
		procesosIni();
		if (tb > 0)
			procesarb();
		procesosIni();
		if (tc > 0)
			procesarc();
		procesosIni();
		if (td > 0)
			procesard();
		procesosIni();
		if (te > 0)
			procesare();
		procesosIni();
		if (tf > 0)
			procesarf();
		procesosIni();
		if (tg > 0)
			procesarg();
		procesosIni();
		if (th > 0)
			procesarh();
		procesosIni();
		if (ti > 0)
			procesari();
		procesosIni();
		if (tj > 0)
			procesarj();
		procesosIni();

	} while (ta > 0 || tb > 0 || tc > 0 || td > 0 || te > 0 || tf > 0 || tg > 0 || th > 0 || ti > 0 || tj > 0);
	procesosIni();
	procesosFin();
	pausar();
}





//----------------------------------------------------

void modificarProceso() { // funcion que dibuja una tabla con los procesos en ejecucion y con los datos de la cabecera...
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	bool repetirdetalle = true;
	char busquedaproceso[15];
	int c = 2;
	int idproceso = 1;
	cout << "[Ingrese proceso]=> ";
	cin.getline(busquedaproceso, 15);
	do
	{
		switch (idproceso)
		{
		case 1: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infosystem();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;

		case 2: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoswinlong();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 3: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infowininit();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 4: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infocsrss();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 5: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infossmss();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 6: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoShellhost();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 7: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoexplorer();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;
			}; break;
		case 8: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infodllhost();
				despliegueproceso(idp);
				modificacionestado(idp);
				cout << endl;
				
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 9: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infolsass();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			};  break;
		case 10: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoservices();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			};  break;
		case 11: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				cout << "El proceso no Existe" << endl;
				repetirdetalle = false;
			}; break;

		}

	} while (repetirdetalle);

}


// funcion que opera los modulos del programa.....conforme comandos......

void modulos()
{
	bool repetirmodulos = true; // variable que valida el bucle do-while......
	int idbfor = 0;
	char comandomodulo[15]; // variable que almacena los caracteres ingresados....(comando-palabra)....
	//int mod = 0; //variable que almacena la cantidad de caracteres  ingresados ...........
	int v1, v2, v3, v4, v5,v6,v7,v8; // variable que almacena el resultado de la comparacion de comandos.....
	bool repetirprocesos=true;
	do //incio del bucle......
	{
		linea();
		//dibujo del cursor... pide el comando.......
		cin.getline(comandomodulo, 15); //....guarda los caracters ingresados...a la varible...
		int mod = (strlen(comandomodulo)); // se crea una variable, que almacena un numero de caracteres ingresados....como comando....
		switch (mod) //condicinal que se ejecuta conforme la cantidad de caracteres ingresados......
		{
		case 1:		v1 = strcmp(comandomodulo, "h"); // modulo de ayuda:: muestra los comandos establecidos  se ejecuta con 'h'
			if (v1 == 0) //comprueba que el caracter se correcto......
			{
				help(); // ejecuta la funcion de modulo de informacion o ayuda....
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl; // mensaje de error... caracter invalido...
			};  break;
		case 2:		v2 = strcmp(comandomodulo, "rr"); // funcio que limpia la pantalla....
			if (v2 == 0)
			{
			 planificacionRoundRobin();
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;
		case 3:		v8 = strcmp(comandomodulo, "cls"); // funcio que limpia la pantalla....
			if (v8 == 0)
			{
				system("cls");
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;

		case 5:		v3 = strcmp(comandomodulo, "salir");// funcio  que cierra la aplicacion......
			if (v3 == 0)
			{
				repetirmodulos = false;
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			};  break;
		case 7:		v4 = strcmp(comandomodulo, "detalle");// modulo de procesos.....
			if (v4 == 0) {

				cout << "En desarrollo";
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 8:		v4 = strcmp(comandomodulo, "procesos");// modulo de procesos.....
			if (v4 == 0) {
				system("cls");
				mostrarProcesos();
				for (int f = 0; f < 4; f++)
				{
					actualizarEstados();
					actualizarProcesos();
					Sleep(300);
				}
				cout << "  --- Todos los procesos han finalizado...!!"; fechahora();
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 9:		v5 = strcmp(comandomodulo, "modificar");// modulo modificar.....
			if (v5 == 0)
			{
				modificarProceso();
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;
		case 10: v6 = strcmp(comandomodulo, "actualizar");// modulo actualizar.....
			if (v6 == 0) {
				
				cout << "modulo en desarrollo.......!! ";
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 11:     v7 = strcmp(comandomodulo, "restablecer");// modulo de detalles......
			if (v7 == 0)
			{
				cargarprocesosauto();
				cout << endl;
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;

		}

	} while (repetirmodulos);


}

//funcion que maneja la estructura principal del programa...........iniciliaza y reliza iteraciones......

void estructuraprincipal() {
	char tab = '\t';
	bool repetirproceso = true; //valida bucle do -while
	char comandoincio[15]; //almacena los caracters ingresados.......
	int comandingresado = 1; // valor de validacion....comand1
	int comandosalida = 1; // valor de validadion _comand2
	do
	{
		system("cls"); //limpia pantalla-.....
		system("color 03"); //establece color de letra......
		logoinicio();
		cout << tab << tab << ".................[B -I - E - N - V - E - N - I - D - O ]................." << endl;
		cout << tab << tab << "--------Inserte comando de incio.... /o [salir]:cerrar aplicacion--------" << endl; //mensaje de inicio.....
		cout << endl;
		linea(); //pide comando.......
		cin.getline(comandoincio, 15);//guarda el comando ingresado.....
		comandosalida = strcmp(comandoincio, "salir"); // compara los caracteres ingresado...
		comandingresado = strcmp(comandoincio, "pcb");// compara los caracteres ingresado...

		if (comandosalida == 0) // valida comando de cierre de procesos.....
		{
			repetirproceso = false; // rompe ciclo bucle...
			cout << "  salio del programa...!!" << endl; // mensaje de cierre de programa.....
			pausar();
		}
		if (comandingresado == 0) // valida ingreso a la estructura principal del programa......
		{

			cargarprocesos(); //incia carga de procesoos.... llama a la funcio cargar procesos...
			Sleep(500); // tiempo para ejecutar programa principal.....
			system("color f"); // establece color de texto del programa principal...
			system("cls"); //limpia la consola.....
			help(); //llama al menu principal desde auxiliardibujos-auxiliar hdeder
			modulos();//invoca a la funcion modulos....modulos del programa......
			repetirproceso = false; // rompe el bucle  do -while....
			cout << "Salio del programa administrador v1-2020" << endl;//confirmaciondel cierre del programa.......
		}

	} while (repetirproceso);

}

//funcion principal de la aplicacion.........
int main()
{
	estructuraprincipal(); //invoca a la estructura principal de la aplicacion......
}

