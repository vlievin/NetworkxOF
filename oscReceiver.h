#ifndef OSCRECEIVER_H
/**

receive and process OSC messages

*/

#define OSCRECEIVER_H

#include "ofApp.h"
#include "ofxOsc.h"
#include "graph.h"
#include <iostream>


// listen on port 12345
#define PORT 5001
#define PORT_INTERNE 12347
#define PORT_INTERFACE 12346
#define PORT_RESOLUME 7000
#define HOST "localhost"
#define NUM_MSG_STRINGS 20
#define WIDTH 1280
#define HEIGHT 800

class graph;

class oscReceiver
{
    public:
        oscReceiver();
        virtual ~oscReceiver();
        void update();
        void processMessage(ofxOscMessage m );
        void processnodeMessage(ofxOscMessage m );
        void processEdgeMessage(ofxOscMessage m );
        void processGroupMessage(ofxOscMessage m );
        void processWeightMessage(ofxOscMessage m);
        void setGraph( graph* g );
        void setSize( int x, int y);
    protected:
    private:
        ofxOscReceiver m_receiver;
        graph* m_graph;
        int size_x;
        int size_y;
};

#endif // OSCRECEIVER_H
