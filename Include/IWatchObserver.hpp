#pragma once
#include <iostream>

class IWatchObserver
{
public:
	virtual void onSwitchClick() = 0;
	virtual void onUpClick() = 0;
	virtual void onDownClick() = 0;
	virtual std::string onSecond() = 0;
	virtual ~IWatchObserver() = default;
};
