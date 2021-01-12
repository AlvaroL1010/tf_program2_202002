#pragma once

#include "Objeto.h"

ref class Explosion: public Objeto {
private:
	System::Media::SoundPlayer^ explosionsound;
public:
	Explosion(Int16 _x, Int16 _y): Objeto(_x, _y){
		sprites = gcnew array<Bitmap^>(1);
		sprites[0] = gcnew Bitmap("Resources/Sprites/explosion.png");
		anim = 0;
		ancho = sprites[0]->Width / 4;
		alto = sprites[0]->Height / 4;
		fila = columna = 0;
		dx = dy = 0;
		explosionsound = gcnew System::Media::SoundPlayer();
		explosionsound->SoundLocation = "Resources/Effects/explosion.wav";
		explosionsound->Play();
	}
	Void Animacion(){
		if (++columna == 3) {
			if (++fila == 3 && columna == 3) {
				fila = 3;
				columna = 3;
			}
			else {
				columna = 0;
			}
		}
	}
	Int16 GetFila() { return fila; }
	Int16 GetColumna() { return columna; }
};
