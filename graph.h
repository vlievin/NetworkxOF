/**

store a graph structure

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <utility>
#include <map>
#include "nodesGroup.h"

class nodeGraph;
class nodesGroup;
class graph
{
    public:
        graph();
        virtual ~graph();
        std::map<int,nodeGraph*> Getnodes() const { return m_nodes; }
        void Setnodes(std::map<int, nodeGraph*> val) { m_nodes = val; }
        void reset();
        void display();
        void addnode( int id, float x, float y);
        void addEdge( int x, int y);

        nodeGraph* getNearestEdge( int x , int y , float range = 0 );

        void reScale( float x , float y , float newx, float newy);

        void addGroup( int color, std::list<nodeGraph*> nodes );

        void setWeightMode( bool b );

    protected:
    private:
        std::map<int, nodeGraph*> m_nodes;
        std::list< std::pair< nodeGraph*, nodeGraph*> > m_edges;
        std::list< nodesGroup* > m_groups;
        bool m_weightMode;
};

#endif // GRAPH_H
