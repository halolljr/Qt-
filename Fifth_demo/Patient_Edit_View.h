#pragma once

#include <QWidget>
#include <QDataWidgetMapper>
#include "ui_Patient_Edit_View.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Patient_Edit_ViewClass; };
QT_END_NAMESPACE

class Patient_Edit_View : public QWidget
{
	Q_OBJECT

public:
	Patient_Edit_View(QWidget *parent = nullptr);
	~Patient_Edit_View();
private:
	Ui::Patient_Edit_ViewClass *ui;
	QDataWidgetMapper* dataMapper_Patient;	//Êý¾ÝÓ³Éä
};
