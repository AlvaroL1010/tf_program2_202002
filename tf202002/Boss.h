#pragma once

#include "Objeto.h"
#include "Explosiones.h"
#include "Muros.h"

ref class Boss :public Objeto {
private:
	Explosiones^ explosiones;
	Random^ r;
	Int16 time;
	Boolean vivo;
public:
	Boss(Int16 _x, Int16 _y): Objeto(_x, _y){
		sprites = gcnew array<Bitmap^>(2);
		sprites[0] = gcnew Bitmap("Resources/Sprites/Boss/boss_hurt.png");
		sprites[1] = gcnew Bitmap("Resources/Sprites/Boss/boss_spell.png");
		anim = 1;
		ancho = sprites[1]->Width / 7;
		alto = sprites[1]->Height / 4;
		columna = 0;
		fila = 2;
		time = 0;
		vivo = true;
		explosiones = gcnew Explosiones();
		r = gcnew Random();
	}
	Void Hechizo(Muros^ muros){
		if (vivo) {
			if (++columna == 6)columna = 0;
			if (++time == 50)time = 0;
			if (time == 0) {
				for (Int16 i = 0; i < 20; i++) {
					explosiones->Agregar(r->Next(65, 735), r->Next(65, 535));
					Boolean colisionn;
					do {
						for (Int16 j = 0; j < muros->Size(); j++) {
							if (explosiones->Get()[i]->Colision(muros->Get()[j]->Margenes()) == true) {
								colisionn = true;
								explosiones->Eliminar(i);
								explosiones->Agregar(r->Next(65, 735), r->Next(65, 535));
								break;
							}
							else {
								colisionn = false;
							}
						}
					} while (colisionn == true);
				}
			}
			if (time == 49) {
				for (Int16 i = 0; i < explosiones->Size(); i++) {
					explosiones->Eliminar(i--);
					continue;
				}
			}
		}
		else {
			anim = 0;
			ancho = sprites[0]->Width / 6;
			alto = sprites[0]->Height;
			fila = 0;
			columna = 5;
		}
	}
	Explosiones^ Get() { return explosiones; }
	Boolean GetVivo() {
		return vivo;
	}
	Void SetVivo(Boolean v) {
		vivo = v;
	}
};