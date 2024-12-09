#pragma once

#include <QWidget>
#include "ui_DoctorView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DoctorViewClass; };
QT_END_NAMESPACE

class DoctorView : public QWidget
{
	Q_OBJECT

public:
	DoctorView(QWidget *parent = nullptr);
	~DoctorView();

private:
	Ui::DoctorViewClass *ui;
};
