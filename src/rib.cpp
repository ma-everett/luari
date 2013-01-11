
/* THIS IS AN AUTOMAGICALLY GENERATED FILE! */

#include "rib.h"

namespace grt
{

  RIB::RIB( Stream * s )
  {
    _stream = s;
    _tabs = 0;
    _prettyPrint = true;
  }

  RIB::~RIB( )
  {

  }

  /* Declare( ... )
 */
int 
RIB::Declare( lua_State * L )
{
	format("Declare",L);
	return 0;
}

/* FrameBegin( ... )
 */
int 
RIB::FrameBegin( lua_State * L )
{
	format("FrameBegin",L);
	_tabs++;
	return 0;
}

/* FrameEnd( ... )
 */
int 
RIB::FrameEnd( lua_State * L )
{
	_tabs--;
	format("FrameEnd",L);
	return 0;
}

/* WorldBegin( ... )
 */
int 
RIB::WorldBegin( lua_State * L )
{
	format("WorldBegin",L);
	_tabs++;
	return 0;
}

/* WorldEnd( ... )
 */
int 
RIB::WorldEnd( lua_State * L )
{
	_tabs--;
	format("WorldEnd",L);
	return 0;
}

/* Format( ... )
 */
int 
RIB::Format( lua_State * L )
{
	format("Format",L);
	return 0;
}

/* FrameAspectRatio( ... )
 */
int 
RIB::FrameAspectRatio( lua_State * L )
{
	format("FrameAspectRatio",L);
	return 0;
}

/* ScreenWindow( ... )
 */
int 
RIB::ScreenWindow( lua_State * L )
{
	format("ScreenWindow",L);
	return 0;
}

/* CropWindow( ... )
 */
int 
RIB::CropWindow( lua_State * L )
{
	format("CropWindow",L);
	return 0;
}

/* Projection( ... )
 */
int 
RIB::Projection( lua_State * L )
{
	format("Projection",L);
	return 0;
}

/* Clipping( ... )
 */
int 
RIB::Clipping( lua_State * L )
{
	format("Clipping",L);
	return 0;
}

/* ClippingPlane( ... )
 */
int 
RIB::ClippingPlane( lua_State * L )
{
	format("ClippingPlane",L);
	return 0;
}

/* DepthOfField( ... )
 */
int 
RIB::DepthOfField( lua_State * L )
{
	format("DepthOfField",L);
	return 0;
}

/* Shutter( ... )
 */
int 
RIB::Shutter( lua_State * L )
{
	format("Shutter",L);
	return 0;
}

/* PixelVariance( ... )
 */
int 
RIB::PixelVariance( lua_State * L )
{
	format("PixelVariance",L);
	return 0;
}

/* PixelSamples( ... )
 */
int 
RIB::PixelSamples( lua_State * L )
{
	format("PixelSamples",L);
	return 0;
}

/* PixelFilter( ... )
 */
int 
RIB::PixelFilter( lua_State * L )
{
	format("PixelFilter",L);
	return 0;
}

/* Exposure( ... )
 */
int 
RIB::Exposure( lua_State * L )
{
	format("Exposure",L);
	return 0;
}

/* Imager( ... )
 */
int 
RIB::Imager( lua_State * L )
{
	format("Imager",L);
	return 0;
}

/* Quantize( ... )
 */
int 
RIB::Quantize( lua_State * L )
{
	format("Quantize",L);
	return 0;
}

/* Display( ... )
 */
int 
RIB::Display( lua_State * L )
{
	format("Display",L);
	return 0;
}

/* Hider( ... )
 */
int 
RIB::Hider( lua_State * L )
{
	format("Hider",L);
	return 0;
}

/* ColorSamples( ... )
 */
int 
RIB::ColorSamples( lua_State * L )
{
	format("ColorSamples",L);
	return 0;
}

/* RelativeDetail( ... )
 */
int 
RIB::RelativeDetail( lua_State * L )
{
	format("RelativeDetail",L);
	return 0;
}

/* Option( ... )
 */
int 
RIB::Option( lua_State * L )
{
	format("Option",L);
	return 0;
}

/* AttributeBegin( ... )
 */
int 
RIB::AttributeBegin( lua_State * L )
{
	format("AttributeBegin",L);
	_tabs++;
	return 0;
}

/* AttributeEnd( ... )
 */
int 
RIB::AttributeEnd( lua_State * L )
{
	_tabs--;
	format("AttributeEnd",L);
	return 0;
}

/* Color( ... )
 */
int 
RIB::Color( lua_State * L )
{
	format("Color",L);
	return 0;
}

/* Opacity( ... )
 */
int 
RIB::Opacity( lua_State * L )
{
	format("Opacity",L);
	return 0;
}

/* TextureCoordinates( ... )
 */
int 
RIB::TextureCoordinates( lua_State * L )
{
	format("TextureCoordinates",L);
	return 0;
}

/* LightSource( ... )
 */
int 
RIB::LightSource( lua_State * L )
{
	format("LightSource",L);
	return 0;
}

/* AreaLightSource( ... )
 */
int 
RIB::AreaLightSource( lua_State * L )
{
	format("AreaLightSource",L);
	return 0;
}

/* Illuminate( ... )
 */
int 
RIB::Illuminate( lua_State * L )
{
	format("Illuminate",L);
	return 0;
}

/* Surface( ... )
 */
int 
RIB::Surface( lua_State * L )
{
	format("Surface",L);
	return 0;
}

/* Atmosphere( ... )
 */
int 
RIB::Atmosphere( lua_State * L )
{
	format("Atmosphere",L);
	return 0;
}

/* Interior( ... )
 */
int 
RIB::Interior( lua_State * L )
{
	format("Interior",L);
	return 0;
}

/* Exterior( ... )
 */
int 
RIB::Exterior( lua_State * L )
{
	format("Exterior",L);
	return 0;
}

/* ShadingRate( ... )
 */
int 
RIB::ShadingRate( lua_State * L )
{
	format("ShadingRate",L);
	return 0;
}

/* ShadingInterpolation( ... )
 */
int 
RIB::ShadingInterpolation( lua_State * L )
{
	format("ShadingInterpolation",L);
	return 0;
}

/* Matte( ... )
 */
int 
RIB::Matte( lua_State * L )
{
	format("Matte",L);
	return 0;
}

/* Bound( ... )
 */
int 
RIB::Bound( lua_State * L )
{
	format("Bound",L);
	return 0;
}

/* DetailRange( ... )
 */
int 
RIB::DetailRange( lua_State * L )
{
	format("DetailRange",L);
	return 0;
}

/* GeometricApproximation( ... )
 */
int 
RIB::GeometricApproximation( lua_State * L )
{
	format("GeometricApproximation",L);
	return 0;
}

/* GeometicRepesentation( ... )
 */
int 
RIB::GeometicRepesentation( lua_State * L )
{
	format("GeometicRepesentation",L);
	return 0;
}

/* Orientation( ... )
 */
int 
RIB::Orientation( lua_State * L )
{
	format("Orientation",L);
	return 0;
}

/* Sides( ... )
 */
int 
RIB::Sides( lua_State * L )
{
	format("Sides",L);
	return 0;
}

/* Identity( ... )
 */
int 
RIB::Identity( lua_State * L )
{
	format("Identity",L);
	return 0;
}

/* Transform( ... )
 */
int 
RIB::Transform( lua_State * L )
{
	format("Transform",L);
	return 0;
}

/* Perspective( ... )
 */
int 
RIB::Perspective( lua_State * L )
{
	format("Perspective",L);
	return 0;
}

/* Translate( ... )
 */
int 
RIB::Translate( lua_State * L )
{
	format("Translate",L);
	return 0;
}

/* Rotate( ... )
 */
int 
RIB::Rotate( lua_State * L )
{
	format("Rotate",L);
	return 0;
}

/* Scale( ... )
 */
int 
RIB::Scale( lua_State * L )
{
	format("Scale",L);
	return 0;
}

/* Skew( ... )
 */
int 
RIB::Skew( lua_State * L )
{
	format("Skew",L);
	return 0;
}

/* Deformation( ... )
 */
int 
RIB::Deformation( lua_State * L )
{
	format("Deformation",L);
	return 0;
}

/* Displacement( ... )
 */
int 
RIB::Displacement( lua_State * L )
{
	format("Displacement",L);
	return 0;
}

/* CoordinateSystem( ... )
 */
int 
RIB::CoordinateSystem( lua_State * L )
{
	format("CoordinateSystem",L);
	return 0;
}

/* CoordSysTransform( ... )
 */
int 
RIB::CoordSysTransform( lua_State * L )
{
	format("CoordSysTransform",L);
	return 0;
}

/* TransformBegin( ... )
 */
int 
RIB::TransformBegin( lua_State * L )
{
	format("TransformBegin",L);
	_tabs++;
	return 0;
}

/* TransformEnd( ... )
 */
int 
RIB::TransformEnd( lua_State * L )
{
	_tabs--;
	format("TransformEnd",L);
	return 0;
}

/* Attribute( ... )
 */
int 
RIB::Attribute( lua_State * L )
{
	format("Attribute",L);
	return 0;
}

/* Polygon( ... )
 */
int 
RIB::Polygon( lua_State * L )
{
	format("Polygon",L);
	return 0;
}

/* GeneralPolygon( ... )
 */
int 
RIB::GeneralPolygon( lua_State * L )
{
	format("GeneralPolygon",L);
	return 0;
}

/* PointsPolygons( ... )
 */
int 
RIB::PointsPolygons( lua_State * L )
{
	format("PointsPolygons",L);
	return 0;
}

/* PointsGeneralPolygons( ... )
 */
int 
RIB::PointsGeneralPolygons( lua_State * L )
{
	format("PointsGeneralPolygons",L);
	return 0;
}

/* Basis( ... )
 */
int 
RIB::Basis( lua_State * L )
{
	format("Basis",L);
	return 0;
}

/* Patch( ... )
 */
int 
RIB::Patch( lua_State * L )
{
	format("Patch",L);
	return 0;
}

/* PatchMesh( ... )
 */
int 
RIB::PatchMesh( lua_State * L )
{
	format("PatchMesh",L);
	return 0;
}

/* NuPatch( ... )
 */
int 
RIB::NuPatch( lua_State * L )
{
	format("NuPatch",L);
	return 0;
}

/* TrimCurve( ... )
 */
int 
RIB::TrimCurve( lua_State * L )
{
	format("TrimCurve",L);
	return 0;
}

/* Sphere( ... )
 */
int 
RIB::Sphere( lua_State * L )
{
	format("Sphere",L);
	return 0;
}

/* Cone( ... )
 */
int 
RIB::Cone( lua_State * L )
{
	format("Cone",L);
	return 0;
}

/* Cylinder( ... )
 */
int 
RIB::Cylinder( lua_State * L )
{
	format("Cylinder",L);
	return 0;
}

/* Hyperboloid( ... )
 */
int 
RIB::Hyperboloid( lua_State * L )
{
	format("Hyperboloid",L);
	return 0;
}

/* Disk( ... )
 */
int 
RIB::Disk( lua_State * L )
{
	format("Disk",L);
	return 0;
}

/* Torus( ... )
 */
int 
RIB::Torus( lua_State * L )
{
	format("Torus",L);
	return 0;
}

/* Curves( ... )
 */
int 
RIB::Curves( lua_State * L )
{
	format("Curves",L);
	return 0;
}

/* Procedural( ... )
 */
int 
RIB::Procedural( lua_State * L )
{
	format("Procedural",L);
	return 0;
}

/* Geometry( ... )
 */
int 
RIB::Geometry( lua_State * L )
{
	format("Geometry",L);
	return 0;
}

/* Points( ... )
 */
int 
RIB::Points( lua_State * L )
{
	format("Points",L);
	return 0;
}

/* SubdivisionMesh( ... )
 */
int 
RIB::SubdivisionMesh( lua_State * L )
{
	format("SubdivisionMesh",L);
	return 0;
}

/* Blobby( ... )
 */
int 
RIB::Blobby( lua_State * L )
{
	format("Blobby",L);
	return 0;
}

/* ProcDelayedReadArchive( ... )
 */
int 
RIB::ProcDelayedReadArchive( lua_State * L )
{
	format("ProcDelayedReadArchive",L);
	return 0;
}

/* ProcRunProgram( ... )
 */
int 
RIB::ProcRunProgram( lua_State * L )
{
	format("ProcRunProgram",L);
	return 0;
}

/* ProcDynamicLoad( ... )
 */
int 
RIB::ProcDynamicLoad( lua_State * L )
{
	format("ProcDynamicLoad",L);
	return 0;
}

/* ProcFree( ... )
 */
int 
RIB::ProcFree( lua_State * L )
{
	format("ProcFree",L);
	return 0;
}

/* SolidBegin( ... )
 */
int 
RIB::SolidBegin( lua_State * L )
{
	format("SolidBegin",L);
	_tabs++;
	return 0;
}

/* Objectbegin( ... )
 */
int 
RIB::Objectbegin( lua_State * L )
{
	format("Objectbegin",L);
	_tabs++;
	return 0;
}

/* ObjectEnd( ... )
 */
int 
RIB::ObjectEnd( lua_State * L )
{
	_tabs--;
	format("ObjectEnd",L);
	return 0;
}

/* ObjectInstance( ... )
 */
int 
RIB::ObjectInstance( lua_State * L )
{
	format("ObjectInstance",L);
	return 0;
}

/* MotionBegin( ... )
 */
int 
RIB::MotionBegin( lua_State * L )
{
	format("MotionBegin",L);
	_tabs++;
	return 0;
}

/* MotionEnd( ... )
 */
int 
RIB::MotionEnd( lua_State * L )
{
	_tabs--;
	format("MotionEnd",L);
	return 0;
}

/* MakeTexture( ... )
 */
int 
RIB::MakeTexture( lua_State * L )
{
	format("MakeTexture",L);
	return 0;
}

/* MakeBump( ... )
 */
int 
RIB::MakeBump( lua_State * L )
{
	format("MakeBump",L);
	return 0;
}

/* MakeLatLongEnvironment( ... )
 */
int 
RIB::MakeLatLongEnvironment( lua_State * L )
{
	format("MakeLatLongEnvironment",L);
	return 0;
}

/* MakeCubeFaceEnvironment( ... )
 */
int 
RIB::MakeCubeFaceEnvironment( lua_State * L )
{
	format("MakeCubeFaceEnvironment",L);
	return 0;
}

/* MakeShadow( ... )
 */
int 
RIB::MakeShadow( lua_State * L )
{
	format("MakeShadow",L);
	return 0;
}

/* ArchiveRead( ... )
 */
int 
RIB::ArchiveRead( lua_State * L )
{
	format("ArchiveRead",L);
	return 0;
}

/* ReadArchive( ... )
 */
int 
RIB::ReadArchive( lua_State * L )
{
	format("ReadArchive",L);
	return 0;
}

/* Trace( ... )
 */
int 
RIB::Trace( lua_State * L )
{
	format("Trace",L);
	return 0;
}

/* TraceEx( ... )
 */
int 
RIB::TraceEx( lua_State * L )
{
	format("TraceEx",L);
	return 0;
}

/* Visibility( ... )
 */
int 
RIB::Visibility( lua_State * L )
{
	format("Visibility",L);
	return 0;
}


  

