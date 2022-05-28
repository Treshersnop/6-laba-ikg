#ifndef OGLDEV_ATB_H
#define	OGLDEV_ATB_H

#include "keys.h"
#include "math_3d.h"

#include "AntTweakBar.h"


class ATB
{
public:
    ATB();

    bool Init();

    bool KeyboardCB(OGLDEV_KEY OgldevKey);

    bool PassiveMouseCB(int x, int y);

    void RenderSceneCB();

    bool MouseCB(OGLDEV_MOUSE Button, OGLDEV_KEY_STATE State, int x, int y);

};


extern TwType TW_TYPE_OGLDEV_VECTOR3F;
extern TwType TW_TYPE_OGLDEV_ATTENUATION;

#endif
