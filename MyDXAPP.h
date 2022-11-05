#pragma once
#include "MyDXBase.h"



using Microsoft::WRL::ComPtr;
using namespace std;
using namespace DirectX;

struct Vertex 
{
	XMFLOAT3 pos;
	XMFLOAT4 Color;
};

struct  RenderObject
{
	XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4();
};

class MyDXAPP:public MyDXBase
{
public:
	MyDXAPP(HINSTANCE hInstance) :MyDXBase(hInstance)
	{

	}

	virtual bool Init() ;
	virtual  LRESULT  MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) override;
private:


	virtual void OnResize() override;
	virtual void Update(const GameTimer& gt) override;
	virtual void Draw(const GameTimer& gt) override;


	virtual void OnMouseDown(WPARAM btnState, int x, int y);
	virtual void OnMouseUp(WPARAM btnState, int x, int y);
	virtual void OnMouseMove(WPARAM btnState, int x, int y);

	//创建存放常量缓冲区描述符推
	void BuildDescriptorHeaps();
	//创建常量缓冲区
	void BuildConstantBuffers();
	//创建根签名
	void BuildRootSignature();
	//编译shader
	void BuildShadersAndInputLayout();

	void BuildBoxGeometry();
	//创建PSO(管线状态对象)
	void BuildPSO();


	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;
	ComPtr<ID3D12DescriptorHeap> mCbvHeap = nullptr;

	std::unique_ptr<UploadBuffer<RenderObject>> mObjectCB = nullptr;

	std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;

	ComPtr<ID3DBlob> mvsByteCode = nullptr;
	ComPtr<ID3DBlob> mpsByteCode = nullptr;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	ComPtr<ID3D12PipelineState> mPSO = nullptr;

	XMFLOAT4X4 mWorld = MathHelper::Identity4x4();
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f * XM_PI;
	float mPhi = XM_PIDIV4;
	float mRadius = 5.0f;

	POINT mLastMousePos;

};

