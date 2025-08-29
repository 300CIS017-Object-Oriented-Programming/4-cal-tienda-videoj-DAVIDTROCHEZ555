#include "Videojuegos.h"
#include <iostream>
using namespace std;

int main() {
    Juego juegos[MAX_JUEGOS] = {
        {1, "Call of Duty", 60, "PS5", "Accion"},
        {2, "Halo", 55, "Xbox", "Accion"},
        {3, "Doom", 40, "PC", "Accion"},
        {4, "Zelda", 70, "Switch", "Aventura"},
        {5, "Uncharted", 50, "PS5", "Aventura"},
        {6, "Tomb Raider", 45, "PC", "Aventura"},
        {7, "FIFA 25", 65, "PS5", "Deportes"},
        {8, "NBA 2K25", 60, "Xbox", "Deportes"},
        {9, "PES 25", 40, "PC", "Deportes"},
        {10, "Civilization VI", 50, "PC", "Estrategia"},
        {11, "Age of Empires", 45, "PC", "Estrategia"},
        {12, "Starcraft", 55, "PC", "Estrategia"}
    };

    int codigos[MAX_CARRITO];
    int cantidades[MAX_CARRITO];
    int cantidadJuegosRegistrados = 0;

    int opcion;
    do {
        cout << "\n=== MENU VIDEOJUEGOS ===\n";
        cout << "1. Ver catalogo\n";
        cout << "2. Agregar juego al carrito\n";
        cout << "3. Ver resumen de compra\n";
        cout << "4. Cargar compra demo\n";
        cout << "5. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarCatalogoJuegos(juegos, 12);
                break;
            case 2: {
                int codigo = leerCodigoJuego();
                int cantidad = leerCantidadJuegos();
                agregarJuegoAlCarrito(codigos, cantidades, cantidadJuegosRegistrados, codigo, cantidad);
                break;
            }
            case 3: {
                int tipo = leerTipoCliente();
                double porcDesc = obtenerPorcentajeDescuento(tipo);
                mostrarResumenCompra(juegos, codigos, cantidades, cantidadJuegosRegistrados, porcDesc);
                break;
            }
            case 4:
                cargarCompraDemo(codigos, cantidades, cantidadJuegosRegistrados);
                cout << "Compra demo cargada.\n";
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 5);

    return 0;
}