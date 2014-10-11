#include "basicTest.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

void testScene_callback(Ref *sender )
{
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    scene->addChild(layer);
    // layer->release();

    Director::getInstance()->replaceScene(scene);
    
    cocostudio::ArmatureDataManager::destroyInstance();
}

void BasicScene::onEnter()
{
Layer::onEnter();

    //add the menu item for back to main menu
    TTFConfig ttfConfig("fonts/arial.ttf", 20);
    auto label = Label::createWithTTF(ttfConfig,"MainMenu");

    auto menuItem = MenuItemLabel::create(label,  testScene_callback );
    auto menu = Menu::create(menuItem, NULL);

menu->setPosition( Vec2::ZERO );
Size visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();
menuItem->setPosition( Vec2( origin.x + visibleSize.width - menuItem->getContentSize().width/2,
                                 origin.y + menuItem->getContentSize().height/2));

    addChild(menu, 1);

}
void BasicScene::runThisTest()
{
    auto scene = Scene::create();
    auto layer = new BasicScene();
    scene->addChild(layer);
    layer->release();
    Director::getInstance()->replaceScene(scene);
}

