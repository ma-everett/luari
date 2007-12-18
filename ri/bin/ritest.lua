
-- ritest.lua
-- RI unit test
-- mae 2007

require("grt_ri")

----[ VECTOR ]----

local VECTOR = { }

function VECTOR:New( o )

	o = o or {r = {0.0,0.0,0.0}}

	setmetatable(o,self)
	self.__index = self

	return o
end

function VECTOR:Out( )

	return self.r[1],self.r[2],self.r[3]
end

function new_vector( r1,r2,r3 )

	local v = VECTOR:New( nil )
	v.r[1] = r1
	v.r[2] = r2
	v.r[3] = r3

	return v
end

--------

local version = 0.1

ri = grt.GetContext( )

grt.Begin(ri, "test.rib" )
	
	-- set the global colours
	local RED = new_vector( 1,0,0 )
	local GREEN = new_vector( 0,1,0 )
	local BLUE = new_vector( 0,0,1 )
	local WHITE = new_vector( 1,1,1 )

	-- set the format/camera options
	local options = {format={xres=1024,yres=512,par=1.0}}	

	
	ri:Comment( "LUA -> RI(SUBSET) INTERFACE" )
	ri:Comment( "UNIT TEST FILE " .. version )  
	ri:Hint( "Created by: mae" )
	ri:Hint( "Created on: " .. os.date( ) )

	ri:PixelSamples( 1, 1 )
	ri:PixelFilter( "catmull-rom", 3, 4 )

	ri:Hider( "stochastic" )

	ri:Color( WHITE:Out( ) )

	ri:CoordinateSystem( "world" )

	ri:FrameBegin( 0 )
	
		ri:Display( "test.tif", "file", "rgb" )
		ri:Format( options.format.xres, options.format.yres, options.format.par )

		ri:LightSource( "pointlight", 1, "from", -1, 1,-1, "intensity", 12)
		ri:LightSource( "pointlight", 2, "from", 1,-1,1, "intensity", 12)
		ri:LightSource( "spherelight",3,"intensity", 10,"from", 1,-1,5 )
	
		ri:Projection( "perspective","fov", 45.0 )
		ri:Translate(0,0,10)
		--ri:Rotate(60,1,0,0)

		ri:WorldBegin( )
			
			ri:CoordSysTransform( "world" )			
			
			ri:AttributeBegin( )
				ri:Attribute( "visibility", "string transmission", "transparent")
				ri:Translate(-1,2,0)
				ri:Scale( 1,1,1 )
				ri:Color( RED:Out( ) )
				ri:Opacity( 1, 1, 1 )
				ri:Surface( "matte" )
				ri:Sphere( 1,-1, 1, 360 )	
			ri:AttributeEnd( )

			ri:AttributeBegin( )
				ri:Translate(0,0,0)
				ri:Scale( 1,1,1 )
				ri:Color( GREEN:Out( ) )
				ri:Opacity( 1, 1, 1 )
				ri:Surface( "matte" )
				ri:Sphere( 1,-1, 1, 360 )	
			ri:AttributeEnd( )
		
			ri:AttributeBegin( )
				ri:Translate(1,0,0)
				ri:Scale( 1,1,1 )
				ri:Color( BLUE:Out( ) )
				ri:Opacity( 1, 1, 1 )
				ri:Surface( "matte" )
				ri:Sphere( 1,-1, 1, 360 )	
			ri:AttributeEnd( )
		
		ri:WorldEnd( )
	ri:FrameEnd( )	
grt.End(ri )
