#pragma once

#include <QWidget>
#include "ui_LoginView.h"
#include "IDataBase.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LoginViewClass; };
QT_END_NAMESPACE

class LoginView : public QWidget
{
	Q_OBJECT

public:
	LoginView(QWidget *parent = nullptr);
	~LoginView();
private slots:
	void do_Btn_Sigin_Clicked();
signals:
	void LoginSucceed();
	void LoginaFailed();
private:
	Ui::LoginViewClass *ui;
};
