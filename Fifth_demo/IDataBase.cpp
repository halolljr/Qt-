#include "IDataBase.h"
#include <QFileDialog>
#include <QMessageBox>

IDataBase::IDataBase(QObject* parent)
	: QObject(parent)
{
	openDataBase();
}
IDataBase::~IDataBase()
{
}

int IDataBase::userLogin(QString username, QString password)
{
	QSqlQuery query;
	query.prepare("select USERNAME,PASSWORD from User where username = :admin_ljr");
	query.bindValue(":admin_ljr", username);
	query.exec();
	if (query.first() && query.value("username").isValid()) {
		QString passwd = query.value("password").toString();
		if (password == passwd) {
			return 1;
		}
		else {
			QMessageBox::warning(nullptr, "错误", "密码错误", QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}
	}
	else {
		QMessageBox::warning(nullptr, "错误", "账号错误", QMessageBox::Ok, QMessageBox::NoButton);
		return 0;
	}
}

void IDataBase::openDataBase()
{
	aFile = QFileDialog::getOpenFileName(nullptr, "选择数据库文件", "", "SQL Lite数据库(*.db *.db3)");
	if (aFile.isEmpty()) {
		aFile = QFileDialog::getOpenFileName(nullptr, "选择数据库文件", "", "SQL Lite数据库(*.db *.db3)");
	}

	database_ = QSqlDatabase::addDatabase("QSQLITE");
	database_.setDatabaseName(aFile);

	if (!database_.open()) {
		QMessageBox::warning(nullptr, "错误", "打开数据库失败", QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	//qDebug() << "成功打开数据库";
}

bool IDataBase::OpenPatientModel()
{
	tableModel_Patient = new QSqlTableModel(this, database_);
	tableModel_Patient->setTable("Patient");
	tableModel_Patient->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel_Patient->setSort(tableModel_Patient->fieldIndex("NAME"), Qt::AscendingOrder);
	if (!tableModel_Patient->select()) {
		return false;
	}

	theSelection_Patient = new QItemSelectionModel(tableModel_Patient);
	return true;
}

bool IDataBase::searchPatient(QString filter)
{
	tableModel_Patient->setFilter(filter);
	return tableModel_Patient->select();
}

bool IDataBase::deleteCurrentPatient()
{
	QModelIndex curIndex = theSelection_Patient->currentIndex();
	tableModel_Patient->removeRow(curIndex.row());
	tableModel_Patient->submitAll();
	tableModel_Patient->select();
	return true;
}

bool IDataBase::submitPatientEdit()
{
	return tableModel_Patient->submitAll();
}

bool IDataBase::revertPatientEdit()
{
	tableModel_Patient->revertAll();
	return true;
}

int IDataBase::addNewPatient()
{
	tableModel_Patient->insertRow(tableModel_Patient->rowCount(), QModelIndex());
	QModelIndex curIndex = tableModel_Patient->index(tableModel_Patient->rowCount() - 1, 1);

	int curRecNo = curIndex.row();
	QSqlRecord curRec = tableModel_Patient->record(curRecNo);
	curRec.setValue("CREATEDTIMESTAMP", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
	curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));

	tableModel_Patient->setRecord(curRecNo, curRec);
	return curIndex.row();
}
