#pragma once

#include "Explosion.h"

ref class Explosiones {
private:
	array<Explosion^>^ explosiones;
	Int16 cant;
public:
	Explosiones(){
		explosiones = nullptr;
		cant = 0;
	}
	~Explosiones(){
		delete[] explosiones;
	}
	Void Agregar(Int16 _x, Int16 _y){
		array<Explosion^>^ aux = gcnew array<Explosion^>(cant + 1);

		for (int i = 0; i < cant; i++)
			aux[i] = explosiones[i];

		aux[cant] = gcnew Explosion(_x, _y);

		delete[] explosiones;
		explosiones = aux;
		cant++;
	}
	Void Eliminar(Int16 pos){
		array<Explosion^>^ aux = gcnew array<Explosion^>(cant - 1);

		for (int i = 0; i < pos; i++)
			aux[i] = explosiones[i];

		delete explosiones[pos];

		for (int i = pos; i < cant - 1; i++)
			aux[i] = explosiones[i + 1];

		delete[] explosiones;
		explosiones = aux;
		cant--;
	}
	Int16 Size() { return cant; }
	array<Explosion^>^ Get() { return explosiones; }
	Void Movimiento(Graphics^ g) {
		for (Int16 i = 0; i < cant; i++) {
			explosiones[i]->Graficar(g);
			explosiones[i]->Animacion();

		}
	}
};
