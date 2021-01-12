#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

//Clase padre
ref class Objeto {
protected:
	Int16 x, y;
	Int16 dx, dy;
	Int16 ancho, alto;
	Int16 fila, columna;
	Int16 anim;
	array<Bitmap^>^ sprites;
	Int16 vida;
public:
	Objeto(){
		anim = 0;
		fila = columna = 1;
		ancho = alto = x = y = 0;
		dx = dy = 5;
	}
	Objeto(Int16 _x, Int16 _y){
		fila = columna = 1;
		ancho = alto = x = y = 0;
		dx = dy = 5;
		x = _x;
		y = _y;
	}
	~Objeto(){}
	Int16 GetX() { return x; }
	Int16 GetY() { return y; }
	Rectangle Margenes() {
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle Margenes(Int16 _x, Int16 _y) {
		return Rectangle(x + _x, y + _y, ancho, alto);
	}
	Boolean Colision(Rectangle r2) {
		Rectangle r1 = Rectangle(x, y, ancho, alto);
		return r1.IntersectsWith(r2);
	}
	Void Graficar(Graphics^ g) {
		Rectangle aVisible(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(sprites[anim], x, y, aVisible, GraphicsUnit::Pixel);
	}
	Void SetD(Int16 v) {
		dx = v;
		dy = v;
	}
};