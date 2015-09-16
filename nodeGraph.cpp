#include "nodeGraph.h"

nodeGraph::nodeGraph()
{
    //ctor
    m_weight = 1.0;
}

nodeGraph::nodeGraph(float x, float y) : ofVec2f(x,y)
{


}

nodeGraph::~nodeGraph()
{
    //dtor
}
