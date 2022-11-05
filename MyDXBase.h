#pragma once





#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include  "Common/d3dUtil.h"
#include "MyWINBase.h"
#include "Common/GameTimer.h"
#include "Common/UploadBuffer.h"
#include "Common/MathHelper.h"
#include "windowsx.h"

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")




class MyDXBase:public MyWINBase
{
public:
	MyDXBase(HINSTANCE sethInstance);


	bool InitDX();

	virtual void OnResize();

	virtual int Run();

	virtual void Update(const GameTimer& gt) = 0;
	virtual void Draw(const GameTimer& gt) = 0;

	//��ʾͳ������
	void CalculateFrameStats();

	void LogAdapters();
	void LogAdapterOutputs(IDXGIAdapter* adapter);
	void LogOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);
	//����������м��б�
	void CreateCommandObjects();
	//����������
	void CreateSwapChain();
	//������������
	void CreateRtvAndDsvDescriptorHeaps();
	//ˢ���������
	void FlushCommandQueue();

	//����msaa
	void Set4xMsaaState(bool value);

	D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView()const;

	static MyDXBase* Get();

protected:
	

		Microsoft::WRL::ComPtr<IDXGIFactory4> mdxgiFactory;
		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
		Microsoft::WRL::ComPtr<ID3D12Device> md3dDevice;

		Microsoft::WRL::ComPtr<ID3D12CommandQueue> mCommandQueue;
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> mDirectCmdListAlloc;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> mCommandList;

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mRtvHeap;
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mDsvHeap;

		static const int SwapChainBufferCount = 2;//����������
		Microsoft::WRL::ComPtr<ID3D12Resource> mSwapChainBuffer[SwapChainBufferCount]; //������Buffer
		Microsoft::WRL::ComPtr<ID3D12Resource> mDepthStencilBuffer; //���ģ��Buffer




		bool      mAppPaused = false;  // is the application paused?
		bool      mMinimized = false;  // is the application minimized?
		bool      mMaximized = false;  // is the application maximized?
		bool      mResizing = false;   // are the resize bars being dragged?
		bool      mFullscreenState = false;// fullscreen enabled

		GameTimer mTimer;

		int mCurrBackBuffer = 0;
		bool      m4xMsaaState = false;    // 4X MSAA ״̬
		UINT      m4xMsaaQuality = 0;      // 4X MSAA����
		UINT mRtvDescriptorSize = 0;
		UINT mDsvDescriptorSize = 0;
		UINT mCbvSrvUavDescriptorSize = 0;

		DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
		DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	    //Χ��
		UINT64 mCurrentFence = 0;
		Microsoft::WRL::ComPtr<ID3D12Fence> mFence;

	     //��Ļ�ӿ�
		D3D12_VIEWPORT mScreenViewport;
	    //����������Ͻ����½�����
		D3D12_RECT mScissorRect;
};






