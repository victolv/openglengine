#ifndef TEXTURE_H
#define TEXTURE_H

#include "image.h"

class texture : public image
{
public:
void load(char* file);
texture(char* file);
texture();
~texture();
};

#endif