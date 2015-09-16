#pragma once

#include "ofMain.h"
#include "graph.h"
#include "oscReceiver.h"
#include "nodeGraph.h"

class oscReceiver;
class nodeGraph;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    private:
        oscReceiver* m_oscReceiver;
        graph* m_graph;
        nodeGraph* m_hoverPoint;
        nodeGraph* m_activePoint;
        ofVec2f previousSize;
};
