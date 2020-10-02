#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "CabeceraAuxiliar.h"
using namespace std;

void color(int color);

// Auxiliardibujos.cpp  es una archivo que apoya al archivo main, contine menus y funciones que utiliza el programa principal.....
void help() {// funcion que dibuja informacion acerca de los comandos del programa......
	color(2);
    char tab = '\t';
    std::cout << tab; std::cout << tab;std::cout << ("...................... C O M A N D O S   PARA   EL   M A N E J O   D E L   P C B  ..................") << std::endl;
    std::cout << tab; std::cout << ("->h           "); std::cout << ("'ayuda....listado de comandos....'");std::cout << ("| ->procesos    ");   cout << (" 'Despliega los procesos '") << endl;
    std::cout << tab; std::cout << ("->cls         "); std::cout << ("'limpia pantalla consola.........'");std::cout << ("| ->modificar   ");   cout << (" 'modifica un proceso    '") << endl;
    std::cout << tab; std::cout << ("->salir       "); std::cout << ("'Cierra la aplicaciòn............'");std::cout << ("| ->            ");   cout << (" 'en desarrollo ...      '") << endl;
	std::cout << tab; std::cout << ("->rr          "); std::cout << ("'Ejecuta el algoritmo RoundRobin'"); std::cout << ("| ->restablecer");   cout << (" 'Reinicia todos los procesos..'") << endl;
	std::cout << endl;

}

void linea() {// dibuja el cursor en la pantalla.......y solicita un comando....
    cout << endl;
    color(1);
    cout << ("[inserte-comando] ==>");
}


void pausar() { //funcion que ejecuta timpo para visualizar contenido en pantalla...
    system("pause");
}

void fechahora()//funcion que permite extraer fecha y hora del sistema de la computadora y visualiza en pantalla.......en tiempo de ejecuacion...
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "|FECHA: %d-%m-%Y | HORA %H:%M:%S |");
    auto str = oss.str();
    std::cout << str;
}

void color(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD woldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    
    switch (color)
    {
    case 1:  GetConsoleScreenBufferInfo(h, &csbiInfo);
             woldColorAttrs = csbiInfo.wAttributes;
             SetConsoleTextAttribute(h, FOREGROUND_RED); break;
    case 2: 
            GetConsoleScreenBufferInfo(h, &csbiInfo);
             woldColorAttrs = csbiInfo.wAttributes;
             SetConsoleTextAttribute(h, FOREGROUND_GREEN); break;
    case 3: GetConsoleScreenBufferInfo(h, &csbiInfo);
			woldColorAttrs = csbiInfo.wAttributes;
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY); break;
            
    case 4: GetConsoleScreenBufferInfo(h, &csbiInfo);
			woldColorAttrs = csbiInfo.wAttributes;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE); break;
	case 5:
			GetConsoleScreenBufferInfo(h, &csbiInfo);
			woldColorAttrs = csbiInfo.wAttributes;
			SetConsoleTextAttribute(h, FOREGROUND_RED); break;
		
    }
    
}



void gotoxy(int x, int y)//funcion gotoxy....para tabular las visulizacionesss..... vertical e horizontal....
{
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

void logoinicio() {
    char tab = '\t';
    std::cout << endl;
    std::cout << tab;   std::cout << ("...................................................................................................") << endl;
    std::cout << tab;   std::cout << (".   ___________       _____________======_____________============================================.") << endl;
    std::cout << tab;   std::cout << (". |            |=====|             |====|              |==========================================.") << endl;
    std::cout << tab;   std::cout << (". |             |====|    ________|=====|                |========================================.") << endl;
    std::cout << tab;   std::cout << (". |     ||==|   |====|   ||=============|    ||=====|    |========================================.") << endl;
    std::cout << tab;   std::cout << (". |     ||==|   |====|   ||=============|    ||=====|   |=========================================.") << endl;
    std::cout << tab;   std::cout << (". |             |====|   ||=============|             /===========================================.") << endl;
    std::cout << tab;   std::cout << (". |     _______|=====|   ||=============|              ===========================================.") << endl;
    std::cout << tab;   std::cout << (". |    ||============|   ||=============|    ||=====|   |=========================================.") << endl;
    std::cout << tab;   std::cout << (". |    ||============|   ||________=====|    ||=====|    |========================================.") << endl;
    std::cout << tab;   std::cout << (". |    ||============|            |=====|                |========================================.") << endl;
    std::cout << tab;   std::cout << (". |    ||============|             |====|               |===V:2.0=================================.") << endl;
    std::cout << tab;   std::cout << ("...................................................................................................") << endl;
}

void infosystem() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion System" << endl;
	cout << tab << "System maneja las tareas a nivel kernel, como los controladores de alojamiento" << endl;
	cout << tab << "para asegurarse de que el software se pueda comunicar con el hardware. " << endl << endl;
}

