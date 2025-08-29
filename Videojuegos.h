#ifndef VIDEOJUEGOS_H
#define VIDEOJUEGOS_H

#include <string>
using namespace std;

// Constantes
const int MAX_JUEGOS = 20;
const int MAX_CARRITO = 10;

// Categorías
const string CATEGORIAS[4] = {"Accion", "Aventura", "Deportes", "Estrategia"};

// Descuentos
const double DESCUENTO_ORO = 0.15;
const double DESCUENTO_PLATA = 0.08;
const double DESCUENTO_REGULAR = 0.0;

// Estructura básica de un juego
struct Juego {
    int codigo;
    string nombre;
    double precio;
    string plataforma;
    string categoria;
};

// Prototipos
void mostrarCatalogoJuegos(const Juego juegos[], int cantidad);
int leerCodigoJuego();
int leerCantidadJuegos();
string obtenerNombreJuego(const Juego juegos[], int codigoJuego, int cantidad);
double obtenerPrecioJuego(const Juego juegos[], int codigoJuego, int cantidad);
string obtenerPlataforma(const Juego juegos[], int codigoJuego, int cantidad);
string obtenerCategoria(const Juego juegos[], int codigoJuego, int cantidad);

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados, int codigo, int cantidad);
double calcularSubtotalCarrito(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void mostrarResumenCompra(const Juego juegos[], const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

#endif//VIDEOJUEGOS_H
// Created by David on 29/08/2025.
//

#ifndef INC_4_CAL_TIENDA_VIDEOJ_DAVIDTROCHEZ555_VIDEOJUEGOS_H
#define INC_4_CAL_TIENDA_VIDEOJ_DAVIDTROCHEZ555_VIDEOJUEGOS_H

#endif //INC_4_CAL_TIENDA_VIDEOJ_DAVIDTROCHEZ555_VIDEOJUEGOS_H