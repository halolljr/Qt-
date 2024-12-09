#include "DoctorView.h"

DoctorView::DoctorView(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DoctorViewClass())
{
	ui->setupUi(this);
}

DoctorView::~DoctorView()
{
	delete ui;
}
