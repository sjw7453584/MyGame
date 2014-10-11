#include "cocos2d.h"
USING_NS_CC;

class BasicScene: public Layer{
public:
    BasicScene(){
        
    };
    virtual ~BasicScene(){
        
    };
    virtual void onEnter() override;
    void runThisTest();
};
