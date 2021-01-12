#pragma once

#include "Assasin.h"
#include "Protagonista.h"

ref class Assasins{
private:
	array<Assasin^>^ assasins;
	Int16 cant;
public:
	Assasins(){
		assasins = nullptr;
		cant = 0;
	}
	~Assasins(){
		for (Int16 i = 0; i < cant; i++)
			delete assasins[i];
		delete[] assasins;
	}
	Void Agregar(Int16 _x, Int16 _y){
		array<Assasin^>^ aux = gcnew array<Assasin^>(cant + 1);

		for (Int16 i = 0; i < cant; i++)
			aux[i] = assasins[i];

		aux[cant] = gcnew Assasin(_x, _y);

		delete[] assasins;
		assasins = aux;
		cant++;
	}
	Void Eliminar(Int16 pos){
		array<Assasin^>^ aux = gcnew array<Assasin^>(cant - 1);

		for (Int16 i = 0; i < pos; i++)
			aux[i] = assasins[i];

		delete assasins[pos];

		for (Int16 i = pos; i < cant - 1; i++)
			aux[i] = assasins[i + 1];

		delete[] assasins;
		assasins = aux;
		cant--;

	}
	Int16 Size() { return cant; }
	array<Assasin^>^ Get() { return assasins; }
	Void Movimiento(Graphics^ g, Muros^ m){
		for (Int16 i = 0; i < cant; i++) {
			assasins[i]->Mover(m);
			assasins[i]->Graficar(g);
		}
	}
	Void Disparos(Graphics^ g, Int16 _x, Int16 _y, Muros^ m) {
		for (Int16 i = 0; i < cant; i++) {
			assasins[i]->Disparar(_x, _y);
			assasins[i]->GetFlechas()->Movimiento(g);
		}
	}
};