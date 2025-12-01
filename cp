if getgenv().SimpleSpyExecuted and type(getgenv().SimpleSpyShutdown)=="function"then getgenv().SimpleSpyShutdown()end
local function blank(...)return...end

local a={
logcheckcaller=false,
autoblock=true,
funcEnabled=true,
advancedinfo=false,

supersecretdevtoggle=false
}

local b=newproxy(true)
local c=getmetatable(b)

c.__index=function(d,e)return a[e]end

local d=syn and syn.oth
local e=d and d.unhook
local f=d and d.hook

local g=string.lower
local h=string.byte local i=
math.round
local j=coroutine.running
local k=coroutine.resume
local l=coroutine.status
local m=coroutine.yield
local n=coroutine.create
local o=coroutine.close
local p=game.GetDebugId
local q=debug.info

local r=game.IsA
local s=tostring

local t=task.delay
local u=task.spawn
local v=table.clear local w=
table.clone local x=

(syn and syn.get_thread_identity)or getidentity or getthreadidentity local y=
(syn and syn.set_thread_identity)or setidentity
local z=islclosure or is_l_closure


local A=getinfo or blank
local B=getupvalues or debug.getupvalues or blank
local C=getconstants or debug.getconstants or blank


local D=getcallingscript or blank
local E=newcclosure or blank
local F=clonefunction or blank
local G=cloneref or blank local H=
request or syn and syn.request
local I=makewriteable or function(I)setreadonly(I,false)end
local J=makereadonly or function(J)setreadonly(J,true)end
local K=isreadonly or table.isfrozen
local L=setclipboard or toclipboard or set_clipboard or(Clipboard and Clipboard.set)or function(...)return ErrorPrompt("Attempted to set clipboard: "..(...),true)end

local M=hookmetamethod or(makewriteable and J and getrawmetatable)and function(M:object,N:string,O:Function)
local P=getrawmetatable(M)

if hookfunction then return hookfunction(P[N],O)else
local Q=P[N]
makewriteable(P)
P[N]=O
J(P)
return Q
end
end

local function Create(N,O,P)
local Q=Instance.new(N)

for R,S in next,O or{}do
Q[R]=S
for T,U in next,P or{}do U.Parent=Q end
end

return Q
end

local function SafeGetService(N)return G(game:GetService(N))end






local function IsCyclicTable(N)
local O={}

local function SearchTable(P)
table.insert(O,P)
for Q,R in next,P do if type(R)=="table"then return table.find(O,R)and true or SearchTable(R)end end
end

return SearchTable(N)
end

local function deepclone(N:table,O:table)
local P
O=O or{}

if type(N)=='table'then
if O[N]then P=O[N]else
P={}
O[N]=P
for Q,R in next,N do P[deepclone(Q,O)]=deepclone(R,O)end
end
elseif typeof(N)=="Instance"then P=G(N)else P=N end
return P
end

local function rawtostring(N)
if type(N)=="table"or typeof(N)=="userdata"then
local O=getrawmetatable(N)
local P=O and rawget(O,"__tostring")

if P then
local Q=K(O)
if Q then I(O)end
rawset(O,"__tostring",nil)
local R=s(N)
rawset(O,"__tostring",P)
if Q then J(O)end
return R
end
end
return s(N)
end

local N=SafeGetService"CoreGui"
local O=SafeGetService"Players"
local P=SafeGetService"RunService"
local Q=SafeGetService"UserInputService"
local R=SafeGetService"TweenService"
SafeGetService"ContentProvider"
local S=SafeGetService"TextService"
local T=SafeGetService"HttpService"
local U=game:GetService"GuiService":GetGuiInset()::Vector2

local function jsone(V)return T:JSONEncode(V)end
local function jsond(V)
local W,X=pcall(T.JSONDecode,T,V)
return W and X or W
end

function ErrorPrompt(V,W)
if getrenv then
local X=getrenv().require(N:WaitForChild"RobloxGui":WaitForChild"Modules":WaitForChild"ErrorPrompt")
local Y=X.new("Default",{HideErrorCode=true})
local Z=Create("ScreenGui",{Parent=N,ResetOnSpawn=false})
local _=W and j()
Y:setParent(Z)
Y:setErrorTitle"Simple Spy V3 Error"
Y:updateButtons({{
Text="Proceed",
Callback=function()
Y:_close()
Z:Destroy()
if _ then k(_)end
end,
Primary=true
}},'Default')
Y:_open(V)
if _ then m(_)end
else
warn(V)
end
end

local V=(isfile and loadfile and isfile"Highlight.lua"and loadfile"Highlight.lua"())or loadstring(game:HttpGet"https://raw.githubusercontent.com/78n/SimpleSpy/main/Highlight.lua")()
local W=loadstring(game:HttpGet"https://raw.githubusercontent.com/78n/Roblox/refs/heads/main/Lua/Libraries/DataToCode/DataToCode.luau")()

local X=Create("ScreenGui",{ResetOnSpawn=false})
local Y=Create("Folder",{})
local Z=Create("Frame",{Parent=X,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,500,0,200),Size=UDim2.new(0,450,0,268)})
local _=Create("Frame",{Parent=Z,BackgroundColor3=Color3.fromRGB(53,52,55),BorderSizePixel=0,Position=UDim2.new(0,0,0,19),Size=UDim2.new(0,131,0,249)})
local aa=Create("ScrollingFrame",{Parent=_,Active=true,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,BorderSizePixel=0,Position=UDim2.new(0,0,0,9),Size=UDim2.new(0,131,0,232),CanvasSize=UDim2.new(0,0,0,0),ScrollBarThickness=4})
local ab=Create("UIListLayout",{Parent=aa,HorizontalAlignment=Enum.HorizontalAlignment.Center,SortOrder=Enum.SortOrder.LayoutOrder})
local ac=Create("Frame",{Parent=Z,BackgroundColor3=Color3.fromRGB(37,36,38),BorderSizePixel=0,Position=UDim2.new(0,131,0,19),Size=UDim2.new(0,319,0,249)})
local ad=Create("Frame",{Parent=ac,BackgroundColor3=Color3.new(0.0823529,0.0745098,0.0784314),BorderSizePixel=0,Size=UDim2.new(0,319,0,119)})
local ae=Create("ScrollingFrame",{Parent=ac,Active=true,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,0,0.5,0),Size=UDim2.new(1,0,0.5,-9),CanvasSize=UDim2.new(0,0,0,0),ScrollBarThickness=4})
local af=Create("UIGridLayout",{Parent=ae,HorizontalAlignment=Enum.HorizontalAlignment.Center,SortOrder=Enum.SortOrder.LayoutOrder,CellPadding=UDim2.new(0,0,0,0),CellSize=UDim2.new(0,94,0,27)})
local ag=Create("Frame",{Parent=Z,BackgroundColor3=Color3.fromRGB(37,35,38),BorderSizePixel=0,Size=UDim2.new(0,450,0,19)})
local ah=Create("TextButton",{Parent=ag,BackgroundColor3=Color3.new(1,1,1),AutoButtonColor=false,BackgroundTransparency=1,Position=UDim2.new(0,5,0,0),Size=UDim2.new(0,57,0,18),Font=Enum.Font.SourceSansBold,Text="Simple Spy",TextColor3=Color3.new(1,1,1),TextSize=14,TextXAlignment=Enum.TextXAlignment.Left})
local ai=Create("TextButton",{Parent=ag,BackgroundColor3=Color3.new(0.145098,0.141176,0.14902),BorderSizePixel=0,Position=UDim2.new(1,-19,0,0),Size=UDim2.new(0,19,0,19),Font=Enum.Font.SourceSans,Text="",TextColor3=Color3.new(0,0,0),TextSize=14})
Create("ImageLabel",{Parent=ai,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,5,0,5),Size=UDim2.new(0,9,0,9),Image="http://www.roblox.com/asset/?id=5597086202"})
local aj=Create("TextButton",{Parent=ag,BackgroundColor3=Color3.new(0.145098,0.141176,0.14902),BorderSizePixel=0,Position=UDim2.new(1,-38,0,0),Size=UDim2.new(0,19,0,19),Font=Enum.Font.SourceSans,Text="",TextColor3=Color3.new(0,0,0),TextSize=14})
Create("ImageLabel",{Parent=aj,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,5,0,5),Size=UDim2.new(0,9,0,9),Image="http://www.roblox.com/asset/?id=5597108117"})
local ak=Create("TextButton",{Parent=ag,BackgroundColor3=Color3.new(0.145098,0.141176,0.14902),BorderSizePixel=0,Position=UDim2.new(1,-57,0,0),Size=UDim2.new(0,19,0,19),Font=Enum.Font.SourceSans,Text="",TextColor3=Color3.new(0,0,0),TextSize=14})
Create("ImageLabel",{Parent=ak,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,5,0,5),Size=UDim2.new(0,9,0,9),Image="http://www.roblox.com/asset/?id=5597105827"})

