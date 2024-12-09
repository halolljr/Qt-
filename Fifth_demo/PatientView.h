#pragma once

#include <QWidget>
#include "IDataBase.h"
#include "ui_PatientView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PatientViewClass; };
QT_END_NAMESPACE

class PatientView : public QWidget
{
	Q_OBJECT

public:
	PatientView(QWidget *parent = nullptr);
	~PatientView();
private slots:
	void do_Btn_Add_Clicked();
	void do_Btn_Search_Clicked();
	void do_Btn_Delete_Clicked();
	void do_Btn_Modify_Clicked();
signals:
	void  P_GoPatientEditView();
private:
	Ui::PatientViewClass *ui;
};
