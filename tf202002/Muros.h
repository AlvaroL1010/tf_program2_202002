#pragma once

#include "Muro.h"

ref class Muros {
private:
	array<Muro^>^ muros;
	Int16 cant;
public:
	Muros() {
		muros = nullptr;
		cant = 0;
	}
	~Muros() {
		for (Int16 i = 0; i < cant; i++)
			delete muros[i];
		delete[] muros;
	}
	Void Agregar(Int16 _x, Int16 _y, Int16 fil, Int16 col) {
		array<Muro^>^ aux = gcnew array<Muro^>(cant + 1);

		for (Int16 i = 0; i < cant; i++)
			aux[i] = muros[i];

		aux[cant] = gcnew Muro(_x, _y, fil, col);

		delete[] muros;
		muros = aux;
		cant++;
	}
	Void Eliminar(Int16 pos) {
		array<Muro^>^ aux = gcnew array<Muro^>(cant - 1);

		for (Int16 i = 0; i < pos; i++)
			aux[i] = muros[i];

		delete muros[pos];

		for (Int16 i = pos; i < cant - 1; i++)
			aux[i] = muros[i + 1];

		delete[] muros;
		muros = aux;
		cant--;

	}
	Int16 Size() { return cant; }
	array<Muro^>^ Get() {
		return muros;
	}
	Void Movimiento(Graphics^ g) {
		for (Int16 i = 0; i < cant; i++) {
			muros[i]->Graficar(g);
		}
	}
};