local al=Create("Frame",{Parent=X,BackgroundColor3=Color3.fromRGB(26,26,26),BackgroundTransparency=0.1,BorderColor3=Color3.new(1,1,1),Size=UDim2.new(0,200,0,50),ZIndex=3,Visible=false})
local am=Create("TextLabel",{Parent=al,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,2,0,2),Size=UDim2.new(0,196,0,46),ZIndex=3,Font=Enum.Font.SourceSans,Text="This is some slightly longer text.",TextColor3=Color3.new(1,1,1),TextSize=14,TextWrapped=true,TextXAlignment=Enum.TextXAlignment.Left,TextYAlignment=Enum.TextYAlignment.Top})

Color3.new(0.321569,0.333333,1)
Color3.new(0.8,0.8,0.8)

local an=999999999
local ao=false
local ap=false
local aq=false
local ar=false
local as=false
local at={}

local au
local av={}
local aw={}




local ax=false
local ay={}
local az={}

getgenv().SIMPLESPYCONFIG_MaxRemotes=300
local aA=4
local aB={}
local aC
local aD={}
local aE=""
local aF=""
local aG
local aH
local aI
local aJ
local aK=false

local aL={}
local aM={}

local aN=false

local aO={}
local aP={}
local aQ={}
local aR={}
local aS

local aT=Instance.new("RemoteEvent",Y)
local aU=Instance.new"UnreliableRemoteEvent"
local aV=Instance.new("RemoteFunction",Y)
Instance.new("BindableEvent",Y)
Instance.new("BindableEvent",Y)
local aW=Instance.new("BindableFunction",Y)

local aX=aT.FireServer
local aY=aU.FireServer
local aZ=aV.InvokeServer
local a_=aW.Invoke

function aW.OnInvoke(a0:Instance)return p(a0)end
local function ThreadGetDebugId(a0:Instance)
return a_(aW,a0)
end

local a0=false

if syn and identifyexecutor then
local a1,a2=identifyexecutor()
if(a2 and a2:sub(1,2)=='v3')then a0=true end
if a1=="Solara"or a1=="JJSploit"or a1=="Xeno"then
ErrorPrompt"Executor too weak"
end
end

xpcall(function()
if isfile and readfile and isfolder and makefolder then
local a1=isfile"SimpleSpy//Settings.json"and jsond(readfile"SimpleSpy//Settings.json")

if a1 then
for a2,a3 in next,a do if a1[a2]==nil then a1[a2]=a3 end end
a=a1
end

if not isfolder"SimpleSpy"then makefolder"SimpleSpy"end
if not isfolder"SimpleSpy//Assets"then makefolder"SimpleSpy//Assets"end
if not isfile"SimpleSpy//Settings.json"then writefile("SimpleSpy//Settings.json",jsone(a))end

c.__newindex=function(a2,a3,a4)
a[a3]=a4
writefile("SimpleSpy//Settings.json",jsone(a))
end
else
c.__newindex=function(a1,a2,a3)a[a2]=a3 end
end
end,function(a1)ErrorPrompt(("An error has occured: (%s)"):format(a1))end)
local function logthread(a1:thread)table.insert(aR,a1)end

function clean()
local a1=getgenv().SIMPLESPYCONFIG_MaxRemotes
if not typeof(a1)=="number"and math.floor(a1)~=a1 then
a1=500
end
if#az>a1 then
for a2=100,#az do
local a3=az[a2]
if typeof(a3[1])=="RBXScriptConnection"then
a3[1]:Disconnect()
end
if typeof(a3[2])=="Instance"then
a3[2]:Destroy()
end
end
local a2={}
for a3=1,100 do
table.insert(a2,az[a3])
end
az=a2
end
end

local function ThreadIsNotDead(a1:thread)
return not l(a1)=="dead"
end


function scaleToolTip()
local a1=S:GetTextSize(am.Text,am.TextSize,am.Font,Vector2.new(196,math.huge))
am.Size=UDim2.new(0,a1.X,0,a1.Y)
al.Size=UDim2.new(0,a1.X+4,0,a1.Y+4)
end


function onToggleButtonHover()
if not ax then
R:Create(ah,TweenInfo.new(0.5),{TextColor3=Color3.fromRGB(252,51,51)}):Play()
else
R:Create(ah,TweenInfo.new(0.5),{TextColor3=Color3.fromRGB(68,206,91)}):Play()
end
end


function onToggleButtonUnhover()
R:Create(ah,TweenInfo.new(0.5),{TextColor3=Color3.fromRGB(255,255,255)}):Play()
end


function onXButtonHover()
R:Create(ai,TweenInfo.new(0.2),{BackgroundColor3=Color3.fromRGB(255,60,60)}):Play()
end


function onXButtonUnhover()
R:Create(ai,TweenInfo.new(0.2),{BackgroundColor3=Color3.fromRGB(37,36,38)}):Play()
end



function onToggleButtonClick()
if ax then
R:Create(ah,TweenInfo.new(0.5),{TextColor3=Color3.fromRGB(252,51,51)}):Play()
else
R:Create(ah,TweenInfo.new(0.5),{TextColor3=Color3.fromRGB(68,206,91)}):Play()
end
toggleSpyMethod()
end


function connectResize()
if not workspace.CurrentCamera then
workspace:GetPropertyChangedSignal"CurrentCamera":Wait()
end
local a1=workspace.CurrentCamera:GetPropertyChangedSignal"ViewportSize":Connect(bringBackOnResize)
workspace:GetPropertyChangedSignal"CurrentCamera":Connect(function()
a1:Disconnect()
if typeof(a1)=='Connection'then
a1:Disconnect()
end
a1=workspace.CurrentCamera:GetPropertyChangedSignal"ViewportSize":Connect(bringBackOnResize)
end)
end


function bringBackOnResize()
validateSize()
if ar then
minimizeSize()
else
maximizeSize()
end
local a1=Z.AbsolutePosition.X
local a2=Z.AbsolutePosition.Y
local a3=workspace.CurrentCamera.ViewportSize
if(a1<0)or(a1>(a3.X-(ar and 131 or Z.AbsoluteSize.X)))then
if a1<0 then
a1=0
else
a1=a3.X-(ar and 131 or Z.AbsoluteSize.X)
end
end
if(a2<0)or(a2>(a3.Y-(ap and 19 or Z.AbsoluteSize.Y)-U.Y))then
if a2<0 then
a2=0
else
a2=a3.Y-(ap and 19 or Z.AbsoluteSize.Y)-U.Y
end
end
R.Create(R,Z,TweenInfo.new(0.1),{Position=UDim2.new(0,a1,0,a2)}):Play()
end



function onBarInput(a1)
if a1.UserInputType==Enum.UserInputType.MouseButton1 or a1.UserInputType==Enum.UserInputType.Touch then
local a2=Q:GetMouseLocation()
local a3=Z.AbsolutePosition
local a4=a3-a2
local a5=a4+a2
if not aO.drag then
aO.drag=P.RenderStepped:Connect(function()
local a6=Q:GetMouseLocation()
if a6~=a2 then
local a7=(a4+a6).X
local a8=(a4+a6).Y
local a9=workspace.CurrentCamera.ViewportSize
if(a7<0 and a7<a5.X)or(a7>(a9.X-(ar and 131 or ag.AbsoluteSize.X))and a7>a5.X)then
if a7<0 then
a7=0
else
a7=a9.X-(ar and 131 or ag.AbsoluteSize.X)
end
end
if(a8<0 and a8<a5.Y)or(a8>(a9.Y-(ap and 19 or Z.AbsoluteSize.Y)-U.Y)and a8>a5.Y)then
if a8<0 then
a8=0
else
a8=a9.Y-(ap and 19 or Z.AbsoluteSize.Y)-U.Y
end
end
a5=Vector2.new(a7,a8)
a2=a6
R.Create(R,Z,TweenInfo.new(0.1),{Position=UDim2.new(0,a5.X,0,a5.Y)}):Play()
end



end)
end
table.insert(aO,Q.InputEnded:Connect(function(a6)
if a1==a6 then
if aO.drag then
aO.drag:Disconnect()
aO.drag=nil
end
end
end))
end
end


