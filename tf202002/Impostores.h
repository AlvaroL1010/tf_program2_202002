#pragma once

#include "Impostor.h"
#include "Protagonista.h"

ref class Impostores {
private:
	array<Impostor^>^ impostores;
	Int16 cant;
public:
	Impostores(){
		impostores = nullptr;
		cant = 0;
	}
	~Impostores(){
		delete[] impostores;
	}
	Void Agregar(Int16 _x, Int16 _y){
		array<Impostor^>^ aux = gcnew array<Impostor^>(cant + 1);

		for (Int16 i = 0; i < cant; i++)
			aux[i] = impostores[i];

		aux[cant] = gcnew Impostor(_x, _y);

		delete[] impostores;
		impostores = aux;
		cant++;
	}
	Void Eliminar(Int16 pos){
		array<Impostor^>^ aux = gcnew array<Impostor^>(cant - 1);

		for (Int16 i = 0; i < pos; i++)
			aux[i] = impostores[i];

		delete impostores[pos];

		for (Int16 i = pos; i < cant - 1; i++)
			aux[i] = impostores[i + 1];

		delete[] impostores;
		impostores = aux;
		cant--;
	}
	Int16 Size() { return cant; }
	array<Impostor^>^ Get() { return impostores; }
	Void Movimiento(Graphics^ g, Protagonista^ pj, Muros^ m){
		for (Int16 i = 0; i < cant; i++) {
			impostores[i]->Graficar(g);
			impostores[i]->Mover(pj->GetX(), pj->GetY(), m, pj);
		}
	}
	Void Kamikaze(Graphics^ g, Protagonista^ pj) {
		for (Int16 i = 0 ; i < cant; i++) {
			if (impostores[i]->GetExplosion()->Size() > 0) {
				impostores[i]->GetExplosion()->Movimiento(g);
				if (impostores[i]->GetExplosion()->Get()[0]->GetFila() == 3 && impostores[i]->GetExplosion()->Get()[0]->GetColumna() == 3) {
					impostores[i]->GetExplosion()->Eliminar(0);
					Eliminar(i--);
					pj->SetVida(-10);
					continue;
				}
			}
		}
	}
};
