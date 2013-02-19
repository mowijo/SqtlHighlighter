#include <QtTest/QtTest>
#include "TestSuite.h"


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
	QList<QObject*> tests;

	tests << TestSuite::cases();
	
	foreach(QObject *test, tests)
	{
		if( QTest::qExec(test) > 0)
		{
            qDebug() << "\n\nFAILURE !!!\n\n";
			return 1;
		}
	}
    qDebug() << "\n\nSUCCESS!!!\n\n";
	return 0;
}
