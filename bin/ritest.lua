
local grt = require("grt_ri")

local version = grt.getVersion( )

-- create a new context to use:
context, err = grt.newContext("one")
if context == nil then error(err) end

-- grab a copy of the RIB interface
ri = context:getRIBInterface( )

-- turn off pretty printing - the default is on
ri:togglePrettyPrint( )
ri:togglePrettyPrint( ) -- turns it back on

stream = context:getStream( )

-- output a RIB stream ready for rendering, args are as you would expect from a RIB ouput
-- common attributes/tokens will be added in a later version

ri:Comment( "Generated from ritest.lua by grt:ri" )
ri:Comment( "lua module version " .. version )
ri:Comment( "Copyright 2007 mae" )

ri:Hint( "This was written to be rendered by Pixie." )


ri:FrameBegin( 1 )
ri:Option( "searchpath","shader", ".:./shaders:&")
ri:Format( 400, 300, 1 )
ri:PixelSamples( 1, 1 )	
ri:ShadingInterpolation( "smooth" )
ri:Display( "ritest.tiff", "file", "rgba" )
ri:Projection( "perspective", "fov", 22)
ri:Exposure( 1.0, 2.2 )

ri:Translate( 0, -0.5, 8 )
ri:Rotate( -40, 1, 0, 0 )
ri:Rotate( -20, 0, 1, 0 ) 

io.write( stream:flush( ) )


ri:WorldBegin( )	
		
ri:Attribute( "visibility", "trace", 1 )
ri:Attribute( "trace", "bias", 0.005 )
	
ri:AttributeBegin( )
ri:Surface( "occsurf2", "samples", 1024 ) 	
ri:Color( 1, 1, 1 )
ri:Polygon( "P", -5, 0, 5,  5, 0, 5,  5, 0, -5,  -5, 0, -5 )
ri:AttributeEnd( )

ri:Color(1,0,0)	
dofile( "fragments/risphere.lua" )
ri:Color(1,1,1)
dofile( "fragments/ricube.lua" )

ri:WorldEnd( )
ri:FrameEnd( )

io.write( stream:flush( ) )
