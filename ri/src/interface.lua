
-- interface.lua
-- constructs the RI SPEC subset as stated below
-- into c source code ready for compiling

-- structure:
--[[ lfun {name=<string> : name of function in the interface,
	 rib=<string> : defaults to name, else is the output (see Comment below as an example)
	 comment=<string> : extra comment in the generated c code
	 argsf=<boolean> : deteremines the type of arguments passed to output
	 stack=<string> "up"|"down" : for pretty tabbing in the output file
	 }
--]]


lfunc{name="Comment",rib="#",comment="NOT apart of RI spec 3.2",argsf=false}
lfunc{name="Hint",rib="##",comment="NOT apart of RI spec 3.2",argsf=false}

lfunc{name="Declare"}

lfunc{name="FrameBegin",stack="up"}
lfunc{name="FrameEnd",stack="down"}
lfunc{name="WorldBegin",stack="up"}
lfunc{name="WorldEnd",stack="down"}

lfunc{name="Format"}
lfunc{name="FrameAspectRatio"}
lfunc{name="ScreenWindow"}
lfunc{name="CropWindow"}
lfunc{name="Projection"}
lfunc{name="Clipping"}
lfunc{name="ClippingPlane"}
lfunc{name="DepthOfField"}
lfunc{name="Shutter"}

lfunc{name="PixelVariance"}
lfunc{name="PixelSamples"}
lfunc{name="PixelFilter"}
lfunc{name="Exposure"}
lfunc{name="Imager"}
lfunc{name="Quantize"}
lfunc{name="Display"}

lfunc{name="Hider"}
lfunc{name="ColorSamples"}
lfunc{name="RelativeDetail"}
lfunc{name="Option"}

lfunc{name="AttributeBegin", stack="up"}
lfunc{name="AttributeEnd", stack="down"}
lfunc{name="Color"}
lfunc{name="Opacity"}
lfunc{name="TextureCoordinates"}

lfunc{name="LightSource"}
lfunc{name="AreaLightSource"}

lfunc{name="Illuminate"}
lfunc{name="Surface"}
lfunc{name="Atmosphere"}
lfunc{name="Interior"}
lfunc{name="Exterior"}
lfunc{name="ShadingRate"}
lfunc{name="ShadingInterpolation"}
lfunc{name="Matte"}

lfunc{name="Bound"}
lfunc{name="DetailRange"}
lfunc{name="GeometricApproximation"}
lfunc{name="GeometicRepesentation"}
lfunc{name="Orientation"}
lfunc{name="Sides"}

lfunc{name="Identity"}
lfunc{name="Transform"}
lfunc{name="Perspective"}
lfunc{name="Translate"}
lfunc{name="Rotate"}
lfunc{name="Scale"}
lfunc{name="Skew"}
lfunc{name="Deformation"}
lfunc{name="Displacement"}
lfunc{name="CoordinateSystem"}
lfunc{name="CoordSysTransform"}

lfunc{name="TransformBegin",stack="up"}
lfunc{name="TransformEnd",stack="down"}

lfunc{name="Attribute"}

lfunc{name="Polygon"}
lfunc{name="GeneralPolygon"}
lfunc{name="PointsPolygons"}
lfunc{name="PointsGeneralPolygons"}
lfunc{name="Basis"}
lfunc{name="Patch"}
lfunc{name="PatchMesh"}
lfunc{name="NuPatch"}
lfunc{name="TrimCurve"}

lfunc{name="Sphere"}
lfunc{name="Cone"}
lfunc{name="Cylinder"}
lfunc{name="Hyperboloid"}
lfunc{name="Disk"}
lfunc{name="Torus"}
lfunc{name="Curves"}
lfunc{name="Procedural"}
lfunc{name="Geometry"}

lfunc{name="Points"}
lfunc{name="SubdivisionMesh"}
lfunc{name="Blobby"}

lfunc{name="ProcDelayedReadArchive"}
lfunc{name="ProcRunProgram"}
lfunc{name="ProcDynamicLoad"}

lfunc{name="ProcFree"}
lfunc{name="SolidBegin", stack="up"}
lfunc{name="Objectbegin", stack="up"}

lfunc{name="ObjectEnd", stack="down"}
lfunc{name="ObjectInstance"}

lfunc{name="MotionBegin", stack="up"}
lfunc{name="MotionEnd", stack="down"}

lfunc{name="MakeTexture"}
lfunc{name="MakeBump"}
lfunc{name="MakeLatLongEnvironment"}
lfunc{name="MakeCubeFaceEnvironment"}
lfunc{name="MakeShadow"}

lfunc{name="ArchiveRead"}
lfunc{name="ReadArchive"}

lfunc{name="Trace"}
lfunc{name="TraceEx"}
lfunc{name="Visibility"}










