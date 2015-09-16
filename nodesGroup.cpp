#ifndef NODESGROUP_CPP
#define NODESGROUP_CPP

#include "nodesGroup.h"

nodesGroup::nodesGroup()
{
    m_color = 0xffffff;
    //ctor
}

nodesGroup::~nodesGroup()
{
    //dtor
}

void nodesGroup::display()
{
    std::list<nodeGraph*>::iterator it;
    ofColor col = ofColor::fromHex(m_color);
    ofSetColor( col );
    for (it = m_nodes.begin() ; it != m_nodes.end() ; ++it )
        ofCircle( **it, 5 );

    ofSetColor(ofColor::white);

}

void nodesGroup::addnode( nodeGraph* node )
{
    m_nodes.push_back( node );

}

 void nodesGroup::removenode( nodeGraph* n)
 {

     m_nodes.remove( n );
 }


#endif // NODEGROUP_CPP
