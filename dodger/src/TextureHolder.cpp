#include "TextureHolder.hpp"

TextureHolder::~TextureHolder() {
    for (auto const& entry : textures) {
	delete entry.second;
    }
}

void TextureHolder::load(const TextureId id, const std::string& path) {
    sf::Texture texture = new sf::Texture();

    if (! texture->loadFromFile(path)) {

    }
}