function fadeOut(a1)
local a2={}
for a3,a4 in next,a1 do
if typeof(a4)=="Instance"and a4:IsA"GuiObject"and a4.Visible then
u(function()
a2[a4]={
BackgroundTransparency=a4.BackgroundTransparency
}
R:Create(a4,TweenInfo.new(0.5),{BackgroundTransparency=1}):Play()
if a4:IsA"TextBox"or a4:IsA"TextButton"or a4:IsA"TextLabel"then
a2[a4].TextTransparency=a4.TextTransparency
R:Create(a4,TweenInfo.new(0.5),{TextTransparency=1}):Play()
elseif a4:IsA"ImageButton"or a4:IsA"ImageLabel"then
a2[a4].ImageTransparency=a4.ImageTransparency
R:Create(a4,TweenInfo.new(0.5),{ImageTransparency=1}):Play()
end
t(0.5,function()
a4.Visible=false
for a5,a6 in next,a2[a4]do
a4[a5]=a6
end
a2[a4]=true
end)
end)
end
end
return function()
for a3,a4 in next,a2 do
u(function()
local a5={
BackgroundTransparency=a3.BackgroundTransparency
}
a3.BackgroundTransparency=1
R:Create(a3,TweenInfo.new(0.5),{BackgroundTransparency=a5.BackgroundTransparency}):Play()
if a3:IsA"TextBox"or a3:IsA"TextButton"or a3:IsA"TextLabel"then
a5.TextTransparency=a3.TextTransparency
a3.TextTransparency=1
R:Create(a3,TweenInfo.new(0.5),{TextTransparency=a5.TextTransparency}):Play()
elseif a3:IsA"ImageButton"or a3:IsA"ImageLabel"then
a5.ImageTransparency=a3.ImageTransparency
a3.ImageTransparency=1
R:Create(a3,TweenInfo.new(0.5),{ImageTransparency=a5.ImageTransparency}):Play()
end
a3.Visible=true
end)
end
end
end


function toggleMinimize(a1)
if ao and not a1 or as then
return
end
ao=true
ap=not ap
if ap then
if not ar then
toggleSideTray(true)
end
_.Visible=true
aG=fadeOut(_:GetDescendants())
R:Create(_,TweenInfo.new(0.5),{Size=UDim2.new(0,131,0,0)}):Play()
wait(0.5)
else
R:Create(_,TweenInfo.new(0.5),{Size=UDim2.new(0,131,0,249)}):Play()
wait(0.5)
if aG then
aG()
aG=nil
end
bringBackOnResize()
end
ao=false
end


function toggleSideTray(a1)
if aq and not a1 or as then
return
end
aq=true
ar=not ar
if ar then
aH=fadeOut(ac:GetDescendants())
wait(0.5)
minimizeSize(0.5)
wait(0.5)
ac.Visible=false
else
if ap then
toggleMinimize(true)
end
ac.Visible=true
maximizeSize(0.5)
wait(0.5)
if aH then
aH()
end
bringBackOnResize()
end
aq=false
end


function toggleMaximize()
if not ar and not as then
as=true
local a1=Instance.new"TextButton"
local a2=UDim2.new(0,ad.AbsoluteSize.X,0,ad.AbsoluteSize.Y)
local a3=UDim2.new(0,ad.AbsolutePosition.X,0,ad.AbsolutePosition.Y)
a1.Size=UDim2.new(1,0,1,0)
a1.BackgroundColor3=Color3.new()
a1.BorderSizePixel=0
a1.Text=0
a1.ZIndex=3
a1.BackgroundTransparency=1
a1.AutoButtonColor=false
ad.ZIndex=4
ad.Position=a3
ad.Size=a2
R:Create(ad,TweenInfo.new(0.5),{Size=UDim2.new(0.5,0,0.5,0),Position=UDim2.new(0.25,0,0.25,0)}):Play()
R:Create(a1,TweenInfo.new(0.5),{BackgroundTransparency=0.5}):Play()
a1.MouseButton1Click:Connect(function()
if Q:GetMouseLocation().Y+U.Y>=ad.AbsolutePosition.Y and Q:GetMouseLocation().Y+U.Y<=ad.AbsolutePosition.Y+ad.AbsoluteSize.Y and Q:GetMouseLocation().X>=ad.AbsolutePosition.X and Q:GetMouseLocation().X<=ad.AbsolutePosition.X+ad.AbsoluteSize.X then
return
end
R:Create(ad,TweenInfo.new(0.5),{Size=a2,Position=a3}):Play()
R:Create(a1,TweenInfo.new(0.5),{BackgroundTransparency=1}):Play()
wait(0.5)
a1:Destroy()
ad.Size=UDim2.new(1,0,0.5,0)
ad.Position=UDim2.new(0,0,0,0)
ad.ZIndex=0
as=false
end)
end
end



function isInResizeRange(a1)
local a2=a1-Z.AbsolutePosition
local a3=5
if a2.X>=ag.AbsoluteSize.X-a3 and a2.Y>=Z.AbsoluteSize.Y-a3
and a2.X<=ag.AbsoluteSize.X and a2.Y<=Z.AbsoluteSize.Y then
return true,'B'
elseif a2.X>=ag.AbsoluteSize.X-a3 and a2.X<=Z.AbsoluteSize.X then
return true,'X'
elseif a2.Y>=Z.AbsoluteSize.Y-a3 and a2.Y<=Z.AbsoluteSize.Y then
return true,'Y'
end
return false
end



function isInDragRange(a1)
local a2=a1-Z.AbsolutePosition
local a3=ag.AbsoluteSize
return a2.X<=a3.X-ai.AbsoluteSize.X*3 and a2.X>=0 and a2.Y<=a3.Y and a2.Y>=0 or false
end


local a1=Create("ImageLabel",{Parent=X,Visible=false,Size=UDim2.fromOffset(200,200),ZIndex=1e9,BackgroundTransparency=1,Image="",Parent=X})
function mouseEntered()
local a2=aO.SIMPLESPY_CURSOR
if a2 then
a2:Disconnect()
aO.SIMPLESPY_CURSOR=nil
end
aO.SIMPLESPY_CURSOR=P.RenderStepped:Connect(function()
Q.MouseIconEnabled=not aN
a1.Visible=aN
if aN and getgenv().SimpleSpyExecuted then
local a3=Q:GetMouseLocation()-U
a1.Position=UDim2.fromOffset(a3.X-a1.AbsoluteSize.X/2,a3.Y-a1.AbsoluteSize.Y/2)
local a4,a5=isInResizeRange(a3)
if a4 and not ap then
if not ar then
a1.Image=a5=='B'and"rbxassetid://6065821980"or a5=='X'and"rbxassetid://6065821086"or a5=='Y'and"rbxassetid://6065821596"
elseif a5=='Y'or a5=='B'then
a1.Image="rbxassetid://6065821596"
end
elseif a1.Image~="rbxassetid://6065775281"then
a1.Image="rbxassetid://6065775281"
end
else
aO.SIMPLESPY_CURSOR:Disconnect()
end
end)
end


function mouseMoved()
local a2=Q:GetMouseLocation()-U
if not ap
and a2.X>=ag.AbsolutePosition.X and a2.X<=ag.AbsolutePosition.X+ag.AbsoluteSize.X
and a2.Y>=Z.AbsolutePosition.Y and a2.Y<=Z.AbsolutePosition.Y+Z.AbsoluteSize.Y then
if not aN then
aN=true
mouseEntered()
end
else
aN=false
end
end


function maximizeSize(a2)
if not a2 then
a2=0.05
end
R:Create(_,TweenInfo.new(a2),{Size=UDim2.fromOffset(_.AbsoluteSize.X,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y)}):Play()
R:Create(ac,TweenInfo.new(a2),{Size=UDim2.fromOffset(Z.AbsoluteSize.X-_.AbsoluteSize.X,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y)}):Play()
R:Create(ag,TweenInfo.new(a2),{Size=UDim2.fromOffset(Z.AbsoluteSize.X,ag.AbsoluteSize.Y)}):Play()
R:Create(ae,TweenInfo.new(a2),{Size=UDim2.fromOffset(Z.AbsoluteSize.X-_.AbsoluteSize.X,110),Position=UDim2.fromOffset(0,Z.AbsoluteSize.Y-119-ag.AbsoluteSize.Y)}):Play()
R:Create(ad,TweenInfo.new(a2),{Size=UDim2.fromOffset(Z.AbsoluteSize.X-_.AbsoluteSize.X,Z.AbsoluteSize.Y-119-ag.AbsoluteSize.Y)}):Play()
R:Create(aa,TweenInfo.new(a2),{Size=UDim2.fromOffset(aa.AbsoluteSize.X,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y-18)}):Play()
end


