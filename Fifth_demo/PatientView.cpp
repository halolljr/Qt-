#include "PatientView.h"

PatientView::PatientView(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::PatientViewClass())
{
	ui->setupUi(this);
	connect(ui->Btn_Add, &QPushButton::clicked, this, &PatientView::do_Btn_Add_Clicked);
	connect(ui->Btn_Search, &QPushButton::clicked, this, &PatientView::do_Btn_Search_Clicked);
	connect(ui->Btn_Delete, &QPushButton::clicked, this, &PatientView::do_Btn_Delete_Clicked);
	connect(ui->Btn_Modify, &QPushButton::clicked, this, &PatientView::do_Btn_Modify_Clicked);
	//һ��ѡ��һ����
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//һ��ֻ��ѡ��һ��
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	//�����Ա༭
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//��ͬ����ʾ��ͬ��ɫ
	ui->tableView->setAlternatingRowColors(true);
	if (IDataBase::instance().OpenPatientModel()) {
		ui->tableView->setModel(IDataBase::instance().tableModel_Patient);
		ui->tableView->setSelectionModel(IDataBase::instance().theSelection_Patient);
	}
}

PatientView::~PatientView()
{
	delete ui;
}

void PatientView::do_Btn_Add_Clicked()
{
	emit P_GoPatientEditView();
}

void PatientView::do_Btn_Search_Clicked()
{
	QString filter = QString("NAME like '%%1%'").arg(ui->lineEdit->text());
	IDataBase::instance().searchPatient(filter);
}

void PatientView::do_Btn_Delete_Clicked()
{
	IDataBase::instance().deleteCurrentPatient();
}

void PatientView::do_Btn_Modify_Clicked()
{

}
