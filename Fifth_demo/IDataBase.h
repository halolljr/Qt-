#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QUuid>
class IDataBase : public QObject
{
	Q_OBJECT

public:
	static IDataBase& instance() {
		static IDataBase instance_;
		return instance_;
	}
	IDataBase(const IDataBase&) = delete;
	IDataBase& operator=(const IDataBase&) = delete;
	~IDataBase();
	/// <summary>
	/// 查找数据库
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <returns>0 if failed；1 if succeed</returns>
	int userLogin(QString username, QString password);
public:
	/// <summary>
	/// 打开数据库连接
	/// </summary>
	void openDataBase();
	/// <summary>
	/// 初始化数据库中的Patient表
	/// </summary>
	/// <returns>bool 成功与否</returns>
	bool OpenPatientModel();

	bool searchPatient(QString filter);

	bool deleteCurrentPatient();

	bool submitPatientEdit();

	bool revertPatientEdit();

	int addNewPatient();
public:
	QSqlTableModel* tableModel_Patient;	//数据模型
	QItemSelectionModel* theSelection_Patient; //选择模型
private:
	explicit IDataBase(QObject* parent = nullptr);
	QString aFile;
	QSqlDatabase database_;
};

#endif // IDATABASE_H
