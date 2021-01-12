#pragma once

#include "Objeto.h"
#include "Explosiones.h"
#include "Muros.h"

ref class Impostor: public Objeto {
private:
	Explosiones^ explosion;
public:
	Impostor(Int16 _x, Int16 _y) :Objeto(_x, _y) {
		sprites = gcnew array<Bitmap^>(4);
		sprites[0] = gcnew Bitmap("Resources/Sprites/BadAlly2/badally2_walkcycle.png");
		sprites[1] = gcnew Bitmap("Resources/Sprites/BadAlly2/badally2_spell.png");
		sprites[2] = gcnew Bitmap("Resources/Sprites/BadAlly2/badally2_hurt.png");
		ancho = sprites[0]->Width / 9;
		alto = sprites[0]->Height / 4;
		explosion = gcnew Explosiones();
	}
	Void Mover(Int16 _x, Int16 _y, Muros^ m, Protagonista^ pjm) {
		if (x > _x) {
			anim = 0; fila = 1;
			if ((!this->Colision(pjm->Margenes()) && !ColisionMuros(m, 1))) {
				x -= dx;
				if (++columna > 8)columna = 0;
			}
		}
		if (x < _x) {
			anim = 0; fila = 3;
			if ((!this->Colision(pjm->Margenes()) && !ColisionMuros(m, 3))) {
				x += dx;
				if (++columna > 8)columna = 0;
			}
		}
		if (y > _y) {
			anim = 0; fila = 0;
			if ((!this->Colision(pjm->Margenes()) && !ColisionMuros(m, 0))) {
				y -= dy;
				if (++columna > 8)columna = 0;
			}
		}
		if (y < _y) {
			anim = 0; fila = 2;
			if ((!this->Colision(pjm->Margenes()) && !ColisionMuros(m, 2))) {
				y += dy;
				if (++columna > 8)columna = 0;
			}
		}
	}
	Boolean ColisionMuros(Muros^ m, Int16 v) {
		for (Int16 i = 0; i < m->Size(); i++) {
			if (v == 1) {
				if (m->Get()[i]->Colision(this->Margenes(-5, 0))) {
					return true;
				}
			}
			if (v == 3) {
				if (m->Get()[i]->Colision(this->Margenes(5, 0))) {
					return true;
				}
			}
			if (v == 0) {
				if (m->Get()[i]->Colision(this->Margenes(0, -5))) {
					return true;
				}
			}
			if (v == 2) {
				if (m->Get()[i]->Colision(this->Margenes(0, 5))) {
					return true;
				}
			}
		}
		return false;
	}
	Explosiones^ GetExplosion() { return explosion; }
};