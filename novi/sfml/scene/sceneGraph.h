#ifndef SCENE_GRAPH_IS_INCLUDED
#define SCENE_GRAPH_IS_INCLUDED



#include <SFML/Graphics.hpp>

#include <memory>
#include <list>
#include <iostream>

#include <map>
#include <stdexcept>
#include <cassert>


template <typename Resource, typename Identifier>
class ResourceHolder{
    public:
        void load(Identifier id, const std::string & file_name);
        Resource & get(Identifier id);
        Resource const & get(Identifier id) const;
    private:
        std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};



template <typename Resource, typename Identifier>
void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string & file_name)
{
    std::unique_ptr<Resource> res( new Resource() );
    if(!res->loadFromFile(file_name))
       throw std::runtime_error("Cannot load form file " + file_name);

    auto inserted = mResourceMap.insert( std::make_pair(id, std::move(res)) );
    if(!inserted.second) {
        std::cerr << "ReseourceHolder: Cannot insert into map resource loaded from " << file_name << std::endl;
        assert(false);
    }
}

template <typename Resource, typename Identifier>
Resource & ResourceHolder<Resource,Identifier>::get(Identifier id)
{
    auto res =  mResourceMap.find(id);
    assert(res != mResourceMap.end());

    return *(res->second);
}

template <typename Resource, typename Identifier>
Resource const & ResourceHolder<Resource,Identifier>::get(Identifier id) const
{
    auto res =  mResourceMap.find(id);
    assert(res != mResourceMap.end());

    return *(res->second);
}

enum class TextureID{
     Landscape, Eagle, Raptor
};

using TextureHolder = ResourceHolder<sf::Texture, TextureID>;



class SceneNode : public sf::Transformable, public sf::Drawable
{
    public:
        using Ptr = std::unique_ptr<SceneNode>;

        SceneNode():mParent(nullptr){}
        void addComponent(Ptr pnode);
        void removeComponent(std::string const & name);

        void update(sf::Time dt);
        std::string getName() const { return mName; }
        static int j;
    private:
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;
        virtual void updateCurrent(sf::Time dt){}
        void updateChildren(sf::Time dt);
        // Implementacijski detalji
    //
        std::list<Ptr> mChildren;
        std::string    mName;
        SceneNode* mParent;
};


// BackgrNode služi za crtanje background-a. On se ne miče
// niti ne centriramo njegov Sprite.
class BackgrNode : public SceneNode {
    public:
        // ...
        explicit BackgrNode(sf::Texture const & texture) : mSprite(texture) {}
        BackgrNode(sf::Texture const & texture, sf::IntRect const & rect) : mSprite(texture, rect) {}

    private:
        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
        { target.draw(mSprite, states); }

        sf::Sprite   mSprite;

};


// SpriteNode služi za crtanje aviona.
class  PlaneNode : public SceneNode{
    public:
        // ....

        void setVelocity(sf::Vector2f v) {mVelocity = v; }
        void setVelocity(float vx, float vy) { mVelocity.x = vx; mVelocity.y = vy; }
        sf::Vector2f getVelocity() const { return mVelocity; }
        enum Type{Eagle,  Raptor};
        PlaneNode(Type t, TextureHolder const & holder);
       virtual void updateCurrent(sf::Time dt){move(mVelocity * dt.asSeconds());}
    private:
        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
        { target.draw(mSprite, states); }

        // ....
        Type mType;
        sf::Sprite   mSprite;
        sf::Vector2f mVelocity;



};
TextureID aircraftTypeToTextureID(PlaneNode::Type);

class World: public sf:: NonCopyable{
public:
    World (sf::RenderWindow & window);

    void update(sf::Time const & dt);
    void draw(){ mWindow.setView(mWorldView); mWindow.draw(mSceneGraph);}
    void handlePlayerInput(sf::Keyboard::Key code);
    void handlePlayerInput(sf::Mouse::Button code, bool isPressed);

private:
    void loadTextures();
    void buildScene();

    enum Layer{ Background, Air, LayerCount };

    sf::RenderWindow & mWindow;
    sf::View mWorldView;
    SceneNode mSceneGraph;
    PlaneNode * mPlane;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    TextureHolder      mTextureHolder;
    sf::FloatRect      mWorldBounds;
    sf::Vector2f       mSpawnPosition;




};


#endif

