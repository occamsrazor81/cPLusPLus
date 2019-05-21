#include "sceneGraph.h"
// Implementacija

int SceneNode::j=0;

void SceneNode::addComponent(SceneNode::Ptr pnode)
{
    pnode->mParent = this;

    if(j==4) pnode->mName="PrankSinatra";
    if(j==5) pnode->mName="j";
    if(j==6) pnode->mName="k";
    if(j==7) pnode->mName="l";


     mChildren.push_back(std::move(pnode));

    ++j;
}

void SceneNode::removeComponent(const std::__cxx11::string &name)
{
    auto itt=mChildren.begin();
    int br=0;
    for(auto it=mChildren.begin();it!=mChildren.end();++it){
        if((*it)->mName==name)

        { itt=it; br=1; break;}

    }

    if(br){
        Ptr found = std::move(*itt);
        found->mParent = nullptr;
        mChildren.erase(itt);
    }




}

void SceneNode::update(sf::Time dt)

{
    updateCurrent(dt);
    updateChildren(dt);
}


void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();


        drawCurrent(target, states);

        for(auto & x : mChildren)
            x->draw(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void SceneNode::updateChildren(sf::Time dt)
{
    for(auto & x : mChildren)
           x->update(dt);
}





TextureID aircraftTypeToTextureID(PlaneNode::Type t)
{
    switch(t){
        case  PlaneNode::Eagle: return TextureID::Eagle;
        case PlaneNode::Raptor: return TextureID::Raptor;
    default:
          throw std::runtime_error("Wrong Plane::Type.");
    }
}


PlaneNode::PlaneNode(Type t, TextureHolder const & holder) : mType(t),
    mSprite(holder.get(aircraftTypeToTextureID(t)))
{
        sf::FloatRect bounds = mSprite.getLocalBounds();
        mSprite.setOrigin(bounds.width/2, bounds.height/2);
}





World::World(sf::RenderWindow &window): mWindow(window),
                                        mPlane(nullptr),
                                        mWorldView(window.getDefaultView()),
                                        mWorldBounds(0.f,0.f,mWorldView.getSize().x, mWorldView.getSize().y),
                                        mSpawnPosition(mWorldView.getSize().x/2.f,mWorldBounds.height - mWorldView.getSize().y/2)


{
    for(auto & x : mSceneLayers) x = nullptr;
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);


}

void World::update(const sf::Time &dt)
{

       mSceneGraph.update(dt);

}

void World::handlePlayerInput(sf::Keyboard::Key code)
{
    if(code==sf::Keyboard::H)
     mPlane->removeComponent("PrankSinatra");


    if(code==sf::Keyboard::J)
     mPlane->removeComponent("j");

    if(code==sf::Keyboard::K)
     mPlane->removeComponent("k");




    if(code==sf::Keyboard::L)
     mPlane->removeComponent("l");




}

void World::handlePlayerInput(sf::Mouse::Button code, bool isPressed)
{


if(code==sf::Mouse::Left)
{

   if(isPressed==true)
    {

       sf::Vector2i mousePos=sf::Mouse::getPosition(mWindow);
       // mPlane->move(((mWindow.mapPixelToCoords(mousePos))-(mPlane->getPosition()))*(dt.asSeconds()));
    mPlane->setVelocity(((mWindow.mapPixelToCoords(mousePos))-(mPlane->getPosition())));
}





    if(isPressed==false)
    {  }

}
if(code==sf::Mouse::Right)
    if(isPressed) mPlane->setVelocity(0.f,0.f);




}

void World::loadTextures()
{
       mTextureHolder.load(TextureID::Landscape, "/home/student1/knivan/Desktop/HOME/c++/scene-occamsrazor81/data/Desert.png");
       mTextureHolder.load(TextureID::Raptor, "/home/student1/knivan/Desktop/HOME/c++/scene-occamsrazor81/data/Raptor.png");
       mTextureHolder.load(TextureID::Eagle, "/home/student1/knivan/Desktop/HOME/c++/scene-occamsrazor81/data/Eagle.png");
}

void World::buildScene()
{ for(std::size_t i = 0; i < LayerCount; ++i) {
        SceneNode::Ptr layer(new SceneNode() );
        mSceneLayers[i] = layer.get();
        mSceneGraph.addComponent(std::move(layer));
    }

        sf::Texture & desert = mTextureHolder.get(TextureID::Landscape);
        desert.setRepeated(true);
        sf::IntRect rect(mWorldBounds);

        std::unique_ptr<BackgrNode> background( new BackgrNode(desert, rect) );
        background->setPosition(mWorldBounds.left, mWorldBounds.top);

        mSceneLayers[Background]->addComponent( std::move(background) );
        std::unique_ptr<PlaneNode> raptor( new PlaneNode(PlaneNode::Raptor, mTextureHolder) );
        mPlane = raptor.get();
        mPlane->setPosition(mSpawnPosition);
        mPlane->setVelocity(0.f, 0.f);
        mSceneLayers[Air]->addComponent( std::move(raptor) );

        std::unique_ptr<PlaneNode> left( new PlaneNode(PlaneNode::Eagle, mTextureHolder) );
        left->setPosition(-80.f,50.f);
        mPlane->addComponent( std::move(left) );



        std::unique_ptr<PlaneNode> right( new PlaneNode(PlaneNode::Eagle, mTextureHolder) );
        right->setPosition(80.f,50.f);
        mPlane->addComponent( std::move(right) );

        std::unique_ptr<PlaneNode> leftleft( new PlaneNode(PlaneNode::Eagle, mTextureHolder) );
        leftleft->setPosition(-160.f,100.f);
        mPlane->addComponent( std::move(leftleft) );

        std::unique_ptr<PlaneNode> rightright( new PlaneNode(PlaneNode::Eagle, mTextureHolder) );
        rightright->setPosition(160.f,100.f);
        mPlane->addComponent( std::move(rightright) );

}

