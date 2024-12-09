#pragma once

#include <QtWidgets/QWidget>
#include "ui_Fifth_Demo.h"
#include <QDebug>
#include "LoginView.h"
#include "Welcomeview.h"
#include "DoctorView.h"
#include "DepartmentView.h"
#include "PatientView.h"
#include "Patient_Edit_View.h"
#include "IDataBase.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Fifth_DemoClass; };
QT_END_NAMESPACE

class Fifth_Demo : public QWidget
{
    Q_OBJECT

public:
    Fifth_Demo(QWidget *parent = nullptr);
    ~Fifth_Demo();
private:
    void push_Widget(QWidget* widget);
private slots:
    void GoToPreviousView();
    void GoToLoginView();
    void GoToWelcomView();
    void GoToDoctorView();
    void GoToDepartmentView();
    void GoToPatientView();
    void GoToPatientEditView();
    void do_Btn_Back_Clicked();
    void do_stackedWidget_CurrentChanged(int arg1);
    void do_Btn_Logout_Clicked();
private:
    Ui::Fifth_DemoClass *ui;

    Welcomeview* welcomeview_ = nullptr;
    DoctorView* doctorview_ = nullptr;
    PatientView* patientview_ = nullptr;
    DepartmentView* departmentview_ = nullptr;
    LoginView* loginview_ = nullptr;
    Patient_Edit_View* patient_edit_view_ = nullptr;

};
