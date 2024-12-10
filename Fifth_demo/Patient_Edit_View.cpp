#include "Patient_Edit_View.h"

Patient_Edit_View::Patient_Edit_View(QWidget *parent,int row_index)
	: QWidget(parent)
	, ui(new Ui::Patient_Edit_ViewClass())
{
	ui->setupUi(this);

	connect(ui->Btn_Save, &QPushButton::clicked, this, &Patient_Edit_View::do_Btn_Save_Clicked);
	connect(ui->Btn_Cancel, &QPushButton::clicked, this, &Patient_Edit_View::do_Btn_Cancel_Clcked);

	dataMapper_Patient = new QDataWidgetMapper();
	QSqlTableModel* tabModel = IDataBase::instance().tableModel_Patient;
	dataMapper_Patient->setModel(IDataBase::instance().tableModel_Patient);
	dataMapper_Patient->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

	dataMapper_Patient->addMapping(ui->lineEdit_ID, tabModel->fieldIndex("ID"));
	dataMapper_Patient->addMapping(ui->lineEdit_IDCard, tabModel->fieldIndex("ID_CARD"));
	dataMapper_Patient->addMapping(ui->lineEdit_Name, tabModel->fieldIndex("NAME"));
	dataMapper_Patient->addMapping(ui->doubleSpinBox_Height, tabModel->fieldIndex("HEIGHT"));
	dataMapper_Patient->addMapping(ui->doubleSpinBox_Width, tabModel->fieldIndex("WEIGHT"));
	dataMapper_Patient->addMapping(ui->lineEdit_Phone, tabModel->fieldIndex("MOBILEPHONE"));
	dataMapper_Patient->addMapping(ui->dateTimeEdit_Birth, tabModel->fieldIndex("DOB"));
	dataMapper_Patient->addMapping(ui->comboBox_Gender, tabModel->fieldIndex("SEX"));
	dataMapper_Patient->addMapping(ui->lineEdit_CreateTime, tabModel->fieldIndex("CREATEDTIMESTAMP"));
	
	dataMapper_Patient->setCurrentIndex(row_index);
}

Patient_Edit_View::~Patient_Edit_View()
{
	delete ui;
	delete dataMapper_Patient;
}

void Patient_Edit_View::do_Btn_Save_Clicked()
{
	IDataBase::instance().submitPatientEdit();
	emit GoToPrevious();
}

void Patient_Edit_View::do_Btn_Cancel_Clcked()
{
	IDataBase::instance().revertPatientEdit();
	emit GoToPrevious();
}

