#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <random>
#include <fstream>
#include <string>



using namespace std;



//Funcion de ataque del jugador (Marcos)
int decisionDeAtaque(int com, int life, int lifeBad, int aB, int aE, string deb, string efec, string debVi, int stats[3]) {
    switch (com) {
    case 1:
        if (efec == debVi) {
            aE * 2;
            cout << "El ataque es super Efectivo.\n";

        }
        else {

        }
        stats[0] = +aE;
        return lifeBad - aE;
        break;
    case 2:
        stats[1] = +aB;
        return lifeBad - aB;
        break;
    case 3:
        stats[2] = +5;
        return 1;

    }

}
//Funcion de ataque del villano (Marcos)
int decisionDeAtaqueVillano(int life, string deb, int aB, int aE, string efec, int num, int defense, int stats[2]) {
    switch (num) {
    case 0:
        if (efec == deb) {
            aE * 2;
            cout << "El enemigo te ha atacado con su ataque elemental, el cual es tu debilidad. Has recibido el doble de daño.\n";
        }
        else {
            cout << "El enemigo te ha atacado con su ataque elemental.\n";
        }
        stats[0] = +aE;
        return life - (aE / defense);
        break;
    case 1:
        cout << "El enemigo te ha atacado con su ataque basico. \n";
        stats[1] = +aB;
        return life - (aB / defense);
        break;

    }

}
//Funcion para determinar el ataque del villano recuperado de Chat Gpt
int random() {
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 1);
    return dist(rng);
}
//Funcion para escribir los stats del juego en un notepad (Marcos)
void stats(int player[3], int villain[2]) {
    ofstream file("stats.txt");
    file << "Stats: \n";
    file << "Jugador:                     Villanos: \n";
    file << "Ataque elemental: " << player[0] << "        Ataque elemental :" << villain[0] << "\n";
    file << "Ataque basico: " << player[1] << "        Ataque basico:" << villain[1] << "\n";
    file << "Vida curada: " << player[2] << "\n";
    file.close();

    string text;

    ifstream fileStatsText("stats.txt");

    while (getline(fileStatsText, text)) {
        cout << text;
    }

}
//(Derick)
class Villano {
public:
    string elementoVillano;
    string debilidadVillano;
    int vidaVillano;
    int ataqueBasico;
    int ataqueElemental;
};

