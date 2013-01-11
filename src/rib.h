#ifndef grt_ri_rib_h
#define grt_ri_rib_h 1

/* THIS IS A AUTOMAGICALLY GENERATED FILE! */

#include "script.h"
#include "reference.h"
#include "stream.h"
#include <string>

namespace grt
{
  
  class RIB : public ReferenceCounted
    {

    public:

      RIB( Stream * );
      ~RIB( );

      int Declare( lua_State *L );
	int FrameBegin( lua_State *L );
	int FrameEnd( lua_State *L );
	int WorldBegin( lua_State *L );
	int WorldEnd( lua_State *L );
	int Format( lua_State *L );
	int FrameAspectRatio( lua_State *L );
	int ScreenWindow( lua_State *L );
	int CropWindow( lua_State *L );
	int Projection( lua_State *L );
	int Clipping( lua_State *L );
	int ClippingPlane( lua_State *L );
	int DepthOfField( lua_State *L );
	int Shutter( lua_State *L );
	int PixelVariance( lua_State *L );
	int PixelSamples( lua_State *L );
	int PixelFilter( lua_State *L );
	int Exposure( lua_State *L );
	int Imager( lua_State *L );
	int Quantize( lua_State *L );
	int Display( lua_State *L );
	int Hider( lua_State *L );
	int ColorSamples( lua_State *L );
	int RelativeDetail( lua_State *L );
	int Option( lua_State *L );
	int AttributeBegin( lua_State *L );
	int AttributeEnd( lua_State *L );
	int Color( lua_State *L );
	int Opacity( lua_State *L );
	int TextureCoordinates( lua_State *L );
	int LightSource( lua_State *L );
	int AreaLightSource( lua_State *L );
	int Illuminate( lua_State *L );
	int Surface( lua_State *L );
	int Atmosphere( lua_State *L );
	int Interior( lua_State *L );
	int Exterior( lua_State *L );
	int ShadingRate( lua_State *L );
	int ShadingInterpolation( lua_State *L );
	int Matte( lua_State *L );
	int Bound( lua_State *L );
	int DetailRange( lua_State *L );
	int GeometricApproximation( lua_State *L );
	int GeometicRepesentation( lua_State *L );
	int Orientation( lua_State *L );
	int Sides( lua_State *L );
	int Identity( lua_State *L );
	int Transform( lua_State *L );
	int Perspective( lua_State *L );
	int Translate( lua_State *L );
	int Rotate( lua_State *L );
	int Scale( lua_State *L );
	int Skew( lua_State *L );
	int Deformation( lua_State *L );
	int Displacement( lua_State *L );
	int CoordinateSystem( lua_State *L );
	int CoordSysTransform( lua_State *L );
	int TransformBegin( lua_State *L );
	int TransformEnd( lua_State *L );
	int Attribute( lua_State *L );
	int Polygon( lua_State *L );
	int GeneralPolygon( lua_State *L );
	int PointsPolygons( lua_State *L );
	int PointsGeneralPolygons( lua_State *L );
	int Basis( lua_State *L );
	int Patch( lua_State *L );
	int PatchMesh( lua_State *L );
	int NuPatch( lua_State *L );
	int TrimCurve( lua_State *L );
	int Sphere( lua_State *L );
	int Cone( lua_State *L );
	int Cylinder( lua_State *L );
	int Hyperboloid( lua_State *L );
	int Disk( lua_State *L );
	int Torus( lua_State *L );
	int Curves( lua_State *L );
	int Procedural( lua_State *L );
	int Geometry( lua_State *L );
	int Points( lua_State *L );
	int SubdivisionMesh( lua_State *L );
	int Blobby( lua_State *L );
	int ProcDelayedReadArchive( lua_State *L );
	int ProcRunProgram( lua_State *L );
	int ProcDynamicLoad( lua_State *L );
	int ProcFree( lua_State *L );
	int SolidBegin( lua_State *L );
	int Objectbegin( lua_State *L );
	int ObjectEnd( lua_State *L );
	int ObjectInstance( lua_State *L );
	int MotionBegin( lua_State *L );
	int MotionEnd( lua_State *L );
	int MakeTexture( lua_State *L );
	int MakeBump( lua_State *L );
	int MakeLatLongEnvironment( lua_State *L );
	int MakeCubeFaceEnvironment( lua_State *L );
	int MakeShadow( lua_State *L );
	int ArchiveRead( lua_State *L );
	int ReadArchive( lua_State *L );
	int Trace( lua_State *L );
	int TraceEx( lua_State *L );
	int Visibility( lua_State *L );
	
      
	 /* hand-coded functions */
	 int Comment( lua_State * L );
      int Hint( lua_State * L );

      int togglePrettyPrint( lua_State *L );
      
    private:
      
      /* parses and generates the output */
      int format( const std::string &, lua_State * );

      
    public:
      
      static const char className[];
      static const Lua<RIB>::RegType methods[];

    protected:

      rStream _stream;
      int _tabs;
      bool _prettyPrint;
    };

  typedef Reference<RIB> rRIB;

}

#endif
