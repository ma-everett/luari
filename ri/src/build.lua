#! /usr/bin/env lua
-- build functions/classes
-- version 0.1
-- mae
-- 30-01-07

local funs = { }
local version = "0.1 for RI Spec 3.2"

local FUNC = { }

function FUNC:New( o )

	o = o or {c_name= nil,    		-- c function name
		  ri_name= nil,
		  rib_name= nil,  		-- rib output name
		  rib_out= nil,
		  comment= nil,
		  argsf= nil,
		  tab_increase= false, 		-- pretty tabbing of output
		  tab_descrease= false}		-- pretty tabbing of output

	setmetatable(o,self)
	self.__index= self

	return o
end

function FUNC:Out( f )

	if f == nil then 
		return -- no output stream!
	end

	-- write the comment first
	if self.ri_name ~= nil then
		f:write("/* " .. self.ri_name .. "( ... )\n")
		
		if self.comment ~= nil then
			f:write(" * " .. self.comment .. "\n")			
		end
	
		f:write(" */\n")
	end

	if self.c_name == nil then
		return -- nothing to write - just an empty comment block!
	end

	-- write the return type on seperate line
	f:write("int_t\n")
	
	-- write the c name
	f:write(self.c_name .. "( lua_State *L ) {\n\n")
	
	if self.tab_descrease == true then
		f:write("pretty_tab_descrease(L);\n\n")
	end

	f:write("pretty_tab(L);\n")
	
	local name = self.rib_out
	local tail = "NULL"
	
	f:write("print_name(L,\"" .. name .. "\");\n")

	if self.argsf == true then
		f:write("print_args_f(L," .. tail .. ");\n\n")
	else
		f:write("print_args(L," .. tail ..");\n\n")
	end

	if self.tab_increase == true then
		f:write("pretty_tab_increase(L);\n\n")
	end
	
	f:write("return 0;\n}\n\n")
end

function FUNC:Out_proto( f )

	if f == nil then
		return 
	end

	if self.c_name == nil then
		return
	end

	f:write("int_t " .. self.c_name .. "( lua_State *L );\n")
	
end

function FUNC:Out_table( f )

	if f == nil then
		return
	end

	f:write("{\"" .. self.rib_name .. "\"," .. self.c_name .. "},\n")
end 

-- ob = {name="func",rib="func",comment="",stack="same" | "up" | "down"}
function lfunc( ob )

	local f = FUNC:New( nil )
		
	f.c_name = "l_Ri" .. ob.name
	f.ri_name =  "Ri" .. ob.name
	
	f.rib_name = ob.name
	f.rib_out = ob.rib or ob.name
	f.argsf = ob.argsf or true
	f.comment = ob.comment or ""

	if ob.stack ~= nil then	

		if ob.stack == "up" then
			f.tab_increase = true
		end

		if ob.stack == "down" then
			f.tab_descrease = true
		end
	end

	-- add to global funs
	funs[ #funs + 1 ] = f	
end	


function print_h_header( f )

	f:write("#ifndef " .. arg[2] .. "_h\n")
	f:write("#define " .. arg[2] .. "_h 1\n\n")
	f:write("#include <lua.h>\n")
	f:write("#include <lualib.h>\n")
	f:write("#include \"typedefs.h\"\n\n")
end

function print_h_footer( f )

	f:write("\n#endif /* " .. arg[2] .. "_h */\n")
end

function print_c_header( f )

	f:write("#include \"prettyprint.h\"\n")
end


print("lua -> c function constructor version " .. version )

		
dofile( arg[1] )

-- print some stastics :
print( "Added " .. #funs .. " lua -> c functions from " .. arg[1]) 


-- output to c file :
local fc = io.open( arg[2] .. ".c", "w" )
local fh = io.open( arg[2] .. ".h", "w" )

if fc == nil then
	print("unable to open file " .. arg[2] .. ".c " .. "for writing!")
	return false
end

print_c_header( fc )

if fh == nil then
	print("unable to open file " .. arg[2] .. ".h " .. "for writing!")
	return false
end

print_h_header( fh )

for i = 1, #funs do

	funs[ i ]:Out_proto( fh )
	funs[ i ]:Out( fc )
end

-- write the lua->c table
fh:write("\nstatic const struct luaL_Reg ril_m[] = {\n")

for i = 1, #funs do

	funs[ i ]:Out_table( fh )
end

fh:write("{NULL,NULL}\n};\n") 

print_h_footer( fh )

fc:close( )
fh:close( )