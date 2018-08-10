#pragma once


namespace framework
{
	void Init(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
}