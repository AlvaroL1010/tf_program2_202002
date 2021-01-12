#pragma once

#include "Imagen.h"
#include "Protagonista.h"
#include "Aliados.h"
#include "Corrupts.h"
#include "Assasins.h"
#include "Impostores.h"
#include "Boss.h"
#include "Muros.h"
#include <ctime>

//Clase controladora
ref class Juego {
private:
	Imagen^ introduccion;
	Imagen^ resultado;
	Protagonista^ pj;
	Aliados^ aliados;
	Corrupts^ corrupts;
	Assasins^ assasins;
	Impostores^ impostores;
	Boss^ boss;
	Muros^ piso;
	Muros^ muros;
	Random^ r;
	System::Media::SoundPlayer^ dungeon;
	Int16 NumAli;
	Boolean jugar;
	Boolean dificultad;
	Boolean salida;
	clock_t time;
	
public:
	Juego(){
		jugar = false;
		dificultad = false;
		salida = false;
		introduccion = gcnew Imagen(0, 0, "Resources/Assets/castle_background.png", 1);
		resultado = gcnew Imagen(350, 300, "Resources/Assets/resultado.png", 2);
		dungeon = gcnew System::Media::SoundPlayer();
		dungeon->SoundLocation = "Resources/Music/dungeon2_128_l.wav";
		dungeon->PlayLooping();
		pj = gcnew Protagonista(128, 100);
		boss = gcnew Boss(13 * 64, 10 * 64);
		aliados = gcnew Aliados();
		corrupts = gcnew Corrupts();
		assasins = gcnew Assasins();
		impostores = gcnew Impostores();
		piso = gcnew Muros();
		muros = gcnew Muros();
		r = gcnew Random();
		NumAli = r->Next(5, 10);
		
		//Creacion del Piso
		for (Int16 i = 0; i < 16; i++) {
			for (Int16 j = 0; j < 12; j++) {
				piso->Agregar(i * 64, j * 64, 5, 4);
			}
		}
		piso->Agregar(1 * 64, 1 * 64, 8, 4);
		piso->Agregar(2 * 64, 2 * 64, 8, 4);
		piso->Agregar(14 * 64, 10 * 64, 4, 4);
		//Creacion de los muros por defecto
			//Esquinas
		muros->Agregar(0, 0, 1, 0);
		muros->Agregar(15 * 64, 0, 1, 2);
		muros->Agregar(0, 11 * 64, 1, 3);
		muros->Agregar(15 * 64, 11 * 64, 1, 1);
			//Bordes
		for (Int16 i = 1; i < 15; i++) {
			muros->Agregar(i * 64, 0, 0, 2);
			muros->Agregar(i * 64, 11 * 64, 0, 3);
		}
		for (Int16 j = 1; j < 11; j++) {
			muros->Agregar(0, j * 64, 0, 0);
			muros->Agregar(15 * 64, j * 64, 0, 1);
		}
			//Interior
		muros->Agregar(0 * 64, 3 * 64, 5, 0);
		muros->Agregar(1 * 64, 3 * 64, 4, 2);
		muros->Agregar(4 * 64, 0 * 64, 0, 4);
		muros->Agregar(4 * 64, 1 * 64, 1, 4);
		muros->Agregar(4 * 64, 2 * 64, 1, 4);
		muros->Agregar(4 * 64, 3 * 64, 2, 1);
		muros->Agregar(3 * 64, 3 * 64, 4, 3);
		muros->Agregar(15 * 64, 9 * 64, 5, 3);
		muros->Agregar(14 * 64, 9 * 64, 5, 1);
		muros->Agregar(13 * 64, 9 * 64, 4, 3);
		muros->Agregar(11 * 64, 11 * 64, 3, 4);
		muros->Agregar(11 * 64, 10 * 64, 4, 0);

		//Muros aleatorios
		for (Int16 i = 1; i < 15; i++) {
			for (Int16 j = 1; j < 11; j++) {
				if (!(((i > 0 && i < 4) && (j > 0 && j < 5)) || i == 2 || i == 4 || i == 14 || j == 3 || j == 9 || j == 10 || j == 8)) {
					Int16 n = r->Next(0, 15);
					if (n == 1 || n == 14) {
						muros->Agregar(i * 64, j * 64, 4, 3);
						muros->Agregar(i * 64 + 64, j * 64, 4, 2);
					}
					if (n == 0 || n == 15) {
						muros->Agregar(i * 64, j * 64, 4, 0);
						muros->Agregar(i * 64, j * 64 + 64, 4, 1);
					}
				}
			}
		}
		for (Int16 i = 0; i < NumAli; i++) {
			aliados->Agregar(r->Next(65, 735), r->Next(65, 535));
			Boolean colisionn;
			do {
				for (Int16 j = 0; j < muros->Size(); j++) {
					if (aliados->GetAliados()[i]->Colision(muros->Get()[j]->Margenes()) == true) {
						colisionn = true;
						aliados->Eliminar(i);
						aliados->Agregar(r->Next(65, 735), r->Next(65, 535));
						break;
					}
					else {
						colisionn = false;
					}
				}
			}while (colisionn == true);
			

		}
		for (Int16 i = 0; i < NumAli * 2 / 5; i++) {
			corrupts->Agregar(r->Next(65, 735), r->Next(65, 535));
			Boolean colisionn;
			do {
				for (Int16 j = 0; j < muros->Size(); j++) {
					if (corrupts->Get()[i]->Colision(muros->Get()[j]->Margenes()) == true) {
						colisionn = true;
						corrupts->Eliminar(i);
						corrupts->Agregar(r->Next(65, 735), r->Next(65, 535));
						break;
					}
					else {
						colisionn = false;
					}
				}
			} while (colisionn == true);
		}
		for (Int16 i = 0; i < NumAli * 3 / 5; i++) {
			assasins->Agregar(r->Next(65, 735), r->Next(65, 535));
			Boolean colisionn;
			do {
				for (Int16 j = 0; j < muros->Size(); j++) {
					if (assasins->Get()[i]->Colision(muros->Get()[j]->Margenes()) == true) {
						colisionn = true;
						assasins->Eliminar(i);
						assasins->Agregar(r->Next(65, 735), r->Next(65, 535));
						break;
					}
					else {
						colisionn = false;
					}
				}
			} while (colisionn == true);
		}
	}
	~Juego(){
		delete[] assasins;
		delete[] corrupts;
		delete[] muros;
		delete[] piso;
		delete[] aliados;
	}
	Void MenuPrincipal(Graphics^ g){
		introduccion->Graficar(g);		
	}
	Void Jugar(Graphics^ g) {
		if (jugar == true) {
			//Graficar piso y muros
			piso->Movimiento(g);
			muros->Movimiento(g);
			//Funciones de Aliados
			aliados->Movimiento(g, pj, muros);
			AliadosCurar();
			//Funciones de Assasins
			assasins->Movimiento(g, muros);
			assasins->Disparos(g, pj->GetX(), pj->GetY(), muros);
			ColisionFlechasAssasins();
			//Funciones de Corrupts
			CorruptsCorromper(g);
			//Funciones de Impostors
			impostores->Movimiento(g, pj, muros);
			ImpostorExplosion(g);
			//Funciones del Protagonista
			pj->Graficar(g);
			BarraJugador(g);
			pj->GetFlechas()->Movimiento(g);
			ColisionFlechasJugador();
			//Otras funciones
			Dificultad(g);
			Resultados(g);
		}
		else {
			introduccion->Graficar(g);
		}
	}
	Void MoverJugador(KeyEventArgs^ e) { pj->Mover(e, muros); }
	Void BarraJugador(Graphics^ g) {
		pj->LineaVida(g);
		g->DrawImage(gcnew Bitmap("Resources/Assets/healthbar.png"), 0, 5);
	}
	Void AliadosCurar() {
		for (Int16 i = 0; i < aliados->Size(); i++) {
			pj->SetVida(1);
		}
	}
	Void CorruptsCorromper(Graphics^ g) {
		for (Int16 i = 0; i < corrupts->Size(); i++) {
			corrupts->Get()[i]->Graficar(g);
		}
		if (corrupts->Size() > 0 && aliados->Size() > 0) {
			for (Int16 i = 0; i < corrupts->Size(); i++) {
				if (corrupts->Size() > 0 && i >= 0 && aliados->Size() > 0) {
					corrupts->Get()[i]->Mover(aliados->GetAliados()[0]->GetX(), aliados->GetAliados()[0]->GetY(), muros);
					if (corrupts->Get()[i]->Colision(aliados->GetAliados()[0]->Margenes())) {
						impostores->Agregar(aliados->GetAliados()[0]->GetX(), aliados->GetAliados()[0]->GetY());
						aliados->Eliminar(0);
						continue;
					}
				}
				
			}
		}
		
	}
	Void ColisionFlechasAssasins() {
		for (Int16 z = 0; z < assasins->Size(); z++) {
			for (Int16 j = 0; j < muros->Size(); j++) {
				for (Int16 i = 0; i < assasins->Get()[z]->GetFlechas()->Size(); i++) {
					if (muros->Get()[j]->Colision(assasins->Get()[z]->GetFlechas()->Get()[i]->Margenes())) {
						assasins->Get()[z]->GetFlechas()->Eliminar(i--);
						continue;
					}
				}
			}
			for (Int16 j = 0; j < aliados->Size(); j++) {
				for (Int16 i = 0; i < assasins->Get()[z]->GetFlechas()->Size(); i++) {
					if (j >= 0)
						if (aliados->GetAliados()[j]->Colision(assasins->Get()[z]->GetFlechas()->Get()[i]->Margenes())) {
							assasins->Get()[z]->GetFlechas()->Eliminar(i--);
							aliados->Eliminar(j--);
							continue;
						}
				}
			}
			for (Int16 i = 0; i < assasins->Get()[z]->GetFlechas()->Size(); i++) {
				if (assasins->Get()[z]->GetFlechas()->Get()[i]->Colision(pj->Margenes())) {
					assasins->Get()[z]->GetFlechas()->Eliminar(i--);
					pj->SetVida(-5);
					continue;
				}
			}
		}
	}
	Void ColisionFlechasJugador() {
		for (Int16 j = 0; j < assasins->Size(); j++) {
			for (Int16 i = 0; i < pj->GetFlechas()->Size(); i++) {
				if (j >= 0)
				if (pj->GetFlechas()->Get()[i]->Colision(assasins->Get()[j]->Margenes())) {
					assasins->Eliminar(j--);
					pj->GetFlechas()->Eliminar(i--);
					continue;
				}
			}
		}
		for (Int16 j = 0; j < corrupts->Size(); j++) {
			for (Int16 i = 0; i < pj->GetFlechas()->Size(); i++) {
				if (j >= 0)
				if (pj->GetFlechas()->Get()[i]->Colision(corrupts->Get()[j]->Margenes())) {
					corrupts->Eliminar(j--);
					pj->GetFlechas()->Eliminar(i--);
					continue;
				}
			}
		}
		for (Int16 j = 0; j < impostores->Size(); j++) {
			for (Int16 i = 0; i < pj->GetFlechas()->Size(); i++) {
				if (j >= 0)
					if (pj->GetFlechas()->Get()[i]->Colision(impostores->Get()[j]->Margenes())) {
						impostores->Eliminar(j--);
						pj->GetFlechas()->Eliminar(i--);
						continue;
					}
			}
		}
		for (Int16 j = 0; j < muros->Size(); j++) {
			for (Int16 i = 0; i < pj->GetFlechas()->Size(); i++) {
				if (muros->Get()[j]->Colision(pj->GetFlechas()->Get()[i]->Margenes())) {
					pj->GetFlechas()->Eliminar(i);
					continue;
				}
			}
		}
		for (Int16 i = 0; i < pj->GetFlechas()->Size(); i++) {
			if (i >= 0)
				if (pj->GetFlechas()->Get()[i]->Colision(boss->Margenes())) {
					boss->SetVivo(false);
					pj->GetFlechas()->Eliminar(i--);
					continue;
				}
		}
	}
	Void ImpostorExplosion(Graphics^ g) {
		for (Int16 i = 0; i < impostores->Size(); i++) {
			if (impostores->Get()[i]->Colision(pj->Margenes())) {
				impostores->Get()[i]->GetExplosion()->Agregar(impostores->Get()[i]->GetX(), impostores->Get()[i]->GetY());
				impostores->Kamikaze(g, pj);
			}
		}
	}
	Void BossExplosiones() {
		for (Int16 i = 0; i < boss->Get()->Size(); i++) {
			if (boss->Get()->Get()[i]->Colision(pj->Margenes())) {
				pj->SetVida(-1);
			}
		}
	}
	Void Dificultad(Graphics^ g) {
		if ((clock() - time) / 1000 >= 30 && assasins->Size() > 0 && corrupts->Size() > 0) {
			if (!dificultad) {
				corrupts->Get()[0]->Mover(assasins->Get()[0]->GetX(), assasins->Get()[0]->GetY(), muros);
				if (corrupts->Get()[0]->Colision(assasins->Get()[0]->Margenes())) {
					dificultad = true;
					MessageBox::Show("Corrupt: Hay que acelerar el paso, el sujeto debe morir.\nAssasin: Entendido, el jefe esta en camino.");
				}
			}
		}
		if (dificultad) {
			boss->Graficar(g);
			boss->Hechizo(muros);
			BossExplosiones();
			boss->Get()->Movimiento(g);
		}
	}
	Void Resultados(Graphics^ g) {
		if ((assasins->Size() == 0 && corrupts->Size() == 0 && impostores->Size() == 0) || (clock() - time) / 1000 >= 120) {
			if (salida == false) {
				salida = true;
				piso->Agregar(14 * 64, 10 * 64, 6, 4);
			}
			if (pj->Colision(piso->Get()[piso->Size() - 1]->Margenes())) {
				resultado->SetFila(0);
				resultado->Graficar(g);
				pj->SetVivo(false);
				g->FillRectangle(Brushes::DarkGreen, 375, 450, 275, 75);
				g->DrawString("Desarrollado por Alvaro Lamg\nSeccion SX21\nProgramacion 2", gcnew System::Drawing::Font("Arial", 14), Brushes::LightGreen, 375, 450);
			}
		}
		if (pj->GetVida() <= 0) {
			resultado->SetFila(1);
			resultado->Graficar(g);
			pj->SetVivo(false);
			g->FillRectangle(Brushes::DarkRed, 375, 450, 275, 75);
			g->DrawString("Desarrollado por Alvaro Lamg\nSeccion SX21\nProgramacion 2", gcnew System::Drawing::Font("Arial", 14), Brushes::Red, 375, 450);
		}
	}
	Boolean GetJugar() { return jugar; }
	Void SetJugar(Boolean v) { jugar = v; }
	Void SetTime(clock_t v) { time = v; }
};
