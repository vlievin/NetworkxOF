#ifndef NODEGRAPH_H
#define NODEGRAPH_H

#include "ofApp.h"

class nodeGraph : public ofVec2f
{
    public:
        nodeGraph();
        nodeGraph(float x, float y);
        virtual ~nodeGraph();
        float Getweight() { return m_weight; }
        void Setweight(float val) { m_weight = val; }
    protected:
    private:
        float m_weight;
};


#endif // NODEGRAPH_H
