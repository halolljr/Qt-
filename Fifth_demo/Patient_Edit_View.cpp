#include "Patient_Edit_View.h"

Patient_Edit_View::Patient_Edit_View(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Patient_Edit_ViewClass())
{
	ui->setupUi(this);
}

Patient_Edit_View::~Patient_Edit_View()
{
	delete ui;
}

