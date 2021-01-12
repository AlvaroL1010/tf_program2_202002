#pragma once

#include "Juego.h"

namespace TF_202012770 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Zion
	/// </summary>
	public ref class Zion : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ espacioBuffer;
	private: System::Windows::Forms::Timer^  timer1;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::PictureBox^  pbxSalir;
	private: System::Windows::Forms::PictureBox^  pbxTutorial;
	private: System::Windows::Forms::PictureBox^  pbxJugar;
	private: System::Windows::Forms::PictureBox^  pbxZion;
	private: System::Windows::Forms::Label^  lblCredito;





			 Juego^ j;

	public:
		Zion(void)
		{
			InitializeComponent();
			g = pnlZion->CreateGraphics();
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
			j = gcnew Juego();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Zion()
		{
			if (components)
			{
				delete components;
			}
			delete buffer;
			delete espacioBuffer;  
			delete g;
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		System::Windows::Forms::Panel^  pnlZion;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Zion::typeid));
			this->pnlZion = (gcnew System::Windows::Forms::Panel());
			this->lblCredito = (gcnew System::Windows::Forms::Label());
			this->pbxZion = (gcnew System::Windows::Forms::PictureBox());
			this->pbxSalir = (gcnew System::Windows::Forms::PictureBox());
			this->pbxTutorial = (gcnew System::Windows::Forms::PictureBox());
			this->pbxJugar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlZion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxZion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSalir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxTutorial))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlZion
			// 
			this->pnlZion->Controls->Add(this->lblCredito);
			this->pnlZion->Controls->Add(this->pbxZion);
			this->pnlZion->Controls->Add(this->pbxSalir);
			this->pnlZion->Controls->Add(this->pbxTutorial);
			this->pnlZion->Controls->Add(this->pbxJugar);
			this->pnlZion->Location = System::Drawing::Point(0, 0);
			this->pnlZion->Name = L"pnlZion";
			this->pnlZion->Size = System::Drawing::Size(1024, 768);
			this->pnlZion->TabIndex = 0;
			// 
			// lblCredito
			// 
			this->lblCredito->AutoSize = true;
			this->lblCredito->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblCredito->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCredito->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblCredito->Location = System::Drawing::Point(12, 735);
			this->lblCredito->Name = L"lblCredito";
			this->lblCredito->Size = System::Drawing::Size(326, 24);
			this->lblCredito->TabIndex = 4;
			this->lblCredito->Text = L"Desarrollado por Alvaro Lamg";
			// 
			// pbxZion
			// 
			this->pbxZion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxZion.BackgroundImage")));
			this->pbxZion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbxZion->Location = System::Drawing::Point(132, 85);
			this->pbxZion->Name = L"pbxZion";
			this->pbxZion->Size = System::Drawing::Size(799, 139);
			this->pbxZion->TabIndex = 3;
			this->pbxZion->TabStop = false;
			// 
			// pbxSalir
			// 
			this->pbxSalir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxSalir.BackgroundImage")));
			this->pbxSalir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbxSalir->Location = System::Drawing::Point(322, 537);
			this->pbxSalir->Name = L"pbxSalir";
			this->pbxSalir->Size = System::Drawing::Size(419, 84);
			this->pbxSalir->TabIndex = 2;
			this->pbxSalir->TabStop = false;
			this->pbxSalir->Click += gcnew System::EventHandler(this, &Zion::pbxSalir_Click);
			// 
			// pbxTutorial
			// 
			this->pbxTutorial->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxTutorial.BackgroundImage")));
			this->pbxTutorial->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbxTutorial->Location = System::Drawing::Point(322, 437);
			this->pbxTutorial->Name = L"pbxTutorial";
			this->pbxTutorial->Size = System::Drawing::Size(419, 84);
			this->pbxTutorial->TabIndex = 1;
			this->pbxTutorial->TabStop = false;
			this->pbxTutorial->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Zion::pbxTutorial_MouseClick);
			// 
			// pbxJugar
			// 
			this->pbxJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxJugar.BackgroundImage")));
			this->pbxJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbxJugar->Location = System::Drawing::Point(322, 336);
			this->pbxJugar->Name = L"pbxJugar";
			this->pbxJugar->Size = System::Drawing::Size(419, 84);
			this->pbxJugar->TabIndex = 0;
			this->pbxJugar->TabStop = false;
			this->pbxJugar->Click += gcnew System::EventHandler(this, &Zion::pbxJugar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Zion::timer1_Tick);
			// 
			// Zion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->Controls->Add(this->pnlZion);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Zion";
			this->Text = L"Zion";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Zion::Zion_KeyDown);
			this->pnlZion->ResumeLayout(false);
			this->pnlZion->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxZion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSalir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxTutorial))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(Color::Black);
		j->Jugar(buffer->Graphics);
		buffer->Render(g);
	}
	private: System::Void Zion_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		j->MoverJugador(e);
	}
	private: System::Void pbxJugar_Click(System::Object^  sender, System::EventArgs^  e) {
		pbxJugar->Visible = false;
		pbxTutorial->Visible = false;
		pbxSalir->Visible = false;
		pbxZion->Visible = false;
		lblCredito->Visible = false;
		j->SetJugar(true);
		j->SetTime(clock());
	} 
	private: System::Void pbxSalir_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void pbxTutorial_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MessageBox::Show("Moverse: Flechas direccionales\nDisparar: Z\n\nMecanicas:\n-Los Aliados te seguiran por el mapa y te curarán.\n-Los Corrupts perseguiran a los Aliados para convertirlos en Impostores.\n-Los Impostores buscan al jugador para explotar a su lado.\n-Los Assasins te dispararan si entras en su campo de vision.");
}
};
}
