#pragma once

#include <stdio.h>
#include <stdint.h>
#include <iostream>

class Settings
{
private:
    /* Here will be the instance stored. */
    static Settings* instance;

    /* Private constructor to prevent instancing. */
    Settings();

public:
  float width = 854.0f;
  float height = 480.0f;

    static Settings* getInstance();
};
