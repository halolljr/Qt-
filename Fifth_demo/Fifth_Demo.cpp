#include "Fifth_Demo.h"

Fifth_Demo::Fifth_Demo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Fifth_DemoClass())
{
    ui->setupUi(this);
	//this->setWindowFlag(Qt::FramelessWindowHint);
	connect(ui->Btn_Back, &QPushButton::clicked, this, &Fifth_Demo::do_Btn_Back_Clicked);
	connect(ui->Btn_Logout, &QPushButton::clicked, this, &Fifth_Demo::do_Btn_Logout_Clicked);
	connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, &Fifth_Demo::do_stackedWidget_CurrentChanged);
	GoToLoginView();
	IDataBase::instance();
}

Fifth_Demo::~Fifth_Demo()
{
    delete ui;
}

void Fifth_Demo::push_Widget(QWidget* widget)
{
	ui->stackedWidget->addWidget(widget);
	int count = ui->stackedWidget->count();
	ui->stackedWidget->setCurrentIndex(count - 1);
	ui->label_Title->setText(widget->windowTitle());
}

void Fifth_Demo::GoToPreviousView()
{
	int count = ui->stackedWidget->count();
	if (count > 1) {
		QWidget* widget = ui->stackedWidget->widget(count - 1);
		ui->stackedWidget->removeWidget(widget);
		delete widget;
		widget = nullptr;

		ui->stackedWidget->setCurrentIndex(count - 2);
		ui->label_Title->setText(ui->stackedWidget->currentWidget()->windowTitle());
	}

}

void Fifth_Demo::GoToLoginView()
{
	loginview_ = new LoginView(this);
	push_Widget(loginview_);

	connect(loginview_, &LoginView::LoginSucceed, this, &Fifth_Demo::GoToWelcomView);
}

void Fifth_Demo::GoToWelcomView()
{
	welcomeview_ = new Welcomeview(this);
	push_Widget(welcomeview_);
	connect(welcomeview_, &Welcomeview::W_GoDeoctorView, this, &Fifth_Demo::GoToDoctorView);
	connect(welcomeview_, &Welcomeview::W_GoDepartmentView, this, &Fifth_Demo::GoToDepartmentView);
	connect(welcomeview_, &Welcomeview::W_GoPatientView, this, &Fifth_Demo::GoToPatientView);
}

void Fifth_Demo::GoToDoctorView()
{
	doctorview_ = new DoctorView(this);
	push_Widget(doctorview_);
}

void Fifth_Demo::GoToDepartmentView()
{
	departmentview_ = new DepartmentView(this);
	push_Widget(departmentview_);
}

void Fifth_Demo::GoToPatientView()
{
	patientview_ = new PatientView(this);
	push_Widget(patientview_);
	connect(patientview_, &PatientView::P_GoPatientEditView, this, &Fifth_Demo::GoToPatientEditView);
}

void Fifth_Demo::GoToPatientEditView(int row_index)
{
	patient_edit_view_ = new Patient_Edit_View(this,row_index);
	push_Widget(patient_edit_view_);
	connect(patient_edit_view_, &Patient_Edit_View::GoToPrevious, this, &Fifth_Demo::GoToPreviousView);
}

void Fifth_Demo::do_Btn_Back_Clicked()
{
	GoToPreviousView();
}

void Fifth_Demo::do_stackedWidget_CurrentChanged(int arg1)
{
	int count = ui->stackedWidget->count();
	if (count > 1) {
		ui->Btn_Back->setEnabled(true);
	}
	else {
		ui->Btn_Back->setEnabled(false);
	}
	QString title = ui->stackedWidget->currentWidget()->windowTitle();
	if (welcomeview_) {
		if (title == welcomeview_->windowTitle()) {
			ui->Btn_Logout->setEnabled(true);
			ui->Btn_Back->setEnabled(false);
		}
		else {
			ui->Btn_Logout->setEnabled(false);
		}
	}
	else {
		ui->Btn_Back->setEnabled(false);
		ui->Btn_Logout->setEnabled(false);
	}
}

void Fifth_Demo::do_Btn_Logout_Clicked()
{
	GoToPreviousView();
}
