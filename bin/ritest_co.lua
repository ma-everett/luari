
-- ritest_co.lua
-- mae 2007
-- the same as ritest.lua except using coroutines

local grt = require("grt_ri")

local DETAIL = 4 -- number of pixel samples : 1=draft, 4+=good quality (slower rendering times)

local version = grt.getVersion( )

-- create a new context to use:
context, err = grt.newContext("one")
if context == nil then error(err) end

-- grab a copy of the RIB interface
ri = context:getRIBInterface( )

-- turn off pretty printing - the default is on
ri:togglePrettyPrint( )

-- grab the stream object for the current context
stream = context:getStream( )

-- create a pair of coroutines to produce the output
-- 'producer' creates generates the rib source
-- whilst 'riboutput' write the source to stdout

producer = coroutine.create( function( )
	
	local frames = 5

	-- output a RIB stream ready for rendering, args are as you would expect from a RIB output
	-- common attributes/tokens will be added in a later version

	ri:Comment( "Generated from ritest.lua by grt:ri" )
	ri:Comment( "lua module version " .. version )
	ri:Comment( "Copyright 2007 mae" )

	ri:Hint( "This was written to be rendered by Pixie." )
	ri:Option( "searchpath","shader", ".:./shaders:&")
	ri:Format( 400, 300, 1 )
	ri:PixelSamples( DETAIL, DETAIL )	
	ri:ShadingInterpolation( "smooth" )

	local u = 0
	local ustep = 1/frames	

	for i=1,frames do

		ri:FrameBegin( i )
		
			ri:Display( "ritest_co-0" .. i .. ".tiff", "file", "rgba" )
			ri:Projection( "perspective", "fov", 22)
			ri:Exposure( 1.0, 2.2 )

			ri:Translate( 0, -0.5, 8 )
			ri:Rotate( -40, 1, 0, 0 )
			ri:Rotate( -20, 0, 1, 0 ) 

		coroutine.yield( ) -- just before the worldbegin block

			ri:WorldBegin( )	
		
				ri:Attribute( "visibility", "trace", 1 )
				ri:Attribute( "trace", "bias", 0.005 )
	
				ri:AttributeBegin( )
					ri:Surface( "occsurf2", "samples", 1024 ) 	
					ri:Color( 1, 1, 1 )
					ri:Polygon( "P", -5, 0, 5,  5, 0, 5,  5, 0, -5,  -5, 0, -5 )
				ri:AttributeEnd( )
	
				-- using the dofile mechanism in Lua allows us to fragment the code into
				-- more useful, seperate files

				ri:Color( 1, u, u )
				dofile( "fragments/risphere.lua" )
				
				ri:Color( 1, 1, 1 )
				dofile( "fragments/ricube.lua" )

		ri:WorldEnd( )
		ri:FrameEnd( ) -- this where the renderer will begin rendering the frame

		u = u + ustep		

	end -- for loop

end ) -- end of coroutine producer

riboutput = coroutine.create( function( )

	-- pump the output to stdout until producer has nothing more
	while coroutine.status(producer) ~= "dead" do
	
		coroutine.resume( producer )
		io.write( stream:flush( ) ) 
		
	end
end ) -- end of coroutine riboutput

-- start the process:
coroutine.resume( riboutput )


--[[ 
  Food for thought. The stream content can of course be written to a file or to where ever you
  may want it to go. As many Contexts can be created and used at the same time as you wish, so
  different streams of information can be created from one source. For instance you may want to
  generate a number of layers for a particular frame from a single set of data.

  The RenderMan Interface allows for calling proceduaral programs/tools during rendering. Using
  Lua and the G&RT:RI module can allow you to develop these tools quickly and with ease. Allowing
  you to spend more of your time creating rather then developing.  

  - mae 2007
--]]
