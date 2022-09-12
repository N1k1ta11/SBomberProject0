#pragma once
#include <iostream>
#include "MyTools.h"
class FileLogger
{
public:
	FileLogger(const std::string& FN)
	{
		MyTools::OpenLogFile(FN);
	}

	~FileLogger()
	{
		MyTools::CloseLogFile();
	}

	void WriteToLog(const std::string& str)
	{
		MyTools::WriteToLog(str);
	}

	void WriteToLog(const std::string& str, int n)
	{
		MyTools::WriteToLog(str, n);
	}

	void WriteToLog(const std::string& str, double n)
	{
		MyTools::WriteToLog(str, n);
	}
};

