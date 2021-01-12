#pragma once

#include "Objeto.h"
#include "Flechas.h"
#include "Muros.h"

ref class Assasin :public Objeto {
private:
	Flechas^ flechas;
	Int16 time;
	Int16 inflijido;
	Random^ r;
public:
	Assasin(Int16 _x, Int16 _y):Objeto(_x, _y){
		sprites = gcnew array<Bitmap^>(4);
		sprites[0] = gcnew Bitmap("Resources/Sprites/Assasin/assasin_walkcycle.png");
		sprites[1] = gcnew Bitmap("Resources/Sprites/Assasin/assasin_bow.png");
		sprites[2] = gcnew Bitmap("Resources/Sprites/Assasin/assasin_spell.png");
		sprites[3] = gcnew Bitmap("Resources/Sprites/Assasin/assasin_hurt.png");
		ancho = sprites[0]->Width / 9;
		alto = sprites[0]->Height / 4;
		flechas = gcnew Flechas();
		r = gcnew Random();
		time = 0;
		dx = dy = 7;
	}
	Void Mover(Muros^ m){
		Int16 random;
		random = r->Next(0, 100);
		if (random >= 0 && random < 25) {
			anim = 0;
			fila = 0;
			if ((!ColisionMuros(m, fila))) {
				y -= dy;
				if (++columna > 8)columna = 0;
			}
		}
		if (random >= 25 && random < 50) {
			anim = 0; 
			fila = 1; 
			if ((!ColisionMuros(m, fila))) {
				x -= dx;
				if (++columna > 8)columna = 0;
			}
		}
		if (random >= 50 && random < 75) {
			anim = 0; 
			fila = 2; 
			if ((!ColisionMuros(m, fila))) {
				y += dy;
				if (++columna > 8)columna = 0;
			}
		}
		if (random >= 75 && random <=100) {
			anim = 0; 
			fila = 3; 
			if ((!ColisionMuros(m, fila))) {
				x += dx;
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
	Void Disparar(Int16 _x, Int16 _y){
		if (time == 0) {
			if (y >= _y && y< _y + alto && x < _x) {
				fila = 3;
				flechas->Agregar(x + ancho / 2, y + alto / 2, fila);
			}else
			if (y >= _y && y< _y + alto && x > _x) {
				fila = 1;
				flechas->Agregar(x + ancho / 2, y + alto / 2, fila);
			}else
			if (x >= _x && x < _x  + ancho && y < _y) {
				fila = 2;
				flechas->Agregar(x + ancho / 2, y + alto / 2, fila);
			}else
			if (x >= _x && x < _x + ancho && y > _y) {
				fila = 0;
				flechas->Agregar(x + ancho / 2, y + alto / 2, fila);
			}
		}
		if (++time == 11)time = 0;
	}
	Flechas^ GetFlechas() { return flechas; }
	Int16 GetInflijido() {
		return inflijido;
	}
	Void SetInflijido(Int16 v) {
		inflijido = v;
	}
};
