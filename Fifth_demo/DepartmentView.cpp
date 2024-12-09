#include "DepartmentView.h"

DepartmentView::DepartmentView(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DepartmentViewClass())
{
	ui->setupUi(this);
}

DepartmentView::~DepartmentView()
{
	delete ui;
}
