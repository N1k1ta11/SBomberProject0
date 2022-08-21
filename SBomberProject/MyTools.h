#pragma once

#include <stdint.h>
#include <string>

namespace MyTools {

	// Палитра цветов от 0 до 15
	enum ConsoleColor
	{
		CC_Black = 0,
		CC_Blue,
		CC_Green,
		CC_Cyan,
		CC_Red,
		CC_Magenta,
		CC_Brown,
		CC_LightGray,
		CC_DarkGray,
		CC_LightBlue,
		CC_LightGreen,
		CC_LightCyan,
		CC_LightRed,
		CC_LightMagenta,
		CC_Yellow,
		CC_White
	};

	//=============================================================================================

	void ClrScr();

	void __fastcall GotoXY(double x, double y);

	uint16_t GetMaxX();

	uint16_t GetMaxY();

	void SetColor(ConsoleColor color);

	//=============================================================================================

	class Logger
	{
	public:
		virtual void OpenLogFile(const std::string& FN) = 0;
		virtual void CloseLogFile() = 0;
		virtual void WriteToLog(const std::string& str) = 0;
		virtual void WriteToLog(const std::string& str, int n) = 0;
		virtual void WriteToLog(const std::string& str, double d) = 0;
	};

	class FileLoggerSingleton : public Logger
	{
	public:
		static FileLoggerSingleton& getInstance()
		{
			static FileLoggerSingleton f;
			return f;
		}

		void __fastcall OpenLogFile(const std::string& FN) override;

		void CloseLogFile();

		void __fastcall WriteToLog(const std::string& str) override;

		void __fastcall WriteToLog(const std::string& str, int n) override;

		void __fastcall WriteToLog(const std::string& str, double d) override;

	private:
		static int num;
		FileLoggerSingleton() {};
		FileLoggerSingleton(FileLoggerSingleton& root) = delete;
		FileLoggerSingleton& operator = (const FileLoggerSingleton&) = delete;
	};

	class LoggerSingleton : public Logger
	{
	private:
		Logger& log = FileLoggerSingleton::getInstance();
		LoggerSingleton() {};
		LoggerSingleton(LoggerSingleton& root) = delete;
		LoggerSingleton& operator = (const LoggerSingleton&) = delete;
	public:

		static LoggerSingleton& getInstance()
		{
			static LoggerSingleton g;
			return g;
		}

		void OpenLogFile(const std::string& FN) override;
		void CloseLogFile() override;
		void WriteToLog(const std::string& str) override;
		void WriteToLog(const std::string& str, int n) override;
		void WriteToLog(const std::string& str, double d) override;
	};

	//=============================================================================================

};