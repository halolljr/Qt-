#pragma once

#include <QWidget>
#include "ui_Welcomeview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeviewClass; };
QT_END_NAMESPACE

class Welcomeview : public QWidget
{
	Q_OBJECT

public:
	Welcomeview(QWidget *parent = nullptr);
	~Welcomeview();
private slots:
	void do_Btn_Department_Clicked();
	void do_Btn_Doctor_Clicked();
	void do_Btn_Patient_Clicked();
signals:
	void W_GoDepartmentView();
	void W_GoDeoctorView();
	void W_GoPatientView();
private:
	Ui::WelcomeviewClass *ui;
};
