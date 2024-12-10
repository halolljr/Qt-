#pragma once

#include <QWidget>
#include <QDataWidgetMapper>
#include <QtSql>
#include "IDataBase.h"
#include "ui_Patient_Edit_View.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Patient_Edit_ViewClass; };
QT_END_NAMESPACE

class Patient_Edit_View : public QWidget
{
	Q_OBJECT

public:
	Patient_Edit_View(QWidget *parent = nullptr,int row_index=0);
	~Patient_Edit_View();
private slots:
	void do_Btn_Save_Clicked();
	void do_Btn_Cancel_Clcked();
signals:
	void GoToPrevious();
private:
	Ui::Patient_Edit_ViewClass *ui;
	QDataWidgetMapper* dataMapper_Patient;	//Êý¾ÝÓ³Éä
};
