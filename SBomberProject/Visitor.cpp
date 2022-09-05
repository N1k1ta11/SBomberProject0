#include "Visitor.h"
void LogVisitor::log(Bomb b)
{
	WriteToLog(string(__FUNCTION__) + " was invoked", b.GetSpeed());
	WriteToLog(string(__FUNCTION__) + " was invoked", b.GetxDirection());
	WriteToLog(string(__FUNCTION__) + " was invoked", b.GetyDirection());
}
void LogVisitor::log(Plane p)
{
	WriteToLog(string(__FUNCTION__) + " was invoked", p.GetSpeed());
	WriteToLog(string(__FUNCTION__) + " was invoked", p.GetxDirection());
	WriteToLog(string(__FUNCTION__) + " was invoked", p.GetyDirection());
}