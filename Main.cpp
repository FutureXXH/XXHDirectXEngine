// MyDXEngine.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "MyDXEngine.h"

#include  "MyDXAPP.h"





int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow)
{



	try
	{
		//²âÊÔ
		MyDXAPP* MyDX = new MyDXAPP(hInstance);

		MyDX->Init();


		MyDX->Run();
	}
	catch (DxException& e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L" Failed", MB_OK);
		return 0;
	}





}





