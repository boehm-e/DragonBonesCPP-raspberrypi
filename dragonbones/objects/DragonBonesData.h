﻿#ifndef __OBJECTS_DRADON_BONES_DATA_H__
#define __OBJECTS_DRADON_BONES_DATA_H__

#include "../DragonBones.h"
#include "ArmatureData.h"

NAME_SPACE_DRAGON_BONES_BEGIN
class DragonBonesData
{
public:
    String name;
    std::vector<ArmatureData *> armatureDataList;
    
public:
    DragonBonesData() {}
    DragonBonesData(const DragonBonesData &copyData)
    {
        operator=(copyData);
    }
    DragonBonesData &operator=(const DragonBonesData &copyData)
    {
        dispose();
        name = copyData.name;
        armatureDataList.reserve(copyData.armatureDataList.size());
        for (size_t i = 0, l = armatureDataList.size(); i < l; ++i)
        {
            armatureDataList.push_back(new ArmatureData());
            *(armatureDataList[i]) = *(copyData.armatureDataList[i]);
        }
        return *this;
    }
    virtual ~DragonBonesData()
    {
        dispose();
    }
    void dispose()
    {
        for (size_t i = 0, l = armatureDataList.size(); i < l; ++i)
        {
            armatureDataList[i]->dispose();
            delete armatureDataList[i];
        }
        armatureDataList.clear();
    }
    
    ArmatureData *getArmatureData(const String &armatureName) const
    {
        for (size_t i = 0, l = armatureDataList.size(); i < l; ++i)
        {
            if (armatureDataList[i]->name == armatureName)
            {
                return armatureDataList[i];
            }
        }
        return nullptr;
    }
};
NAME_SPACE_DRAGON_BONES_END
#endif  // __OBJECTS_DRADON_BONES_DATA_H__