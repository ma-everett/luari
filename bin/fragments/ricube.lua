
-- a white cube

ri:AttributeBegin( )
ri:Surface( "occsurf3", "samples", 1024 ) 
ri:Translate( 0.3, 0.01, 0 )
ri:Rotate( -30, 0, 1, 0 )
ri:Polygon( "P", 0, 0, 0,  0, 0, 1,  0, 1, 1,  0, 1, 0 )
ri:Polygon( "P", 1, 1, 0,  1, 1, 1,  1, 0, 1,  1, 0, 0 )
ri:Polygon( "P", 0, 1, 0,  1, 1, 0,  1, 0, 0,  0, 0, 0)
ri:Polygon( "P", 0, 0, 1,  1, 0, 1,  1, 1, 1,  0, 1, 1 )
ri:Polygon( "P",0, 1, 1,  1, 1, 1,  1, 1, 0,  0, 1, 0 )
ri:AttributeEnd( )