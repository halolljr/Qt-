#include "LoginView.h"

LoginView::LoginView(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::LoginViewClass())
{
	ui->setupUi(this);
	connect(ui->Btn_Sigin, &QPushButton::clicked, this, &LoginView::do_Btn_Sigin_Clicked);
}

LoginView::~LoginView()
{
	delete ui;
}

void LoginView::do_Btn_Sigin_Clicked()
{
	int status = IDataBase::instance().userLogin(ui->lineEdit_UserName->text(), ui->lineEdit_UserPassword->text());
	if (status == 1) {
		emit LoginSucceed();
	}
}
