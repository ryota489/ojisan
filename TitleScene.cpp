#include "TitleScene.h"
#include "Engine\\Input.h"
#include "Engine\\Text.h"
#include "Engine\\sceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), pText_(nullptr), pSceneManager_(nullptr)
{
}

void TitleScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();

	pSceneManager_ = dynamic_cast<SceneManager*>(GetParent());
}

void TitleScene::Update()
{
	if (Input::IsKey(DIK_P))
	{
		pSceneManager_->ChangeScene(SCENE_ID_TEST);
	}
}

void TitleScene::Draw()
{
	pText_->Draw(300, 250, "PRESS P TO START");
}

void TitleScene::Release()
{
	if (pText_)
	{
		pText_->Release();
		pText_ = nullptr;
	}
}	