function minimizeSize(a2)
if not a2 then
a2=0.05
end
R:Create(_,TweenInfo.new(a2),{Size=UDim2.fromOffset(_.AbsoluteSize.X,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y)}):Play()
R:Create(ac,TweenInfo.new(a2),{Size=UDim2.fromOffset(0,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y)}):Play()
R:Create(ag,TweenInfo.new(a2),{Size=UDim2.fromOffset(_.AbsoluteSize.X,ag.AbsoluteSize.Y)}):Play()
R:Create(ae,TweenInfo.new(a2),{Size=UDim2.fromOffset(0,119),Position=UDim2.fromOffset(0,Z.AbsoluteSize.Y-119-ag.AbsoluteSize.Y)}):Play()
R:Create(ad,TweenInfo.new(a2),{Size=UDim2.fromOffset(0,Z.AbsoluteSize.Y-119-ag.AbsoluteSize.Y)}):Play()
R:Create(aa,TweenInfo.new(a2),{Size=UDim2.fromOffset(aa.AbsoluteSize.X,Z.AbsoluteSize.Y-ag.AbsoluteSize.Y-18)}):Play()
end


function validateSize()
local a2,a3=Z.AbsoluteSize.X,Z.AbsoluteSize.Y
local a4=workspace.CurrentCamera.ViewportSize
if a2+Z.AbsolutePosition.X>a4.X then
if a4.X-Z.AbsolutePosition.X>=450 then
a2=a4.X-Z.AbsolutePosition.X
else
a2=450
end
elseif a3+Z.AbsolutePosition.Y>a4.Y then
if a4.X-Z.AbsolutePosition.Y>=268 then
a3=a4.Y-Z.AbsolutePosition.Y
else
a3=268
end
end
Z.Size=UDim2.fromOffset(a2,a3)
end



function backgroundUserInput(a2)
local a3=Q:GetMouseLocation()-U
local a4,a5=isInResizeRange(a3)
if a2.UserInputType==Enum.UserInputType.MouseButton1 and a4 then
local a6=Q:GetMouseLocation()
local a7=Z.AbsoluteSize-a6
local a8=a6+a7
if not aO.SIMPLESPY_RESIZE then
aO.SIMPLESPY_RESIZE=P.RenderStepped:Connect(function()
local a9=Q:GetMouseLocation()
if a9~=a6 then
local ba=(a9+a7).X
local bb=(a9+a7).Y
if ba<450 then
ba=450
end
if bb<268 then
bb=268
end
a8=Vector2.new(ba,bb)
Z.Size=UDim2.fromOffset((not ar and not ap and(a5=="X"or a5=="B"))and a8.X or Z.AbsoluteSize.X,(not ap and(a5=="Y"or a5=="B"))and a8.Y or Z.AbsoluteSize.Y)
validateSize()
if ar then
minimizeSize()
else
maximizeSize()
end
a6=a9
end
end)
end
table.insert(aO,Q.InputEnded:Connect(function(a9)
if a2==a9 then
if aO.SIMPLESPY_RESIZE then
aO.SIMPLESPY_RESIZE:Disconnect()
aO.SIMPLESPY_RESIZE=nil
end
end
end))
elseif isInDragRange(a3)then
onBarInput(a2)
end
end


function getPlayerFromInstance(a2)
for a3,a4 in next,O:GetPlayers()do
if a4.Character and(a2:IsDescendantOf(a4.Character)or a2==a4.Character)then
return a4
end
end
end


function eventSelect(a2)
if au and au.Log then
if au.Button then
u(function()
R:Create(au.Button,TweenInfo.new(0.5),{BackgroundColor3=Color3.fromRGB(0,0,0)}):Play()
end)
end
au=nil
end
for a3,a4 in next,at do
if a2==a4.Log then
au=a4
end
end
if au and au.Log then
u(function()
R:Create(a2.Button,TweenInfo.new(0.5),{BackgroundColor3=Color3.fromRGB(92,126,229)}):Play()
end)
aI:setRaw(au.GenScript)
end
if ar then
toggleSideTray()
end
end


function updateFunctionCanvas()
ae.CanvasSize=UDim2.fromOffset(af.AbsoluteContentSize.X,af.AbsoluteContentSize.Y)
end


function updateRemoteCanvas()
aa.CanvasSize=UDim2.fromOffset(ab.AbsoluteContentSize.X,ab.AbsoluteContentSize.Y)
end




function makeToolTip(a2,a3)
if a2 and a3 then
if al.Visible then
al.Visible=false
local a4=aO.ToolTip
if a4 then
a4:Disconnect()
end
end
local a4=true
aO.ToolTip=P.RenderStepped:Connect(function()
local a5=Q:GetMouseLocation()
local a6=a5+Vector2.new(20,-15)
local a7=a6+al.AbsoluteSize
local a8=workspace.CurrentCamera.ViewportSize
local a9=a8.X
local ba=a8.Y

if a6.X<0 then
a6=Vector2.new(0,a6.Y)
elseif a7.X>a9 then
a6=Vector2.new(a9-al.AbsoluteSize.X,a6.Y)
end
if a6.Y<0 then
a6=Vector2.new(a6.X,0)
elseif a7.Y>ba-35 then
a6=Vector2.new(a6.X,ba-al.AbsoluteSize.Y-35)
end
if a6.X<=a5.X and a6.Y<=a5.Y then
a6=Vector2.new(a5.X-al.AbsoluteSize.X-2,a5.Y-al.AbsoluteSize.Y-2)
end
if a4 then
al.Position=UDim2.fromOffset(a6.X,a6.Y)
a4=false
else
al:TweenPosition(UDim2.fromOffset(a6.X,a6.Y),"Out","Linear",0.1)
end
end)
am.Text=a3
am.TextScaled=true
al.Visible=true
return
else
if al.Visible then
al.Visible=false
local a4=aO.ToolTip
if a4 then
a4:Disconnect()
end
end
end
end





function newButton(a2,a3,a4)
local a5=Create("Frame",{Name="FunctionTemplate",Parent=ae,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Size=UDim2.new(0,125,0,23)})
Create("Frame",{Name="ColorBar",Parent=a5,BackgroundColor3=Color3.new(1,1,1),BorderSizePixel=0,Position=UDim2.new(0,7,0,10),Size=UDim2.new(0,7,0,18),ZIndex=3})
Create("TextLabel",{Text=a2,Name="Text",Parent=a5,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,19,0,10),Size=UDim2.new(0,69,0,18),ZIndex=2,Font=Enum.Font.SourceSans,TextColor3=Color3.new(1,1,1),TextSize=14,TextStrokeColor3=Color3.new(0.145098,0.141176,0.14902),TextXAlignment=Enum.TextXAlignment.Left})
local a6=Create("TextButton",{Name="Button",Parent=a5,BackgroundColor3=Color3.new(0,0,0),BackgroundTransparency=0.69999998807907,BorderColor3=Color3.new(1,1,1),Position=UDim2.new(0,7,0,10),Size=UDim2.new(0,80,0,18),AutoButtonColor=false,Font=Enum.Font.SourceSans,Text="",TextColor3=Color3.new(0,0,0),TextSize=14})

a6.MouseEnter:Connect(function()
makeToolTip(true,a3())
end)
a6.MouseLeave:Connect(function()
makeToolTip(false)
end)
a5.AncestryChanged:Connect(function()
makeToolTip(false)
end)
a6.MouseButton1Click:Connect(function(...)
logthread(j())
a4(a5,...)
end)
updateFunctionCanvas()
end








function newRemote(a2,a3)
if an<1 then an=999999999 end
local a4=a3.remote
local a5=a3.callingscript

