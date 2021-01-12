#pragma once

#include "Objeto.h"

ref class Muro :public Objeto {
public:
	Muro(Int16 _x, Int16 _y, Int16 fil, Int16 col):Objeto(_x, _y) {
		sprites = gcnew array<Bitmap^>(1);
		sprites[0] = gcnew Bitmap("Resources/Assets/wall_sheet.png");
		ancho = sprites[0]->Width / 5;
		alto = sprites[0]->Height / 10;
		columna = col;
		fila = fil;
	}
};