

#ifndef __MYDX
#define __MYDX



#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"D3D12.lib")
#pragma comment(lib,"dxgi.lib")


class MyDXBase
{
public:
	MyDXBase();
	~MyDXBase();


	bool InitDX();
	void Test();
private:
	


};




#endif
