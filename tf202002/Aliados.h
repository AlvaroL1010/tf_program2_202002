#pragma once

#include "Protagonista.h"
#include "Aliado.h"
#include "Muros.h"

ref class Aliados {
private:
	array<Aliado^>^ aliados;
	Int16 cant;
public:
	Aliados(){
		aliados = nullptr;
		cant = 0;
	}
	~Aliados(){
		for (Int16 i = 0; i < cant; i++)
			delete aliados[i];
		delete[] aliados;
	}
	Void Agregar(Int16 _x, Int16 _y){
		array<Aliado^>^ aux = gcnew array<Aliado^>(cant + 1);

		for (Int16 i = 0; i < cant; i++)
			aux[i] = aliados[i];

		aux[cant] = gcnew Aliado(_x, _y);

		delete[] aliados;
		aliados = aux;
		cant++;
	}
	Void Eliminar(Int16 pos){
		array<Aliado^>^ aux = gcnew array<Aliado^>(cant - 1);

		for (Int16 i = 0; i < pos; i++)
			aux[i] = aliados[i];

		delete aliados[pos];

		for (Int16 i = pos; i < cant - 1; i++)
			aux[i] = aliados[i + 1];

		delete[] aliados;
		aliados = aux;
		cant--;

	}
	Int16 Size() { return cant; }
	array<Aliado^>^ GetAliados(){
		return aliados;
	}
	Void Movimiento(Graphics^ g, Protagonista^ pj, Muros^ m){
		for (Int16 i = 0; i < cant; i++) {
			aliados[i]->Mover(pj->GetX(), pj->GetY(), pj->Margenes(), m);
			aliados[i]->Graficar(g);
			
		}
	}
};