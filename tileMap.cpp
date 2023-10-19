
#include <SFML/Graphics.hpp>
#include <vector>
#include <cassert>

#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream> // DEBUGing
#define DEBUG std::cout << " DEBUG: L" << __LINE__ << " "

class TileMap : public sf::Drawable, public sf::Transformable
{

public:
    TileMap() : Drawable(),
                Transformable(),
                m_vertices(),
                m_tileset(),
                bounderyList(),
                passableTexturesID(),
                textureID()
    {
    }

    bool load(const std::string &tileset,
              sf::Vector2u tileSize,
              std::vector<int> tiles,
              unsigned int width,
              unsigned int height,
              std::vector<int> passableTilesIn)

    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Triangles);
        m_vertices.resize(width * height * 6);

        // populate the vertex array, with two triangles per tile
        for (unsigned int row = 0; row < height; row++)    // row - was j
            for (unsigned int col = 0; col < width; col++) // column - was i
            {
                // TODO find name then replace the math with the variable..
                //      int foo = row * width + col; 
                
                // get the current tile number
                int tileNumber = tiles[row * width + col];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the triangles' vertices of the current tile
                sf::Vertex *triangles = &m_vertices[(col + row * width) * 6];

                // define the 6 corners of the two triangles
                triangles[0].position = sf::Vector2f(col * tileSize.x, row * tileSize.y);
                triangles[1].position = sf::Vector2f((col + 1) * tileSize.x, row * tileSize.y);
                triangles[2].position = sf::Vector2f(col * tileSize.x, (row + 1) * tileSize.y);
                triangles[3].position = sf::Vector2f(col * tileSize.x, (row + 1) * tileSize.y);
                triangles[4].position = sf::Vector2f((col + 1) * tileSize.x, row * tileSize.y);
                triangles[5].position = sf::Vector2f((col + 1) * tileSize.x, (row + 1) * tileSize.y);

                // define the 6 matching texture coordinates
                triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

                // create a boundery for colistions
                sf::FloatRect tileBounding(col * tileSize.x, row * tileSize.y, tileSize.x, tileSize.y);
                
                assert(row * width + col == bounderyList.size());
                bounderyList.push_back(tileBounding);

                // Vectores for colistion detection
                // TODO remname to texture.....
                passableTexturesID = passableTilesIn;
                textureID = tiles;
            }

        return true;
    }

    std::vector<sf::FloatRect> GetBounderies()
    {
        return bounderyList;
    }

    std::vector<int> GetPassableTiles()
    {
        return passableTexturesID;
    }

    bool TileIsPassable(int index)
    {
        size_t length = passableTexturesID.size();

        for (size_t i = 0; i < length; i++)
        {
            if (textureID[index] == passableTexturesID[i])
            {
                return true;
            }
        }

        return false;
    }

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    std::vector<sf::FloatRect> bounderyList;
    std::vector<int> passableTexturesID;
    std::vector<int> textureID;
};

#endif