  /* hand-coded functions */
  int 
  RIB::Comment( lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );

    _stream->string( "#" )->ws( );
   
    if (lua_gettop(L) >= 1)
      {
	_stream->string( luaL_checkstring(L,1) );
      }

    _stream->nl( );
    return 0;
  }

  int 
  RIB::Hint( lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );

    _stream->string( "##" )->ws( );
   
    if (lua_gettop(L) >= 1)
      {
	_stream->string( luaL_checkstring(L,1) );
      }

    _stream->nl( );
    return 0;
  }    

  int 
  RIB::togglePrettyPrint( lua_State * L )
  {
    /* ignore any variables */
    _prettyPrint = !_prettyPrint;

    lua_pushnumber(L,_prettyPrint);
    return 1;
  }

  int 
  RIB::format( const std::string & n, lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );


    /* the name: */
    _stream->string( n )->ws( );


    int top = lua_gettop(L);

    if (top == 0)
      {
	_stream->nl( );
	return 0;
      }
    else
      { /* parse all the attributes and print to stream */

	for (unsigned int op= 1; op <= top; op++)
	  {
	    if (lua_isnumber(L,op))
	      {
		_stream->number( luaL_checknumber(L,op) )->ws( );
	      }
	    else if (lua_isstring(L,op))
	      {
		_stream->quote( luaL_checkstring(L,op) )->ws( );
	      }
	  }

	_stream->nl( );
	return 0;
      }

  }
 
  const char RIB::className[] = "RIB";
  const Lua<RIB>::RegType RIB::methods[] = 
    {      
      SCRIPTMETHOD(RIB,Declare),
SCRIPTMETHOD(RIB,FrameBegin),
SCRIPTMETHOD(RIB,FrameEnd),
SCRIPTMETHOD(RIB,WorldBegin),
SCRIPTMETHOD(RIB,WorldEnd),
SCRIPTMETHOD(RIB,Format),
SCRIPTMETHOD(RIB,FrameAspectRatio),
SCRIPTMETHOD(RIB,ScreenWindow),
SCRIPTMETHOD(RIB,CropWindow),
SCRIPTMETHOD(RIB,Projection),
SCRIPTMETHOD(RIB,Clipping),
SCRIPTMETHOD(RIB,ClippingPlane),
SCRIPTMETHOD(RIB,DepthOfField),
SCRIPTMETHOD(RIB,Shutter),
SCRIPTMETHOD(RIB,PixelVariance),
SCRIPTMETHOD(RIB,PixelSamples),
SCRIPTMETHOD(RIB,PixelFilter),
SCRIPTMETHOD(RIB,Exposure),
SCRIPTMETHOD(RIB,Imager),
SCRIPTMETHOD(RIB,Quantize),
SCRIPTMETHOD(RIB,Display),
SCRIPTMETHOD(RIB,Hider),
SCRIPTMETHOD(RIB,ColorSamples),
SCRIPTMETHOD(RIB,RelativeDetail),
SCRIPTMETHOD(RIB,Option),
SCRIPTMETHOD(RIB,AttributeBegin),
SCRIPTMETHOD(RIB,AttributeEnd),
SCRIPTMETHOD(RIB,Color),
SCRIPTMETHOD(RIB,Opacity),
SCRIPTMETHOD(RIB,TextureCoordinates),
SCRIPTMETHOD(RIB,LightSource),
SCRIPTMETHOD(RIB,AreaLightSource),
SCRIPTMETHOD(RIB,Illuminate),
SCRIPTMETHOD(RIB,Surface),
SCRIPTMETHOD(RIB,Atmosphere),
SCRIPTMETHOD(RIB,Interior),
SCRIPTMETHOD(RIB,Exterior),
SCRIPTMETHOD(RIB,ShadingRate),
SCRIPTMETHOD(RIB,ShadingInterpolation),
SCRIPTMETHOD(RIB,Matte),
SCRIPTMETHOD(RIB,Bound),
SCRIPTMETHOD(RIB,DetailRange),
SCRIPTMETHOD(RIB,GeometricApproximation),
SCRIPTMETHOD(RIB,GeometicRepesentation),
SCRIPTMETHOD(RIB,Orientation),
SCRIPTMETHOD(RIB,Sides),
SCRIPTMETHOD(RIB,Identity),
SCRIPTMETHOD(RIB,Transform),
SCRIPTMETHOD(RIB,Perspective),
SCRIPTMETHOD(RIB,Translate),
SCRIPTMETHOD(RIB,Rotate),
SCRIPTMETHOD(RIB,Scale),
SCRIPTMETHOD(RIB,Skew),
SCRIPTMETHOD(RIB,Deformation),
SCRIPTMETHOD(RIB,Displacement),
SCRIPTMETHOD(RIB,CoordinateSystem),
SCRIPTMETHOD(RIB,CoordSysTransform),
SCRIPTMETHOD(RIB,TransformBegin),
SCRIPTMETHOD(RIB,TransformEnd),
SCRIPTMETHOD(RIB,Attribute),
SCRIPTMETHOD(RIB,Polygon),
SCRIPTMETHOD(RIB,GeneralPolygon),
SCRIPTMETHOD(RIB,PointsPolygons),
SCRIPTMETHOD(RIB,PointsGeneralPolygons),
SCRIPTMETHOD(RIB,Basis),
SCRIPTMETHOD(RIB,Patch),
SCRIPTMETHOD(RIB,PatchMesh),
SCRIPTMETHOD(RIB,NuPatch),
SCRIPTMETHOD(RIB,TrimCurve),
SCRIPTMETHOD(RIB,Sphere),
SCRIPTMETHOD(RIB,Cone),
SCRIPTMETHOD(RIB,Cylinder),
SCRIPTMETHOD(RIB,Hyperboloid),
SCRIPTMETHOD(RIB,Disk),
SCRIPTMETHOD(RIB,Torus),
SCRIPTMETHOD(RIB,Curves),
SCRIPTMETHOD(RIB,Procedural),
SCRIPTMETHOD(RIB,Geometry),
SCRIPTMETHOD(RIB,Points),
SCRIPTMETHOD(RIB,SubdivisionMesh),
SCRIPTMETHOD(RIB,Blobby),
SCRIPTMETHOD(RIB,ProcDelayedReadArchive),
SCRIPTMETHOD(RIB,ProcRunProgram),
SCRIPTMETHOD(RIB,ProcDynamicLoad),
SCRIPTMETHOD(RIB,ProcFree),
SCRIPTMETHOD(RIB,SolidBegin),
SCRIPTMETHOD(RIB,Objectbegin),
SCRIPTMETHOD(RIB,ObjectEnd),
SCRIPTMETHOD(RIB,ObjectInstance),
SCRIPTMETHOD(RIB,MotionBegin),
SCRIPTMETHOD(RIB,MotionEnd),
SCRIPTMETHOD(RIB,MakeTexture),
SCRIPTMETHOD(RIB,MakeBump),
SCRIPTMETHOD(RIB,MakeLatLongEnvironment),
SCRIPTMETHOD(RIB,MakeCubeFaceEnvironment),
SCRIPTMETHOD(RIB,MakeShadow),
SCRIPTMETHOD(RIB,ArchiveRead),
SCRIPTMETHOD(RIB,ReadArchive),
SCRIPTMETHOD(RIB,Trace),
SCRIPTMETHOD(RIB,TraceEx),
SCRIPTMETHOD(RIB,Visibility),

      SCRIPTMETHOD(RIB,Comment),
      SCRIPTMETHOD(RIB,Hint),
      SCRIPTMETHOD(RIB,togglePrettyPrint),
      { 0,0 }};
}