local a6=Create("Frame",{LayoutOrder=an,Name="RemoteTemplate",Parent=aa,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Size=UDim2.new(0,117,0,27)})
Create("Frame",{Name="ColorBar",Parent=a6,BackgroundColor3=(a2=="event"and Color3.fromRGB(255,242,0))or Color3.fromRGB(99,86,245),BorderSizePixel=0,Position=UDim2.new(0,0,0,1),Size=UDim2.new(0,7,0,18),ZIndex=2})
Create("TextLabel",{TextTruncate=Enum.TextTruncate.AtEnd,Name="Text",Parent=a6,BackgroundColor3=Color3.new(1,1,1),BackgroundTransparency=1,Position=UDim2.new(0,12,0,1),Size=UDim2.new(0,105,0,18),ZIndex=2,Font=Enum.Font.SourceSans,Text=a4.Name,TextColor3=Color3.new(1,1,1),TextSize=14,TextXAlignment=Enum.TextXAlignment.Left})
local a7=Create("TextButton",{Name="Button",Parent=a6,BackgroundColor3=Color3.new(0,0,0),BackgroundTransparency=0.75,BorderColor3=Color3.new(1,1,1),Position=UDim2.new(0,0,0,1),Size=UDim2.new(0,117,0,18),AutoButtonColor=false,Font=Enum.Font.SourceSans,Text="",TextColor3=Color3.new(0,0,0),TextSize=14})

local a8={
Name=a4.name,
Function=a3.infofunc or"--Function Info is disabled",
Remote=a4,
DebugId=a3.id,
metamethod=a3.metamethod,
args=a3.args,
Log=a6,
Button=a7,
Blocked=a3.blocked,
Source=a5,
returnvalue=a3.returnvalue,
GenScript="-- Generating, please wait...\n-- (If this message persists, the remote args are likely extremely long)"
}

