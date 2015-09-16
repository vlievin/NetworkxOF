#include "ofApp.h"


const int SQUARE_RANGE = 25;
//--------------------------------------------------------------
void ofApp::setup(){
    m_oscReceiver = new oscReceiver();
    m_graph = new graph();
    m_oscReceiver->setGraph( m_graph );

    m_hoverPoint = NULL;
    m_activePoint = NULL;

     m_oscReceiver->setSize( ofGetWindowWidth(), ofGetWindowHeight());
     previousSize = nodeGraph( ofGetWindowWidth(), ofGetWindowHeight() );
}

//--------------------------------------------------------------
void ofApp::update(){
    m_oscReceiver->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    if (m_hoverPoint)
    {
        float w = m_hoverPoint->Getweight();
        //cout << " w : " << w << endl;
        ofColor c1 = ofColor( 255, 255, 255, 100);
        ofColor c2 = ofColor( 51, 204, 255, 200);
        ofSetColor(  c2 * w + c1 * ( 1 - w ) );
        ofCircle( *(m_hoverPoint), 1.5 * (2 + 20 * w ));
        ofSetColor((ofColor::white));
    }
    //std::cout << " graph size: " << m_graph->GetnodeGraphs().size() << std::endl;
    m_graph->display();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    m_hoverPoint = m_graph->getNearestEdge( x , y , SQUARE_RANGE );
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (m_activePoint)
    {
        float w = m_activePoint->Getweight();
        *m_activePoint = nodeGraph( x , y );
         m_activePoint->Setweight(w);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    m_activePoint = m_graph->getNearestEdge( x , y , SQUARE_RANGE );
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    m_activePoint = NULL;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    m_oscReceiver->setSize(w , h);
    m_graph->reScale( previousSize.x  , previousSize.y , w , h );
    previousSize = nodeGraph( w , h );
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
