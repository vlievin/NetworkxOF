# NetworkxOF

*This software is a prototype*

## Overview

**This software runs with OpenFrameworks, you need to include ofxOsc addon. You can use networkx to generate graph and pyOSC to comunicate with this soft **

Draw graph from Networkx thanks to OSC. 

features:
- draw a graph
- draw groups of nodes with specified colours
- draw nodes with weight

Please find a python example below.

## Python example

You need to run NetworkxOF, then type the following code in python to runs the example. (hint: install easily pyOSC and networkx with Anaconda)

#### import libraries
	import networkx as nx
	import matplotlib.pyplot as plt
	import matplotlib.mlab as mlab
	import numpy as np 
	import random 
	import scipy
	import socket, OSC, re, time, threading, math

#### def draw function
	def drawGraphOF( G ):
	    
	    # OSC basic client
	    c = OSC.OSCClient()
	    c = OSC.OSCClient()
	    c.connect( ("127.0.0.1", 5001) )
	
	    pos=nx.fruchterman_reingold_layout(G)
	    print "pos defined"
	    msg = OSC.OSCMessage()
	    msg.setAddress("/reset")
	    c.send(msg)
	
	    for n in pos:
	        msg = OSC.OSCMessage()
	        msg.setAddress("/node")
	        msg.append( n )
	        msg.append( pos[n][0])
	        msg.append( pos[n][1])
	        c.send(msg)
	
	    for e in G.edges():
	        msg = OSC.OSCMessage()
	        msg.setAddress("/edge")
	        msg.append( e[0])
	        msg.append( e[1])
	        c.send(msg)
	        
	    return

#### def weight function  
*values must be between 0 & 1*

	def drawDegree( G ):
	    
	    # OSC basic client
	    c = OSC.OSCClient()
	    c = OSC.OSCClient()
	    c.connect( ("127.0.0.1", 5001) )
	    
	    degrees = G.degree()
	    degList = []
	    for d in degrees:
	        degList.append(degrees[d])
	    maxx = max(degList)
	    for n in degrees:
	        msg = OSC.OSCMessage()
	        msg.setAddress("/weight")
	        msg.append( n)
	        msg.append( float(degrees[n]) / maxx )
	        c.send(msg)
	    return
  
#### def group function
	def drawGroup( nodes, color):
	        msg = OSC.OSCMessage()
	        msg.setAddress("/group")
	        msg.append( color )
	        for n in nodes:
	            msg.append( n )
	        c.send(msg)
	        return


#### use weight feature
	J = nx.barabasi_albert_graph( 2000 , 1)
	drawGraphOF( J )
	drawDegree( J )



#### use group feature

	rdmNode = random.choice(GCC.nodes())
	distanceMap = nx.single_source_shortest_path_length( GCC, rdmNode )
	
	grp2 = []
	grp1 = []
	grp3 = []
	
	for n in GCC.nodes():
	    if distanceMap[n] == 1:
	        grp1.append( n )
	    elif distanceMap[n] == 2:
	        grp2.append( n )
	    elif distanceMap[n] == 3:
	        grp3.append( n )
	        
	
	grp0 = []
	grp0.append( rdmNode )
	
	drawGraphOF( GCC )
	drawGroup( grp0 , 0x0066FF )
	drawGroup( grp1 , 0x00ff99 )
	drawGroup( grp2 , 0xCCFF99 )
	drawGroup( grp3 , 0xFFFFCC )





