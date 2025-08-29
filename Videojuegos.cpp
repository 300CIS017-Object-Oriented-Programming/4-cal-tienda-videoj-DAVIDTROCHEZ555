#include "Videojuegos.h"
#include <iostream>
using namespace std;

void mostrarCatalogoJuegos(const Juego juegos[], int cantidad) {
    cout << "=== Catalogo de Videojuegos ===\n";
    for (int i = 0; i < cantidad; i++) {
        cout << juegos[i].codigo << ". " << juegos[i].nombre
             << " - $" << juegos[i].precio
             << " - " << juegos[i].plataforma
             << " (" << juegos[i].categoria << ")\n";
    }
}

int leerCodigoJuego() {
    int codigo;
    cout << "Ingrese codigo del juego: ";
    cin >> codigo;
    return codigo;
}

int leerCantidadJuegos() {
    int cantidad;
    cout << "Ingrese cantidad: ";
    cin >> cantidad;
    return cantidad;
}

string obtenerNombreJuego(const Juego juegos[], int codigoJuego, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (juegos[i].codigo == codigoJuego) return juegos[i].nombre;
    return "Desconocido";
}

double obtenerPrecioJuego(const Juego juegos[], int codigoJuego, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (juegos[i].codigo == codigoJuego) return juegos[i].precio;
    return 0.0;
}

string obtenerPlataforma(const Juego juegos[], int codigoJuego, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (juegos[i].codigo == codigoJuego) return juegos[i].plataforma;
    return "";
}

string obtenerCategoria(const Juego juegos[], int codigoJuego, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (juegos[i].codigo == codigoJuego) return juegos[i].categoria;
    return "";
}

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados, int codigo, int cantidad) {
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        if (codigos[i] == codigo) {
            cantidades[i] += cantidad;
            return;
        }
    }
    if (cantidadJuegosRegistrados < MAX_CARRITO) {
        codigos[cantidadJuegosRegistrados] = codigo;
        cantidades[cantidadJuegosRegistrados] = cantidad;
        cantidadJuegosRegistrados++;
    } else {
        cout << "Carrito lleno (max " << MAX_CARRITO << " juegos)\n";
    }
}

double calcularSubtotalCarrito(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double subtotal = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        subtotal += obtenerPrecioJuego(juegos, codigos[i], MAX_JUEGOS) * cantidades[i];
    }
    return subtotal;
}

int leerTipoCliente() {
    int tipo;
    cout << "Tipo de cliente: 1.Oro 2.Plata 3.Regular: ";
    cin >> tipo;
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoCliente) {
    if (tipoCliente == 1) return DESCUENTO_ORO;
    if (tipoCliente == 2) return DESCUENTO_PLATA;
    return DESCUENTO_REGULAR;
}

double calcularDescuentosAdicionales(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double extra = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        string plataforma = obtenerPlataforma(juegos, codigos[i], MAX_JUEGOS);
        if (plataforma == "PC") {
            extra += obtenerPrecioJuego(juegos, codigos[i], MAX_JUEGOS) * cantidades[i] * 0.05; // 5% descuento en PC
        }
    }
    return extra;
}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales) {
    return subtotal - (subtotal * porcentajeDescuento) - descuentosAdicionales;
}

void mostrarResumenCompra(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento) {
    cout << "\n=== Resumen de Compra ===\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        double precio = obtenerPrecioJuego(juegos, codigos[i], MAX_JUEGOS);
        cout << obtenerNombreJuego(juegos, codigos[i], MAX_JUEGOS) << " x" << cantidades[i]
             << " = $" << precio * cantidades[i] << "\n";
        subtotal += precio * cantidades[i];
    }
    double descuentosAdicionales = calcularDescuentosAdicionales(juegos, codigos, cantidades, cantidadJuegosRegistrados);
    double total = calcularTotalFinal(subtotal, porcentajeDescuento, descuentosAdicionales);

    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento Cliente: -" << subtotal * porcentajeDescuento << "\n";
    cout << "Descuentos Extra: -" << descuentosAdicionales << "\n";
    cout << "TOTAL: $" << total << "\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    codigos[0] = 1; cantidades[0] = 2;
    codigos[1] = 5; cantidades[1] = 1;
    cantidadJuegosRegistrados = 2;
}//
// Created by David on 29/08/2025.
//