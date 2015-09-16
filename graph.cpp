#include "graph.h"


const float offset = 20.0;

graph::graph()
{

    m_weightMode = false;
    //ctor
}

graph::~graph()
{
    //dtor
}


void graph::display()
{
    std::list< std::pair< nodeGraph*, nodeGraph*> >::const_iterator e;
    for ( e= m_edges.begin() ; e != m_edges.end() ; e++)
        ofLine( *(e->first) , *(e->second));

    /*std::map<int, nodeGraph*>::const_iterator it;

    for ( it = m_nodes.begin() ; it != m_nodes.end() ; it++)
        ofCircle( *(it->second) , 5);*/

    if (m_weightMode)
    {
        std::map<int, nodeGraph*>::iterator it;
        for ( it = m_nodes.begin() ; it != m_nodes.end() ; it++)
        {
            float w = (*it).second->Getweight();
            //cout << " w : " << w << endl;
            ofColor c1 = ofColor( 255, 255, 255, 100);
            ofColor c2 = ofColor( 51, 204, 255, 200);
            ofSetColor(  c2 * w + c1 * ( 1 - w ) );
            ofCircle( *(it->second), 2 + 20 * w );
            ofSetColor((ofColor::white));
        }
    }
    else
    {
        std::list<nodesGroup*>::iterator it;
        for ( it = m_groups.begin() ; it!= m_groups.end() ; ++it )
            (*it)->display();
    }



}

void graph::reset()
{
    m_edges.clear();

    std::list<nodesGroup*>::iterator ig;

    for ( ig = m_groups.begin() ; ig != m_groups.end() ; )
    {
        delete *ig;
        ig = m_groups.erase(ig);

    }

    std::map<int, nodeGraph*>::iterator it;

    for ( it = m_nodes.begin() ; it != m_nodes.end() ; )
    {
        delete it->second;
        it = m_nodes.erase(it);

    }

    nodesGroup* g = new nodesGroup();
    m_groups.push_back( g );

    m_weightMode = false;

}

void graph::addnode(int id,  float x, float y)
{
    nodeGraph* node = new nodeGraph( x , y);
    m_nodes[id] = node;

    nodesGroup* g = *(m_groups.begin());

    g->addnode(  node );

}

void graph::addEdge( int x, int y)
{
   std::pair< nodeGraph*, nodeGraph*> p = std::make_pair( m_nodes[x] , m_nodes[y] );
   m_edges.push_back( p ) ;
}

nodeGraph* graph::getNearestEdge( int x , int y, float range  )
{
    nodeGraph* result = NULL;
    nodeGraph pos = nodeGraph( x ,y);
    float d = 999999999999;
    std::map<int,nodeGraph*>::iterator it;

    for ( it = m_nodes.begin() ; it != m_nodes.end() ; it++)
    {
        float d_tmp = (it->second)->squareDistance( pos );

        if ( d_tmp < d )
        {
            d = d_tmp;
            result = it->second;
        }

    }

    if (range == 0)
        return result;
    else if ( d > range )
        return NULL;
    else return result;

}


void graph::reScale( float x , float y , float newx, float newy)
{
    std::map<int,nodeGraph*>::iterator it;

    //cout << x << " |"<< y<< endl;
    for ( it = m_nodes.begin() ; it != m_nodes.end() ; it++)
    {
        ofVec2f tmp = *(it->second) - nodeGraph(offset, offset);

        tmp = nodeGraph(offset , offset) + nodeGraph( newx * tmp.x / x , newy * tmp.y /y);

        (*(it->second)).x = tmp.x;
        (*(it->second)).y = tmp.y;


    }
}

void graph::addGroup( int color, std::list<nodeGraph*> nodes )
{
      std::list<nodesGroup*>::iterator ig;

    for ( ig = m_groups.begin() ; ig != m_groups.end() ; ig++)
    {
        std::list<nodeGraph*>::iterator it;
        for ( it = nodes.begin() ; it != nodes.end() ; ++it)
            (*ig)->removenode(*it);
    }

    nodesGroup* g = new nodesGroup();
    g->Setnodes( nodes );

    g->Setcolor( color );

    m_groups.push_back( g );
}

void graph::setWeightMode( bool b )
{
    m_weightMode = b;
}