int main() {
    //Variables del programa
    string nombre, elemento, debilidad;
    int x = 0;
    int clase;
    int confirmacion, combate;
    int vida, ataqueBasico, ataqueElemental;
    int aleatorio;
    int defensa = 1;
    int statsPlayer[3];
    int statsVillain[2];

    //primer villano 
    Villano villain1;
    villain1.elementoVillano = "Fuego";
    villain1.debilidadVillano = "Agua";
    villain1.vidaVillano = 70;
    villain1.ataqueBasico = 10;
    villain1.ataqueElemental = 16;
    //segundo Villano 
    Villano villain2;
    villain2.elementoVillano = "Tierra";
    villain2.debilidadVillano = "Viento";
    villain2.vidaVillano = 80;
    villain2.ataqueBasico = 10;
    villain2.ataqueElemental = 18;
    //tercer villano 
    Villano villain3;
    villain3.elementoVillano = "Agua";
    villain3.debilidadVillano = "Tierra";
    villain3.vidaVillano = 90;
    villain3.ataqueBasico = 10;
    villain3.ataqueElemental = 20;

    //Introduccion al juego
    cout << "Bienvenido a los Elemental Trials para comenzar tu expedicion porfavor entre su nombre de jugador: \n";
    cin >> nombre;
    cout << "Bienvenido " << nombre << " ahora debera escoger su clase.\nA continuacion se le mostraran 4 clases cada una con ventajas y desventajas: \n";
    //En este loop el usuario escoge su clase (Marcos)
    while (x < 1) {
        cout << "Escoja 1 para seleccionar Monje de Aire y ver sus habilidades\n";
        cout << "Escoja 2 para seleccionar Soldado de Fuego y ver sus habilidades\n";
        cout << "Escoja 3 para seleccionar Mago de Agua y ver sus habilidades\n";
        cout << "Escoja 4 para seleccionar Luchador de Tierra y ver sus habilidades\n";
        cin >> clase;
        switch (clase) {
        case 1:
            cout << "Monje de Aire" << endl;
            cout << "Vida = 56" << endl;
            cout << "Ataque elemental de Aire = 24 puntos de damage tipo Aire" << endl;
            cout << "Ataque elemental efectivo contra Fuego (doble de damage)" << endl;
            cout << "Eres debil contra atques tipo Agua (recibes doble de damage)" << endl;
            cout << "Ataque basico = 14 puntos de damage" << endl;
            cout << "Si desea esta clase selecione el 1. Si desea ver las otras clases selccione el 2" << endl;
            cin >> confirmacion;
            if (confirmacion == 1) {
                cout << "Excelente eleccion buena suerte en tu aventura." << endl;
                x++;
                elemento = "Aire";
                debilidad = "Agua";
                vida = 56;
                ataqueBasico = 14;
                ataqueElemental = 24;
            }
            else {
                system("cls");
            }
            break;

        case 2:
            cout << "Soldado de Fuego" << endl;
            cout << "Vida = 65" << endl;
            cout << "Ataque elemental de Fuego = 26 puntos de damage." << endl;
            cout << "Ataque elemental efectivo contra Tierra (doble de damage)" << endl;
            cout << "Eres debil contra atques tipo Aire (recibes doble de damage)" << endl;
            cout << "Ataque basico = 12 puntos de damage" << endl;
            cout << "Si desea esta clase selecione el 1. Si desea ver las otras clases seleccione el 2" << endl;
            cin >> confirmacion;
            if (confirmacion == 1) {
                cout << "Exclente eleccion buena suerte en tu aventura." << endl;
                x++;
                elemento = "Fuego";
                debilidad = "Aire";
                vida = 65;
                ataqueBasico = 12;
                ataqueElemental = 26;
            }
            else {
                system("cls");
            }
            break;

        case 3:
            cout << "Mago de Agua" << endl;
            cout << "Vida = 50" << endl;
            cout << "Ataque elemental de Agua = 30 puntos de damage." << endl;
            cout << "Ataque elemental efectivo contra Aire (doble de damage)" << endl;
            cout << "Eres debil contra atques tipo Tierra (recibes doble de damage)" << endl;
            cout << "Ataque baico = 10 puntos de damage" << endl;
            cout << "Si desea esta clase selecione el 1. Si desea ver las otras clases seleccione el 2" << endl;
            cin >> confirmacion;
            if (confirmacion == 1) {
                cout << "Exclente eleccion buena suerte en tu aventura." << endl;
                x++;
                elemento = "Agua";
                debilidad = "Tierra";
                vida = 50;
                ataqueBasico = 10;
                ataqueElemental = 30;
            }
            else {
                system("cls");
            }
            break;

        case 4:
            cout << "Luchador de Tierra" << endl;
            cout << "Vida = 70" << endl;
            cout << "Ataque elemental de Tierra = 21 puntos de damage." << endl;
            cout << "Ataque elemental efectivo contra Agua (doble de damage)" << endl;
            cout << "Eres debil contra ataques tipo Fuego (recibes doble de damage)" << endl;
            cout << "Ataque basico = 18 puntos de damage" << endl;
            cout << "Si desea esta clase selecione el 1. Si desea ver las otras clases seleccione el 2" << endl;
            cin >> confirmacion;
            if (confirmacion == 1) {
                cout << "Excelente eleccion buena suerte en tu aventura." << endl;
                x++;
                elemento = "Tierra";
                debilidad = "Fuego";
                vida = 70;
                ataqueBasico = 18;
                ataqueElemental = 21;
            }
            else {
                system("cls");
            }
            break;

        default:
            cout << "ERROR intente de nuevo" << endl;


        }
    }
    //Esta variable se define para reiniciar la vida del jugador
    const int vidaOG = vida;
    system("cls");

    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << ":Loading..\n";

    system("cls");
    //Primera Batalla(Derick)
    cout << nombre;
    cout << "  Bienvenido al primer piso de la torre \n";
    cout << "Para pasar al proximo nivel, deberas derrotar el guardian de este piso \n";
    cout << "El guardian del piso 1 es el Monarca del Fuego \n";
    cout << "Comienza la batalla!; \n";

    while (vida > 0 && villain1.vidaVillano > 0) {
        cout << "Vida del heroe:" << vida << endl;
        cout << "vida del villano:" << villain1.vidaVillano << endl;
        cout << "---------------------------------------------------------------------------------------------\n ";
        cout << "   Escoge el 1 para utilzar tu ataque elemental\n";
        cout << "   Escoge el 2 para utilzar tu ataque basico\n";
        cout << "   Escoge el 3 para utilzar tu defensa reduciendo el siguiente ataque un 50 % y curando 5 HP\n";
        cin >> combate;
        //Funciones de ataque creadas por Marcos
        if (decisionDeAtaque(combate, vida, villain1.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain1.debilidadVillano, statsPlayer) == 1) {
            vida = vida + 5;
            defensa = 2;

        }
        else {
            villain1.vidaVillano = decisionDeAtaque(combate, vida, villain1.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain1.debilidadVillano, statsPlayer);
        }

        aleatorio = random();
        vida = decisionDeAtaqueVillano(vida, debilidad, villain1.ataqueBasico, villain1.ataqueElemental, villain1.elementoVillano, aleatorio, defensa, statsVillain);
        defensa = 1;
        if (vida <= 0) {
            vida = 0;
        }
        else if (villain1.vidaVillano <= 0) {
            villain1.vidaVillano = 0;
            vida = vidaOG;
        }
        //Cambio de piso/nivel creado por Derick 
        Sleep(1000);
        system("cls");

        if (villain1.vidaVillano <= 0) {
            cout << "  El enemigo ha sido derrotado por ti \n";
            cout << "  Estas pasando a la proxima zona \n";
            vida = vidaOG;
            break;
        }

        if (vida <= 0) {
            cout << "Ha muerto \n";
            return 1;
        }
    }
    Sleep(1000);
    system("cls");
    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << ":Loading..\n";
    system("cls");

    //Segunda batalla (Derick)
    cout << "Has conquistado el primer piso \n";
    cout << "Para pasar al ultimo piso, deberas derrotar el guardian de este piso \n";
    cout << "El guardian de este piso es el Monarca de la Tierra \n";
    cout << "Comienza la batalla!; \n";
    while (vida > 0 && villain2.vidaVillano > 0) {
        cout << "Vida del heroe:" << vida << endl;
        cout << "vida del villano:" << villain2.vidaVillano << endl;
        cout << "---------------------------------------------------------------------------------------------\n ";
        cout << "   Escoge el 1 para utilzar tu ataque elemental\n";
        cout << "   Escoge el 2 para utilzar tu ataque basico\n";
        cout << "   Escoge el 3 para utilzar tu defensa reduciendo el siguiente ataque un 50 % y curando 5 HP\n";
        cin >> combate;
        if (decisionDeAtaque(combate, vida, villain2.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain2.debilidadVillano, statsPlayer) == 1) {
            vida = vida + 5;
            defensa = 2;

        }
        else {
            villain2.vidaVillano = decisionDeAtaque(combate, vida, villain2.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain2.debilidadVillano, statsPlayer);
        }

        aleatorio = random();
        vida = decisionDeAtaqueVillano(vida, debilidad, villain2.ataqueBasico, villain2.ataqueElemental, villain2.elementoVillano, aleatorio, defensa, statsVillain);
        defensa = 1;
        if (vida <= 0) {
            vida = 0;
        }
        else if (villain2.vidaVillano <= 0) {
            villain2.vidaVillano = 0;
            vida = vidaOG;
        }
        Sleep(1000);
        system("cls");
        if (villain2.vidaVillano <= 0) {
            cout << "  El enemigo ha sido derrotado por ti \n";
            cout << "  Estas pasando a la proxima zona \n";
            vida = vidaOG;
            break;
        }

        if (vida <= 0) {
            cout << "Ha muerto \n";
            return 1;
        }
    }
    Sleep(1000);
    system("cls");

    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << ":Loading..\n";
    system("cls");

    //Tercera Batalla(Derick)
    cout << "Wao! Has conquistado el segundo piso \n";
    cout << "Bienvenido al ultimo nivel \n";
    cout << "Derrotas el guardian de este piso y podras escapar de la torre \n";
    cout << "El guardian de este piso es el Monarca De La Creacion \n";
    cout << "Comienza la batalla \n";
    while (vida > 0 && villain3.vidaVillano > 0) {
        cout << "Vida del heroe:" << vida << endl;
        cout << "vida del villano:" << villain3.vidaVillano << endl;
        cout << "---------------------------------------------------------------------------------------------\n ";
        cout << "   Escoge el 1 para utilzar tu ataque elemental\n";
        cout << "   Escoge el 2 para utilzar tu ataque basico\n";
        cout << "   Escoge el 3 para utilzar tu defensa reduciendo el siguiente ataque un 50 % y curando 5 HP\n";
        cin >> combate;
        if (decisionDeAtaque(combate, vida, villain3.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain3.debilidadVillano, statsPlayer) == 1) {
            vida = vida + 5;
            defensa = 2;

        }
        else {
            villain3.vidaVillano = decisionDeAtaque(combate, vida, villain3.vidaVillano, ataqueBasico, ataqueElemental, debilidad, elemento, villain3.debilidadVillano, statsPlayer);
        }

        aleatorio = random();
        vida = decisionDeAtaqueVillano(vida, debilidad, villain3.ataqueBasico, villain3.ataqueElemental, villain3.elementoVillano, aleatorio, defensa, statsVillain);
        defensa = 1;
        if (vida <= 0) {
            vida = 0;
        }
        else if (villain3.vidaVillano <= 0) {
            villain3.vidaVillano = 0;
            vida = vidaOG;
        }
        Sleep(1000);
        system("cls");

        if (villain3.vidaVillano <= 0) {
            cout << "  El enemigo ha sido derrotado por ti \n";
            cout << "Has logrado escapar la torre \n";
            vida = vidaOG;
            break;
        }

        if (vida <= 0) {
            cout << "Ha muerto \n";
            return 1;
        }
    }

    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << "Loading..\n";
    Sleep(1000);
    cout << ":Loading..\n";
    system("cls");

    cout << "Felicidades el escapar la torre, sabiamos que lo podias hacer \n";
    cout << " ";
    //Funcion que escribe los stats
    stats(statsPlayer, statsVillain);



    return 0;
}