void infoswinlong() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion winlong" << endl;
	cout << tab << "Su primera función es cargar su perfil de usuario cuando windows inicia sesión" << endl;
	cout << tab << "Para completar sus funciones, winlogon también muestra el protector de pantalla " << endl;
	cout << tab << "y / o bloquea tu PC después de que hayas estado fuera por un tiempo. " << endl << endl;
}

void infowininit() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion wininit" << endl;
	cout << tab << "Su función más importante es actuar como un trampolín para la mayoría de las aplicaciones " << endl;
	cout << tab << "en segundo plano y los procesos que se ejecutan cuando se inicia Windows. " << endl << endl;
}

void infocsrss() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion csrss" << endl;
	cout << tab << "En los viejos tiempos, este proceso manejaba todos los elementos gráficos de Windows. " << endl;
	cout << tab << "Pero ahora, maneja algunas funciones de fondo en su lugar, Si algo se estropea y " << endl;
	cout << tab << "este proceso no se ejecuta al arrancar, verá una pantalla azul." << endl << endl;
}

void infossmss() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion smss" << endl;
	cout << tab << "Este proceso ha existido en Windows desde Windows 3.1. Cada vez que Windows se carga, " << endl;
	cout << tab << "smss primero hace algunos preparativos. Mapea tus discos y crea paginación " << endl;
	cout << tab << "de memoria virtual, por nombrar algunos. " << endl << endl;
}


void infoShellhost() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion Shellhost" << endl;
	cout << tab << "Seguramente habrá notado la nueva capa de pintura que Windows 10 ha aplicado a las grapas, como" << endl;
	cout << tab << "el reloj y el calendario. El proceso Windows Shell Experience Host maneja estos elementos," << endl;
	cout << tab << "junto con los efectos de color y transparencia del menú Inicio y la barra de tareas Windows 10. " << endl << endl;
}

void infoexplorer() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion explorer" << endl;
	cout << tab << "Maneja gran parte de la interfaz gráfica que utiliza todos los días. La finalización de Windows Explorer " << endl;
	cout << tab << "no solo cerrará ninguna ventana abierta de File Explorer, sino que también dejará inutilizable el menú " << endl;
	cout << tab << "Inicio, la barra de tareas y la bandeja del sistema." << endl << endl;
}


void infodllhost() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion dllhost" << endl;
	cout << tab << "Pertenece al sistema operativo Microsoft Windows. Este proceso ejecutable se conoce popularmente como sustituto COM, DLL " << endl;
	cout << tab << "que administra las aplicaciones. Además, trabaja para el control de los procesos en los Servicios de Internet Information " << endl;
	cout << tab << "Server (IIS), carga el tiempo de ejecución. NET y realiza otras actividades. " << endl << endl;
}

void infolsass() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion lsass" << endl;
	cout << tab << "Proceso del Servicio de autenticación de seguridad local de Microsoft, responsable de la autenticación " << endl;
	cout << tab << "de identificación de usuario y la aplicación de políticas de seguridad. " << endl << endl;
}

void infoservices() {
	char tab = '\t';
	char newline = '\n';

	cout << newline << newline;
	cout << tab << "Informacion services" << endl;
	cout << tab << "Componente clave del sistema operativo en las versiones de Windows 2000 y posteriores, " << endl;
	cout << tab << "responsable de hacer empezar y parar servicios de sistema. " << endl << endl;
}