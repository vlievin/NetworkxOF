#include "oscReceiver.h"

const float offset = 20.0;

oscReceiver::oscReceiver()
{
    //ctor
    m_receiver.setup(PORT);
    size_x = 600;
    size_y = 400;
}

oscReceiver::~oscReceiver()
{
    //dtor
}

void oscReceiver::update()
{
       while(m_receiver.hasWaitingMessages())
    {
        ofxOscMessage m ;
        m_receiver.getNextMessage(&m);
        processMessage(m);
    }

}

void oscReceiver::processGroupMessage(ofxOscMessage m )
{
    int color = m.getArgAsInt32(0);

    std::list<nodeGraph*> nodes;
    std::map<int, nodeGraph*> Existingnodes = m_graph->Getnodes();

    for (int i = 1 ; i < m.getNumArgs() ; i ++)
    {
        nodes.push_back( Existingnodes[m.getArgAsInt32( i )] );
    }

    m_graph->addGroup( color , nodes );


}

void oscReceiver::processMessage(ofxOscMessage m )
{

    //cout << " got a message :  " << m.getAddress() << endl;


    if (m.getAddress() == "/reset")
        m_graph->reset();
    else if (m.getAddress() =="/node")
        processnodeMessage(m);
    else if (m.getAddress() == "/edge" )
        processEdgeMessage( m ) ;
    else if (m.getAddress() =="/group")
        processGroupMessage(m);
    else if (m.getAddress() == "/weight")
        processWeightMessage( m);
}

void oscReceiver::processWeightMessage(ofxOscMessage m)
{
    std::map<int,nodeGraph*> nodes = m_graph->Getnodes();
    if (m.getArgAsInt32(0) < 0 )
        m_graph->setWeightMode( false );
    else
    {
        m_graph->setWeightMode( true );
        nodeGraph* n = nodes[m.getArgAsInt32(0)];
        if (n)
            n->Setweight( m.getArgAsFloat(1) );
    }


}
void oscReceiver::processEdgeMessage(ofxOscMessage m )
{
    m_graph->addEdge( m.getArgAsInt32(0), m.getArgAsInt32(1) );
}
void oscReceiver::processnodeMessage(ofxOscMessage m )
{
    /*cout << " |  " << m.getArgAsInt32(0) ;
    cout << " |  " << m.getArgAsFloat(1) ;
    cout << " |  " << m.getArgAsFloat(2) ;
    cout << endl;*/
    float x = offset + (float(size_x) - 2 * offset) * m.getArgAsFloat(1) ;
    float y = offset + (float(size_y) - 2 * offset) * m.getArgAsFloat(2);

    //cout << x << " | " << y << endl;
    m_graph->addnode( m.getArgAsInt32(0), x , y);

}

void oscReceiver::setGraph( graph* g)
{
    m_graph = g;

}

void oscReceiver::setSize( int x, int y)
{
    size_x = x;
    size_y = y;
}
