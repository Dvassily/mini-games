#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include "TextureId.hpp"

class TextureHolder
{
private:
    std::map<TextureId, sf::Texture*> textures;
public:
    virtual ~TextureHolder();
    void load(const TextureId id, const std::string& path);
};

#endif /* TEXTUREHOLDER_H */
