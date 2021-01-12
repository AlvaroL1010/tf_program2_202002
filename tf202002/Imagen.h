#pragma once

#include "Objeto.h"

ref class Imagen : public Objeto {
public:
	Imagen(Int16 _x, Int16 _y, String^ path, Int16 cantFil):Objeto(_x, _y) {
		sprites = gcnew array<Bitmap^>(1);
		sprites[0] = gcnew Bitmap(path);
		ancho = sprites[0]->Width;
		alto = sprites[0]->Height / cantFil;
		columna = fila = 0;
	}
	Void SetFila(Int16 v) {
		fila = v;
	}
};