#pragma once

#include "Corrupt.h"

ref class Corrupts {
private:
	array<Corrupt^>^ corrupts;
	Int16 cant;
public:
	Corrupts(){
		corrupts = nullptr;
		cant = 0;
	}
	~Corrupts(){
		for (Int16 i = 0; i < cant; i++)
			delete corrupts[i];
		delete[] corrupts;
	}
	Void Agregar(Int16 _x, Int16 _y) {
		array<Corrupt^>^ aux = gcnew array<Corrupt^>(cant + 1);

		for (Int16 i = 0; i < cant; i++)
			aux[i] = corrupts[i];

		aux[cant] = gcnew Corrupt(_x, _y);

		delete[] corrupts;
		corrupts = aux;
		cant++;
	}
	Void Eliminar(Int16 pos) {
		array<Corrupt^>^ aux = gcnew array<Corrupt^>(cant - 1);

		for (Int16 i = 0; i < pos; i++)
			aux[i] = corrupts[i];

		delete corrupts[pos];

		for (Int16 i = pos; i < cant - 1; i++)
			aux[i] = corrupts[i + 1];

		delete[] corrupts;
		corrupts = aux;
		cant--;

	}
	Int16 Size() { return cant; }
	array<Corrupt^>^ Get() {
		return corrupts;
	}
};
