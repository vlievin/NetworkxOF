/**

store a group of nodes in order to display them with a specific color

**/

#ifndef NODESGROUP_H
#define NODESGROUP_H

#include <list>
#include <utility>

#include "nodeGraph.h"


class nodeGraph;

class nodesGroup
{
    public:
        nodesGroup();
        virtual ~nodesGroup();
        int Getcolor() { return m_color; }
        void Setcolor(int val) { m_color = val; }
        std::list<nodeGraph*> Getnodes() { return m_nodes; }
        void addnode( nodeGraph* node );
        void Setnodes(std::list<nodeGraph*> val) { m_nodes = val; }
        void display();
        void removenode( nodeGraph* n);
    protected:
    private:
        int m_color;
        std::list<nodeGraph*> m_nodes;
};

#endif // NODEGROUP_H
