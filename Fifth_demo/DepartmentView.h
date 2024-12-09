#pragma once

#include <QWidget>
#include "ui_DepartmentView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentViewClass; };
QT_END_NAMESPACE

class DepartmentView : public QWidget
{
	Q_OBJECT

public:
	DepartmentView(QWidget *parent = nullptr);
	~DepartmentView();

private:
	Ui::DepartmentViewClass *ui;
};
