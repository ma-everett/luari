-- grt ri
-- gen-interface.lua

-- generate interface code

-- arg[1] should be the interface file
-- arg[2] should be the src file location

local funs = { }

local Func = { }

function Func:new( o )

	o = 	o or {  name= nil,
			comment= nil,
			pp = {	tab_i= false,
				tab_d= false }
			}

	setmetatable(o,self)
	self.__index= self

	return o
end

function Func:source( )

	-- comment block
	local s = "/* " .. self.name .. "( ... )\n"
	if self.comment ~= nil then s = s .. " * " .. self.comment .. "\n" end
	s = s .. " */\n"

	-- function decalaration
	s = s .. "int \nRIB::" .. self.name .. "( lua_State * L )\n{\n"
		
	if self.pp.tab_d then s = s .. "\t_tabs--;\n" end

	s = s .. "\tformat(\"" .. self.name .. "\",L);\n"

	if self.pp.tab_i then s = s .. "\t_tabs++;\n" end

	s = s .. "\treturn 0;\n"
	s = s .. "}\n\n"

	return s
end



function Func:proto( )

	return "int " .. self.name .. "( lua_State *L );\n\t"
end

function Func:method( )

	return "SCRIPTMETHOD(RIB," .. self.name .. "),\n"
end


function lfunc( ob )

	local f = Func:new( nil )
	
	f.name = ob.name or nil
	f.comment = ob.comment or nil

	if ob.stack ~= nil then
		if ob.stack == "up" then f.pp.tab_i = true end
		if ob.stack == "down" then f.pp.tab_d = true end
	end

	funs[ #funs + 1 ] = f
end


-- basically we copy the template file and insert the required interface functions

-- HEADER TEMPLATE FILE:
local h_copy = io.open( arg[3] .. ".h", "r" ) -- this should be ./interface/rib-template.h
local header = h_copy:read("*all")
h_copy:close( )

-- SOURCE TEMPLATE FILE:
local cpp_copy = io.open( arg[3] .. ".cpp", "r" )
local source = cpp_copy:read("*all")
cpp_copy:close( )


dofile( arg[1] )

local header_functions = ""
local source_functions = ""
local source_methods = ""

for op = 1, #funs do
	
	header_functions = header_functions .. funs[op]:proto( )
	source_functions = source_functions .. funs[op]:source( )
	source_methods = source_methods .. funs[op]:method( )
end 


-- do string replacement here
header = string.gsub(header,"<FUNCTIONS>", header_functions)
source = string.gsub(source,"<FUNCTIONS>", source_functions)
source = string.gsub(source,"<METHODS>", source_methods)

-- WRITE NEW HEADER FILE
local fh = io.open( arg[2] .. ".h", "w" ) -- this should be something like ./src/rib.h
fh:write(header)
fh:close( )

-- WRITE NEW SOURCE FILE
local fs = io.open( arg[2] .. ".cpp","w" )
fs:write(source)
fs:close( )