at[#at+1]=a8
local a9=a7.MouseButton1Click:Connect(function()
logthread(j())
eventSelect(a6)
a8.GenScript=genScript(a8.Remote,a8.args)
if blocked then
a8.GenScript="-- THIS REMOTE WAS PREVENTED FROM FIRING TO THE SERVER BY SIMPLESPY\n\n"..a8.GenScript
end
if au==a8 and a6 then
eventSelect(a6)
end
end)
an-=1
table.insert(az,1,{a9,a6})
clean()
updateRemoteCanvas()
end


function genScript(a2,a3)
ay={}
local a4=""
if#a3>0 then
xpcall(function()
a4="local args = "..W.Convert(a3,true).."\n"
end,function(a5)
a4 ..="-- An error has occured:\n--"..a5 .."\n-- TableToString failure! Reverting to legacy functionality (results may vary)\nlocal args = {"
xpcall(function()
for a6,a7 in next,a3 do
if type(a6)~="Instance"and type(a6)~="userdata"then
a4=a4 .."\n    [object] = "
elseif type(a6)=="string"then
a4=a4 ..'\n    ["'..a6 ..'"] = '
elseif type(a6)=="userdata"and typeof(a6)~="Instance"then
a4=a4 .."\n    ["..string.format("nil --[[%s]]",typeof(a7))..")] = "
elseif type(a6)=="userdata"then
a4=a4 .."\n    [game."..a6:GetFullName()..")] = "
end
if type(a7)~="Instance"and type(a7)~="userdata"then
a4=a4 .."object"
elseif type(a7)=="string"then
a4=a4 ..'"'..a7 ..'"'
elseif type(a7)=="userdata"and typeof(a7)~="Instance"then
a4=a4 ..string.format("nil --[[%s]]",typeof(a7))
elseif type(a7)=="userdata"then
a4=a4 .."game."..a7:GetFullName()
end
end
a4 ..="\n}\n\n"
end,function()
a4 ..="}\n-- Legacy tableToString failure! Unable to decompile."
end)
end)
if not a2:IsDescendantOf(game)and not aK then
a4="function getNil(name,class) for _,v in next, getnilinstances()do if v.ClassName==class and v.Name==name then return v;end end end\n\n"..a4
end
if a2:IsA"RemoteEvent"or a2:IsA"UnreliableRemoteEvent"then
a4 ..=W.ConvertKnown("Instance",a2)..":FireServer(unpack(args))"
elseif a2:IsA"RemoteFunction"then
a4=a4 ..W.ConvertKnown("Instance",a2)..":InvokeServer(unpack(args))"
end
else
if a2:IsA"RemoteEvent"or a2:IsA"UnreliableRemoteEvent"then
a4 ..=W.ConvertKnown("Instance",a2)..":FireServer()"
elseif a2:IsA"RemoteFunction"then
a4 ..=W.ConvertKnown("Instance",a2)..":InvokeServer()"
end
end
ay={}
return a4
end


local a2={
Vector3=(function()
local a2={}
for a3,a4 in Vector3 do
if type(a4)=="vector"then
a2[a4]=string.format("Vector3.%s",a3)
end
end
return a2
end)(),
Vector2=(function()
local a2={}
for a3,a4 in Vector2 do
if type(a4)=="userdata"then
a2[a4]=string.format("Vector2.%s",a3)
end
end
return a2
end)(),
CFrame={
[CFrame.identity]="CFrame.identity"
}
}

local a3={inf=
"math.huge",
["-inf"]="-math.huge",nan=
"0/0"
}

local a4
a4={
TweenInfo=function(a5)
return string.format("TweenInfo.new(%s, %s, %s, %s, %s, %s)",a5.Time,a5.EasingStyle,a5.EasingDirection,a5.RepeatCount,a5.Reverses,a5.DelayTime)
end,
Ray=function(a5)
local a6=a4.Vector3
return string.format("Ray.new(%s, %s)",a6(a5.Origin),a6(a5.Direction))
end,
BrickColor=function(a5)
return string.format("BrickColor.new(%s)",a5.Number)
end,
NumberRange=function(a5)
return string.format("NumberRange.new(%s, %s)",a5.Min,a5.Max)
end,
Region3=function(a5)
local a6=a5.CFrame.Position
local a7=a5.Size/2
local a8=a4.Vector3
return string.format("Region3.new(%s, %s)",a8(a6-a7),a8(a6+a7))
end,
Faces=function(a5)
local a6={}
if a5.Top then
table.insert(a6,"Top")
end
if a5.Bottom then
table.insert(a6,"Enum.NormalId.Bottom")
end
if a5.Left then
table.insert(a6,"Enum.NormalId.Left")
end
if a5.Right then
table.insert(a6,"Enum.NormalId.Right")
end
if a5.Back then
table.insert(a6,"Enum.NormalId.Back")
end
if a5.Front then
table.insert(a6,"Enum.NormalId.Front")
end
return string.format("Faces.new(%s)",table.concat(a6,", "))
end,
EnumItem=function(a5)
return s(a5)
end,
Enums=function(a5)
return"Enum"
end,
Enum=function(a5)
return string.format("Enum.%s",a5)
end,
Vector3=function(a5)
return a2.Vector3[a5]or string.format("Vector3.new(%s)",a5)
end,
Vector2=function(a5)
return a2.Vector2[a5]or string.format("Vector2.new(%s)",a5)
end,
CFrame=function(a5)
return a2.CFrame[a5]or string.format("CFrame.new(%s)",table.concat({a5:GetComponents()},", "))
end,
PathWaypoint=function(a5)
return string.format('PathWaypoint.new(%s, %s, "%s")',a4.Vector3(a5.Position),a5.Action,a5.Label)
end,
UDim=function(a5)
return string.format("UDim.new(%s)",a5)
end,
UDim2=function(a5)
return string.format("UDim2.new(%s)",a5)
end,
Rect=function(a5)
local a6=a4.Vector2
return string.format("Rect.new(%s, %s)",a6(a5.Min),a6(a5.Max))
end,
Color3=function(a5)
return string.format("Color3.new(%s, %s, %s)",a5.R,a5.G,a5.B)
end,
RBXScriptSignal=function(a5)
return"nil --[[RBXScriptSignal unsupported]]"
end,
RBXScriptConnection=function(a5)
return"nil --[[RBXScriptConnection unsupported]]"
end,
}

local a5={
number=function(a5)
local a6=s(a5)
return a3[a6]or a6
end,
boolean=function(a5)
return s(a5)
end,
string=function(a5,a6)
return formatstr(a5,a6)
end,
["function"]=function(a5)
return f2s(a5)
end,
table=function(a5,a6,a7,a8,a9,ba,bb,bc,bd,be)
return t2s(a5,a6,a7,a8,a9,ba,bb,bc,bd,be)
end,
Instance=function(a5)
local a6=p(a5)
return i2p(a5,aQ[a6])
end,
userdata=function(a5)
if b.advancedinfo then
if getrawmetatable(a5)then
return"newproxy(true)"
end
return"newproxy(false)"
end
return"newproxy(true)"
end
}

local a6={
userdata=function(a6,a7)
if a4[a7]then
return a4[a7](a6)
end
string.format("%s(%s) --[[Generation Failure]]",a7,rawtostring(a6))
end,
vector=a4.Vector3
}


function v2s(a7,a8,a9,ba,bb,bc,bd,be,bf,bg)
local bh=typeof(a7)
local bi=a5[bh]
local bj=a6[type(a7)]
type(a7)
if not bg then
bg={0}
else
bg[1]+=1
end

if bi then
return bi(a7,a8,a9,ba,bb,bc,bd,be,bf,bg)
elseif bj then
return bj(a7,bh)
end
return string.format("%s(%s) --[[Generation Failure]]",bh,rawtostring(a7))
end



function v2v(a7)
aE=""
aF=""
aK=false
local a8=""
local a9=1
for ba,bb in next,a7 do
if type(ba)=="string"and ba:match"^[%a_]+[%w_]*$"then
a8=a8 .."local "..ba.." = "..v2s(bb,nil,nil,ba,true).."\n"
elseif rawtostring(ba):match"^[%a_]+[%w_]*$"then
a8=a8 .."local "..g(rawtostring(ba)).."_"..rawtostring(a9).." = "..v2s(bb,nil,nil,g(rawtostring(ba)).."_"..rawtostring(a9),true).."\n"
else
a8=a8 .."local "..type(bb).."_"..rawtostring(a9).." = "..v2s(bb,nil,nil,type(bb).."_"..rawtostring(a9),true).."\n"
end
a9=a9+1
end
if aK then
aE="function getNil(name,class) for _,v in next, getnilinstances() do if v.ClassName==class and v.Name==name then return v;end end end\n"..aE
end
if#aE>0 then
a8=aE.."\n"..a8
end
if#aF>0 then
a8=a8 ..aF
end
return a8
end

function tabletostring(a7:table,a8:boolean)

end












function t2s(a7,a8,a9,ba,bb,bc,bd,be,bf,bg)
local bh=table.find(getgenv(),a7)
if type(bh)=="string"then
return bh
end
if not bg then
bg={0}
end
if not be then
be=""
end
if not a8 then
a8=0
bf={}
end
if not a9 then
a9=a7
end
for bi,bj in next,bf do
if ba and rawequal(bj,a7)then
aF=aF.."\n"..rawtostring(ba)..rawtostring(be).." = "..rawtostring(ba)..rawtostring(({v2p(bj,a9)})[2])
return"{} --[[DUPLICATE]]"
end
end
table.insert(bf,a7)
local bi="{"
local bj=0
a8+=aA
for bk,bl in next,a7 do
bj=bj+1
if bj>(getgenv().SimpleSpyMaxTableSize or 1000)then
bi=bi.."\n"..string.rep(" ",a8).."-- MAXIMUM TABLE SIZE REACHED, CHANGE 'getgenv().SimpleSpyMaxTableSize' TO ADJUST MAXIMUM SIZE "
break
end
if rawequal(bk,a7)then
aF..=string.format("\n%s%s[%s%s] = %s",ba,be,ba,be,rawequal(bl,bk)and string.format("%s%s",ba,be)or v2s(bl,a8,a9,ba,bb,bk,a7,string.format("%s[%s%s]",ba,be,ba),bf))
bj-=1
continue
end
local bm=""
if type(bk)=="string"and bk:match"^[%a_]+[%w_]*$"then
bm="."..bk
else
bm="["..v2s(bk,a8,a9,ba,bb,bk,a7,be..bm,bf,bg).."]"
end
if bj%100==0 then
scheduleWait()
end

bi=bi.."\n"..string.rep(" ",a8).."["..v2s(bk,a8,a9,ba,bb,bk,a7,be..bm,bf,bg).."] = "..v2s(bl,a8,a9,ba,bb,bk,a7,be..bm,bf,bg)..","
end
if#bi>1 then
bi=bi:sub(1,#bi-1)
end
if bj>0 then
bi=bi.."\n"..string.rep(" ",a8-aA)
end
return bi.."}"
end


function f2s(a7)
for a8,a9 in next,getgenv()do
local ba,bb
if rawequal(a9,a7)then
ba,bb=true,""
elseif type(a9)=="table"then
ba,bb=v2p(a7,a9)
end
if ba and type(a8)~="function"then
if type(a8)=="string"and a8:match"^[%a_]+[%w_]*$"then
return a8 ..bb
else
return"getgenv()["..v2s(a8).."]"..bb
end
end
end

if b.funcEnabled then
local a8=q(a7,"n")

if a8 and a8:match"^[%a_]+[%w_]*$"then
return string.format("function %s() end -- Function Called: %s",a8,a8)
end
end
return s(a7)
end



function i2p(a7,a8)
if a8 then
return a8
end
local a9=getplayer(a7)
local ba=a7
local bb=""
if ba==nil then
return"nil"
elseif a9 then
while true do
if ba and ba==a9.Character then
if a9==O.LocalPlayer then
return'game:GetService("Players").LocalPlayer.Character'..bb
else
return i2p(a9)..".Character"..bb
end
else
if ba.Name:match"[%a_]+[%w+]*"~=ba.Name then
bb=':FindFirstChild('..formatstr(ba.Name)..')'..bb
else
bb="."..ba.Name..bb
end
end
task.wait()
ba=ba.Parent
end
elseif ba~=game then
while true do
if ba and ba.Parent==game then
if SafeGetService(ba.ClassName)then
if g(ba.ClassName)=="workspace"then
return string.format("workspace%s",bb)
else
return'game:GetService("'..ba.ClassName..'")'..bb
end
else
if ba.Name:match"[%a_]+[%w_]*"then
return"game."..ba.Name..bb
else
return'game:FindFirstChild('..formatstr(ba.Name)..')'..bb
end
end
elseif not ba.Parent then
aK=true
return'getNil('..formatstr(ba.Name)..', "'..ba.ClassName..'")'..bb
else
if ba.Name:match"[%a_]+[%w_]*"~=ba.Name then
bb=':WaitForChild('..formatstr(ba.Name)..')'..bb
else
bb=':WaitForChild("'..ba.Name..'")'..bb
end
end
if a7:IsDescendantOf(O.LocalPlayer)then
return'game:GetService("Players").LocalPlayer'..bb
end
ba=ba.Parent
task.wait()
end
else
return"game"
end
end


function getplayer(a7)
for a8,a9 in next,O:GetPlayers()do
if a9.Character and(a7:IsDescendantOf(a9.Character)or a7==a9.Character)then
return a9
end
end
end


function v2p(a7,a8,a9,ba)
if not a9 then
a9=""
end
if not ba then
ba={}
end
if rawequal(a7,a8)then
return true,""
end
for bb,bc in next,a8 do
if rawequal(bc,a7)then
if type(bb)=="string"and bb:match"^[%a_]+[%w_]*$"then
return true,(a9 .."."..bb)
else
return true,(a9 .."["..v2s(bb).."]")
end
end
if type(bc)=="table"then
local bd=false
for be,bf in next,ba do
if rawequal(bf,bc)then
bd=true
end
end
if not bd then
table.insert(ba,a8)
local be
be,aJ=v2p(a7,bc,a9,ba)
if be then
if type(bb)=="string"and bb:match"^[%a_]+[%w_]*$"then
return true,"."..bb..aJ
else
return true,"["..v2s(bb).."]"..aJ
end
end
end
end
end
return false,""
end


function formatstr(a7,a8)
if not a8 then
a8=0
end
local a9,ba=handlespecials(a7,a8)
return'"'..a9 ..'"'..(ba and" --[[ MAXIMUM STRING SIZE REACHED, CHANGE 'getgenv().SimpleSpyMaxStringSize' TO ADJUST MAXIMUM SIZE ]]"or"")
end



local function isFinished(a7:table)
for a8,a9 in next,a7 do
if l(a9)=="running"then
return false
end
end
return true
end

local a7={
["\n"]=function(a7,a8)
k(a7,a8,"\\n")
end,
["\t"]=function(a7,a8)
k(a7,a8,"\\t")
end,
["\\"]=function(a7,a8)
k(a7,a8,"\\\\")
end,
['"']=function(a7,a8)
k(a7,a8,"\\\"")
end
}

function handlespecials(a8,a9)
local ba=0
local bb=1
local bc={}
local bd=function(bd,be)
a8=a8:sub(0,bd-1)..be..a8:sub(bd+1,-1)
end
local be=0
repeat
ba+=1
if be>=10 then
task.wait()
be=0
end
local bf=a8:sub(ba,ba)

if h(bf)then
be+=1
local bg=n(bd)
table.insert(bc,bg)
local bh=a7[bf]

if bh then
bh(bg,ba)
ba+=1
elseif h(bf)>126 or h(bf)<32 then
k(bg,ba,"\\"..h(bf))

ba+=#rawtostring(h(bf))
end
if ba>=bb*100 then
local bi=string.format('" ..\n%s"',string.rep(" ",a9+aA))
a8=a8:sub(0,ba)..bi..a8:sub(ba+1,-1)
ba+=#bi
bb+=1
end
end
until bf==""or ba>(getgenv().SimpleSpyMaxStringSize or 10000)
while not isFinished(bc)do
P.Heartbeat:Wait()
end
v(bc)
if ba>(getgenv().SimpleSpyMaxStringSize or 10000)then
a8=string.sub(a8,0,getgenv().SimpleSpyMaxStringSize or 10000)
return a8,true
end
return a8,false
end



function getScriptFromSrc(a8)
local a9
local ba

local bb,bc
local bd=false
if a8:sub(1,1)=="="then
a9=game
bb=2
else
ba=a8:sub(2,bc and bc-1 or-1)
for be,bf in next,getnilinstances()do
if bf.Name==ba then
a9=bf
break
end
end
bb=#ba+1
end
if a9 then
bc=a8:sub(bb,-1):find"%."
local be=0
repeat
be+=1
if not bc then
ba=a8:sub(bb,-1)
local bf=a9.FindFirstChild(a9,ba)
if bf then
a9=bf
end
bd=true
else
ba=a8:sub(bb,bc)
local bf=a9.FindFirstChild(a9,ba)
local bg=bc
if bf then
a9=bf
bb=bc+2
bc=a8:sub(bc+2,-1):find"%."
bc=bc and bc+bg or bc
else
bc=a8:sub(bc+2,-1):find"%."
bc=bc and bc+bg or bc
end
end
until bd or be>=50
end
return a9
end



function schedule(a8,...)
table.insert(aB,{a8,...})
end


function scheduleWait()
local a8=j()
schedule(function()
k(a8)
end)
m()
end


local function taskscheduler()
if not ax then
aB={}
return
end
if#aB>SIMPLESPYCONFIG_MaxRemotes+100 then
table.remove(aB,#aB)
end
if#aB>0 then
local a8=aB[1]
table.remove(aB,1)
if type(a8)=="table"and type(a8[1])=="function"then
pcall(unpack(a8))
end
end
end

local function tablecheck(a8,a9,ba)
return a8[ba]or a8[a9.Name]
end

function remoteHandler(a8)
if b.autoblock then
local a9=a8.id

if aM[a9]then
return
end
if not aL[a9]then
aL[a9]={badOccurances=0,lastCall=tick()}
end
if tick()-aL[a9].lastCall<1 then
aL[a9].badOccurances+=1
return
else
aL[a9].badOccurances=0
end
if aL[a9].badOccurances>3 then
aM[a9]=true
return
end
aL[a9].lastCall=tick()
end

if(a8.remote:IsA"RemoteEvent"or a8.remote:IsA"UnreliableRemoteEvent")and g(a8.method)=="fireserver"then
newRemote("event",a8)
elseif a8.remote:IsA"RemoteFunction"and g(a8.method)=="invokeserver"then
newRemote("function",a8)
end
end

local a8=function(a8,a9,...)
if typeof(...)=='Instance'then
local ba=G(...)

if ba:IsA"RemoteEvent"or ba:IsA"RemoteFunction"or ba:IsA"UnreliableRemoteEvent"then
if not b.logcheckcaller and checkcaller()then return a9(...)end
local bb=ThreadGetDebugId(ba)
local bc=tablecheck(aw,ba,bb)
local bd={select(2,...)}

if not tablecheck(av,ba,bb)and not IsCyclicTable(bd)then
local be={
method=a8,
remote=ba,
args=deepclone(bd),
infofunc=infofunc,
callingscript=callingscript,
metamethod="__index",
blockcheck=bc,
id=bb,
returnvalue={}
}
bd=nil

if b.funcEnabled then
be.infofunc=q(2,"f")
local bf=D()
be.callingscript=bf and G(bf)or nil
end

schedule(remoteHandler,be)



















end
if bc then return end
end
end
return a9(...)
end

local a9=E(function(...)
local a9=getnamecallmethod()

if a9 and(a9=="FireServer"or a9=="fireServer"or a9=="InvokeServer"or a9=="invokeServer")then
if typeof(...)=='Instance'then
local ba=G(...)

if r(ba,"RemoteEvent")or r(ba,"RemoteFunction")or r(ba,"UnreliableRemoteEvent")then
if not b.logcheckcaller and checkcaller()then return aS(...)end
local bb=ThreadGetDebugId(ba)
local bc=tablecheck(aw,ba,bb)
local bd={select(2,...)}

if not tablecheck(av,ba,bb)and not IsCyclicTable(bd)then
local be={
method=a9,
remote=ba,
args=deepclone(bd),
infofunc=infofunc,
callingscript=callingscript,
metamethod="__namecall",
blockcheck=bc,
id=bb,
returnvalue={}
}
bd=nil

if b.funcEnabled then
be.infofunc=q(2,"f")
local bf=D()
be.callingscript=bf and G(bf)or nil
end

schedule(remoteHandler,be)



















end
if bc then return end
end
end
end
return aS(...)
end)

local ba=E(function(...)return a8("FireServer",aX,...)end)
local bb=E(function(...)return a8("FireServer",aY,...)end)
local bc=E(function(...)return a8("InvokeServer",aZ,...)end)

local function disablehooks()
if a0 then
e(getrawmetatable(game).__namecall,aS)
e(Instance.new"RemoteEvent".FireServer,aX)
e(Instance.new"RemoteFunction".InvokeServer,aZ)
e(Instance.new"UnreliableRemoteEvent".FireServer,aY)
restorefunction(aS)
restorefunction(aX)
restorefunction(aZ)
else
if M then M(game,"__namecall",aS)else hookfunction(getrawmetatable(game).__namecall,aS)end
hookfunction(Instance.new"RemoteEvent".FireServer,aX)
hookfunction(Instance.new"RemoteFunction".InvokeServer,aZ)
hookfunction(Instance.new"UnreliableRemoteEvent".FireServer,aY)
end
end


function toggleSpy()
if not ax then
local bd
if a0 then
bd=f(getrawmetatable(game).__namecall,F(a9))
aX=f(Instance.new"RemoteEvent".FireServer,F(ba))
aZ=f(Instance.new"RemoteFunction".InvokeServer,F(bc))
aY=f(Instance.new"UnreliableRemoteEvent".FireServer,F(bb))
else
if M then bd=M(game,"__namecall",F(a9))else bd=hookfunction(getrawmetatable(game).__namecall,F(a9))end
aX=hookfunction(Instance.new"RemoteEvent".FireServer,F(ba))
aZ=hookfunction(Instance.new"RemoteFunction".InvokeServer,F(bc))
aY=hookfunction(Instance.new"UnreliableRemoteEvent".FireServer,F(bb))
end
aS=aS or function(...)return bd(...)end
else
disablehooks()
end
end


function toggleSpyMethod()
toggleSpy()
ax=not ax
end


local function shutdown()
if aC then aC:Disconnect()end
for bd,be in next,aO do be:Disconnect()end
for bd,be in next,aR do if ThreadIsNotDead(be)then o(be)end end
v(aR)
v(aO)
v(at)
v(az)
disablehooks()
X:Destroy()
Y:Destroy()
Q.MouseIconEnabled=true
getgenv().SimpleSpyExecuted=false
end


if not getgenv().SimpleSpyExecuted then
local bd,be=pcall(function()
if not P:IsClient()then error"SimpleSpy cannot run on the server!"end

getgenv().SimpleSpyShutdown=shutdown
onToggleButtonClick()

if not M then ErrorPrompt("Simple Spy V3 will not function to it's fullest capablity due to your executor not supporting hookmetamethod.",true)end

aI=V.new(ad)
logthread(u(function()
local bd,be=pcall(game.HttpGet,game,"https://raw.githubusercontent.com/78n/SimpleSpy/main/UpdateLog.lua")
aI:setRaw((bd and be)or"")
end))

getgenv().SimpleSpy=aD
getgenv().getNil=function(bd,be)for bf,bg in next,getnilinstances()do if bg.ClassName==be and bg.Name==bd then return bg end end end
Z.MouseEnter:Connect(function(...)
aN=true
mouseEntered()
end)
Z.MouseLeave:Connect(function(...)
aN=false
mouseEntered()
end)
am:GetPropertyChangedSignal"Text":Connect(scaleToolTip)
ak.MouseButton1Click:Connect(toggleMinimize)
aj.MouseButton1Click:Connect(toggleSideTray)
ah.MouseButton1Click:Connect(onToggleButtonClick)
ai.MouseEnter:Connect(onXButtonHover)
ai.MouseLeave:Connect(onXButtonUnhover)
ah.MouseEnter:Connect(onToggleButtonHover)
ah.MouseLeave:Connect(onToggleButtonUnhover)
ai.MouseButton1Click:Connect(shutdown)
table.insert(aO,Q.InputBegan:Connect(backgroundUserInput))
connectResize()
X.Enabled=true
logthread(u(function()t(1,onToggleButtonUnhover)end))
aC=P.Heartbeat:Connect(taskscheduler)
bringBackOnResize()
X.Parent=(gethui and gethui())or(syn and syn.protect_gui and syn.protect_gui(X))or N
logthread(u(function()
local bd=O.LocalPlayer or O:GetPropertyChangedSignal"LocalPlayer":Wait()or O.LocalPlayer
aQ={
[p(bd)]='game:GetService("Players").LocalPlayer',
[p(bd:GetMouse())]='game:GetService("Players").LocalPlayer:GetMouse',
[p(game)]="game",
[p(workspace)]="workspace"
}
end))
end)
if bd then
getgenv().SimpleSpyExecuted=true
task.delay(math.random(0.5738929354, 1.57812589789235), toggleSpyMethod)
else
shutdown()
ErrorPrompt("An error has occured:\n"..rawtostring(be))
return
end
else
X:Destroy()
return
end

function aD.newButton(bd,be,bf,bg)
return newButton(be,bf,bg)
end
























newButton(
"Copy Code",
function()return"Click to copy code"end,
function()
L(aI:getString())
am.Text="Copied successfully!"
end
)


newButton(
"Copy Remote",
function()return"Click to copy the path of the remote"end,
function()
if au and au.Remote then
L(v2s(au.Remote))
am.Text="Copied!"
end
end
)


newButton("Run Code",
function()return"Click to execute code"end,
function()
local bd=au and au.Remote
if bd then
am.Text="Executing..."
xpcall(function()
local be
if bd:IsA"RemoteEvent"or bd:IsA"UnreliableRemoteEvent"then
be=bd:FireServer(unpack(au.args))
elseif bd:IsA"RemoteFunction"then
be=bd:InvokeServer(unpack(au.args))
end

am.Text=("Executed successfully!\n%s"):format(v2s(be))
end,function(be)
am.Text=("Execution error!\n%s"):format(be)
end)
return
end
am.Text="Source not found"
end
)


newButton(
"Get Script",
function()return"Click to copy calling script to clipboard\nWARNING: Not super reliable, nil == could not find"end,
function()
if au then
if not au.Source then
au.Source=rawget(getfenv(au.Function),"script")
end
L(v2s(au.Source))
am.Text="Done!"
end
end
)


newButton("Function Info",function()return"Click to view calling function information"end,
function()
local bd=au and au.Function
if bd then
local be=typeof(bd)

if be~='string'then
aI:setRaw"--[[Generating Function Info please wait]]"
P.Heartbeat:Wait()
local bf=z(bd)
local bg=rawget(getfenv(bd),"script")
local bh=au.Source or nil
local bi={}

bi={
info=A(bd),
constants=bf and deepclone(C(bd))or"N/A --Lua Closure expected got C Closure",
upvalues=deepclone(B(bd)),
script={
SourceScript=bg or'nil',
CallingScript=bh or'nil'
}
}

if b.advancedinfo then
local bj=au.Remote

bi.advancedinfo={
Metamethod=au.metamethod,
DebugId={
SourceScriptDebugId=bg and typeof(bg)=="Instance"and p(bg)or"N/A",
CallingScriptDebugId=bh and typeof(bg)=="Instance"and p(bh)or"N/A",
RemoteDebugId=p(bj)
},
Protos=bf and getprotos(bd)or"N/A --Lua Closure expected got C Closure"
}

if bj:IsA"RemoteFunction"then
bi.advancedinfo.OnClientInvoke=getcallbackmember and(getcallbackmember(bj,"OnClientInvoke")or"N/A")or"N/A --Missing function getcallbackmember"
elseif getconnections then
bi.advancedinfo.OnClientEvents={}

for bk,bl in next,getconnections(bj.OnClientEvent)do
bi.advancedinfo.OnClientEvents[bk]={
Function=bl.Function or"N/A",
State=bl.State or"N/A"
}
end
end
end
aI:setRaw"--[[ Converting table to string please wait ]]"
au.Function=v2v{functionInfo=bi}
end
aI:setRaw("-- Calling function info\n-- Generated by the SimpleSpy V3\n\n"..au.Function)
am.Text="Done! Function info generated by the SimpleSpy V3"
else
am.Text="Error! Selected function was not found."
end
end)


newButton(
"Clear Logs",
function()return"Click to clear logs"end,
function()
am.Text="Clearing..."
v(at)

for bd,be in next,aa:GetChildren()do if not be:IsA"UIListLayout"then be:Destroy()end end

aI:setRaw""
au=nil
am.Text="Logs cleared!"
end
)


newButton(
"Exclude (i)",
function()return"Click to exclude this Remote.\nExcluding a remote makes SimpleSpy ignore it, but it will continue to be usable."end,
function()
if au then
av[p(au.Remote)]=true
am.Text="Excluded!"
end
end
)


newButton(
"Exclude (n)",
function()return"Click to exclude all remotes with this name.\nExcluding a remote makes SimpleSpy ignore it, but it will continue to be usable."end,
function()
if au then
av[au.Name]=true
am.Text="Excluded!"
end
end
)


newButton("Clr blacklist",
function()return"Click to clear the blacklist.\nExcluding a remote makes SimpleSpy ignore it, but it will continue to be usable."end,
function()
av={}
am.Text="Blacklist cleared!"
end)


newButton(
"Block (i)",
function()return"Click to stop this remote from firing.\nBlocking a remote won't remove it from SimpleSpy logs, but it will not continue to fire the server."end,
function()
if au then
aw[p(au.Remote)]=true
am.Text="Excluded!"
end
end
)


newButton("Block (n)",function()
return"Click to stop remotes with this name from firing.\nBlocking a remote won't remove it from SimpleSpy logs, but it will not continue to fire the server."end,
function()
if au then
aw[au.Name]=true
am.Text="Excluded!"
end
end
)


newButton(
"Unblock All",
function()return"Click to stop blocking remotes.\nBlocking a remote won't remove it from SimpleSpy logs, but it will not continue to fire the server."end,
function()
aw={}
am.Text="Blocklist cleared!"
end
)


newButton("Decompile",
function()
return"Decompile source script"
end,function()
if decompile then
if au and au.Source then
local bd=au.Source
if not aP[bd]then
aI:setRaw"--[[Decompiling]]"

xpcall(function()
local be=decompile(bd):gsub("-- Decompiled with the Synapse X Luau decompiler.","")
local bf=v2s(bd)
if(be):find"script"and bf then
aP[bd]=("local script = %s\n%s"):format(bf,be)
end
end,function(be)
return aI:setRaw(("--[[\nAn error has occured\n%s\n]]"):format(be))
end)
end
aI:setRaw(aP[bd]or"--No Source Found")
am.Text="Done!"
else
am.Text="Source not found!"
end
else
am.Text="Missing function (decompile)"
end
end
)



















newButton(
"Disable Info",
function()return string.format("[%s] Toggle function info (because it can cause lag in some games)",b.funcEnabled and"ENABLED"or"DISABLED")end,
function()
b.funcEnabled=not b.funcEnabled
am.Text=string.format("[%s] Toggle function info (because it can cause lag in some games)",b.funcEnabled and"ENABLED"or"DISABLED")
end
)

newButton(
"Auto Block",
function()return string.format("[%s] [BETA] Intelligently detects and excludes spammy remote calls from logs",b.autoblock and"ENABLED"or"DISABLED")end,
function()
b.autoblock=not b.autoblock
am.Text=string.format("[%s] [BETA] Intelligently detects and excludes spammy remote calls from logs",b.autoblock and"ENABLED"or"DISABLED")
aL={}
aM={}
end
)

newButton("Log caller",function()
return("[%s] Log remotes fired by the client"):format(b.logcheckcaller and"ENABLED"or"DISABLED")
end,
function()
b.logcheckcaller=not b.logcheckcaller
am.Text=("[%s] Log remotes fired by the client"):format(b.logcheckcaller and"ENABLED"or"DISABLED")
end)
