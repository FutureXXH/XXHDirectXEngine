#pragma once
#include <string>

#include "framework.h"

//windows´°¿ÚÀà
class MyWINBase
{
public:
	MyWINBase();
	


	HINSTANCE hInstance;
	HWND      mhMainWnd = nullptr; // main window handle


	static  MyWINBase* Get();


	bool InitWIN();

	virtual  LRESULT  MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


	std::wstring mMainWndCaption = L"MyDXEngine";
	int mClientWidth = 800;
	int mClientHeight = 600;


private:


};

