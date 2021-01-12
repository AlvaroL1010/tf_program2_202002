#pragma once

#include "Objeto.h"
#include "Flechas.h"
#include "Muros.h"
#include "Assasins.h"
#include "Corrupts.h"

ref class Protagonista :public Objeto{
	Int16 puntos;
	Flechas^ flechas;
	Boolean vivo;
public:
	Protagonista(Int16 _x, Int16 _y):Objeto(_x, _y){
		puntos = 0;
		vida = 100;
		vivo = true;
		sprites = gcnew array<Bitmap^>(4);
		sprites[0] = gcnew Bitmap("Resources/Sprites/PJ/pj_walkcycle.png");
		sprites[1] = gcnew Bitmap("Resources/Sprites/PJ/pj_bow.png");
		sprites[3] = gcnew Bitmap("Resources/Sprites/PJ/pj_hurt.png");
		ancho = sprites[0]->Width / 9;
		alto = sprites[0]->Height / 4;
		flechas = gcnew Flechas();
	}
	Void Mover(KeyEventArgs^ e, Muros^ m){
		if (vivo) {
			if (e->KeyCode == Keys::Down && !ColisionMuros(e, m)) { dy = 5; anim = 0; fila = 2; y += dy; if (++columna > 8)columna = 0; }
			if (e->KeyCode == Keys::Up && !ColisionMuros(e, m)) { dy = 5; anim = 0; fila = 0; y -= dy; if (++columna > 8)columna = 0; }
			if (e->KeyCode == Keys::Right && !ColisionMuros(e, m)) { dx = 5; anim = 0; fila = 3; x += dx; if (++columna > 8)columna = 0; }
			if (e->KeyCode == Keys::Left && !ColisionMuros(e, m)) { dx = 5; anim = 0; fila = 1; x -= dx; if (++columna > 8)columna = 0; }
			if (e->KeyCode == Keys::Z) { Disparar(); }
		}
		else {
			anim = 3;
			ancho = sprites[3]->Width / 7;
			alto = sprites[3]->Height;
			fila = 0;
			columna = 6;
		}
	}
	Void LineaVida(Graphics^ lienzo) {
		if (vida > 100)vida = 100;
		if (vida < 0)vida = 0;
		lienzo->FillRectangle(Brushes::Red, Rectangle(55, 27, vida*1.5, 16));
		lienzo->DrawString(Convert::ToString(vida), gcnew System::Drawing::Font("Arial", 12), Brushes::White, 80, 26);
	}
	Void SetVida(Int16 v) {
		vida += v;
	}
	Int16 GetVida() {
		return vida;
	}
	Boolean ColisionMuros(KeyEventArgs^ e, Muros^ m) {
		for (Int16 i = 0; i < m->Size(); i++) {
			if (e->KeyCode == Keys::Down) {
				if (m->Get()[i]->Colision(this->Margenes(0, 5))) {
					return true;
				}
			}
			if (e->KeyCode == Keys::Up) {
				if (m->Get()[i]->Colision(this->Margenes(0, -5))) {
					return true;
				}
			}
			if (e->KeyCode == Keys::Right) {
				if (m->Get()[i]->Colision(this->Margenes(5, 0))) {
					return true;
				}
			}
			if (e->KeyCode == Keys::Left) {
				if (m->Get()[i]->Colision(this->Margenes(-5, 0))) {
					return true;
				}
			}
		}
		return false;
	}
	Void Disparar(){
		flechas->Agregar(x + ancho / 2, y + alto / 2, fila);
	}
	Void Morir(Graphics^ g){
		vivo = false;
		anim = 3;
		ancho = sprites[3]->Width / 6;
		alto = sprites[3]->Height;
		dx = 0;
		dy = 0;
		fila = 0;
		columna = 0;
		if (++columna >= 5)columna = 5;
	}
	Flechas^ GetFlechas() {
		return flechas;
	}
	Boolean GetVivo() {
		return vivo;
	}
	Void SetVivo(Boolean v) {
		vivo = v;
	}
};