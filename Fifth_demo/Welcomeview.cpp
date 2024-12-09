#include "Welcomeview.h"

Welcomeview::Welcomeview(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WelcomeviewClass())
{
	ui->setupUi(this);
	connect(ui->Btn_Department, &QPushButton::clicked, this, &Welcomeview::do_Btn_Department_Clicked);
	connect(ui->Btn_Doctor, &QPushButton::clicked, this, &Welcomeview::do_Btn_Doctor_Clicked);
	connect(ui->Btn_Patient, &QPushButton::clicked, this, &Welcomeview::do_Btn_Patient_Clicked);
}

Welcomeview::~Welcomeview()
{
	delete ui;
}

void Welcomeview::do_Btn_Department_Clicked()
{
	emit W_GoDepartmentView();
}

void Welcomeview::do_Btn_Doctor_Clicked()
{
	emit W_GoDeoctorView();
}

void Welcomeview::do_Btn_Patient_Clicked()
{
	emit W_GoPatientView();
}
