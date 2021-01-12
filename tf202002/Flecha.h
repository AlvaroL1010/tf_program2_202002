#pragma once
#include "Objeto.h"

ref class Flecha :public Objeto {
private:
	System::Media::SoundPlayer^ shootsound;
public:
	Flecha(){}
	Flecha(Int16 _x, Int16 _y, Int16 _anim): Objeto(_x, _y){
		sprites = gcnew array<Bitmap^>(4);
		sprites[0] = gcnew Bitmap("Resources/Sprites/flechaw.png");
		sprites[1] = gcnew Bitmap("Resources/Sprites/flechaa.png");
		sprites[2] = gcnew Bitmap("Resources/Sprites/flechas.png");
		sprites[3] = gcnew Bitmap("Resources/Sprites/flechad.png");
		anim = _anim;
		ancho = sprites[anim]->Width;
		alto = sprites[anim]->Height;
		fila = columna = 0;
		dx = dy = 15;
		shootsound = gcnew System::Media::SoundPlayer();
		shootsound->SoundLocation = "Resources/Effects/bow_shot.wav";
		shootsound->Play();
	}
	Void Mover(){
		if (anim == 0) {
			y -= dy;
		}
		if (anim == 1) {
			x -= dx;
		}
		if (anim == 2) {
			y += dy;
		}
		if (anim == 3) {
			x += dx;
		}
	}
};
