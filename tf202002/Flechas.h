#pragma once

#include "Flecha.h"

ref class Flechas {
private:
	array<Flecha^>^ flechas;
	Int16 cant;
public:
	Flechas(){
		flechas = nullptr;
		cant = 0;
	}
	~Flechas(){
		for (int i = 0; i < cant; i++)
			delete flechas[i];
		delete[] flechas;
	}
	Void Agregar(Int16 _x, Int16 _y, Int16 _anim){
		array<Flecha^>^ aux = gcnew array<Flecha^>(cant + 1);

		for (int i = 0; i < cant; i++)
			aux[i] = flechas[i];

		aux[cant] = gcnew Flecha(_x, _y, _anim);

		delete[] flechas;
		flechas = aux;
		cant++;
	}
	Void Eliminar(Int16 pos){
		array<Flecha^>^ aux = gcnew array<Flecha^>(cant - 1);

		for (int i = 0; i < pos; i++)
			aux[i] = flechas[i];

		delete flechas[pos];

		for (int i = pos; i < cant - 1; i++)
			aux[i] = flechas[i + 1];

		delete[] flechas;
		flechas = aux;
		cant--;
	}
	Int16 Size() { return cant; }
	array<Flecha^>^ Get() { return flechas; }
	Void Movimiento(Graphics^ g) {
		for (Int16 i = 0; i < cant; i++) {
			flechas[i]->Mover();
			flechas[i]->Graficar(g);

		}
	}
};