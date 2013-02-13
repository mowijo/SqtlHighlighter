#include "TestSuite.h"
#include "TokenTest.h"
#include "TokenizerTest.h"



namespace TestSuite
{
	QList<QObject*> cases()
	{
		QList<QObject*> tests;
        tests << new TokenTest;
        tests << new TokenizerTest;
        return tests;
	}
}


